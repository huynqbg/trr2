#include <iostream>
#include <queue>

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

void bfs(int u) {
	queue<int> q;
	q.push(u);
	chuaxet[u] = false;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int t=1; t<=n; t++) {
			if (chuaxet[t] && a[v][t]) {
				q.push(t);
				chuaxet[t] = false;
			}
		}
	}
	
}

int main() {
    readData();
    init();
    bfs(1);
    return 0;
}

