// englishnum.cpp - utility to convert numbers to english
// Copyright (C) 2023 Noam Bechhofer
//
// You should have received a copy of the GNU General Public License along with 
// this program.  If not, see <https://www.gnu.org/licenses/>.

#include "string_utils.hpp"
#include "englishnum.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string
append_suffix(string num)
{
    if (ends_with(num, "one")) {
        num.replace(num.length() - (string("one").length()),
                    string("one").length(),
                    "first");
    } else if (ends_with(num, "two")) {
        num.replace(num.length() - (string("two").length()),
                    string("two").length(),
                    "second");
    } else if (ends_with(num, "three")) {
        num.replace(num.length() - (string("three").length()),
                    string("three").length(),
                    "third");
    } else if (ends_with(num, "five")) {
        num.replace(num.length() - (string("five").length()),
                    string("five").length(),
                    "fifth");
    } else if (ends_with(num, "eight")) {
        num.replace(num.length() - (string("eight").length()),
                    string("eight").length(),
                    "eighth");
    } else if (ends_with(num, "nine")) {
        num.replace(
            num.length() - (string("e").length()), string("e").length(), "th");
    } else if (ends_with(num, "twelve")) {
        num.replace(num.length() - (string("ve").length()),
                    string("ve").length(),
                    "fth");
    } else if (ends_with(num, "y")) {
        num.replace(num.length() - 1, 1, "ieth");
    } else {
        num.append("th");
    }

    return num;
}

string
int_to_english(int32_t n)
{
    if (n < 0) {
        if (n == INT32_MIN) {
            return "negative two billion one hundred forty seven million four "
                   "hundred eighty three thousand six hundred forty eight";
        }
        return "negative " + int_to_english(-1 * n);
    }

    string ret;

    if (n <= 10) {
        switch (n) {
            case 0:
                ret = "zero";
                break;
            case 1:
                ret = "one";
                break;
            case 2:
                ret = "two";
                break;
            case 3:
                ret = "three";
                break;
            case 4:
                ret = "four";
                break;
            case 5:
                ret = "five";
                break;
            case 6:
                ret = "six";
                break;
            case 7:
                ret = "seven";
                break;
            case 8:
                ret = "eight";
                break;
            case 9:
                ret = "nine";
                break;
            case 10:
                ret = "ten";
                break;
            default:
                throw runtime_error("unexpected number: " + to_string(n) +
                                    " @ line " + to_string(__LINE__));
        }
    } else if (n >= 11 && n <= 19) {
        switch (n) {
            case 11:
                ret = "eleven";
                break;
            case 12:
                ret = "twelve";
                break;
            case 13:
                ret = "thirteen";
                break;
            case 14:
                ret = "fourteen";
                break;
            case 15:
                ret = "fifteen";
                break;
            case 16:
                ret = "sixteen";
                break;
            case 17:
                ret = "seventeen";
                break;
            case 18:
                ret = "eighteen";
                break;
            case 19:
                ret = "nineteen";
                break;
            default:
                throw runtime_error("unexpected number: " + to_string(n) +
                                    " @ line " + to_string(__LINE__));
        }
    } else if (n >= 20 && n <= 90 && n % 10 == 0) {
        switch (n) {
            case 20:
                ret = "twenty";
                break;
            case 30:
                ret = "thirty";
                break;
            case 40:
                ret = "forty";
                break;
            case 50:
                ret = "fifty";
                break;
            case 60:
                ret = "sixty";
                break;
            case 70:
                ret = "seventy";
                break;
            case 80:
                ret = "eighty";
                break;
            case 90:
                ret = "ninety";
                break;
            default:
                throw runtime_error("unexpected number: " + to_string(n) +
                                    " @ line " + to_string(__LINE__));
        }
    } else if (n >= 20 && n <= 99) {
        int ones = n % 10;

        ret = int_to_english(n - ones);
        if (ones != 0) {
            ret += " " + int_to_english(ones);
        }
    } else if (n >= 100 && n <= 999) {
        int tens_section = n % 100;
        int hundreds = n / 100;

        ret = int_to_english(hundreds) + " hundred";
        if (tens_section != 0) {
            ret += " " + int_to_english(tens_section);
        }
    } else if (n >= 1'000 && n <= 999'999) {
        int hundreds_section = n % 1'000;
        int thousands_section = n / 1'000;

        ret = int_to_english(thousands_section) + " thousand";
        if (hundreds_section != 0) {
            ret += " " + int_to_english(hundreds_section);
        }
    } else if (n >= 1'000'000 && n <= 999'999'999) {
        int thousands_section = n % 1'000'000;
        int millions_section = n / 1'000'000;

        ret = int_to_english(millions_section) + " million";
        if (thousands_section != 0) {
            ret += " " + int_to_english(thousands_section);
        }
    } else if (n >= 1'000'000'000 && n <= INT32_MAX) {
        int millions_section = n % 1'000'000'000;
        int billions_section = n / 1'000'000'000;

        ret = int_to_english(billions_section) + " billion";
        if (millions_section != 0) {
            ret += " " + int_to_english(millions_section);
        }
    }

    return ret;
}

/**
 * @brief convert a number to its ordinal form
 *
 * @param n the number to convert
 *
 * @return the ordinal form of n
 */
string
ordinal(int32_t num)
{
    return append_suffix(int_to_english(num));
}