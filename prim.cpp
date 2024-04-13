#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
struct Edge{
    int     s, e, c;
};
class   Graph{
    private:
        int     n, s, A[MAX][MAX], ne, neT, T[MAX][MAX], chuaxet[MAX];
        Edge    eArr[MAX], eArr_T[MAX];
    public:
        void    readdata();
        void    init();
        void    reInit();
        void    T_DFS(int s);
        void    Kruskal();
        void    Prim(int u);
        int     getS(){ return s;   }
};
void    Graph::readdata(){
    cin>>n>>s;
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
    if(e1.c==e2.c)
        if(e1.s==e2.s)
            return  e1.e<e2.e;
        else
            return e1.s<e2.s;
    return  e1.c<=e2.c;
}
void    Graph::Kruskal(){
    int     dH=0;
    sort(eArr+1, eArr+ne+1, eCompare);
    neT=0;
    for(int e=1; e<=ne; e++){
        reInit();   T_DFS(eArr[e].s);
        if(chuaxet[eArr[e].e]==1){
            dH+=eArr[e].c;
            T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;
            neT++;
            eArr_T[neT].s=eArr[e].s;    eArr_T[neT].e=eArr[e].e;
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(int e=1; e<=neT; e++)
        cout<<eArr_T[e].s<<" "<<eArr_T[e].e<<endl;
}
void    Graph::Prim(int u){
    int     dH=0;
    sort(eArr+1, eArr+ne+1, eCompare);
    neT=0;
    for(int eT=1; eT<=n-1; eT++){
        reInit();   T_DFS(u);
        for(int e=1; e<=ne; e++){
            if(chuaxet[eArr[e].s]+chuaxet[eArr[e].e]==1){
                dH+=eArr[e].c;
                T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;
                neT++;
                eArr_T[neT].s=eArr[e].s;    eArr_T[neT].e=eArr[e].e;
                break;
            }
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(int e=1; e<=neT; e++)
        cout<<eArr_T[e].s<<" "<<eArr_T[e].e<<endl;
}
int main(){
    Graph   g;
    g.readdata();   g.init();   g.Prim(g.getS());
}
