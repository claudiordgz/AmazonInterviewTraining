#ifndef __GAYLE_CH01_EX13_HPP__
#define __GAYLE_CH01_EX13_HPP__

#include <boost/tuple/tuple.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range/iterator_range.hpp>

#include <string>
#include <vector>

/*! @brief Similar to Python's Zip function 
 * Allows simultaneous iteration of multiple 
 * containers */
template<class... Conts>
auto zip_range(Conts&... conts) -> decltype(boost::make_iterator_range(
  boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
  boost::make_zip_iterator(boost::make_tuple(conts.end()...)))
  )
{
  return {boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
          boost::make_zip_iterator(boost::make_tuple(conts.end()...))};
}


/*! @brief Given two strings, write a method 
 * to decide if one is a permutation of the other. */
bool IsPermutation(std::string const &lhs, std::string const &rhs);

/*! @brief Inserts a char into a bit container, 
 * if the char already exist in that bit container 
 * then use a new one. */ 
void PushOffsetIntoContainer(std::vector<int> &bit_container, char const &element);

#endif