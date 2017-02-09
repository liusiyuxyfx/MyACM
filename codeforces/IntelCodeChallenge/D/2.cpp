#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
struct Tree{
  int maxx,pos;
}tree[N<<2];
int y[N];
set <int>s;

void pushUp(int t) {
  if (tree[t<<1].maxx >= tree[t<<1|1].maxx) {
    tree[t].maxx=tree[t<<1].maxx;
    tree[t].pos=tree[t<<1].pos;
  } else {
    tree[t].maxx=tree[t<<1|1].maxx;
    tree[t].pos=tree[t<<1|1].pos;
  }
}

void build(int t,int L,int R) {
  if (L==R) {
    tree[t].maxx=y[L];
    tree[t].pos=L;
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid);
  build(t<<1|1,mid+1,R);
  pushUp(t);
}

void update(int t,int L,int R,int x,int v) {
  if (L==R && L==x) {
    tree[t].maxx=v;
    return;
  }
  int mid=(L+R)>>1;
  if (x<=mid) update(t<<1,L,mid,x,v);
  else update(t<<1|1,mid+1,R,x,v);
  pushUp(t);
}

int main() {
  int n,i;
  s.insert(0);
  s.insert(-1);
  scanf("%d",&n);
  for (i=1; i<=n; ++i) {
    scanf("%d",&y[i]);
    s.insert(y[i]);
  }
  build(1,1,n);
  bool flag=1;
  while (flag) {
    int tmp=tree[1].maxx,last=-1;
    for (; tmp; tmp>>=1) {
      if (!s.count(tmp)) {
        last=tmp;
        s.insert(tmp);
        y[tree[1].pos]=tmp;
        update(1,1,n,tree[1].pos,tmp);
        break;
      }
    }
    if (last==-1) flag=0;
  }
  for (i=1; i<n; ++i)
    printf("%d ",y[i]);
  printf("%d\n",y[n]);
}


