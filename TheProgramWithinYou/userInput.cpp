#include <iostream>
#include <string>

// Forward declaration
#include "userInput.hpp"
#include "utilities.hpp"
#include "passwordUtilities.hpp"


// Grabs user input
std::string fetchInput(std::string prompt) {

    do {

        std::string input;

        // Displays the string prompt
        std::cout << prompt;

        std::getline(std::cin, input);

        // Only returns if the number is a double or a valid type to convert
        if (!doesStringInclude(input, " ") && !hasNumber(input) && hasUppercase(input) && !hasSpecialCharacter(input)) {
            return input;
        }

        std::cout << "Error: Please input a valid DNA string.\n\n";

        // No number found so clear the cin error flag:
        std::cin.clear();
        // Ignore remaining user input to reset stream for the next try.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (true);

}