// http://codevs.cn/problem/3143/


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
int tree[maxn][maxn];
#define L 1
#define R 2
void tree_pre(int i)
{
    if(i!=0)
    {
        cout<<i<<" ";
        tree_pre(tree[i][L]);
        tree_pre(tree[i][R]);
    }
}
void tree_mid(int i)
{
    if(i!=0)
    {
        tree_mid(tree[i][L]);
        cout<<i<<" ";
        tree_mid(tree[i][R]);
    }
}
void tree_epilogue(int i)
{
    if(i!=0)
    {
        tree_epilogue(tree[i][L]);
        tree_epilogue(tree[i][R]);
        cout<<i<<" ";
    }
}
int main()
{
    int n,x,y;
    while(cin>>n)
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            tree[i][L]=x;
            tree[i][R]=y;
        }
        tree_pre(1);
        cout<<endl;
        tree_mid(1);
        cout<<endl;
        tree_epilogue(1);
        cout<<endl;
    }
}
