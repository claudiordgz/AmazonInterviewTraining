#ifndef MATRIXOPERATIONS__HPP__
#define MATRIXOPERATIONS__HPP__

#include <vector>

namespace basicAdt {

template<class _T>
class CW {
public:
  void rotate(_T &upperLCorner, _T &upperRCorner, _T &lowerLCorner, _T &lowerRCorner){
    _T temp = upperLCorner;
    upperLCorner = lowerLCorner;
    lowerLCorner = lowerRCorner;
    lowerRCorner = upperRCorner;
    upperRCorner = temp;
  }
};

template<class _T>
class CCW {
public:
  void rotate(_T &upperLCorner, _T &upperRCorner, _T &lowerLCorner, _T &lowerRCorner){
    _T temp = upperLCorner;
    upperLCorner = upperRCorner;
    upperRCorner = lowerRCorner;
    lowerRCorner = lowerLCorner;
    lowerLCorner = temp;
  }
};

/*! Given an image represented by an NxN matrix, where each pixel in the image is
 *  4 bytes, write a method to rotate the image by 90 degrees. IN PLACE
 */
template<template<typename> class DirectionPolicy, class _Type>
class Rotate {
  DirectionPolicy<_Type> direction;
public:
  Rotate(std::vector<std::vector<_Type> > &squareMatrix){
    int n = squareMatrix.size() - 1;
    int outerEnd = squareMatrix.size() / 2;
    int innerEnd = (squareMatrix.size() + 1) / 2;
    for (int i = 0; i != outerEnd; ++i) {
      for (int j = 0; j != innerEnd; ++j) {
        direction.rotate(squareMatrix[i][j], squareMatrix[j][n - i],
          squareMatrix[n - j][i], squareMatrix[n - i][n - j]);
      }
    }
  }
};

  
}

#endif