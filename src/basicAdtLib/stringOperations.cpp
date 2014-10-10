#include <Training/basicAdt/stringOperations.hpp>

namespace basicAdt 
{

bool AllUnique(string const &rhs) {
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

void Reverse(char *str) {
  if(str){
    char *end = str;
    while(*end) {
      ++end;
    }
    --end;
    char tmp;
    while(str < end) {
      tmp = *str;
      *str++ = *end;
      *end--  = tmp;
    }
  }
}


void RemoveDuplicate(std::string &rhs)
{
  if(!rhs.empty()){
    int flag=0;
    for(std::size_t i=0; i!=rhs.size(); ++i){
      int offset = rhs.at(i) - 'a';
      offset = 1 << offset;
      if(flag & offset){
        rhs.erase(rhs.begin()+i);
        i--;
      }
      flag = flag | offset;
    }
  }
}

void PushOffsetIntoContainer(int &bit_container, char const &element);

bool IsPermutation(std::string const &lhs, std::string const &rhs)
{
  bool returnVal = false;
  if(lhs.size() == rhs.size()){
    int flag_lhs = 0;
    int flag_rhs = 0;
    for(std::size_t i=0; i != lhs.size(); ++i){
      PushOffsetIntoContainer(flag_lhs, lhs.at(i));
      PushOffsetIntoContainer(flag_rhs, rhs.at(i));
    }
    if(flag_lhs == flag_rhs){
      returnVal = true;
    }
  }
  return (returnVal);
}

void PushOffsetIntoContainer(int &bit_container, char const &element){
  int offset_ = element - 'a';
  offset_ = 1 << offset_;
  bit_container = bit_container | offset_;
}

}