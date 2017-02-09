/*************************************************************************
     File Name: CF748D.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月09日 星期一 10时23分05秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
map <string,int> Hash;
bool p[MAXN];
int n,k, v, len = 0;
string s[MAXN + 10];
struct Node
{
    int v;
    bool operator < (const Node& x) const
    {
        return v>x.v;
    }
};
vector<Node> g[MAXN*2+50];
int main() {
    scanf("%d %d", &n, &k);
    Hash.clear();
    for (int i = 0;i <= 2*n; ++i) g[i].clear();
    for (int i = 1;i <= n; ++i) {
        cin >>s[i] >> v;
        if (!Hash.count(s[i])) Hash[s[i]] = ++len;
        int id = Hash[s[i]];
        g[id].push_back({v});
    }
    for (int i = 1;i <= len; ++i)
      sort(g[i].begin(), g[i].end());
    memset(p, 0, sizeof(p));
    long long ans = 0;
    int ss = 0;
    for (int i = 1; i <= n; ++i) {
        char t[MAXN+50] = {'\0'};
        int len1 = s[i].length();
        for (int j = len1 - 1;j >= 0; --j)
          t[len1-1-j] = s[i][j];
        t[len1] = '\0';
        if (!Hash.count(t)) continue;
        int u = Hash[s[i]],v = Hash[t];
        if( p[u]) continue;
        p[u] = p[v] = 1;
        if(u != v) {
            for(int i = 0; i < min(g[u].size() , g[v].size()); ++i)
                if(g[u][i].v + g[v][i].v < 0) 
                  break;
                else 
                  ans += g[u][i].v+g[v][i].v;
        }
        else {
            int w;
            for (w = 0; w < g[u].size(); ++w) if(g[u][w].v < 0) 
              break;
            if (w % 2 == 0)
                for(int i = 0; i < w; ++i) ans += g[u][i].v;
            else {
                if (w >= g[u].size()) {
                    for (int i = 0;i < w-1; ++i) ans += g[u][i].v;
                    ss = max(ss,g[u][w-1].v);
                    continue;
                }
                for(int i = 0;i < w-1; ++i) 
                  ans += g[u][i].v;
                if(g[u][w-1].v + g[u][w].v < 0) {
                    ss=max(ss,g[u][w-1].v);
                    continue;
                }
                ans += g[u][w-1].v + g[u][w].v;
                ss = max(ss,-g[u][w].v);
            }
        }
    }
    printf("%lld\n",ans+ss);
    return 0;
}

