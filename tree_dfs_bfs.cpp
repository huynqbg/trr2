#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int n, k, chuaxet[MAX], a[MAX][MAX], soCanh, canhTM[MAX][2];


void nhap() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }

}

void init() {
    soCanh = 0;
    for(int i=0; i<=n; i++) {
        chuaxet[i] = true;
        for(int j=0; j<=1; j++) canhTM[i][j] = 0;
    }
}

void treeDFS(int i) {
    chuaxet[i] = false;
    if(soCanh == n-1) return;
    for(int j=1; j<=n; j++) {
        if(chuaxet[j] && a[i][j]){
            ++soCanh;
            canhTM[soCanh][0] = i;
            canhTM[soCanh][1] = j;
            treeDFS(j);
        }
    }
}

void in() {
    for(int i=1; i<=soCanh; i++) {
       if(canhTM[i][0] > canhTM[i][1]) {
           swap(canhTM[i][0], canhTM[i][1]);
       }
       cout << canhTM[i][0] << " " << canhTM[i][1] << endl;
    }
}

void treeBFS(int u) {
    queue<int> q;
    q.push(u);
    chuaxet[u] = false;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int t=1; t<=n; t++){
            if(a[v][t] && chuaxet[t]){
                q.push(t);
                ++soCanh;
                canhTM[soCanh][0] = v;
                canhTM[soCanh][1] = t;
                chuaxet[t] = false;
            }
        }
    }
}

int main() {
    nhap();
    init();
    treeDFS(k);
    if(soCanh >= n-1) {
        cout << "DFS tree\n";
        in();
    }
    init();
    treeBFS(k);
    if(soCanh >= n-1){
        cout << "BFS tree\n";
        in();
    }
    return 0;
}
