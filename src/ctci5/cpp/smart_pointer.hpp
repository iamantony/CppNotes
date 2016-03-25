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
    SmartPointer() : obj(nullptr), counter(nullptr) {}
    explicit SmartPointer(const T* ptr)
    {
        if (nullptr != ptr)
        {
            obj = ptr;
            counter = new unsigned int;
            *counter = 1;
        }
    }

    SmartPointer(const SmartPointer<T>& other)
    {
        this->obj = other.obj;
        this->counter = other.counter;
        if (nullptr != counter)
        {
            ++(*counter);
        }
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other)
    {
        if (this == &other)
        {
            return *this;
        }

        check_remove();
        this->obj = other.obj;
        this->counter = other.counter;
        if (nullptr != counter)
        {
            ++(*counter);
        }

        return *this;
    }

    T& operator*()
    {
        return *obj;
    }

    T* operator->()
    {
        return obj;
    }

    ~SmartPointer()
    {
        check_remove();
    }

    void set(const T* ptr)
    {
        if (nullptr == counter)
        {
            obj = ptr;
            counter = new unsigned int;
            *counter = 1;
        }
        else
        {
            check_remove();

            counter = new unsigned int;
            obj = ptr;
            *counter = 1;
        }
    }

    T* get()
    {
        return obj;
    }

private:
    void check_remove()
    {
        if (nullptr == counter)
        {
            return;
        }

        if (0 < *counter)
        {
            --(*counter);
        }

        if (0 == *counter)
        {
            if (nullptr != obj)
            {
                delete obj;
                obj = nullptr;
            }

            delete counter;
            counter = nullptr;
        }
    }

private:
    T* obj;
    unsigned int* counter;
};

#endif /* SMART_POINTER_HPP_ */
