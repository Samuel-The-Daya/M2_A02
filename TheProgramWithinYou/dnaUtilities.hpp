#pragma once
#include <map>

namespace dna {

	std::map<char, int> countBases(std::string);

	std::string hamming(std::string, std::string);
}
