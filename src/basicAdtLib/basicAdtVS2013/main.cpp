#include <iostream>
#include <Training/basicAdt/basicAdt.hpp>
#include <Training/basicAdt/stringOperations.hpp>



int main() {
  using basicAdt::AllUnique;
  using basicAdt::Reverse;
  using basicAdt::RemoveDuplicate;
  using basicAdt::IsPermutation;
  using basicAdt::encodeSpacesStringNoFindNoInsert;
  using basicAdt::encodeSpacesStringFind;

	/*std::string word("parangacutirimicuaro");
	std::string permutation("oraucimiritucagnarap");
	IsPermutation(word, permutation);

	word = "ooooooooooaaaaoooooooo";
	permutation = "ooaooooaooooaooooaoooo";
	IsPermutation(word, permutation);


	word = "ooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaoooooooo";
	permutation = "ooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaoooo";
	IsPermutation(word, permutation);*/

  encodeSpacesStringNoFindNoInsert(std::string("Mr   John Smith    "));
  encodeSpacesStringFind(std::string("Mr   John Smith    "));
	return 0;
}