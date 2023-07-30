// string_utils.cpp - utility functions for strings
// Copyright (C) 2023 Noam Bechhofer
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <https://www.gnu.org/licenses/>.include <string>
#include "string_utils.hpp"
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