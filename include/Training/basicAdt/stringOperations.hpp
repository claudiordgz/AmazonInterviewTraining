#ifndef STRINGOPERATIONS__HPP__
#define STRINGOPERATIONS__HPP__

#include <string>

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

namespace basicAdt {

/*!
 *  Implement an algorithm to determine if a string
 *  has all unique characters. What if you can not use
 *  additional data structures
 */
bool AllUnique(std::string const &rhs);


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