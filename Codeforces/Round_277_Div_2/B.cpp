// http://codeforces.com/contest/486/problem/B


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
const int maxn=50010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n,m;
int g[110][110],ans[110][110];
void solve(int x,int y)
{
    for(int i=1;i<=n;i++)
        ans[x][i]=0;
    for(int i=1;i<=m;i++)
        ans[i][y]=0;
}
bool check()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j])
            {
                int num=0;
                for(int jj=1;jj<=n;jj++)
                    num+=ans[i][jj];
                for(int ii=1;ii<=m;ii++)
                    num+=ans[ii][j];
                if(!num) return false;
            }
        }
    }
    return true;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            ans[i][j]=1;
        }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(!g[i][j]) solve(i,j);
    if(check()==false) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j>1) cout<<" ";
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}
