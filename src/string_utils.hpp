// string_utils.hpp - header for string_utils.cpp
// Copyright (C) 2023 Noam Bechhofer
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <https://www.gnu.org/licenses/>.
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

/**
 * @brief check whether a string starts with a specified substring
 *
 * @param a the string to check
 * @param b the substring
 *
 * @return true if a starts with b
 */
bool
starts_with(const string& a, const string& b);

#endif // STRING_UTILS_H