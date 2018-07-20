#ifndef SHARED_POINTER_HPP_
#define SHARED_POINTER_HPP_

// Write a shared pointer class. A shared pointer is a data type, usually
// implemented with templates, that simulates a pointer while also providing
// automatic garbage collection. It automatically counts the number of
// references to a SharedPointer<T*> object and frees the object of type T
// when the reference count hits zero.

// http://lokiastari.com/blog/2014/12/30/c-plus-plus-by-example-smart-pointer/
// http://lokiastari.com/blog/2015/01/15/c-plus-plus-by-example-smart-pointer-part-ii/
// http://lokiastari.com/blog/2015/01/23/c-plus-plus-by-example-smart-pointer-part-iii/

#include <mutex>

namespace Pointers {

template<typename T>
class SharedPointer
{
    class RefCounter {
        T* obj;
        int counter;
        std::mutex mutex;

    public:
        RefCounter() : obj(nullptr), counter(0) { }
        explicit RefCounter(T* ptr) : obj(ptr) {
            if (obj) {
                counter = 1;
            }
        }

        RefCounter(const RefCounter& other) = delete;
        RefCounter& operator=(const RefCounter& other) = delete;
        RefCounter(const RefCounter&& other) = delete;
        RefCounter& operator=(const RefCounter&& other) = delete;

        ~RefCounter() {
            DecreaseReferenceCounter();
        }

        // Inside Get() we don't change 'obj', so we could make it const method
        T* Get() const {
            return obj;
        }

        void IncreaseReferenceCounter() {
            std::lock_guard<std::mutex> lock(mutex);
            obj == nullptr ? counter = 0 : ++counter;
        }

        void DecreaseReferenceCounter() {
            std::lock_guard<std::mutex> lock(mutex);
            --counter;
            if (counter <= 0 && obj != nullptr) {
                delete obj;
                obj = nullptr;
                counter = 0;
            }
        }
    };

    RefCounter* rc;

public:
    // Default constructor
    SharedPointer() : rc(nullptr) {}

    // Constructor with T* arg
    explicit SharedPointer(T* ptr) : rc(nullptr) {
        if (nullptr != ptr) {
            // We could not have enough memory to create new RefCounter,
            // so we should catch exception, delete ptr (or it will be
            // leaked) and rethrow exception
            try {
                rc = new RefCounter(ptr);
            }
            catch(...) {
                delete ptr;
                throw;
            }
        }
    }

    // Copy constructor
    SharedPointer(const SharedPointer<T>& other) {
        rc = other.rc;
        if (rc != nullptr) {
            rc->IncreaseReferenceCounter();
        }
    }

    // Copy assignment operator
    // Here we implicitly create copy of the some other SharedPointer into
    // function argument. Next we just swap rc members. In destructor of
    // argument object ref counter of our old rc member will be decreased.
    SharedPointer<T>& operator=(SharedPointer<T> other) {
        other.swap(*this);
        return *this;
    }

    // Move constructor
    // Move semantics say that the source object may be left in an undefined
    // (but must be valid) state. So the easiest way to implement this is
    // simply to swap the state of the current object with the source object
    // (we know our state is valid so just swap it with the incoming object
    // state (its destructor will then take care of destroying the pointer
    // we are holding)).
    SharedPointer(SharedPointer<T>&& other) {
        other.swap(*this);
    }

    // Move assignment operator
    SharedPointer<T>& operator=(const SharedPointer<T>&& other) {
        other.swap(*this);
        return *this;
    }

    // Destructor
    ~SharedPointer() {
        CheckRemove();
    }

    void swap(SharedPointer<T>& other) noexcept {
        std::swap(rc, other.rc);
    }

    T& operator*() const {
        return *Get();
    }

    T* operator->() const {
        return Get();
    }

    void Reset(const T* ptr) {
        if (nullptr != rc) {
            CheckRemove();
        }

        try {
            rc = new RefCounter(ptr);
        }
        catch(...) {
            delete ptr;
            throw;
        }
    }

    T* Get() {
        if (rc) {
            return rc->obj;
        }

        return nullptr;
    }

private:
    void CheckRemove() {
        if (rc != nullptr) {
            delete rc;
            rc = nullptr;
        }
    }
};

template <typename T>
class SharedPointer2 {
    T* object = nullptr;
    int* counter = nullptr;

public:
    // Default constructor
    SharedPointer2() { }

    // Explicit constructor that get pointer to some object that we want to
    // share
    explicit SharedPointer2(T* obj) {
        if (obj != nullptr) {
            // If we would not have enough memory to create new counter, we
            // will get std::bad_alloc exception. So in catch() section
            // we should delete 'obj' (or it will be leaked)
            // and rethrow exception
            try {
                counter = new int(1);
            }
            catch(...) {
                delete obj;
                throw;
            }

            object = obj;
        }
    }

    // Copy constructor
    SharedPointer2(const SharedPointer2<T>& other) {
        object = other.object;
        counter = other.counter;
        if (counter) {
            ++(*counter);
        }
    }

    // Copy assignment operator
    // Here we implicitly create copy of the some other SharedPointer2 into
    // function argument. Next we just swap class members. In destructor of
    // argument object our old 'counter' will be decreased and object will be
    // removed, if necessary
    SharedPointer2<T>& operator=(SharedPointer2<T> other) {
        other.swap(*this);
        return *this;
    }

    // Move constructor
    // Move semantics say that the source object may be left in an undefined
    // (but must be valid) state. So the easiest way to implement this is
    // simply to swap the state of the current object with the source object
    // (we know our state is valid so just swap it with the incoming object
    // state (its destructor will then take care of destroying the pointers
    // we are holding)).
    SharedPointer2(SharedPointer2<T>&& other) {
        other.swap(*this);
    }

    // Move assignment operator
    SharedPointer2<T>& operator=(const SharedPointer2<T>&& other) {
        other.swap(*this);
        return *this;
    }

    // Destructor
    ~SharedPointer2() {
        if (nullptr == counter) {
            return;
        }

        --(*counter);
        if (*counter <= 0) {
            if (object != nullptr) {
                delete object;
                object = nullptr;
            }

            delete counter;
            counter = nullptr;
        }
    }

    void swap(SharedPointer2<T>& other) {
        std::swap(object, other.object);
        std::swap(counter, other.counter);
    }

    // Inside these access functions we don't change 'object', so we could
    // define them as const methods
    T& operator*() const {
        return *Get();
    }

    T* operator->() const {
        return Get();
    }

    T* Get() const {
        return object;
    }
};

}

#endif /* SHARED_POINTER_HPP_ */
