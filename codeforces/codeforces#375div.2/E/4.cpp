
/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月04日 星期二 15时41分40秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int MAXM=MAXN*MAXN;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int inde[MAXN];
int outde[MAXN];
int deg[MAXN];
bool vis[MAXN][MAXN];
struct Edge  
{  
    int v;  
    int next;  
    int flow;  
};  
Edge edge[MAXM];  
int head[MAXN],edgeNum;  
int now[MAXN],d[MAXN],vh[MAXN],pre[MAXN],preh[MAXN];  
  
void Addedge(int a,int b,int c)  
{  
    edge[edgeNum].v = b;  
    edge[edgeNum].flow = c;  
    edge[edgeNum].next = head[a];  
    head[a] = edgeNum++;  
    edge[edgeNum].v = a;  
    edge[edgeNum].flow = 0;  
    edge[edgeNum].next = head[b];  
    head[b] = edgeNum++;  
}  
  
void Init()  
{  
    edgeNum = 0;  
    memset(head,-1,sizeof(head));  
    memset(d,0,sizeof(d));  
}  
  
int sap(int s,int t,int n)
{  
    int i,x,y;  
    int f,ans = 0;  
    for(i = 0; i < n; i++)  
        now[i] = head[i];  
    vh[0] = n;  
    x = s;  
    while(d[s] < n)  
    {  
        for(i = now[x]; i != -1; i = edge[i].next)  
            if(edge[i].flow > 0 && d[y=edge[i].v] + 1 == d[x])  
                break;  
            if(i != -1)  
            {  
                now[x] = preh[y] = i;  
                pre[y] = x;  
                if((x=y) == t)  
                {  
                    for(f = INF,i=t; i != s; i = pre[i])  
                        if(edge[preh[i]].flow < f)  
                            f = edge[preh[i]].flow;  
                    ans += f;  
                    do  
                    {  
                        edge[preh[x]].flow -= f;  
                        edge[preh[x]^1].flow += f;  
                        x = pre[x];  
                    }while(x!=s);  
                }  
            }  
            else  
            {  
                if(!--vh[d[x]])  
                    break;  
                d[x] = n;  
                for(i=now[x]=head[x]; i != -1; i = edge[i].next)  
                {  
                    if(edge[i].flow > 0 && d[x] > d[edge[i].v] + 1)  
                    {  
                        now[x] = i;  
                        d[x] = d[edge[i].v] + 1;  
                    }  
                }  
                ++vh[d[x]];  
                if(x != s)  
                    x = pre[x];  
            }  
    }  
    return ans;  
}  
 int main() {
  int Test;
  cin>>Test;
  while (Test--) {
    int n,m;
    scanf("%d %d",&n,&m);
    int u,v;
    edgeNum=0;
    MEM(inde,0);
    MEM(deg,0);
    MEM(outde,0);
    Init();
    for (int i=0; i<m; ++i) {
      scanf("%d %d",&u,&v);
      Addedge(u,v,1);
      outde[u]++;
      inde[v]++;
      deg[u]++;
      deg[v]++;
    }
    int pre=0;
    int ans=n;
    int cnt=0;
    int b[MAXN];
    for (int i=1; i<=n; ++i) 
      //if (deg[i]%2) b[++cnt]=i;
      if (abs(inde[i] - outde[i]) % 2 == 1)b[++cnt] = i;
    for (int i = 1; i <= cnt; i += 2) {
            Addedge(b[i], b[i + 1], 1);
            ++outde[b[i]];
            ++inde[b[i + 1]];
            printf("bi:%d bi+1:%d\n",b[i],b[i+1]);
    }
    for (int i=1 ;i<=n; ++i) {
      int x=abs(outde[i]-inde[i])/2;
      if (inde[i]>outde[i]) {
        Addedge(i,n+1,x);
      }
      else if (inde[i]<outde[i]) {
        Addedge(0,i,x);
      }
    }
    sap(0,n+1,n+2);
    printf("%d\n",n-cnt);
    for (int i=0; i<m*2; i+=2) {
      int from=edge[i].v;
      int to=edge[i^1].v;
      if (edge[i].flow==1) printf("%d %d\n",from,to);
      else printf("%d %d\n",to,from);
    }
  }
}
