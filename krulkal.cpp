#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1000;

using namespace std;

int n;

struct edge {
    int u, v;
    int w;
};

vector<edge> canh;

int parent[maxn], sz[maxn];

void make_set(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] + sz[b];
    return true;
}

void inp(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x; cin >> x;
            if(x != 0 && i<j){
                edge e;
                e.u = i;
                e.v = j;
                e.w = x;
                canh.push_back(e);
            }
        }
    }
}

bool cmp(edge a, edge b){
    if (a.w == b.w) return a.u < b.u;
    return a.w < b.w;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i=0; i<=canh.size()-1; i++){
        if(mst.size() ==  n-1) break;
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }

    }

    if(mst.size() == n -1){
        cout << "dH = " << d << endl;
        for(auto it: mst){
            cout << it.u << " " << it.v << endl;
        }
    }
}


int main(){
    inp();
    make_set();
    kruskal();
    return 0;
}
