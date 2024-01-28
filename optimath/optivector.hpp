/**
 * @file optivector.hpp
 * @brief Defines the OptiVector class for dynamic array management.
 */

#ifndef OPTIVECTOR_HPP
#define OPTIVECTOR_HPP

#include <cstddef>
#include <stdexcept>

/**
 * @class OptiVector
 * @brief Implements a dynamic array of integers.
 * 
 * OptiVector is a class that manages a dynamic array of integers,
 * allowing for basic operations like adding, accessing, and swapping elements.
 */
class OptiVector {
public:
    /**
     * @brief Constructs an empty OptiVector.
     */
    OptiVector();

    /**
     * @brief Destructs the OptiVector, releasing allocated memory.
     */
    virtual ~OptiVector();

    /**
     * @brief Adds a new value to the end of the vector.
     * @param value The integer value to be added.
     */
    void push_back(int value);

    /**
     * @brief Accesses the element at a specified index in the vector.
     * @param index Index of the element to access.
     * @return The value at the specified index.
     * @throw std::out_of_range If index is out of range.
     */
    int at(size_t index);

    /**
     * @brief Swaps the values of two elements in the vector.
     * @param i The index of the first element.
     * @param j The index of the second element.
     * @throw std::out_of_range If either index is out of range.
     */
    void swap_elements(size_t i, size_t j);

private:
    void resize(size_t new_capacity);

    int* data_;      ///< Pointer to the dynamically allocated array of integers.
    size_t size_;    ///< Current number of elements in the vector.
    size_t capacity_; ///< Current capacity of the vector.
};

extern "C" OptiVector* create_vector();
extern "C" void push_back(OptiVector* vec, int value);
extern "C" int at(OptiVector* vec, size_t index);
extern "C" void swap_elements(OptiVector* vec, size_t i, size_t j);
extern "C" void delete_vector(OptiVector* vec);

#endif // OPTIVECTOR_HPP
