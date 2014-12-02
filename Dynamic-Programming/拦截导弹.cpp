// http://codevs.cn/problem/1044/


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
const int maxn=300;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n = 0, dp1[100005], dp2[100005];
int a[100005];
int DP1(int len)
{
	int i, j, ans = 1, Max = 0;
	dp1[1] = 1;
	for(i = 2; i <= len; i++)
	{
		Max = 0;
		for(j = 1; j < i; j++)
		{
			if(dp1[j] > Max && a[j] > a[i])
			    Max = dp1[j];
		}
		dp1[i] = Max + 1;
		if(dp1[i] > ans)
		     ans = dp1[i];
	}
	return ans;
}
int DP2(int len)
{
	int i, j, ans = 1, Max = 0;
	dp2[1] = 1;
	for(i = 2; i <= len; i++)
	{
		Max = 0;
		for(j = 1; j < i; j++)
		{
			if(dp2[j] > Max && a[j] < a[i])
			    Max = dp2[j];
		}
		dp2[i] = Max + 1;
		if(dp2[i] > ans)
		     ans = dp2[i];
	}
	return ans;
}
int main()
{
	while(scanf("%d", &a[++n]) != EOF);
	printf("%d\n", DP1(n - 1));
	printf("%d\n", DP2(n - 1));
	return 0;
}
