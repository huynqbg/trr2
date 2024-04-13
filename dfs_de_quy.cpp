#include <iostream>

using namespace std;

int n, chuaxet[100], a[100][100];

void init() {
	for (int i=1; i<=n; i++) {
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
	cout << u << " ";
	chuaxet[u] = false;
	for(int v=1; v<=n; v++) {
		if (chuaxet[v] && a[u][v]) {
			dfs(v);
		}
	}
}

int main() {
    readData();
    init();
    dfs(1);
    return 0;
}

