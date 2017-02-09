#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 205, M = N * N * 20, Z = 1e9 + 7, inf = 0x3f3f3f3f;
template <class T1, class T2>inline void gadd(T1 &a, T2 b) { a = (a + b) % Z; }
int casenum, casei;
int n, m;
int ind[N], oud[N];
int ST, ED;
int first[N]; int id;
int w[M], cap[M], nxt[M];
void ins(int x, int y, int cap_)
{
	w[++id] = y;
	cap[id] = cap_;
	nxt[id] = first[x];
	first[x] = id;
	w[++id] = x;
	cap[id] = 0;
	nxt[id] = first[y];
	first[y] = id;
}
int d[N];
bool bfs()
{
	MS(d, -1);
	queue<int>q; q.push(ST); d[ST] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int z = first[x]; z; z = nxt[z])if (cap[z])
		{
			int y = w[z];
			if (d[y] == -1)
			{
				d[y] = d[x] + 1;
				q.push(y);
				if (y == ED)return 1;
			}
		}
	}
	return 0;
}
int dfs(int x, int all)
{
	if (x == ED)return all;
	int use = 0;
	for (int z = first[x]; z; z = nxt[z])if (cap[z])
	{
		int y = w[z];
		if (d[y] == d[x] + 1)
		{
			int tmp = dfs(y, min(cap[z], all - use));
			cap[z] -= tmp;
			cap[z ^ 1] += tmp;
			use += tmp;
			if (use == all)break;
		}
	}
	if (use == 0)d[x] = -1;
	return use;
}
int dinic()
{
	int ret = 0;
	while (bfs())ret += dfs(ST, inf);
        cout<<ret<<endl;
	return ret;
}
int b[N], g;
void solve()
{
	int sum = 0;
	g = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (abs(ind[i] - oud[i]) % 2 == 1)b[++g] = i;
	}
        puts("-----");
	for (int i = 1; i <= g; i += 2)
	{
		ins(b[i], b[i + 1], 1);
		++oud[b[i]];
		++ind[b[i + 1]];
                printf("Addedge(%d %d)\n",b[i],b[i+1]);
	}
	for (int i = 1; i <= n; ++i)
	{
		int w = abs(ind[i] - oud[i]) / 2;
		if (ind[i] > oud[i])
                {
                  printf("add:%d ED=%d\n",i,w);
			ins(i, ED, w);
			sum += w;
		}
		if (oud[i] > ind[i])
		{
                  printf("add:ST %d=%d\n",i,w);
			ins(ST, i, w);
		}
	}
	dinic();
	int ans = n - g;
	printf("%d\n", ans);
        for (int i=2; i<=id; ++i) {
          printf("id:%d u:%d v:%d cap:%d\n",i,w[i^1],w[i],cap[i]);
        }

	for (int i = 2; i <= 2 * m; i += 2)
	{
		if (cap[i] == 0)printf("%d %d\n", w[i], w[i ^ 1]);
		else printf("%d %d\n", w[i ^ 1], w[i]);
	}
}
int main()
{
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%d%d", &n, &m);
		ST = 0;
		ED = n + 1;
		MS(first, 0); id = 1;
		for (int i = 1; i <= n; ++i)oud[i] = ind[i] = 0;
		for (int i = 1; i <= m; ++i)
		{
			int x, y; scanf("%d%d", &x, &y);
			++oud[x];
			++ind[y];
			ins(x, y, 1);
                        printf("Addedge(%d %d)\n",x,y);
		}
		solve();
	}
	return 0;
}
/*
【trick&&吐槽】


【题意】
n个点m条边的无向连通图
没有自环没有重边
我们要把所有点都定向
希望使得尽可能多的点拥有相同的入度与出度
让你输出满足这个条件的最大点数和每条边最后的定向

【类型】
欧拉回路 或 网络流

【分析】
首先，有一个猜想——
就是满足那个条件的最大点数为拥有偶数度数的点数。

基于这个猜想，
我们可以把度数为奇数的点配对连边
这时的图一定存在一个欧拉回路，也就使得每个点的入度=出度，使得我们的猜想成立
我们可以用欧拉回路算法解决这道题，复杂度O(n+m)


也可以套用网络流解决
复杂度O(n*m)
网络流的建图方式是——
一开始把所有点任意定向，（奇点之间配对连边）
后来把设w=abs(ind[i]-oud[i])/2
如果ind[i]>oud[i]，就从i向ED连容量为w的边
如果oud[i]>ind[i]，就从ST向i连容量为w的边

这时跑下最大流，如果满流，就存在欧拉回路
因为我们的连边方式，肯定满流，肯定从在欧拉回路
我们只要通过流量判定边的具体方向就好了

【时间复杂度&&优化】
O(n+m) or O(nm)

*/
