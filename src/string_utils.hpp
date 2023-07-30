#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

using namespace std;

/**
 * @brief check whether a string ends with a specified substring
 *
 * @param a the string to check
 * @param b the substring
 *
 * @return true if a ends with b
 */
bool
ends_with(const string& a, const string& b);

#endif // STRING_UTILS_H