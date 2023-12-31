// englishnum.hpp - header file for englishnum.cpp
// Copyright (C) 2023 Noam Bechhofer
//
// you should have received a copy of the GNU General Public License along with
// this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef ENGLISHNUM_HPP
#define ENGLISHNUM_HPP

#include <string>

using namespace std;

/**
 * @brief the appropriate ordinal to an english number
 *
 * @details this function may remove the last few characters of the string
 * before  appending. In other words, the original string may not be a substring
 * of the returned string.
 *
 * @param num the number to append the suffix to
 *
 * @return the number with the appropriate suffix appended
 */
string
append_suffix(string num);

/**
 * @brief convert a number to its english representation
 *
 * @details this function will convert an integer to english. It will not append
 * an ordinal suffix. To do that, use @link append_suffix @endlink.
 *
 * @param num the number to convert
 *
 * @return the english representation of the number
 */
string
int_to_english(int32_t num);

#endif // ENGLISHNUM_HPP