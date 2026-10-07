#include <iostream>
#include <string>

// Forward Declaration
#include "passwordUtilities.hpp"
#include "utilities.hpp"

// Checks string length to see if the character length passes the minimum parameter
bool minimumCharacterLength(std::string password, int min) {

    if (password.length() >= min) 
        return true;
    else 
        return false;
}

// Checks if any character in the string is an uppercase
bool hasUppercase(std::string password) {

    for (int i = 0; i < password.size(); i++) {

        if (std::isupper(password[i])) return true;
    }

    return false;

}

// Checks if any character in the string is a lowercase
bool hasLowercase(std::string password) {

    for (int i = 0; i < password.size(); i++) {

        if (std::islower(password[i])) return true;
    }

    return false;

}

// Checks if any character in the string is a number 
bool hasNumber(std::string password) {

    for (int i = 0; i < password.size(); i++) {

        if (std::isdigit(password[i])) return true;
    }

    return false;

}

// Checks if any character in string ISN'T an alphanumerical character
// This means it checks if a character in the string isn't:
// a-z
// 0-9
bool hasSpecialCharacter(std::string password) {

    for (int i = 0; i < password.size(); i++) {

        if (!std::isalnum(password[i])) return true;
    }

    return false;

}
