#include "ch01/ex1_8.hpp"

bool IsRotation::isSubstring(std::string const &lhs, std::string const &rhs) {
  return (lhs.find(rhs) != std::string::npos);
}

bool IsRotation::check(std::string const &lhs, std::string const &rhs){
  return (isSubstring(std::string(lhs+lhs), rhs));
}