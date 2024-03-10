#ifndef OPTIVECTOR_HPP
#define OPTIVECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <algorithm>

template <typename T>
class OptiVector {
    T* data_;  // Pointer to the dynamically allocated array of integers.
    size_t size_;  // Current number of elements in the vector.
    size_t capacity_;  // Current capacity of the vector.

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i]; // Use copy assignment of T
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    OptiVector() : data_(nullptr), size_(0), capacity_(0) {}

    virtual ~OptiVector() {
        delete[] data_;
    }

    void push_back(T value) {
        if (size_ == capacity_) {
            resize((capacity_ == 0) ? 1 : 2 * capacity_);
        }
        data_[size_++] = value;
    }

    T at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        };
        return data_[index];
    }

    void swap_elements(size_t i, size_t j) {
        if (i >= size_ || j >= size_) {
            throw std::out_of_range("Index out of range");
        }
        std::swap(data_[i], data_[j]);
    }
};

#endif // OPTIVECTOR_HPP
