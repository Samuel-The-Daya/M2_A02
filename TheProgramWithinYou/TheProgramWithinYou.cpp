#include <iostream>
#include <string>
#include <map>

#include "userInput.hpp"
#include "dnaUtilities.hpp"

int main()
{
    
    std::string strandX{};
    std::string strandY{};

    do {
        // Ask for two DNA strings
        strandX = fetchInput("Please input a DNA string.\n\n");
        strandY = fetchInput("Please input a second DNA string.\n\n");

        // Escape loop if they are equal
        if (strandY.size() == strandX.size()) break;

        // Prints an error message
        std::cout << "DNA strings do not match the same length. Try again. \n\n";

    } while (true);

    // Count bases for each strand
    std::map countedBasesX = dna::countBases(strandX);
    std::map countedBasesY = dna::countBases(strandY);

    // Prints the strand and it's sorted bases
    std::cout << "\n\n" << strandX << "\n";
    for (auto& p : countedBasesX)
        std::cout << p.first << " : " <<
        p.second << std::endl;

    // Prints the strand and it's sorted bases
    std::cout << "\n" << strandY << "\n";
    for (auto& p : countedBasesY)
        std::cout << p.first << " : " <<
        p.second << std::endl;
    
    // Prints the hamming distance
    std::cout << "\n" << dna::hamming(strandX, strandY);
}
