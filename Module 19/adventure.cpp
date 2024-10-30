#include <bits/stdc++.h>
using namespace std;


// Function to solve 0-1 knapsack for each test case
int solveKnapsack(int N, int W, vector<int>& weights, vector<int>& values) {
    // Create a 2D DP table
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    
    // Fill the dp table
    for(int i = 1; i <= N; i++) {
        for(int w = 0; w <= W; w++) {
            // Don't include current item
            dp[i][w] = dp[i-1][w];
            
            // Include current item if possible
            if(weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], 
                              dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[N][W];
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N, W;
        cin >> N >> W;
        
        // Read weights
        vector<int> weights(N);
        for(int i = 0; i < N; i++) {
            cin >> weights[i];
        }
        
        // Read values
        vector<int> values(N);
        for(int i = 0; i < N; i++) {
            cin >> values[i];
        }
        
        // Solve and print result for this test case
        cout << solveKnapsack(N, W, weights, values) << endl;
    }
    
    return 0;