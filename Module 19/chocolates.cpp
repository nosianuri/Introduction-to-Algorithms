#include <bits/stdc++.h>

using namespace std;


bool canDivideEqually(vector<int>& chocolates, int totalSum) {
    if (totalSum % 2 != 0) 
        return false; 
    int targetSum = totalSum / 2;
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true; 
    for (int choco : chocolates) {
        for (int j = targetSum; j >= choco; j--) {
            dp[j] = dp[j] || dp[j - choco];
        }
    }
    return dp[targetSum];
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        int N;
        cin >> N; 
        vector<int> chocolates(N);
        int totalSum = 0;
        for (int i = 0; i < N; i++) {
            cin >> chocolates[i];
            totalSum += chocolates[i];
        }
        if (canDivideEqually(chocolates, totalSum)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
