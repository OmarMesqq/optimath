#include "optivector.hpp"
#include <cstring>

OptiVector::OptiVector() : data_(nullptr), size_(0), capacity_(0) {}

OptiVector::~OptiVector() {
    delete[] data_;
}

void OptiVector::push_back(int value) {
    if (size_ == capacity_) {
        resize((capacity_ == 0) ? 1 : 2 * capacity_);
    }
    data_[size_++] = value;
}

int OptiVector::at(size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

void OptiVector::swap_elements(size_t i, size_t j) {
    if (i >= size_ || j >= size_) throw std::out_of_range("Index out of range");
    std::swap(data_[i], data_[j]);
}

void OptiVector::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::memcpy(new_data, data_, size_ * sizeof(int));
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

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
