// http://codeforces.com/contest/483/problem/A


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
const int maxn=5002;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int n,m;
LL gcd(LL a, LL b)
{
    return b==0 ? a : gcd(b, a%b);
}
int main()
{
    // freopen("in.txt","r",stdin);
    LL le,ri;
    cin>>le>>ri;
    LL a,b,c;
    int flag=0;
    for(LL i=le;i<=ri;i++)
    {
        for(LL j=i+1;j<=ri;j++)
        {
            if(gcd(i,j)==1)
            {
                a=i,b=j;
                for(LL k=j+1;k<=ri;k++)
                {
                    if(gcd(j,k)==1 && gcd(i,k)!=1)
                    {
                        c=k;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag==1) cout<<a<<" "<<b<<" "<<c<<endl;
    else cout<<-1<<endl;
}
