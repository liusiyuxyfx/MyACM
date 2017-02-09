/*************************************************************************
     File Name: 747C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月06日 星期五 11时10分37秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct node1{
  int id;
  int finish;
  friend bool operator < (node1 a, node1 b) {
    return a.id > b. id;
  }
}no;


struct node2{
  int id,finish;
  friend bool operator < (node2 a, node2 b) {
    return a.finish > b.finish;
  }
}ne;

priority_queue<node1> q1;
priority_queue<node2> q2;

int main() {
  int n, q;
  int t,k,d;
  scanf("%d %d", &n, &q);
  for (int i = 1 ; i <= n; ++i) {
     no.id = i;
     no.finish = 0;
     q1.push(no);
  }
  for(int i = 0; i < q; ++i) {
    scanf("%d %d %d", &t, &k, &d);
    while(!q2.empty()){
      ne = q2.top();
      //printf("q2op: ne.finish = %d\n",ne.finish);
      if (ne. finish <= t) q2.pop();
      else break;
      no.id = ne.id;
      no.finish = 0;
      q1.push(no);
    }
    int sum = 0;
    if (q1.size() >= k) {
      while (k != 0) {
        k--;
        no = q1.top();
        sum += no.id;
        q1.pop();
        ne.id = no.id;
        ne.finish = t + d;
        q2.push(ne);
      }
      printf("%d\n", sum);
    }
    else puts("-1");
  }
}


