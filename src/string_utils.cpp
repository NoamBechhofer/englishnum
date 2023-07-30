#include <string>

using namespace std;

bool
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

bool
starts_with(const string& a, const string& b)
{
#if __cplusplus >= 202002L
    return a.starts_with(b);
#else
    if (a.length() >= b.length()) {
        return 0 == a.compare(0, b.length(), b);
    } else {
        return false;
    }
#endif
}