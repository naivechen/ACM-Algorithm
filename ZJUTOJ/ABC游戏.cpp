// http://acm.zjut.edu.cn/onlinejudge/problem.php?id=1325


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
using namespace std;
#define LL long long int
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=1010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//---------------------------------------------------------
map<int,int> ma;
int a[maxn],b[maxn*maxn];
int num;
int bsearch(int target)
{
    int le=0,ri=num,ans=0,mid;
    while(le<=ri)
    {
        mid=(le+ri)/2;
        if(b[mid]==target)
        {
            ans++;
            for(int i=mid+1;i<=ri;i++)
                if(target==b[i]) ans++;
            for(int i=mid-1;i>=le;i--)
                if(target==b[i]) ans++;
            return ans;
        }
        else if(target<b[mid]) ri=mid-1;
        else le=mid+1;
    }
    return 0;
}
int main()
{
    int A,B,C,inp;
    while(scanf("%d %d %d",&A,&B,&C)!=EOF)
    {
        for(int i=1;i<=A;i++)
            scanf("%d",&a[i]);
        num=0;
        for(int i=1;i<=B;i++)
        {
            scanf("%d",&inp);
            for(int j=1;j<=A;j++)
                b[++num]=a[j]+inp;
        }
        int ans=0;
        sort(b+1,b+num+1);
        for(int i=1;i<=C;i++)
        {
            scanf("%d",&inp);
            ans+=bsearch(inp);
        }
        printf("%d\n",ans);
    }
}
