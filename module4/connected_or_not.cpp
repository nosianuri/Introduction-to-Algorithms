#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v;
    for (int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int A, B;
        cin >> A >> B;
        bool pos = (A == B);
        for (const auto& v : v) {
            if (v.first == A && v.second == B) {
                pos = true;
                break;
            }
        }
        cout << (pos ? "YES" : "NO") << endl;
    }
    return 0;
}