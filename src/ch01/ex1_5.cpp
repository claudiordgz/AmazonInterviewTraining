#include "ch01/ex1_5.hpp"
#include <sstream>

std::string compressWord(std::string const &rhs) {
  auto it = rhs.begin();
  auto pastEl = *it;
  std::advance(it, 1);
  std::stringstream finalAssembly;
  int count = 1;
  for (; it != rhs.end(); ++it) {
    if (pastEl == *it){
      count += 1;
    }
    else {
      finalAssembly << pastEl << count;
      count = 1;
      pastEl = *it;
    }
  }
  finalAssembly << pastEl << count;
  std::string result = finalAssembly.str();
  if (rhs.size() <= result.size()) {
    return rhs;
  }
  else {
    return result;
  }
}