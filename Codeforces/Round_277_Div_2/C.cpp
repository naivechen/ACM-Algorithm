// http://codeforces.com/contest/486/problem/C


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
const int maxn=6010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
string str;
int n,pos;
int main()
{
    while(cin>>n>>pos)
    {
        pos--;
        cin>>str;
        int left=0,right=n/2-1;
        if(n/2<=pos) pos=n-pos-1;
        while(left<right && str[left] == str[n-left-1] ) left++;
        while(right>=0 && str[right] == str[n-right-1]) right--;
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int tmp=abs(str[i] - str[n-i-1]);
            ans+=min(tmp,26-tmp);
        }
        if(left<right) ans+=min(abs(pos-left),abs(pos-right)) +right-left;
        else if(left==right) ans+=abs(pos-left);
        cout<<ans<<endl;
    }
}

