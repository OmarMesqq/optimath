#include <iostream>
#include <cstring>
#include "allocator/olloc.h"
/*
TODO: use memory allocation functions available in C instead of new/delete
*/
class OptiVector {
public:
    OptiVector() : data_(nullptr), size_(0), capacity_(0) {}
    ~OptiVector() { delete[] data_; }

    void push_back(int value) {
        if (size_ == capacity_) {
            resize((capacity_ == 0) ? 1 : 2 * capacity_);
        }
        data_[size_++] = value;
    }

    int at(size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    void swap_elements(size_t i, size_t j) {
        if (i >= size_ || j >= size_) throw std::out_of_range("Index out of range");
        __asm__ (
            "xchg %[x], %[y]"
            : [x] "=r" (data_[i]), [y] "=r" (data_[j])
            : "0" (data_[i]), "1" (data_[j])
        );
    }

private:
    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity];
        std::memcpy(new_data, data_, size_ * sizeof(int));
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    int* data_;
    size_t size_;
    size_t capacity_;
};

extern "C" OptiVector* create_vector() {
    return new OptiVector();
}

extern "C" void push_back(OptiVector* vec, int value) {
    vec->push_back(value);
}

extern "C" int at(OptiVector* vec, size_t index) {
    return vec->at(index);
}

extern "C" void swap_elements(OptiVector* vec, size_t i, size_t j) {
    vec->swap_elements(i, j);
}

extern "C" void delete_vector(OptiVector* vec) {
    delete vec;
}
