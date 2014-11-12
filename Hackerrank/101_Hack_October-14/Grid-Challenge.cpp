// https://www.hackerrank.com/contests/101hack18/challenges/grid-challenge

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
const int maxn=110;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string str[maxn];
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
            sort(str[i].begin(),str[i].end());
        }
        // check
        int flag=1;
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(str[i][j]>str[i+1][j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0) break;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

