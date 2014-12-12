// http://codeforces.com/contest/493/problem/B


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
const int maxn=200010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
LL n,val[maxn];
int f[maxn],s[maxn];
int main()
{
    cin>>n;
    int fi=0,si=0;
    LL first=0,second=0;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
        if(val[i]>0) first+=val[i],f[++fi]=val[i];
        else second+=(-val[i]),s[++si]=-val[i];
    }
    if(first>second) cout<<"first"<<endl;
    else if(first<second) cout<<"second"<<endl;
    else
    {
        int flag=0;
        int i=1,j=1;
        while(i<=fi && j<=si)
        {
            if(s[j]<f[i])
            {
                cout<<"first"<<endl;
                return 0;
            }
            else if(s[j]>f[i])
            {
                cout<<"second"<<endl;
                return 0;
            }
            i++;j++;
        }
        if(i<=fi)
        {
            cout<<"first"<<endl;
        }
        else if(j<=si) cout<<"second"<<endl;
        else if(val[1]<0) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
}
