#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, chuaxet[100], a[100][100];

void reInit() {
	for(int i=1; i<=n; i++){
		chuaxet[i] = true;
	}
}

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

int test() {
	for(int u=1; u<=n; u++) {
		if (chuaxet[u]) return 1;
	}
	return 0;
}

int stronglyConnected() {
	readData();
	reInit();
	for(int u=1; u<=n; u++) {
		chuaxet[u] = false;
		if (u==1) dfs(2);
		else dfs(1);
		if(test()) return 0;
		reInit();
	}
	return 1;
}

int main() {
    if(stronglyConnected()) cout << "strongly connected";
    else cout << "not strongly connected";
    return 0;
}





