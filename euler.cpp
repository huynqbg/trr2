#include <iostream>
#include <stack>

using namespace std;

int n, u, a[100][100];

void nhap() {
    cin >> n >> u;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

void euler() {
    stack<int> st;
    int CE[100];
    st.push(u);
    int t= 1;
    while(!st.empty()) {
        int v = st.top();
        int x = 1;
        while(x<=n && a[v][x] == 0) ++x;
        if(x<=n) {
            st.push(x);
            a[v][x] = 0;
            a[x][v] = 0;
        } else {
            CE[t] = v;
            t++;
            st.pop();
        }
    }

    for (int i=t-1; i>0; i--) {
        cout << CE[i] << " ";
    }
}

int main() {
    nhap();
    euler();
    return 0;
}
