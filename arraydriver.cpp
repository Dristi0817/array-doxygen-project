/**
 * @file arraydriver.cpp
 * @author Deitel and Deitel
 * @brief Driver program to test the Array class.
 * @date 2026-01-28
 * @version 1.0
 *
 * @details
 * This program demonstrates:
 * - Creating Array objects and checking the static object count
 * - Input/output of arrays using overloaded stream operators (>> and <<)
 * - Comparison operators (== and !=)
 * - Copy construction and assignment
 * - Bounds checking using operator[]
 *
 * @note
 * The final test intentionally attempts an out-of-range index (integers1[15]) to
 * demonstrate that the Array class terminates on invalid subscripts.
 *
 * @see Array
 * @test Run the program and enter 17 integers when prompted.
 */

#include "array.h"

/**
 * @brief Entry point for the Array class driver/test program.
 * @return 0 when the program ends (if it is not terminated earlier by an assert).
 *
 * @pre The user provides valid integer input when prompted.
 * @post
 * - Demonstrates Array operations and prints results to standard output.
 * - The program will terminate early at the out-of-range subscript test.
 *
 * @remark This driver is meant for testing and demonstration, not as a library component.
 */
int main() {
   // no objects yet
   cout << "# of arrays instantiated = "
        << Array::getArrayCount() << endl;

   // create two arrays and print Array count
   Array integers1(7), integers2;
   cout << "# of arrays instantiated = "
        << Array::getArrayCount() << endl << endl;

   // print integers1 size and contents
   cout << "Size of array integers1 is " << integers1.getSize() << endl
        << "Array after initialization:" << endl << integers1 << endl;

   // print integers2 size and contents
   cout << "Size of array integers2 is " << integers2.getSize() << endl
        << "Array after initialization:" << endl << integers2 << endl;

   // input and print integers1 and integers2
   cout << "Input 17 integers:" << endl;
   cin >> integers1 >> integers2;
   cout << "After input, the arrays contain:" << endl
        << "integers1: " << integers1
        << "integers2: " << integers2 << endl;

   // use overloaded inequality (!=) operator
   cout << "Evaluating: integers1 != integers2" << endl;
   if (integers1 != integers2)
      cout << "They are not equal" << endl;

   // create array integers3 using integers1 as an initializer
   Array integers3(integers1);

   cout << endl << "Size of array integers3 is " << integers3.getSize() << endl
        << "Array after initialization:" << endl << integers3 << endl;

   // use overloaded assignment (=) operator
   cout << "Assigning integers2 to integers1:" << endl;
   integers1 = integers2;
   cout << "integers1: " << integers1
        << "integers2: " << integers2 << endl;

   // use overloaded equality (==) operator
   cout << "Evaluating: integers1 == integers2" << endl;
   if (integers1 == integers2)
      cout << "They are equal" << endl << endl;

   // use overloaded subscript operator to create rvalue
   cout << "integers1[5] is " << integers1[5] << endl;

   // use overloaded subscript operator to create lvalue
   cout << "Assigning 1000 to integers1[5]" << endl;
   integers1[5] = 1000;
   cout << "integers1: " << integers1 << endl;

   // attempt to use out of range subscript (intentional error case)
   cout << endl << "Attempt to assign 1000 to integers1[15]" << endl;
   integers1[15] = 1000;  // ERROR: out of range (expected to terminate via assert)

   return 0;
}
