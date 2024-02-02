#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<vector<int>, vector<int>>> adjList(n); 
    for (int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> to;
        adjList[from].first.push_back(to);
        adjList[to].first.push_back(from); 
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        sort(adjList[x].first.rbegin(), adjList[x].first.rend());
        if (adjList[x].first.empty()) {
            cout << -1 << endl;
        } else {
            for (int node : adjList[x].first) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
    return 0;
}