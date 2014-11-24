// http://codeforces.com/contest/490/problem/A


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
const int maxn=5010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n;
vector<int> v[5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        v[val].push_back(i);
    }
    int ans=v[1].size();
    for(int i=1;i<=3;i++)
    {
        int len=v[i].size();
        if(len<ans) ans=len;
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
        cout<<v[1][i-1]<<" "<<v[2][i-1]<<" "<<v[3][i-1]<<endl;
}

