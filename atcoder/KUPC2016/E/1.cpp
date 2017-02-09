/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 17时01分20秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int MAXM=2e5+20;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct MaxFlow{  
    int head[MAXN];  
    struct Edge{  
        int u,v,nex,cap,flow;  
    }edge[MAXM];  
    int tot;
    int s,t;
    int dis[MAXN];  
    int cur[MAXN];  
    void Dinic_init(int s,int t){  
        this->s=s;
        this->t=t;  
        MEM(head,-1);  
        tot=0;  
    }  
    void Addedge(int u,int v,int w) {  
        edge[tot].v=v,edge[tot].cap=w,edge[tot].flow=0,edge[tot].nex=head[u],head[u]=tot++;  
        edge[tot].v=u,edge[tot].cap=0,edge[tot].flow=0,edge[tot].nex=head[v],head[v]=tot++;  
    }  
    bool bfs() {  
        MEM(dis,-1);  
        queue<int>q;  
        dis[s]=0;  
        q.push(s);  
        while (!q.empty()) {  
            int u=q.front();  
            q.pop();  
            for (int i=head[u]; ~i; i=edge[i].nex) {  
                int v=edge[i].v;  
                if (edge[i].cap>edge[i].flow&&dis[v]==-1) {  
                    q.push(v);  
                    dis[v]=dis[u]+1;  
                }  
            }  
        }  
        return dis[t]!=-1;  
    }  
    int dfs(int u,int delta) {  
        if (u==t||delta==0)  
            return delta;  
            int ret=0;  
            int aug;  
            for(int &i=cur[u]; ~i; i=edge[i].nex) {  
                int v=edge[i].v;  
                if (dis[v]==dis[u]+1&&(aug=dfs(v,min(edge[i].cap-edge[i].flow,delta)))>0) {  
                    edge[i].flow+=aug;  
                    edge[i^1].flow-=aug;  
                    delta-=aug;  
                    ret+=aug;  
                    if (delta==0) break;  
                }  
            }  
            //dis[u]=-1;
            return ret;  
    }  
    void dinic() {  
        int ret=0;  
        while(bfs()) {  
            memcpy(cur,head,sizeof head);  
            ret+=dfs(s,INF);  
        }  
        cout<<ret<<endl;  
     }  
}nima; 
int n,m;
int zb(int i,int j) {
  return (i*m+j)*2;
}
char mp[110][110];
int main() {
  int T,S;
  cin>>n>>m;
  S=n*m*2+1;
  T=S-1;
  nima.Dinic_init(T,S);
  for (int i=0; i<n; ++i) {
    scanf("%s",mp[i]);
  }

  for (int i=0; i<n; ++i) {
    if (mp[i][0]=='X'||mp[i][m-1]=='X') {
      puts("-1");
      return 0;
    }
    nima.Addedge(T,zb(i,0),INF);
    nima.Addedge(T,zb(i,m-1),INF);
  }
  for (int i=0; i<m; ++i) {
    if (mp[0][i]=='X'||mp[m-1][n]=='X') {
      puts("-1");
      return 0;
    }
    nima.Addedge(T,zb(0,i),INF);
    nima.Addedge(T,zb(n-1,i),INF);
  }
  for (int i=0; i<n; ++i) 
    for (int j=0; j<m; ++j) {
      if (mp[i][j]=='X') nima.Addedge(zb(i,j),S,INF);
      else {
        nima.Addedge(zb(i,j),zb(i,j)+1,1);
      }
      for (int k=0; k<4; ++k) {
        int x=i+dx[k];
        int y=j+dy[k];
        if (x<0||x>=n||y<0||y>=m)continue;
        nima.Addedge(zb(i,j)+1,zb(x,y),INF);
      }
    }
  nima.dinic();
}

        

