// http://codevs.cn/problem/3116/


#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int maxn=210;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
string add(string s1,string s2)
{
    string ret="";
    int flag=0;
    int len1=s1.length(),len2=s2.length();
    int i=0,j=0;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(i<len1 && j<len2)
    {
        flag+=(s1[i]-'0')+(s2[j]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        i++;j++;
    }
    while(i<len1)
    {
        flag+=(s1[i]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        i++;
    }
    while(j<len2)
    {
        flag+=(s2[j]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        j++;
    }
    if(flag) ret+=char(flag+'0');
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string ans=add(s1,s2);
    cout<<ans<<endl;
}

