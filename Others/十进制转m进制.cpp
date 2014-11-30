// http://codevs.cn/problem/1474/


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
map<int,char> ma;
int main()
{
    ma[10]='A';
    ma[11]='B';
    ma[12]='C';
    ma[13]='D';
    ma[14]='E';
    ma[15]='F';
    int n,m;
    int a[maxn];
    while(cin>>n>>m)
    {
        int i=0;
        while(n>=m)
        {
            a[i]=n%m;
            n/=m;
            i++;
        }
        a[i]=n;
        while(a[i]==0) i--;
        for( ; i>=0;i--)
        {
            if(a[i]>9) cout<<ma[a[i]];
            else cout<<a[i];
        }
        cout<<endl;
    }
}
