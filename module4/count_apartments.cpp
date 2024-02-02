#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<char> bui;
bool vis[1000000]; 

void dfs(int x, int y, int N, int M) {
    vis[x * M + y] = true;
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < N && newY >= 0 && newY < M &&
            bui[newX * M + newY] == '.' && !vis[newX * M + newY]) {
            dfs(newX, newY, N, M);
        }
    }
}

int countApartments(int N, int M) {
    int apartments = 0;
    memset(vis, false, sizeof(vis)); 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (bui[i * M + j] == '.' && !vis[i * M + j]) {
                dfs(i, j, N, M);
                apartments++;
            }
        }
    }
    return apartments;
}

int main() {
    int n, m;
    cin >> n >> m;
    bui.resize(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> bui[i];
    }
    int numApartments = countApartments(n, m);
    cout << numApartments << endl;
    return 0;
}