//

#pragma comment(liner, "/STACK:1024000000,1024000000")
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cassert>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#define LL long long int
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=111;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------

LL cnt1, cnt2, x, y;
LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}
bool ok(LL n){
    LL t1 = n / x, t2 = n / y, t3 = n / (x * y / gcd(x, y));
    if(n - t1 >= cnt1 && n - t2 >= cnt2 && cnt1 + cnt2 + t3 <= n) return true;
    return false;
}
int main()
{
    while(~scanf("%I64d%I64d%I64d%I64d", &cnt1, &cnt2, &x, &y))
    {
        LL low = 0, high = inf * 2, ans;
        while(low <= high)
        {
            LL mid = (low + high) >> 1;
            if(ok(mid))
            {
                high  = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
