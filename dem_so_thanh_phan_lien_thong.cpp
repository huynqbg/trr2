#include <iostream>

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

void init() {
	for (int i=1; i<=n; i++) {
		chuaxet[i] = true;
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

void connectedComponent() {
	int ans = 0;
	init();
	for(int i=1; i<=n; i++) {
		if(chuaxet[i]) {
			++ans;
			dfs(i);
		}
	}
	cout << ans;
}

int main() {
    readData();
    connectedComponent();
    return 0;
}

