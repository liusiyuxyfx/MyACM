
/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月18日 星期二 20时42分07秒
************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e6+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1000000007;
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
struct Edge {
  int v;
  LL w;
  int nex;
}edge[MAXN<<2];
int head[MAXN];
int top;

void Addedge(int u,int v,LL w) {
  edge[top].v=v;
  edge[top].nex=head[u];
  edge[top].w=w;
  head[u]=top++;
}

int n,m;
bool vis[MAXN];
LL dis[2][MAXN];
vector<int>ans;

void Dij (int id,int s) {
  MEM(vis,false);
  queue<int>q;
  dis[id][s]=0;
  q.push(s);
  vis[s]=true;
  while(!q.empty()) {
    int u=q.front();
    q.pop();
    vis[u]=0;
    for (int i=head[u]; ~i; i=edge[i].nex) {
      int v=edge[i].v;
      if (dis[id][v]>dis[id][u]+edge[i].w) {
        dis[id][v]=dis[id][u]+edge[i].w;
        if (!vis[v]) {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
}

int main() {
  int T;
  int n,m,s;
  LL t;
  read(T);
  for (int cas=1; cas<=T; ++cas) {
    MEM(head,-1);
    top=0;
   printf("Case #%d: ",cas);
   read(n),read(m);
   for (int i=0; i<=n+m+1; ++i) {
     dis[0][i]=dis[1][i]=INF;
   }

   top=0;
   for (int i=1; i<=m; ++i) {
     read(t),read(s);
     for (int j=1; j<=s; ++j) {
       int v;
       read(v);
       Addedge(v,i+n,0);
       Addedge(i+n,v,t);
     }
   }
   Dij(0,1);
   Dij(1,n);
   LL tt=INF;
   ans.clear();
   for (int i=1; i<=n; ++i) tt=min(tt,max(dis[0][i],dis[1][i]));

   for (int i=1; i<=n; ++i) 
     if (tt==max(dis[0][i],dis[1][i])) ans.push_back(i);
   
   if (tt==INF) printf("Evil John\n");
   else {
     printf("%I64d\n",tt);
     for (int i=0; i<ans.size()-1; ++i) {
       printf("%d ",ans[i]);
     }
     printf("%d\n",ans[ans.size()-1]);
   }
  }
}



