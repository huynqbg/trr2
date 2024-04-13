#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, s, t, chuaxet[100], truoc[100], a[100][100];

void readData() {
    cin >> n >> s >> t;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void dfs(int u) {
    chuaxet[u] = false;
    for(int v=1; v<=n; v++) {
        if(chuaxet[v] && a[u][v]) {
            truoc[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    chuaxet[u] = false;
    q.push(u);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int t=1; t<=n; t++) {
            if(chuaxet[t] && a[v][t]) {
                q.push(t);
                truoc[t] = v;
                chuaxet[t] = false;
            }
        }
    }
}

void pathDFS(int s, int t) {
    memset(chuaxet, true, sizeof(chuaxet));
    memset(truoc, 0, sizeof(truoc));
    dfs(s);
    if(truoc[t]==0) {
        cout << "no path";
    } else {
        cout << "DFS path: " << t << " ";
        int u = truoc[t];
        while(u!=s) {
            cout << u << " ";
            u = truoc[u];
        }
        cout << s;
    }
}

void pathBFS(int s, int t) {
    memset(chuaxet, true, sizeof(chuaxet));
    memset(truoc, 0, sizeof(truoc));
    bfs(s);
    if (truoc[t] != 0) {
        cout << "BFS path: " << t << " ";
        int u = truoc[t];
        while(u!=s) {
            cout << u << " ";
            u = truoc[u];
        }
        cout << s;
    }
}

int main() {
    readData();
    pathDFS(s, t);
    cout << endl;
    pathBFS(s, t);
    return 0;
}
