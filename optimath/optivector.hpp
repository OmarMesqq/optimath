#ifndef OPTIVECTOR_HPP
#define OPTIVECTOR_HPP

#include <cstddef>
#include <stdexcept>

class OptiVector {
public:
    OptiVector();
    virtual ~OptiVector();

    void push_back(int value);
    int at(size_t index);
    void swap_elements(size_t i, size_t j);

private:
    void resize(size_t new_capacity);

    int* data_;
    size_t size_;
    size_t capacity_;
};

extern "C" OptiVector* create_vector();
extern "C" void push_back(OptiVector* vec, int value);
extern "C" int at(OptiVector* vec, size_t index);
extern "C" void swap_elements(OptiVector* vec, size_t i, size_t j);
extern "C" void delete_vector(OptiVector* vec);

#endif // OPTIVECTOR_HPP
