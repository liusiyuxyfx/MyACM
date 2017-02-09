/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月04日 星期日 09时34分11秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long LL;
const int N=410;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int g[N][N],l1[N],l2[N],s[N],t[N],match1[N],match2[N],n,ans[N];

void KM() {
  int p,q,i,j,k;
  for (i=0; i < n; ++i) {
    l1[i]=-INF;
    for (j=0; j < n; ++j)
      l1[i]=g[i][j]>l1[i]? g[i][j]:l1[i];
  }
  MEM(l2,0),MEM(match1,-1),MEM(match2,-1);
  for (i=0; i < n; ++i) {
    MEM(t,-1),p=q=0;
    for (s[0]=i; p <= q && match1[i] < 0; ++p)
      for (k=s[p],j=0; j < n && match1[i] < 0; ++j) {
        if (l1[k]+l2[j]!=g[k][j] || t[j] >= 0) continue;
        s[++q]=match2[j];
        t[j]=k;
        if (s[q] >= 0) continue;
        for (p=j; p >= 0; j=p) {
          match2[j]=k=t[j];
          p=match1[k];
          match1[k]=j;
        }
      }
    if (match1[i] >= 0) continue;
    --i,p=INF;
    for (k=0; k <= q; ++k)
      for (j=0; j < n; ++j)
        if (t[j] < 0 && l1[s[k]]+l2[j]-g[s[k]][j] < p)
          p=l1[s[k]]+l2[j]-g[s[k]][j];
    for (j=0; j < n; ++j)
      l2[j]+=t[j]<0? 0:p;
    for (k=0; k <= q; ++k)
      l1[s[k]]-=p;
  }
  MEM(ans,-1);
  
  for (i=0; i < n; ++i) {
    //cout<<"g["<<i<<"]["<<match1[i]<<"]="<<g[match2[i]][match1[i]]<<endl;
    if (g[i][match1[i]])// ans[match2[i]]=match1[i];
      printf("%d%c",match1[i]+1," \n"[i==n-1]);
    else printf("0%c"," \n"[i==n-1]);

  }
  //for (i=0; i < n; ++i)
    //printf("%d%c",g[i][match1[i]]," \n"[i==n-1]);
  //for (i=0; i < n; ++i)
    //printf("%d%c",ans[i]+1," \n"[i==n-1]);
}

int v[N];

int main() {
  int k,i,j,x;
  while (~scanf("%d",&n)) {
    MEM(g,0);
    for (i=0; i < n; ++i)
      scanf("%d",v+i);
    for (i=0; i < n; ++i) {
      scanf("%d",&k);
      for (j=0; j < k; ++j) {
        scanf("%d",&x);
        x--;
        g[i][x]=v[i];
        //cout<<"g["<<i<<"]["<<x<<"]="<<g[i][x]<<endl;
      }
    }
    KM();
  }
}
