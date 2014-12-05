#ifndef __GAYLE_CH01_EX15_HPP__
#define __GAYLE_CH01_EX15_HPP__

#include <string>

/*! Implement a method to perform basic string 
 * compression using the counts of repeated characters. 
 * For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not 
 * become smaller than the original string, your method 
 * should return the original string. */
std::string compressWord(std::string const &rhs);


#endif