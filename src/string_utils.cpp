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
inline bool
ends_with(const string& a, const string& b)
{
#if __cplusplus >= 202002L
    return a.ends_with(b);
#else
    if (a.length() >= b.length()) {
        return 0 == a.compare(a.length() - b.length(), b.length(), b);
    } else {
        return false;
    }
#endif
}