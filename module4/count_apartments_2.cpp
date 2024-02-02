#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m;
vector<char> bui;
vector<bool> vis;

int dfs(int x, int y) {
    vis[x * m + y] = true;
    int rooms = 1; 
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
            bui[newX * m + newY] == '.' && !vis[newX * m + newY]) {
            rooms += dfs(newX, newY);
        }
    }
    return rooms;
}

int main() {
    cin >> n >> m;
    bui.resize(n * m);
    vis.assign(n * m, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> bui[i * m + j];
        }
    }
    vector<int> countApartment;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (bui[i * m + j] == '.' && !vis[i * m + j]) {
                countApartment.push_back(dfs(i, j));
            }
        }
    }
    sort(countApartment.begin(), countApartment.end());
    for (int count : countApartment) {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}