#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* elements;
    size_t size_;

public:
    Array() : elements(nullptr), size_(0) {}

    Array(unsigned int n) : elements(new T[n]()), size_(n) {
    }

    Array(const Array& other) : elements(new T[other.size_]), size_(other.size_)
    {
        for (size_t i = 0; i < size_; ++i)
        {
            elements[i] = other.elements[i];
        }
    }
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] elements;
            size_ = other.size_;
            elements = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    ~Array()
    {
        delete[] elements;
    }
    const T& operator[](size_t index) const
    {
        if (this->size_ == 0 || index >= this->size_)
        {
            throw InvalidIndexException();
        }
        return elements[index];
    }

    T& operator[](size_t index)
    {
        if (this->size_ == 0 || index >= size_)
        {
            throw InvalidIndexException();
        }
        return elements[index];
    }

    class	InvalidIndexException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
            {
                return ("InvalidIndexException");
            };
	};
    size_t size() const
    {
        return size_;
    }
};
