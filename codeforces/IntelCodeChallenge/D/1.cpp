#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+5;
struct Tree{
  int maxs,pos;
}tree[MAXN<<2];
int aa[MAXN];
void Push_up(int t) {
  if (tree[t<<1].maxs>=tree[t<<1|1].maxs) {
    tree[t].maxs=tree[t<<1].maxs;
    tree[t].pos=tree[t<<1].pos;
  }
  else {
    tree[t].maxs=tree[t<<1|1].maxs;
    tree[t].pos=tree[t<<1|1].pos;
  }
}

void Build_tree(int ll,int rr ,int t) {
  if (ll==rr) {
    tree[t].maxs=aa[ll];
    tree[t].pos=ll;
    return;
  }
  int mid=(ll+rr)>>1;
  Build_tree(ll,mid,t<<1);
  Build_tree(mid+1,rr,t<<1|1);
  Push_up(t);
}
void update(int ll,int rr,int t,int x,int v) {
  if (ll==rr&&ll==x) {
    tree[t].maxs=v;
    return;
  }
  int mid=(ll+rr)<<1;
  if (x<=mid) update(ll,mid,t<<1,x,v);
  else update(mid+1,rr,t<<1|1,x,v);
  Push_up(t);
}

int main() {
  int n,i;
  ios::sync_with_stdio(0);
  set<int>se;
  se.insert(0);
  se.insert(-1);
  cin>>n;
  for (int i=1; i<=n; ++i) {
    cin>>aa[i];
    se.insert(aa[i]);
  }
  Build_tree(1,1,n);
  while (true) {
    int tmp=tree[1].maxs,last=-1;
    for (;tmp;tmp<<1) {
      if (!se.count(tmp)) {
        last=tmp;
        se.insert(tmp);
        aa[tree[1].pos]=tmp;
        update(1,n,1,tree[1].pos,tmp);
        break;
      }
    }

      if (last==-1) break;
    }
    for (int i=1; i<=n; ++i) {
      cout<<aa[i]<<" \n"[i==n];
    }
  }



