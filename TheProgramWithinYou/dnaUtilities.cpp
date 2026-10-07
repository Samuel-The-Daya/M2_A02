#include <map>
#include <string>
#include "dnaUtilities.hpp"

// Counts the bases of the strand and returns it as a map
std::map<char, int> dna::countBases(std::string strand) {

	// Initialize integer counters
	int aCount{ 0 };
	int cCount{ 0 };
	int gCount{ 0 };
	int tCount{ 0 };

	// Checks for each base and increases their individual count based on the iterated character
	for (int i = 0; i < strand.size(); i++) {

		if (strand[i] == 'A') aCount++;
		if (strand[i] == 'C') cCount++;
		if (strand[i] == 'G') gCount++;
		if (strand[i] == 'T') tCount++;
	}

	// Initialize the map with the four bases and their paired counts
	return { {'A', aCount}, {'C', cCount}, {'G', gCount}, {'T', tCount}};

}

// Returns a string message of the hamming distance between two strands.
// Returns an error string message if both strands are not of equal length.
std::string dna::hamming(std::string strandX, std::string strandY) {

	// If the two strands are not of equal length, return an error message.
	if (strandX.size() != strandY.size()) return "Error: Strands are of not of equal length.";

	// Initialize integer counter
	int hammingDistance{ 0 };

	// Check if characters in their respective strands are equal or not
	// Increase the hammingDistance count if they are not equal
	for (int i = 0; i < strandX.size(); i++) {

		if (strandX[i] != strandY[i]) hammingDistance++;
	}

	// Returns the hamming distance message
	return "Hamming Distance Between DNA Strings: " + std::to_string(hammingDistance) + "\n\n";

}