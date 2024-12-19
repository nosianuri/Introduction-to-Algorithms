#include <bits/stdc++.h>

using namespace std;



int main()
{
     int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<pair<int, int>> h(n); 
        for (int i = 0; i < n; i++) {
            cin >> h[i].first;
            h[i].second = i; 
        }
        sort(h.rbegin(), h.rend());
        int firstIndex = h[0].second;
        int secondIndex = h[1].second;
        if (firstIndex < secondIndex) {
            cout << firstIndex << " " << secondIndex << endl;
        } else {
            cout << secondIndex << " " << firstIndex << endl;
        }
    }
    return 0;
}