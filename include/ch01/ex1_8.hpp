#ifndef __GAYLE_CH01_EX17_HPP__
#define __GAYLE_CH01_EX17_HPP__

#include <string>

/*!Assume you have a method isSubstring which checks if one word is a
 * substring of another. Given two strings, si and s2, write code to check if s2 is
 * a rotation of s1 using only one call to isSubstring (e.g.,"waterbottle"is a rota-
 * tion of "erbottlewat"
*/
class IsRotation {
public:
  bool check(std::string const &lhs, std::string const &rhs);
private:
  bool isSubstring(std::string const &lhs, std::string const &rhs);
};

#endif