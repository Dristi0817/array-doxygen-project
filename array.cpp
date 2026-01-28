/**
 * @file array.cpp
 * @author Deitel/Deitel (Additional comments by Olson and Zander)
 * @brief Member function definitions for class Array.
 * @date 2026-01-28
 * @version 1.0
 *
 * @details
 * Implements a dynamic integer array that supports:
 * - Whole-array input/output using stream operators
 * - Assignment and element-by-element comparisons
 * - Built-in size tracking
 * - Range checking using assertions (terminates on out-of-bounds)
 *
 * @note Assumptions:
 * - Size defaults to 10 if size is not specified or if a negative value is passed.
 * - Elements are initialized to zero.
 * - User must enter valid integers when using operator>>.
 * - operator<< prints 10 integers per line.
 */

#include "array.h"
#include <cassert>

/**
 * @brief Tracks the number of Array objects currently instantiated.
 * @details This static data member is defined at file scope and incremented/
 * decremented by constructors/destructor.
 */
int Array::arrayCount = 0;

/**
 * @brief Construct an Array with a given size (default is 10).
 * @param [in] arraySize Requested number of elements.
 *
 * @pre None.
 * @post
 * - size is set to arraySize if arraySize > 0, otherwise size becomes 10.
 * - ptr points to a heap-allocated array of length size.
 * - All elements are initialized to 0.
 * - arrayCount is incremented.
 *
 * @remark Uses assert to verify memory allocation succeeded.
 */
Array::Array(int arraySize) {
   ++arrayCount;
   size = (arraySize > 0 ? arraySize : 10);
   ptr = new int[size];
   assert(ptr != NULL);

   for (int i = 0; i < size; i++)
      ptr[i] = 0;
}

/**
 * @brief Copy construct a new Array from an existing Array.
 * @param [in] init The Array to copy from.
 *
 * @pre init.ptr points to an allocated array with at least init.size elements.
 * @post
 * - *this becomes a deep copy of init.
 * - ptr points to newly allocated memory of length init.size.
 * - arrayCount is incremented.
 *
 * @remark Uses assert to verify memory allocation succeeded.
 */
Array::Array(const Array &init) {
   ++arrayCount;
   size = init.size;
   ptr = new int[size];
   assert(ptr != NULL);

   for (int i = 0; i < size; i++)
      ptr[i] = init.ptr[i];
}

/**
 * @brief Destroy the Array and free its heap memory.
 *
 * @pre ptr points to memory allocated on the heap.
 * @post
 * - ptr memory is deallocated.
 * - arrayCount is decremented.
 */
Array::~Array() {
   --arrayCount;
   delete [] ptr;
}

/**
 * @brief Get the size of the array.
 * @return The number of elements in the array.
 *
 * @pre None.
 * @post Returns the current size of the Array.
 */
int Array::getSize() const { return size; }

/**
 * @brief Assign one Array to another (deep copy).
 * @param [in] right The Array to assign from.
 * @return Reference to *this after assignment.
 *
 * @pre right.ptr points to an allocated array with at least right.size elements.
 * @post
 * - If right is not the same object as *this, *this becomes a deep copy of right.
 * - The old ptr memory is deallocated and replaced by newly allocated memory.
 *
 * @note Self-assignment is safely handled.
 * @remark Uses assert to verify memory allocation succeeded.
 */
const Array& Array::operator=(const Array& right) {
   if (&right != this) {
      delete [] ptr;
      size = right.size;
      ptr = new int[size];
      assert(ptr != NULL);

      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];
   }

   return *this;
}

/**
 * @brief Check if two arrays are equal (same size and elements).
 * @param [in] right The Array to compare with.
 * @return true if sizes match and every element matches; otherwise false.
 *
 * @pre ptr and right.ptr point to allocated arrays with at least size and right.size elements.
 * @post Returns true only when arrays are equal in both size and contents.
 */
bool Array::operator==(const Array& right) const {
   if (size != right.size)
      return false;

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return false;

   return true;
}

/**
 * @brief Check if two arrays are not equal.
 * @param [in] right The Array to compare with.
 * @return true if arrays differ in size or at least one element differs; otherwise false.
 *
 * @pre ptr and right.ptr point to allocated arrays with at least size and right.size elements.
 * @post Returns logical negation of operator==.
 */
bool Array::operator!=(const Array& right) const {
   return !(*this == right);
}

/**
 * @brief Access an element by index with bounds checking.
 * @param [in] subscript Index to access.
 * @return Reference to the element at the given index.
 *
 * @pre 0 <= subscript < size.
 * @post Returns a reference to ptr[subscript].
 *
 * @note If subscript is out of range, the program terminates via assert.
 */
int& Array::operator[](int subscript) {
   assert(0 <= subscript && subscript < size);
   return ptr[subscript];
}

/**
 * @brief Get the number of Array objects currently instantiated.
 * @return Number of Array objects.
 *
 * @pre None.
 * @post Returns the value of the static member arrayCount.
 */
int Array::getArrayCount() { return arrayCount; }

/**
 * @brief Overloaded input operator; reads values for the entire array.
 * @param [in,out] input Input stream to read from.
 * @param [in,out] a Array to fill.
 * @return Reference to the input stream after reading.
 *
 * @pre a.ptr points to an allocated array with at least a.size elements.
 * @post The first a.size elements of a.ptr are filled with integers read from input.
 *
 * @test Provide a stream with exactly a.size integers and verify all elements match.
 */
istream& operator>>(istream &input, Array &a) {
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];
   return input;
}

/**
 * @brief Overloaded output operator; prints the entire array.
 * @param [in,out] output Output stream to write to.
 * @param [in] a Array to print.
 * @return Reference to the output stream after writing.
 *
 * @pre a.ptr points to an allocated array with at least a.size elements.
 * @post The first a.size elements of a.ptr are written to output, 10 per line, ending with endl.
 *
 * @test Print an array of size 10 and confirm there is a newline after 10 elements.
 */
ostream& operator<<(ostream &output, const Array &a) {
   int i;
   for (i = 0; i < a.size; i++) {
      output << a.ptr[i] << ' ';
      if ((i + 1) % 10 == 0)
         output << endl;
   }

   if (i % 10 != 0)
      output << endl;
   return output;
}
