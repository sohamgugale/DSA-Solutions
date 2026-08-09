class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i+1] + piles[i];
        
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        
        function<int(int,int)> dp = [&](int i, int M) -> int {
            if (i >= n) return 0;
            if (i + 2*M >= n) return suffix[i];   // can take all
            if (memo[i][M] != -1) return memo[i][M];
            int best = 0;
            for (int X = 1; X <= 2*M; X++)
                best = max(best, suffix[i] - dp(i + X, max(M, X)));
            return memo[i][M] = best;
        };
        
        return dp(0, 1);
    }
};