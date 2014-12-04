// http://codevs.cn/problem/1006/


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
int n,a[maxn],b[maxn];
map<int,int> ma;
bool find(int aim)
{
    if(ma[aim]==1) return true;
    return false;
}
int solve(int cha,int base)
{
    int ans=2,target=base+cha;
    while(find(target))
    {
        target+=cha;
        ans++;
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma[a[i]]=1;
    }
    if(n==1 || n==2)
    {
        cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    int ans=-1;
    int pre=a[1],tmp=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==pre) tmp++;
        else
        {
            ans=max(ans,tmp);
            tmp=1;
            pre=a[i];
        }
    }
    int nn=1;
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(b[nn]!=a[i])
        {
            nn++;
            b[nn]=a[i];
        }
    }
    n=nn;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans=max(ans,solve(b[j]-b[i],b[j]));
    cout<<ans<<endl;
}
