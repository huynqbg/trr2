#include <iostream>
#include <cstring>

using namespace std;

int n, chuaxet[100], a[100][100];

void readData() {
    cin >> n;
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
            dfs(v);
        }
    }
}

void dinh_tru() {
    int so_tplt = 0;
    for(int i=1; i<=n; i++) {
        if(chuaxet[i]) {
            ++so_tplt;
            dfs(i);
        }
    }

    for(int i=1; i<=n; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        chuaxet[i] = false; // loai bo dinh i
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(chuaxet[j]) {
                ++cnt;
                dfs(j);
            }
        }

        if(cnt > so_tplt) {
            cout << i << " ";
        }
    }
}

int main() {
    readData();
    memset(chuaxet, true, sizeof(chuaxet));
    dinh_tru();
    return 0;
}




