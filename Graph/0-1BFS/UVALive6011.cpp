/*************************************************************************
     File Name: UVALive6011.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月11日 星期二 22时40分07秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e6;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int HASH(char *s) {
  return (s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
}
int s,t;
struct Edge{
  int u,v,w;
  int nex;
}edge[MAXN];
int head[MAXN];
int top;
void Addedge(int u,int v,int w) {
  edge[top].v=v,edge[top].nex=head[u],edge[top].w=w,head[u]=top++;
}

int dis[MAXN];
int booking[MAXN];
void bfs() {
  deque<int>q;
  q.push_front(s);
  dis[s]=0;
  int u,v;
  booking[s]=0;
  while(!q.empty()) {
    u=q.front();
    q.pop_front();
    for (int p=head[u]; ~p; p=edge[p].nex) {
      v=edge[p].v;
      if (booking[v]>booking[u]+1) {
        booking[v]=booking[u]+1;
        dis[v]=dis[u]+edge[p].w;
        q.push_back(v);
      }
      else {
        if (booking[v]==booking[u]+1&&dis[v]>dis[u]+edge[p].w) {
          dis[v]=dis[u]+edge[p].w;
          q.push_front(v);
        }
      }
    }
  }
  printf("%d\n",dis[t]);
}
string st,ed;

int main() {
  int T;
  cin>>T;
  while (T--) {
    MEM(dis,0);
    MEMINF(booking);
    MEM(head,-1);
    top=0;
    int n;
    scanf("%d",&n);
    char a[4];
    char b[4];
    for (int i=0; i<n; ++i) {
      scanf("%s %s",a,b);
      int ha=HASH(a);
      int hb=HASH(b);
      Addedge(ha,hb,1);
      Addedge(hb,ha,1);
    }
    int ha,hb;
    cin>>n;
    for (int i=0; i<=n; ++i) {
      if (i==0) {
        scanf("%s",a);
        ha=HASH(a);
        st=a;
        s=ha;
        continue;
      }
      hb=ha;
      scanf("%s",a);
      ha=HASH(a);
      Addedge(hb,ha,0);
    }
    ed=a;
    t=ha;
    bfs();
  }
}



