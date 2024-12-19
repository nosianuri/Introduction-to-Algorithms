#include <bits/stdc++.h>

using namespace std;



bool canAchieveTarget(int target, vector<int>& marks) {
    if (target < 0) return false; 
    vector<bool> dp(target + 1, false);
    dp[0] = true; 
    for (int mark : marks) {
        for (int j = target; j >= mark; j--) {
            dp[j] = dp[j] || dp[j - mark];
        }
    }
    return dp[target];
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        int N, M;
        cin >> N >> M; 
        vector<int> marks(N);
        for (int i = 0; i < N; i++) {
            cin >> marks[i];
        }
        int target = 1000 - M;
        if (canAchieveTarget(target, marks)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}