// http://codevs.cn/problem/1012/


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
const int maxn=210;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
// 两个数的乘积等于二者最大公约数和最小公倍数的乘积
int gcd(int a, int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int t=n*m;
        int ans=0;
        for(int i=n;i<=sqrt(t)+1;i++)
        {
            if(t%i==0 && gcd(t/i,i)==n)
                ans+=2;
        }
        cout<<ans<<endl;
    }
}
