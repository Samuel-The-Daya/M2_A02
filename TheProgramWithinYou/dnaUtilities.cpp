#include <map>
#include <string>
#include "dnaUtilities.hpp"

std::map<char, int> dna::countBases(std::string strand) {

	int aCount{ 0 };
	int cCount{ 0 };
	int gCount{ 0 };
	int tCount{ 0 };

	for (int i = 0; i < strand.size(); i++) {

		if (strand[i] == 'A') aCount++;
		if (strand[i] == 'C') cCount++;
		if (strand[i] == 'G') gCount++;
		if (strand[i] == 'T') tCount++;
	}

	return { {'A', aCount}, {'C', cCount}, {'G', gCount}, {'T', tCount}};

}

std::string dna::hamming(std::string strandX, std::string strandY) {

	if (strandX.size() != strandY.size()) return "Error: Strands are of not of equal length.";

	int hammingDistance{ 0 };

	for (int i = 0; i < strandX.size(); i++) {

		if (strandX[i] != strandY[i]) hammingDistance++;
	}

	return "Hamming Distance Between DNA Strings: " + std::to_string(hammingDistance) + "\n\n";

}