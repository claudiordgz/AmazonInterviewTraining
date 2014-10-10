#define BOOST_TEST_MAIN 
#define BOOST_TEST_MODULE BasicAbstractDataTypes
#include <boost/test/unit_test.hpp>

#include <Training/basicAdt/basicAdt.hpp>
#include <Training/basicAdt/stringOperations.hpp>

using basicAdt::AllUnique;
using basicAdt::Reverse;
using basicAdt::RemoveDuplicate;
using basicAdt::IsPermutation;

BOOST_AUTO_TEST_SUITE(BasicAbstractDataTypes_suite)

BOOST_AUTO_TEST_CASE( string_all_unique_test_true )
{
	std::string murcielago("murcielago");
	BOOST_CHECK(AllUnique(murcielago));
	std::string abc("abcdefghijklmnoprstuvwxyz");
	BOOST_CHECK(AllUnique(abc));
}

BOOST_AUTO_TEST_CASE( string_all_unique_test_false )
{
  	std::string pepe("pepe");
	BOOST_CHECK(!AllUnique(pepe));
	std::string onomatopeya("onomatopeya");
	BOOST_CHECK(!AllUnique(onomatopeya));
}

BOOST_AUTO_TEST_CASE( string_reverse )
{
	char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	Reverse(hello);
	std::string result("olleH");
	BOOST_CHECK(!result.compare(hello));
}

BOOST_AUTO_TEST_CASE( string_reverse_long_string )
{
	char paranga[] = { 'P', 'a', 'r', 'a', 'n', 'g', 'a', 'c',
			'u', 't', 'i', 'r', 'i', 'm', 'i', 'c', 'u', 'a', 'r', 'o', '\0' };
	Reverse(paranga);
	std::string result("oraucimiritucagnaraP");
	BOOST_CHECK(!result.compare(paranga));
}

BOOST_AUTO_TEST_CASE( string_remove_duplicate )
{
	std::string onomatopeya("onomatopeya");
	RemoveDuplicate(onomatopeya);
	BOOST_CHECK(!onomatopeya.compare("onmatpey"));
}

BOOST_AUTO_TEST_CASE( string_remove_duplicate_long )
{
	std::string longest_word_maybe("pneumonoultramicroscopicsilicovolcanoconiosis");
	RemoveDuplicate(longest_word_maybe);
	BOOST_CHECK(!longest_word_maybe.compare("pneumoltraicsv"));
}

BOOST_AUTO_TEST_CASE( permutation_small )
{
	std::string word("Parangacutirimicuaro");
	std::string permutation("oraucimiritucagnaraP");
	BOOST_CHECK(IsPermutation(word, permutation));
}

BOOST_AUTO_TEST_SUITE_END()