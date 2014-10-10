#ifndef STRINGOPERATIONS__HPP__
#define STRINGOPERATIONS__HPP__

#include <string>

using std::string;

namespace basicAdt {

/*!
 *  Implement an algorithm to determine if a string
 *  has all unique characters. What if you can not use
 *  additional data structures
 */
bool AllUnique(string const &rhs);


/*!
 * Write code to reverse a C Style String
 */
void Reverse(char *str);

/*!
 * Design an algorithm and write code to remove the duplicate
 * characters in a string without using any additional buffer
 */
void RemoveDuplicate(std::string &rhs);

/*!
 * Given two strings, write a method to decide if one is a permutation of the other.
 */
bool IsPermutation(std::string const &lhs, std::string const &rhs);

}

#endif