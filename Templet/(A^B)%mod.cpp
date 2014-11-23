#pragma comment(linker, "/STACK:1024000000,1024000000")
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
using namespace std;
#define LL long long
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=100010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int  A[maxn], B[maxn];
LL solve(LL N, LL K)
{
    if(K==0) return 1;
    if(K==1) return N;
    if(K%2==0)
    {
        LL tmp=solve(N,K/2)%mod;
        return (tmp*tmp)%mod;
    }
    else
    {
        LL tmp=solve(N,K/2)%mod;
        return ( ((tmp*tmp)%mod)*N)%mod;
    }
}
int main()
{
    string s1,s2;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1;
        cin>>s2;
        for(int i=0;i<s1.length();i++)
            A[i]=s1[i]-'0';
        for(int i=0;i<s2.length();i++)
            B[i]=s2[i]-'0';
        LL a=A[0],b=B[0];
        LL MOD=mod;
        for(int i=1;i<s1.length();i++)
            a = ((a%MOD)*10+A[i])%MOD;
        MOD--;
        for(int i=1;i<s2.length();i++)
            b = ((b%MOD)*10+B[i])%MOD;
        cout<<solve(a,b)<<endl;
    }
}


