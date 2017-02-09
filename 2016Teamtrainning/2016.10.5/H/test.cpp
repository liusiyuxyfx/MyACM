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

int A[32767], B[32767];
int main() {
    int testcase, n, m, cases = 0;
    scanf("%d", &testcase);
    while (testcase--) {
        map<int, int> R;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < m; i++) {
            scanf("%d", &B[i]);
            R[B[i]]++;
        }
        int diff = (int)R.size();
        long long ret = 0;
        for (int i = 0; i < n; i++) {
          printf("Round %d----------------\n",i);
          printf("before :R[%d]=%d\n",A[i],R[A[i]]);
            int &x = R[A[i]];
            printf("x:%d\n",x);
            if (x == 1) {
                printf("because x==1 diff-- -> %d\n",diff-1);
                diff--;
            }
            else if(x == 0) {
              printf("because x==0 dif++ ->%d\n",diff+1);
                diff++;
            }
            x--;
            printf("R[%d]-> %d\n",A[i],R[A[i]]);
            if (i - m >= 0) {
              printf("into i-m=%d A[i-m]=%d R[%d]=%d\n",i-m,A[i-m],A[i-m],R[A[i-m]]);
                int &y = R[A[i-m]];
                printf("y=%d\n",y);
                if (y == 0) {
                    diff++;
                    printf("because y==0 diff++ ->%d\n",diff);
                }

                else if(y == -1) {
                    diff--;
                    printf("because y==-1 diff-- ->%d\n",diff);
                }

                y++;
                printf("R[%d]->%d\n",A[i-m],y);
            }
            printf("diff :%d\n",diff);
            if (diff == 0) {
                long long pos = i - m + 2;
                ret += pos * pos;
                printf("pos %d\n", pos);
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}
