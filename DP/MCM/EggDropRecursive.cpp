class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n, int f) {
        if (f <= 1) return f;
        
        if (n == 1) return f;
        
        int ans = INT_MAX;        
        
        for (int k = 1; k <= f; k++) {
            
            int temp = 1 + max(eggDrop(n-1, k-1), eggDrop(n, f-k));
        
            ans = min(temp, ans);
        }
        return ans;
    }
    int eggDrop(int n, int f) {
        // code here
        return solve(n, f);
        //vector<vector<int>> dp(n+1, vector<int> (f+1, INT_MAX));
        
    }
};