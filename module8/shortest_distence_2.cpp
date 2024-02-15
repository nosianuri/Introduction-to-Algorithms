#include<bits/stdc++.h>
using namespace std;

const long long V = 1e18;

int main() {
    int N, E;
    cin >> N >> E;
    long long dis[N + 1][N + 1];
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dis[i][j] = V;
        }
    }
    for (int i = 1; i <= N; ++i) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < E; ++i) {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        dis[A][B] = min(dis[A][B], W); 
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dis[i][k] != V && dis[k][j] != V) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        if (dis[X][Y] != V) {
            cout << dis[X][Y] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}