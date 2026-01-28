/**
 * @file array.h
 * @author Deitel/Deitel (Additional comments by Olson and Zander)
 * @brief Defines the Array class (a safe integer array with I/O and comparisons).
 * @date 2026-01-28
 * @version 1.0
 *
 * @details
 * This header defines class Array, which behaves like an integer array but adds:
 * - Whole-array input/output using stream operators
 * - Assignment and element-by-element comparisons
 * - Built-in size tracking (no need to pass size around)
 * - Range checking for subscripts (terminates on out-of-bounds)
 *
 * @note
 * - Default size is 10 if no size is specified (or if a negative size is given).
 * - Elements are initialized to 0.
 * - Input expects valid integers.
 * - Output prints 10 integers per line.
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

/**
 * @class Array
 * @brief A dynamic array of integers with bounds checking and stream I/O.
 *
 * @details
 * Stores its size internally, allocates memory on the heap, and supports:
 * copying, assignment, comparison, and safe indexed access.
 */
class Array {

   /**
    * @brief Overloaded input operator for Array; reads values for the entire array.
    * @param [in,out] in Input stream to read from.
    * @param [in,out] a Array object to fill.
    * @return Reference to the input stream after reading.
    *
    * @pre a.ptr points to an allocated array with at least a.size elements.
    * @post The first a.size elements of a.ptr are filled with integers read from in.
    */
   friend istream& operator>>(istream& in, Array& a);

   /**
    * @brief Overloaded output operator for Array; prints the entire array.
    * @param [in,out] out Output stream to write to.
    * @param [in] a Array object to print.
    * @return Reference to the output stream after writing.
    *
    * @pre a.ptr points to an allocated array with at least a.size elements.
    * @post The first a.size elements of a.ptr are written to out, 10 per line, ending with endl.
    */
   friend ostream& operator<<(ostream& out, const Array& a);

public:
   /**
    * @brief Construct an Array with a given size (default is 10).
    * @param [in] arraySize Requested size of the array.
    *
    * @pre None.
    * @post
    * - ptr points to a heap-allocated array of size arraySize (or 10 if arraySize is negative).
    * - All elements are initialized to 0.
    * - arrayCount is incremented.
    */
   Array(int arraySize = 10);

   /**
    * @brief Copy construct a new Array from an existing Array.
    * @param [in] init The Array to copy from.
    *
    * @pre init.ptr points to an allocated array with at least init.size elements.
    * @post
    * - *this becomes a deep copy of init (new memory, same values).
    * - arrayCount is incremented.
    */
   Array(const Array& init);

   /**
    * @brief Destroy the Array and free its heap memory.
    *
    * @pre ptr points to memory on the heap (or is nullptr if implementation uses that).
    * @post
    * - ptr memory is deallocated.
    * - arrayCount is decremented.
    */
   ~Array();

   /**
    * @brief Get the size of the array.
    * @return The number of elements in the array.
    *
    * @pre None.
    * @post Returns the size of the array.
    */
   int getSize() const;

   /**
    * @brief Assign one Array to another (deep copy).
    * @param [in] right The Array to assign from.
    * @return Reference to *this after assignment.
    *
    * @pre right.ptr points to an allocated array with at least right.size elements.
    * @post *this contains a deep copy of right.
    */
   const Array& operator=(const Array& right);

   /**
    * @brief Check if two arrays are equal (same size and same elements).
    * @param [in] right The Array to compare with.
    * @return true if same size and all elements match; otherwise false.
    *
    * @pre ptr and right.ptr point to allocated arrays with at least size and right.size elements.
    * @post Returns true if arrays match in size and values; false otherwise.
    */
   bool operator==(const Array& right) const;

   /**
    * @brief Check if two arrays are not equal.
    * @param [in] right The Array to compare with.
    * @return true if arrays differ in size or any element differs; otherwise false.
    *
    * @pre ptr and right.ptr point to allocated arrays with at least size and right.size elements.
    * @post Returns logical negation of operator==.
    */
   bool operator!=(const Array& right) const;

   /**
    * @brief Access an element by index with bounds checking.
    * @param [in] subscript Index of the element to access.
    * @return Reference to the element at position subscript.
    *
    * @pre 0 <= subscript < size.
    * @post Returns a reference to the array element at index subscript.
    * @note If subscript is out of range, the program terminates (per project description).
    */
   int& operator[](int subscript);

   /**
    * @brief Get the number of Array objects currently instantiated.
    * @return Number of Array objects.
    *
    * @pre None.
    * @post Returns the number of arrays (arrayCount).
    */
   static int getArrayCount();

private:
   int* ptr;              ///< Pointer to first element of the array.
   int size;              ///< Size of the array.
   static int arrayCount; ///< Number of Array objects instantiated.
};

#endif
