// User function Template for C++
class Solution {
  public:
    int solve(string &s, bool istrue, int i, int j, unordered_map<string, int> &mp)
    {
        if (i > j)  return 0;
        
        string in = to_string(i) + " " + to_string(j) + " " + to_string(istrue);
        
        if (mp.find(in) != mp.end())    return mp[in];
        
        if (i==j) {
            if (istrue) {
                return s[i] == 'T';
            } else {
                return s[i] == 'F';
            }
        }
        
        int ans = 0;
        
        for (int k=i+1; k<j; k = k+2) {
            
            int lt = solve(s, true, i, k-1, mp); 
            int lf = solve(s, false, i, k-1, mp);
            int rt = solve(s, true, k+1, j, mp);
            int rf = solve(s, false, k+1, j, mp);
            
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
        
        return mp[in] = ans;
    }
    
    int countWays(string &s) {
        // code here
        int n = s.size();
        unordered_map<string, int> mp;
        
        return solve (s, true, 0, n-1, mp);
    }
};