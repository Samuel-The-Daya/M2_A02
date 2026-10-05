#include <iostream>
#include <string>
#include <map>

#include "userInput.hpp"
#include "dnaUtilities.hpp"

int main()
{
    std::string strandX = fetchInput("Please input a DNA string.\n\n");
    std::string strandY = fetchInput("Please input a second DNA string.\n\n");

    std::map countedBasesX = dna::countBases(strandX);
    std::map countedBasesY = dna::countBases(strandY);

    std::cout << strandX << "\n";
    for (auto& p : countedBasesX)
        std::cout << p.first << " " <<
        p.second << std::endl;

    std::cout << "\n" << strandY << "\n";
    for (auto& p : countedBasesY)
        std::cout << p.first << " " <<
        p.second << std::endl;

    std::cout << "\n" << dna::hamming(strandX, strandY);
}
