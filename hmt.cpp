#include <iostream>

using namespace std;

int n, u, d, a[100][100], chuaxet[100], x[100];

void nhap() {
    cin >> n >> u;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void init() {
    for(int i=1; i<=n; i++) chuaxet[i] = true;
}

void hmt(int k) {
    for(int i=1; i<=n; i++) {
        if(a[x[k-1]][i]) {
            if(k==n+1 && i==u) { // do đi qua n đỉnh và quay về đỉnh ban đầu nên k + 1, i == u nghĩa là đã quay về đỉnh ban đầu
                for(int j=1; j<=n; j++) {
                    cout << x[j] << " ";
                }
                cout << x[1] << endl;
            } else if(chuaxet[i]) {
                x[k] = i;
                chuaxet[i] = false;
                hmt(k+1);
                chuaxet[i] = true;
            }
        }
    }
}


int main() {
    nhap();
    init();
    x[1] = u;
    chuaxet[u] = false;
    hmt(2);
    return 0;
}
