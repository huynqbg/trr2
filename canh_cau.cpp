#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#define pb push_back

using namespace std;

int n, chuaxet[100], a[100][100];

vector<pair<int, int>> dsc;
//set<set<int>> st;

void readData() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j] == 1 && a[j][i] == 1) {
				dsc.pb({i, j});
				a[j][i] = 0;
			} else if (a[i][j] == 1 && a[j][i] == 0) {
				dsc.pb({i, j});
			}
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

void dfs2(int u, int s, int t) {
    chuaxet[u] = false;
    for(int v=1; v<=n; v++) {
        if((u==s && v == t) || (u==t && v == s)) continue;
        if(chuaxet[v] && a[u][v]) dfs2(v, s, t);
    }
}

void canh_cau() {
    int tplt=0;
    for(int i=1; i<=n; i++) {
        if(chuaxet[i]) {
            ++tplt;
            dfs(i);
        }
    }
    
    for(auto it: dsc) {
        int x=it.first;
        int y = it.second;
        memset(chuaxet, true, sizeof(chuaxet));
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(chuaxet[j]) {
                ++cnt;
                dfs2(j, x, y);
            }
        }
        
        if (cnt > tplt) {
            cout << x << " " << y << endl;
        }
    }
}

int main() {
    readData();
    memset(chuaxet, true, sizeof(chuaxet));
    canh_cau();
    return 0;
}

