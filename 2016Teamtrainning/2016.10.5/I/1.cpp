
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <assert.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
#define INF 0x3f3f3f3f
int main() {
    int testcase, cases = 0;
    int n, s, e;
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &n);
        vector< pair<int, int> > D;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &e);
            D.push_back(make_pair(s, e));
        }
        sort(D.begin(), D.end(), cmp);
        vector<int> leftside;
        for (int i = 0; i < D.size(); i++) {
          printf("routd %d :----------------------\n",i);
            int pos = (int)(lower_bound(leftside.begin(), leftside.end(), D[i].first + 1)
                            - leftside.begin());
            printf("lower_bound:%d\n",D[i].first+1);
            puts("next is the leftsid :");
            for (int i=0; i<leftside.size(); ++i) {
              printf("pos:%d %d\n",i,leftside[i]);
            }
            puts("end");

            printf("pos:%d\n",pos);
            if (pos == leftside.size()) {
              printf("push%d\n",D[i].first);
                leftside.push_back(D[i].first);
            } else {
                leftside[pos] = D[i].first;
                printf("left[%d]=%d\n",pos,D[i].first);
            }
        }
        printf("Case %d: %d\n\n\n\n", ++cases, (int)leftside.size());
    }
    return 0;
}

