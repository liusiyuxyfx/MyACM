/*************************************************************************
     File Name: HDU2196.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月08日 星期二 21时07分38秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MEM(a, b) memset(a,b, sizeof a);
using namespace std;
const int MAXN = 1e4+10;
struct Edge {
    int v, w;
    Edge* next;
}*head[MAXN],edge[MAXN << 1];
int top;
int dis[MAXN];

void Addedge(int u, int v, int w) {
    Edge *p = &edge[top++];
    p->v = v, p->w =w ,p ->next = head[u], head[u] = p;
}

void DFS(int u, int pre, int now){
    dis[u] += now;
    for (Edge* p = head[u]; p; p = p->next) {
        int v = p->v;
        if (v == pre) continue;
        DFS(v, u, now + p->w);
    }
}
int ans [MAXN] ;
int main(){
    int n;
    //freopen("in.txt","r",stdin);
    while (~ scanf("%d", &n)) {
        int u, w;
        MEM(head, 0);
        MEM(ans, 0);
        top = 0;
        for (int i = 2; i <= n; ++i){
            scanf("%d %d", &u, &w);
            Addedge (i, u, w);
            Addedge (u, i, w);
        }
        MEM(dis, 0);
        DFS(1,-1, 0);

        int maxpos = 0;
        //cout <<"maxpos="<< maxpos <<endl;
        for (int i = 1; i <= n; ++i){
            if (dis[i] > dis[maxpos])
                //printf("dis[%d]=%d\n",i,dis[i]);
                maxpos = i;
            }
        MEM(dis, 0);
        DFS(maxpos, -1, 0);
        maxpos = 0;
        //cout <<"maxpos2="<< maxpos <<endl;
        for (int i = 1; i <= n; ++i){
            if (dis[i] >  dis[maxpos])
                maxpos = i;
            ans[i] = max(dis[i], ans[i]);
        }
        MEM(dis, 0);
        DFS(maxpos, -1, 0);
        for (int i = 1; i <= n; ++i){
            printf("%d\n",max(ans[i], dis[i]));
        }
    }
}



