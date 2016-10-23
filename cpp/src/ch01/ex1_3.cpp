#include "ch01/ex1_3.hpp"


bool IsPermutation(std::string const &lhs, std::string const &rhs)
{
  bool returnVal = false;
  if(lhs.size() == rhs.size()) {
    std::vector<int> flag_lhs { 0 };
    std::vector<int> flag_rhs { 0 };
    for(auto&& str : zip_range(lhs, rhs)) {
		PushOffsetIntoContainer(flag_lhs, str.get<0>());
		PushOffsetIntoContainer(flag_rhs, str.get<1>());
    }
    if(flag_rhs.size() == flag_lhs.size()) {
      for(auto&& bitContainer : zip_range(flag_lhs, flag_rhs)) {
		  if (bitContainer.get<0>() == bitContainer.get<1>()) {
          returnVal = true;
        } else {
          returnVal = false;
        }
      }
    }
  }
  return (returnVal);
}

void PushOffsetIntoContainer(std::vector<int> &bit_container, char const &element){
  int offset_ = element - 'a';
  offset_ = 1 << offset_;
  for(auto it = bit_container.begin(); it != bit_container.end(); ++it) {
    if(*it & offset_) {
		  if (std::distance(it, bit_container.end()) == 1) {
		    int pushIt = std::distance(bit_container.begin(), it);
		    bit_container.push_back(0);
		    it = bit_container.begin();
		    std::advance(bit_container.begin(), pushIt);
		  }
    } else {
      *it = *it | offset_;  
      break;
    }
  }
}