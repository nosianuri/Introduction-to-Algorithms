#include <bits/stdc++.h>

using namespace std;



const int MAX_N = 1005;
char maze[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

class Edge {
public:
    int x, y;
    Edge(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    bool operator<(const Edge& e) const {
        if (x != e.x) return x < e.x;
        return y < e.y;
    }
};

void findPath(int n, int m) {
    Edge start, end;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'R') {
                start = Edge(i, j);
            }
            else if(maze[i][j] == 'D') {
                end = Edge(i, j);
            }
        }
    }
    
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {1, -1, 0, 0}; 
    queue<Edge> q;
    map<Edge, Edge> parnt;  
    q.push(start);
    parnt[start] = start;
    
    memset(vis, false, sizeof(vis));
    vis[start.x][start.y] = true;
    bool found = false;
    
    while(!q.empty() && !found) {
        Edge curr = q.front();
        q.pop();
        if(curr.x == end.x && curr.y == end.y) {
            found = true;
        } else {
            for(int i = 0; i < 4 && !found; i++) {
                int newX = curr.x + dx[i];
                int newY = curr.y + dy[i];
                Edge next(newX, newY);
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && 
                   maze[newX][newY] != '#' && !vis[newX][newY]) {
                    q.push(next);
                    parnt[next] = curr;
                    vis[newX][newY] = true;
                }
            }
        }
    }
    
    if(found) {
        Edge curr = end;
        while(!(curr.x == start.x && curr.y == start.y)) {
            if(maze[curr.x][curr.y] == '.') {
                maze[curr.x][curr.y] = 'X';
            }
            curr = parnt[curr];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    findPath(n, m);
    return 0;
}