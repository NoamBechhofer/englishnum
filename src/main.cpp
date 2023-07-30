// main.cpp - Main file for the englishnum program
// Copyright (C) 2023 Noam Bechhofer
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <https://www.gnu.org/licenses/>.

#include "englishnum.hpp"
#include "string_utils.hpp"

#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using void_funct = function<void()>;

void
display_version()
{
    cout << program_invocation_short_name << " 0.0.1" << endl;
}

void
display_help()
{
    std::cout << "englishnum\n"
              << "Usage: " << program_invocation_short_name
              << " [OPTION]... [number]...\n"
              << "Convert numbers to their english representation.\n"
              << "\n"
              << "  -h, --help     display this help and exit\n"
              << "  -v, --version  display version information and exit\n"
              << "  -o, --ordinal  display ordinal numbers (e.g., \"first\" instead of \"one\")\n"
              << "\n"
              << "Report bugs to Noam Bechhofer, noam.bechhofer+englishnum@gmail.com."
              << endl;
}

int
main(int argc, char** argv)
{
    if (argc < 2) {
        display_help();
        return 1;
    }

    // e.g. both "-h" and "--help" return display_help()
    multimap<string, void_funct> argmap;
    argmap.insert({ "-h", []() {
                       display_help();
                       exit(0);
                   } });
    argmap.insert({ "--help", []() {
                       display_help();
                       exit(0);
                   } });
    argmap.insert({ "-v", []() {
                       display_version();
                       exit(0);
                   } });
    argmap.insert({ "--version", []() {
                       display_version();
                       exit(0);
                   } });

    bool ordinal = false;
    void_funct ordinal_funct = [&ordinal]() { ordinal = true; };
    argmap.insert({ "-o", ordinal_funct });
    argmap.insert({ "--ordinal", ordinal_funct });

    vector<string> output;

    int num;
    for (int i = 1; i < argc; i++) {
        string param = string(argv[i]);
        try {
            num = stoi(param);
        } catch (invalid_argument& e) {
            if (param.starts_with("-")) {
                if (!argmap.contains(param)) {
                    cerr << program_invocation_short_name
                         << ": invalid option: " << param << endl;
                    return 1;
                } else {
                    argmap.equal_range(param).first->second();
                    continue;
                }
            } else {
                cerr << program_invocation_short_name
                     << ": invalid number: " << param << endl;
                return 1;
            }
        } catch (out_of_range& e) {
            cerr << program_invocation_short_name
                 << ": number out of range: " << param << endl;
            return 1;
        }

        string english = int_to_english(num);
        output.push_back(english);
    }

    if (ordinal) {
        transform(output.begin(), output.end(), output.begin(), [](string s) {
            return append_suffix(s);
        });
    }

    // now write each string to stdout on its own line
    copy(output.begin(), output.end(), ostream_iterator<string>(cout, "\n"));

    std::cout << flush;
    return 0;
}