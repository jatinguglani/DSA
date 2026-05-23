//01234
//12345
//HELLO
class Solution {
public:
    unordered_map<string, bool> mp;

    bool solve (string s1,string s2) {

        int n = s1.length();

        string str = s1 + " " + s2;

        if (mp.find(str) != mp.end())   return mp[str];

        if (s1.compare(s2) == 0)     return mp[str] = true;

        if (n <= 1) return mp[str] = false;

        mp[str] = false;

        for (int i = 1; i < n; i++) {

            bool condition1 = solve(s1.substr(0, i), s2.substr(0, i)) && 
                                solve(s1.substr(i, n-i), s2.substr(i, n-i));

            bool condition2 = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                                solve(s1.substr(i, n-i), s2.substr(0, n-i));

            if (condition1 || condition2){
                //return true;
                mp[str] = true;
                break;        
            }                    
        }
        return mp[str];
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        return solve(s1 , s2);
    }
};