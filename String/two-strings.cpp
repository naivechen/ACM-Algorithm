// https://www.hackerrank.com/challenges/two-strings


// When I wrote this, only God and I understood what I was doing
// now, God only knows

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
const int maxn=100010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int hdir[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,1},{2,1},{-2,-1},{2,-1}};
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
int n,m;
int a[30];
string s1,s2;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        memset(a,0,sizeof(a));
        for(int i=0;i<s1.length();i++)
            a[s1[i]-'a']=1;
        int flag=0;
        for(int i=0;i<s2.length();i++)
        {
            int tmp=a[s2[i]-'a'];
            if(tmp!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
