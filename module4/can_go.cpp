#include<bits/stdc++.h>
using namespace std;


const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> bui(n * m);
    vector<bool> vis(n * m, false);
    pair<int, int> A, B;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char cell;
            cin >> cell;
            bui[i * m + j] = cell;
            if (cell == 'A') A = {i, j};
            if (cell == 'B') B = {i, j};
        }
    }
    queue<pair<int, int>> q;
    q.push(A);
    vis[A.first * m + A.second] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur == B) {
            cout << "YES\n";
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = cur.first + dx[i];
            int newY = cur.second + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                bui[newX * m + newY] != '#' && !vis[newX * m + newY]) {
                q.push({newX, newY});
                vis[newX * m + newY] = true;
            }
        }
    }
    cout << "NO\n";
    return 0;
}