#include <iostream>
#include <string>
#include <vector>

// Forward Declaration
#include "utilities.hpp"

// Boolean to check if the main string contains the substring
bool doesStringInclude(std::string_view str, std::string substr) {

    if (str.find(substr) != std::string::npos) return true;
    else
        return false;
}

// Overload of the first boolean
// Boolean to check if the main string contains any of the substrings in the vector
bool doesStringInclude(std::string_view str, std::vector<std::string> strVector) {

    for (int i = 0; i < strVector.size(); i++) {

        if (str.find(strVector[i]) != std::string::npos) return true;
    }

    return false;
}

int randomInteger(int min, int max) {
    const int range = max - min + 1;
    return rand() % range + min;
}