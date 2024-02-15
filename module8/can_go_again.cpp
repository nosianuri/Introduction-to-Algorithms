#include<bits/stdc++.h>
using namespace std;

const long long V = 1e18;

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
    vector<long long> dis(N + 1, V);
    dis[S] = 0;
    for (int i = 1; i <= N - 1; ++i) {
        for (int u = 1; u <= N; ++u) {
            for (auto& edge : graph[u]) {
                int v = edge.first;
                long long w = edge.second;
                if (dis[u] != V && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
    for (int u = 1; u <= N; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (dis[u] != V && dis[u] + w < dis[v]) {
                cout << "Negative Cycle Detected\n";
                return 0;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int D;
        cin >> D;
        if (dis[D] != V) {
            cout << dis[D] << endl;
        } else {
            cout << "Not Possible\n";
        }
    }
    return 0;
}