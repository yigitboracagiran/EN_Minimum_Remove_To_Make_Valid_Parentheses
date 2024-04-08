#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string minRemoveToMakeValid( std::string s ) {
        std::vector<int> leftParenthesesIndexes, rightParenthesesIndexes;
        bool control = false;
        for ( int i = 0 ; i < s.size(); i++ ) {
            if ( control == false && s[i] == ')' ) {
                s.erase( i--, 1 );
            }
            else if ( s[i] == '(' ) {
                control = true;
            }
        }
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == '(' ) {
                leftParenthesesIndexes.push_back( i );
            }
            else if ( s[i] == ')' ) {
                if ( leftParenthesesIndexes.empty() ) {
                    s.erase( i--, 1 );
                }
                else {
                    leftParenthesesIndexes.erase(leftParenthesesIndexes.begin());
                }
            }
        }
        for ( auto i = leftParenthesesIndexes.rbegin() ; leftParenthesesIndexes.size() != 0 ; i++ ) {
            s.erase( leftParenthesesIndexes[ leftParenthesesIndexes.size() - 1 ], 1 );
            leftParenthesesIndexes.erase( leftParenthesesIndexes.end() - 1 );
        }
        return ( s );
    }
};

int main ( void ) {
    Solution sol;
    std::string s = "lee(t(c)o)de)";
    std::cout << s << "\n";
    std::string answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    s = "a)b(c)d";
    std::cout << s << "\n";
    answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    s = "))((";
    std::cout << s << "\n";
    answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    s = "())()(((";
    std::cout << s << "\n";
    answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    s = "v((((((())";
    std::cout << s << "\n";
    answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    s = "(t(e)y))d(()(e(";
    std::cout << s << "\n";
    answer = sol.minRemoveToMakeValid( s );
    std::cout << "Cevap: " << answer << "\n......\n";
    return 0;
}