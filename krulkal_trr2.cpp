#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
struct Edge{
    int     s, e, c;    //s: edge start; e: edge end;   c: edge weight
};
class   Graph{
    private:
        int     n, A[MAX][MAX], ne, neT, T[MAX][MAX], chuaxet[MAX];
        Edge    eArr[MAX];
    public:
        void    readdata();
        void    init();
        void    reInit();
        void    T_DFS(int s);
        void    Kruskal();
};
void    Graph::readdata(){
    cin>>n;
    ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
            if((A[i][j]!=0)&&(i<j)){
                ne++;
                eArr[ne].s=i;   eArr[ne].e=j;   eArr[ne].c=A[i][j];
            }
        }
}
void    Graph::init(){
    for(int i=1; i<=n; i++){
        chuaxet[i]=1;
        for(int j=1; j<=n; j++) T[i][j]=0;
    }
}
void    Graph::reInit(){
    for(int i=1; i<=n; i++)
        chuaxet[i]=1;
}
void    Graph::T_DFS(int s){
    chuaxet[s]=0;
    for(int v=1; v<=n; v++)
        if((T[s][v]!=0)&&(chuaxet[v]==1))   T_DFS(v);
}
bool    eCompare(Edge   e1, Edge    e2){
    return  e1.c<=e2.c;
}
void    Graph::Kruskal(){
    int     dH=0;
    sort(eArr+1, eArr+ne+1, eCompare);
    //bubble sort
    //for(int e1=1; e1<ne;    e1++)
    //    for(int e2=ne; e2>e1; e2--)
    //    }
    for(int e=1; e<=ne; e++){
        reInit();   T_DFS(eArr[e].s);
        if(chuaxet[eArr[e].e]==1){
            dH+=eArr[e].c;
            T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if((T[i][j]!=0)&&(i<j)) cout<<i<<" "<<j<<endl;
}
int main(){
    Graph   g;
    g.readdata();   g.init();   g.Kruskal();
}
