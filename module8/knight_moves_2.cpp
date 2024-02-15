#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int Ki, Kj, Qi, Qj;
        cin >> Ki >> Kj >> Qi >> Qj;
        vector<int> dis(N * M, -1);
        queue<pair<int, int>> q;
        q.push({Ki * M + Kj, 0});
        dis[Ki * M + Kj] = 0;
        while (!q.empty()) {
            int cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            int x = cur / M, y = cur % M;
            if (x == Qi && y == Qj) {
                cout << dis[cur] << endl;
                break;
            }
            for (auto &dir : d) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && dis[nx * M + ny] == -1) {
                    dis[nx * M + ny] = steps + 1;
                    q.push({nx * M + ny, steps + 1});
                }
            }
        }
        if (dis[Qi * M + Qj] == -1) {
            cout << -1 << endl;
        }
    }
    return 0;
}