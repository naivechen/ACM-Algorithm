// http://hihocoder.com/problemset/problem/1082?sid=246621



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
const int maxn=100510;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
string str;
string p1="marshtomp";
string p2="MARSHTOMP";
string t="fjxmlhx";
bool check(int i)
{
    int len=p1.length();
    for(int j=0;j<len;j++)
    {
        if(str[i]!=p1[j] && str[i]!=p2[j]) return false;
        i++;
    }
    return true;
}
int main()
{
    freopen("in","r",stdin);
    while(getline(cin,str))
    {
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            if(i+9<=len && check(i))
            {
                cout<<t;
                i+=8;
            }
            else cout<<str[i];
        }
        cout<<endl;
    }
}
