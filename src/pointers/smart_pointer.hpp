#ifndef SMART_POINTER_HPP_
#define SMART_POINTER_HPP_

// Write a smart pointer class.A smart pointer is a data type, usually
// implemented with templates, that simulates a pointer while also providing
// automatic garbage collection. It automatically counts the number of
// references to a SmartPointer<T*> object and frees the object of type T
// when the reference count hits zero.

template<typename T>
class SmartPointer
{
public:
    SmartPointer() : rc(nullptr) {}
    explicit SmartPointer(const T* ptr)
    {
        if (nullptr != ptr)
        {
            rc = new RefCounter(ptr);
        }
    }

    SmartPointer(const SmartPointer<T>& other)
    {
        this->rc = other.rc;
        ++(*this->rc->counter);
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other)
    {
        if (this->rc == other.rc)
        {
            return *this;
        }

        check_remove();
        this->rc = other.rc;
        ++(*this->rc->counter);

        return *this;
    }

    T& operator*()
    {
        return (*this->rc->obj);
    }

    T* operator->()
    {
        return this->rc->obj;
    }

    ~SmartPointer()
    {
        check_remove();
    }

    void set(const T* ptr)
    {
        if (nullptr != rc)
        {
            check_remove();
        }

        rc = new RefCounter(ptr);
    }

    T* get()
    {
        return this->rc->obj;
    }

private:
    void check_remove()
    {
        if (nullptr == rc)
        {
            return;
        }

        if (0 == --(*rc->counter))
        {
            delete rc;
            rc = nullptr;
        }
    }

private:
    struct RefCounter
    {
        T* obj;
        unsigned int* counter;

        RefCounter(T* ptr)
        {
            obj = ptr;
            counter = new unsigned int;
            *counter = 1;
        }

        ~RefCounter()
        {
            delete obj;
            obj = nullptr;

            delete counter;
            counter = nullptr;
        }
    };

    RefCounter* rc;
};

#endif /* SMART_POINTER_HPP_ */
