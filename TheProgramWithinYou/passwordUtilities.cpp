#include <iostream>
#include <string>

// Forward Declaration
#include "passwordUtilities.hpp"
#include "utilities.hpp"

// Master boolean to check if the password is strong
// This could be a very powerful function, but for the sake of simplicity, it is hardcoded
bool strongPassword(std::string password) {

    // List of criterias to pass
    // If the password fails any of these criterias; return false

    // Password must have a minimum eight character length
    if (!minimumCharacterLength(password, 8)) {

        std::cout << "\n\nError: Your password must be at least 8 characters in length.\n\n";
        return false;

    }
    // Password must have a lowercase
    else if (!hasLowercase(password)) {

        std::cout << "\n\nError: Your password must contain at least one lower case letter.\n\n";
        return false;

    }
    // Password must have an uppercase
    else if (!hasUppercase(password)) {

        std::cout << "\n\nError: Your password must contain at least one upper case letter.\n\n";
        return false;

    }
    // Password must have a number
    else if (!hasNumber(password)) {

        std::cout << "\n\nError: Your password must contain at least one number.\n\n";
        return false;

    }
    // Samuel Special: Password must have a special character
    else if (!hasSpecialCharacter(password)) {
        std::cout << "\n\nError: Your password must contain at least one special character.\n\n";
        return false;
    }

    return true;

}

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
