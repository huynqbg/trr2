#include <iostream>
#include <cstring>

using namespace std;

int n, chuaxet[100], a[100][100];
int cnt = 1;

void readData() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
}

int dfs(int u) {
    chuaxet[u] = false;
    for(int v=1; v<=n; v++) {
        if(chuaxet[v] && a[u][v]) {
            ++cnt;
            dfs(v);
        }
    }
    return cnt;
}

bool lt_manh() {
    for(int i=1; i<=n; i++) {
        if(dfs(i) != n){
            return false;
        } else {
            memset(chuaxet, true, sizeof(chuaxet));
            cnt = 1;
        }
    }
    return true;
}

int main() {
    readData();
    memset(chuaxet, true, sizeof(chuaxet));
    if(lt_manh()) {
        cout << "strongly connected";
    } else {
        cout << "not strongly connected";
    }
    return 0;
}

