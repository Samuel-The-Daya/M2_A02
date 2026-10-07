#pragma once
#include <string>

/// <summary>
/// Checks string size to be more than minimum integer value
/// </summary>
/// <param name="password"></param>
/// <param name="minimum"></param>
/// <returns>boolean</returns>
bool minimumCharacterLength(std::string, int);

/// <summary>
/// Returns true if string contains an uppercase
/// </summary>
/// <param name="password"></param>
/// <returns>boolean</returns>
bool hasUppercase(std::string password);

/// <summary>
/// Returns true if string contains a lowercase
/// </summary>
/// <param name="password"></param>
/// <returns>boolean</returns>
bool hasLowercase(std::string password);

/// <summary>
/// Returns true if string contains a numerical character
/// </summary>
/// <param name="password"></param>
/// <returns>boolean</returns>
bool hasNumber(std::string password);

/// <summary>
/// Returns true if string contains a non-alphanumerical character
/// </summary>
/// <param name="password"></param>
/// <returns></returns>
bool hasSpecialCharacter(std::string password);