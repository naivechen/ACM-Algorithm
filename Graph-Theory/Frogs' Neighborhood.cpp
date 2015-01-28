// http://poj.org/problem?id=1659



// When I wrote this, only God and I understood what I was doing
// now, God only knows

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
//---------------------------------------------------------------
int n;
int g[11][11];
struct chen
{
    int deg;
    int index;
}ch[11];
bool cmp(chen a,chen b)
{
    return a.deg>b.deg;
}
int main()
{
    freopen("in","r",stdin);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        if(i) cout<<endl;
        memset(g,0,sizeof(g));
        memset(ch,0,sizeof(ch));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>ch[i].deg;
            ch[i].index=i;
        }
        int flag=1;
        while(flag)
        {
            sort(ch+1,ch+1+n,cmp);
            if(ch[n].deg<0)
            {
                flag=0;
                cout<<"NO"<<endl;
            }
            else if(ch[1].deg==0)
            {
                cout<<"YES"<<endl;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(j>1) cout<<" ";
                        cout<<g[i][j];
                    }
                    cout<<endl;
                }
                flag=0;
            }
            else
            {
                int aim=ch[1].deg;
                int index=ch[1].index;
                for(int i=2;i<=n;i++)
                {
                    if(ch[1].deg==0) break;
                    ch[1].deg--;
                    ch[i].deg--;
                    g[index][ch[i].index]=1;
                    g[ch[i].index][index]=1;
                }
                if(ch[1].deg>0)
                {
                    flag=0;
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}
