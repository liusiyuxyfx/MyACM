#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N];
struct ndoe{
  int position;
  LL x;
}node[N<<2];

void Push_up(int t) {
  if (node[t<<1].x>node[t<<1|1].x) {
    node[t].x=node[t<<1|1].x;
    node[t].position=node[t<<1|1].position;
  } else {
    node[t].x=node[t<<1].x;
    node[t].position=node[t<<1].position;
  }
}

void Buildndoe(int t,int L,int R) {
  if (L==R) {
    if (a[L]>=0) node[t].x=a[L];
    else node[t].x=-a[L];
    node[t].position=L;
    return;
  }
  int mid=(L+R)>>1;
  Buildndoe(t<<1,L,mid);
  Buildndoe(t<<1|1,mid+1,R);
  Push_up(t);
}

void Update(int t,int L,int R,int x,int v) {
  if (L==R && L==x) {
    node[t].x+=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) Update(t<<1,L,mid,x,v);
  else Update(t<<1|1,mid+1,R,x,v);
  Push_up(t);
}

int main() {
  ios::sync_with_stdio(0);
  LL n,k,x;
  int i;
  cin>>n>>k>>x;
    MEM(node,0);
    int cnt=0;
    for (i=1; i<=n; ++i) {
      cin>>a[i];
      if (a[i]<0) cnt++;
    }
    Buildndoe(1,1,n);
    if (cnt%2) {
      for (int i=0; i<k; ++i) {
        int temp=node[1].position;
        if (a[temp]>=0) a[temp]+=x;
        else a[temp]-=x;
        Update(1,1,n,temp,x);
      }
    } 
    else {
      int temp=node[1].position;
      LL aa=a[temp];
      while (k>0 && node[1].x>=0) {
        if (a[temp]>=0) aa+=-x;
        else aa-=-x;
        Update(1,1,n,temp,-x);
        k--;
      }
      a[temp]=aa;
      Update(1,1,n,node[1].position,-2*node[1].x);
      while (k>0) {
        int temp=node[1].position;
        if (a[temp]>=0) a[temp]+=x;
        else a[temp]-=x;
        Update(1,1,n,temp,x);
        k--;
      }
    }
    for (i=1; i<=n; ++i) {
      cout<<a[i];
      if (i!=n)
        cout<<" ";
    }
    cout<<endl;
}

