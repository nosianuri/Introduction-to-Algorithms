#include <bits/stdc++.h>

using namespace std;



const long long v = 1e18;
int main() {
    int N, E;
    cin >> N >> E;
    vector<pair<int, long long>> graph[N + 1];
    for (int i = 0; i < E; ++i) {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        graph[A].push_back({B, W});
    }

    int S;
    cin >> S; 
    int T;
    cin >> T;
    while (T--) {
        int D;
        long long DW;
        cin >> D >> DW; 
        vector<long long> dis(N + 1, v);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, S});
        dis[S] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (d > dis[u]) continue;
            for (auto& edge : graph[u]) {
                int v = edge.first;
                long long w = edge.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        if (dis[D] <= DW) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}