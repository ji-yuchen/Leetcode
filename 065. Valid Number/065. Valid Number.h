/*

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
*/
#include <string>
class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        // skip the spaces
        for(; s[i] == ' '; i++) {}
    
        // check the significand
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
    
        int n_nm = 0, n_pt = 0;
        for(; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
            s[i] == '.' ? n_pt++:n_nm++;       
        if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
            return false;
    
        // check the exponent if exist
        if(s[i] == 'e') {
            i++;
            if(s[i] == '+' || s[i] == '-') i++; // skip the sign
        
            int n_nm = 0;
            for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
            if(n_nm<1)
                return false;
        }
        // skip the trailing whitespaces
        for(; s[i] == ' '; i++) {}
        
        return i==s.size();  // must reach the ending of the string
    }
};
