class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n, int f, vector<vector<int>> &dp) {
        
        if (f <= 1) return dp[n][f] = f;
        
        if (n == 1) return dp[n][f] = f;
        
        if (dp[n][f] != INT_MAX)    return dp[n][f];
        
        for (int k = 1; k <= f; k++) {
            
            int temp, did_break, no_break;
            
            if (dp[n-1][k-1] != INT_MAX)
                did_break = dp[n-1][k-1];
            else 
                did_break = dp[n-1][k-1] = solve(n-1, k-1, dp);
            
            if (dp[n][f-k] != INT_MAX)
                no_break = dp[n][f-k];
            else 
                no_break = dp[n][f-k] = solve(n, f-k, dp);
                
            temp = 1 + max(did_break, no_break);
        
            dp[n][f] = min(temp, dp[n][f]);
        }
        return dp[n][f];
    }
    
    int eggDrop(int n, int f) {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (f+1, INT_MAX));
        
        return solve(n, f, dp);
    }
};