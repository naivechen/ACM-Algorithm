// http://acm.hdu.edu.cn/showproblem.php?pid=1280


#pragma comment(linker, "/STACK:1024000000,1024000000")
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
using namespace std;
#define LL long long
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=3210;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m,a[maxn];
int ans[maxn];
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        priority_queue<int> q;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int val=a[i]+a[j];
                q.push(-val);
                if(q.size()>m) q.pop();
            }
        int num=0;
        while(!q.empty())
        {
            ans[++num]=q.top();
            q.pop();
        }
        for(int i=num;i>1;i--)
            printf("%d ",-ans[i]);
        printf("%d\n",-ans[1]);
    }
}
