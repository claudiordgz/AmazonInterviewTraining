#include "ch01/ex1_1.hpp"


bool AllUnique(std::string const &rhs) {
  if(rhs.size() > 26) {
    return false;
  }
  int flag=0;
  for(std::size_t i=0; i!=rhs.size(); ++i){
    int offset = rhs.at(i) - 'a';
    offset = 1 << offset;
    if(flag & offset){
      return false;
    }
    flag = flag | offset;
  }
  return true;
}