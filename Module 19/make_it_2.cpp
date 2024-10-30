#include <bits/stdc++.h>
using namespace std;


bool testCase(int N, int curr, vector<int>& dp) {
    if (curr == N) 
        return true;          
    if (curr > N)
        return false;           
    if (dp[curr] != -1)
        return dp[curr];
    bool addThree = testCase(N, curr + 3, dp);
    bool multiplyTwo = testCase(N, curr * 2, dp);
    dp[curr] = addThree || multiplyTwo;
    return dp[curr];
}

int main() {
    int T;
    cin >> T;
    vector<int> results(T);  
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        // Initialize memoization array with -1 (uncomputed)
        vector<int> dp(N + 1, -1);
        if (testCase(N, 1, dp)) {
            results[i] = 1;  
        } else {
            results[i] = 0; 
        }
    }
    for (int res : results) {
        cout << (res ? "YES" : "NO") << endl;
    }
    return 0;
}
