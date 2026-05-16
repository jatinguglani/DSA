// User function Template for C++
#include <bitset>/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string &s, bool istrue, int i, int j) {
        
        if (i > j)  return 0;
        
        if (i==j) {
            if (istrue) {
                return s[i] == 'T';
            } else {
                return s[i] == 'F';
            }
        }
        
        int ans = 0;
        
        for (int k=i+1; k<j; k = k+2) {
            
            int lt = solve(s, true, i, k-1); 
            int lf = solve(s, false, i, k-1);
            int rt = solve(s, true, k+1, j);
            int rf = solve(s, false, k+1, j);
            
            if (s[k] == '|') {
                
                if (istrue) {
                    ans += (lt*rt) + (lt*rf) + (lf*rt);
                } else {
                    ans += lf*rf;
                }   
                
            } else if (s[k] == '&') {
                
                if (istrue) {
                    ans += rt*lt;
                } else {
                    ans += (lf*rf) + (lt*rf) + (lf*rt);
                }
                
            } else {
                
                if (istrue) {
                    ans += (lt*rf) + (lf*rt);
                } else {
                    ans += (lt*rt) + (rf*lf);
                }
            }
        }
        
        return ans;
    }
    
    int countWays(string &s) {
        // code here
        int n = s.size();
        
        return solve (s, true, 0, n-1);
    }
};