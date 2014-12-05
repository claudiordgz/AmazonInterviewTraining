#ifndef __GAYLE_CH01_EX17_HPP__
#define __GAYLE_CH01_EX17_HPP__

#include <vector>
#include <set>

/*! @brief Write an algorithm such that if an 
 * element in an MxN matrix is 0, its 
 * entire row and column are set to 0. */
class ClearRowsColumns {
public:
  ClearRowsColumns(std::vector<std::vector<int> > &rectangularMatrix);

private:
  void clearCells(std::vector<std::vector<int> > &rectangularMatrix, 
                        std::set<int> const &mostZeros,
                        std::set<int> const &leastZeros, 
                        std::set<int> const &leastNumbers, int const&N);
  std::set<int> rowZeros;
  std::set<int> columnZeros;
  std::set<int> rowNumbers;
  std::set<int> columnNumbers;
};

#endif