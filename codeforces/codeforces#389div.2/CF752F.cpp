/*************************************************************************
     File Name: CF752F.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月09日 星期一 16时44分42秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
vector<int> g[MAXN+50],a,b;
int v[MAXN+50], sum[MAXN+50], f[MAXN+50];
int n, m, s, ans;
void dfs(int k, int fa) {
    sum[k] = v[k];
    f[k] = fa;
    for (int i = 0;i < g[k].size(); ++i)
        if(g[k][i] != fa) {
            dfs(g[k][i],k);
            sum[k] += sum[g[k][i]];
        }
}
bool check(int k) {
    for (int i = 0; i < g[k].size(); ++i)
        if (g[k][i] == f[k]) {
            if (s-sum[k] > s/2) return false;
        }
        else if (sum[g[k][i]] > s/2) 
          return false;
    return true;
}
void print(int k,int fa) {
    if(v[k])
        if(a.size() < m) a.push_back(k);
        else b.push_back(k);
    for (int i = 0; i < g[k].size(); ++i)
        if (g[k][i] != fa) print(g[k][i], k);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
      g[i].clear();
    for (int i = 1; i <= n-1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(v, 0, sizeof(v));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= 2*m; ++i) {
        int x;
        scanf("%d", &x);
        v[x] = 1;
    }
    dfs(1, -1);
    s = sum[1];
    for(ans = 1; ans <= n; ++ans)
        if (check(ans)) break;
    printf("1\n%d\n", ans);
    a.clear(),b.clear();
    print(ans, -1);
    for (int i = 0; i<m; ++i) 
      printf("%d %d %d\n", a[i], b[i], ans);
    return 0;
}
