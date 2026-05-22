//01234
//12345
//HELLO
class Solution {
public:
    bool solve (string s1,string s2) {

        int n = s1.length();

        if (s1.compare(s2) == 0)    return true;

        if (n <= 1) return false;

        bool flag = false;

        for (int i = 1; i < n; i++) {

            bool condition1 = solve(s1.substr(0, i), s2.substr(0, i)) && 
                                solve(s1.substr(i, n-i), s2.substr(i, n-i));

            bool condition2 = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                                solve(s1.substr(i, n-i), s2.substr(0, n-i));

            if (condition1 || condition2){
                flag = true;
                break;        
            }                    
        }
        return flag;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        return solve(s1 , s2);
    }
};