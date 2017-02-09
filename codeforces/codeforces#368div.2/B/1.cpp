/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月20日 星期六 21时40分34秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int  dis[MAXN];
bool vis[MAXN];
int vv[MAXN];
int a[MAXN];
struct edge {
  int v,w;
  edge *nex;
}e[MAXN<<1],*head[MAXN];
int cnt=0;
void Addedge(int u,int v,int w) {
  edge *p=&e[cnt++];
  p->v=v;
  p->w=w;
  p->nex=head[u];
  head[u]=p;
}

void spfa(int s){
  queue<int >q;
  MEMINF(dis);
  MEM(vis,false);
  dis[s]=0;
  q.push(s);
  while(!q.empty()) {
    int u=q.front();
    q.pop();
    vis[u]=false;
    for (edge *p=head[u]; p; p=p->nex) {
      if(dis[p->v]>dis[u]+p->w) {
        dis[p->v]=dis[u]+p->w;
        if(!vis[p->v]) {
          q.push(p->v);
          vis[p->v]=true;
      }
    }
  }
}
}

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  MEM(head,0);
  int u,v,w;
  for (int i=1; i<=m; ++i) {
    scanf("%d %d %d",&u,&v,&w);
    Addedge(u,v,w);
    Addedge(v,u,w);
  }
  int temp;
  for (int i=0 ;i<k; ++i) {
    scanf("%d",&temp);
    vv[temp]=1;
    a[i]=temp;
  }
  int minn=INF;
  for (int i=1; i<=n; ++i) {
    if(vv[i]) continue;
    spfa(i);
    for (int j=0; j<k; ++j) {
     // printf("%d %d\n",i,dis[a[j]]);
      minn=min(dis[a[j]],minn);
    }
  }
  if (minn==INF) puts("-1");
  else printf("%d\n",minn);
}
