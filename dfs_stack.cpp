#include <iostream>
#include <stack>

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

void dfsStack(int u) {
	stack<int> stk;
	cout << u << " ";
	stk.push(u);
	chuaxet[u] = false;
	while (!stk.empty()) {
		int s = stk.top();
		stk.pop();
		for(int t=1; t<=n; t++) {
			if (chuaxet[t] && a[s][t]) {
				cout << t << " ";
				chuaxet[t] = false;
				stk.push(s); 
				stk.push(t);
				break;
			}
		}
	}
	
	
}

int main() {
    readData();
    init();
    dfsStack(1);
    return 0;
}


