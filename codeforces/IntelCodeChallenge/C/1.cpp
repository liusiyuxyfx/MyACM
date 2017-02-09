/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月01日 星期六 22时40分15秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Node{
  int val;
  Node *nex,*pre;
}node[MAXN];
int top;
int a[MAXN];
LL b[MAXN];
LL sum[MAXN];
multiset <LL> ms;
int main() {
  top=0;
  int n;
  scanf("%d",&n);
  for (int i=1; i<=n; ++i) 
    scanf("%d",&a[i]);
  sum[0]=0;
  for (int i=1; i<=n; ++i)
    sum[i]=sum[i-1]+(LL)a[i];
  printf("-----");
  int c;
  Node *pl=&node[top++];
  Node *pr=&node[top++];
  pl->pre=NULL;
  pl->val=0;
  pl->nex=pr;
  pr->nex=NULL;
  pr->pre=pl;
  pr->val=n+1;
  int last_val;
  scanf("%d",&c);
  Node *pno=&node[top++];
  pno->val=c;
  pno->pre=pl;
  pno->nex=pr;
  pl->nex=pno;
  pr->pre=pno;
  printf("--------------");
  if(c>1){
  LL now_left=sum[c-1]-sum[0];
  ms.insert(-now_left);
  }
  if(n>pno->val) {
  LL now_right=sum[n]-sum[pno->val];
  ms.insert(-now_right);
  }
  last_val=c;
  printf("%lld",-*ms.begin()); 
  for (int i=2; i<=n; ++i) {
    scanf("%d",&c);
    if (c>pno->val) {
      ms.erase(ms.find(-(sum[(pno->nex)->val]-sum[pno->val])));
      Node *pne=&node[top++];
      Node *pnor=pno->nex;
      pne->val=c;
      pne->pre=pno;
      pne->nex=pnor;


      pnor->pre=pne;
      pno->nex=pne;
      if (c>pno->val+1) {
        ms.insert(-(sum[c-1]-sum[pno->val]));
      }
      if (c<pnor->val-1) {
        ms.insert(-(sum[pnor->val-1]-sum[c]));
      }
    }
    else if (c<pno->val) {
      ms.erase(ms.find(-(sum[pno->val]-sum[(pno->pre)->val])));
      Node ne;
      Node *pne=&node[top++];
      Node *pnol;
      pnol=pno->pre;
      //Node pnol=pno->pre;
      pne->val=c;
      pne->nex=pno;
      pne->pre=pnol;
      pnol->nex=pne;
      pno->pre=pne;
      if (c>pnol->val+1) {
        ms.insert(-(sum[c-1]-sum[pnol->val]));
       }
      if (c<pno->val-1) {
        ms.insert(-(sum[pno->val-1]-sum[c]));
      }
    }
    printf("%lld ",-*ms.begin());
  }
  }

    


