#pragma once
#include <map>

namespace dna {

	/// <summary>
	/// Counts the bases from the dna strand and returns as a map
	/// </summary>
	/// <param name="strand"></param>
	/// <returns>std::map(char, int)</returns>
	std::map<char, int> countBases(std::string);

	/// <summary>
	/// Returns a string message of the hamming distance between two strands.
	/// Returns an error string message if both strands are not of equal length.
	/// </summary>
	/// <param name="strandX"></param>
	/// <param name="strandY"></param>
	/// <returns>std::string</returns>
	std::string hamming(std::string, std::string);
}
