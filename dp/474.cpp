/*
474. Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // substr [i, j] largest valid subset at most i 0's and j 1's.
        // dp[i][j] = dp[i - zeors[k]][j - ones[k]] + 1

        for (int k = 0; k < strs.size(); ++k) {
            int ones = 0, zeros = 0;
            for (auto c : strs[k]) {
                if (c == '0') zeros++;
                else ones++;
            }
            for(int i = m; i >= zeros; --i) {
                for(int j = n; j >= ones; --j) {
                    dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
         
        return dp[m][n];
    }
};
