#include <Training/basicAdt/stringOperations.hpp>
#include <vector>
#include <boost/tuple/tuple.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range/iterator_range.hpp>

template<class... Conts>
auto zip_range(Conts&... conts)
  -> decltype(boost::make_iterator_range(
  boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
  boost::make_zip_iterator(boost::make_tuple(conts.end()...))))
{
  return {boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
          boost::make_zip_iterator(boost::make_tuple(conts.end()...))};
}


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

void PushOffsetIntoContainer(std::vector<int> &bit_container, char const &element);

bool IsPermutation(std::string const &lhs, std::string const &rhs)
{
  bool returnVal = false;
  if(lhs.size() == rhs.size()) {
    std::vector<int> flag_lhs { 0 };
    std::vector<int> flag_rhs { 0 };
    for(std::size_t i=0; i != lhs.size(); ++i) {
      PushOffsetIntoContainer(flag_lhs, lhs.at(i));
      PushOffsetIntoContainer(flag_rhs, rhs.at(i));
    }
    if(flag_rhs.size() == flag_lhs.size()) {
      for(auto&& t : zip_range(flag_lhs, flag_rhs)) {
        if(t.get<0>() == t.get<1>()) {
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
      if ( std::distance( it, bit_container.end() ) == 1 ) {
        int new_flag = 0 | offset_;
        bit_container.push_back(new_flag);
      } 
    } else {
      *it = *it | offset_;  
    }
  }
}

}