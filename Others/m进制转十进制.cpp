// http://codevs.cn/problem/1475/


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
map<char,int> ma;
void init()
{
    for(int i=0;i<10;i++)
        ma[char(i+'0')]=i;
    ma['A']=10;
    ma['B']=11;
    ma['C']=12;
    ma['D']=13;
    ma['E']=14;
    ma['F']=15;
}
int main()
{
    string n;
    int m;
    init();
    while(cin>>n>>m)
    {
        int ans=0;
        int times=0;
        while(n.length()>0)
        {
            int tmp=1;
            for(int i=1;i<=times;i++)
                tmp*=m;
            char nn=n[n.length()-1];
            ans=ans+tmp*ma[nn];
            times++;
            n=n.substr(0,n.length()-1);
        }
        cout<<ans<<endl;
    }
}
