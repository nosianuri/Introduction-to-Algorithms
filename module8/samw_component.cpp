#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<char> grid;
bool vis[1000000]; 
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && grid[x * M + y] != '-';
}

void dfs(int x, int y) {
    vis[x * M + y] = true;

    for (const auto& dir : d) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        
        if (isValid(newX, newY) && !vis[newX * M + newY]) {
            dfs(newX, newY);
        }
    }
}

int main() {
    cin >> N >> M;
    grid.resize(N * M);
    for (int i = 0; i < N * M; ++i) {
        cin >> grid[i];
    }
    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;
    memset(vis, false, sizeof(vis));
    dfs(Si, Sj);
    if (vis[Di * M + Dj]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}