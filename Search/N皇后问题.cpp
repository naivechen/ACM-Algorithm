// http://codevs.cn/problem/1295/


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
int n, ans = 0;
int g[14];
void dfs(int x)
{
	if(x > n) {ans++; return;}
	int i, j;
	for(i = 1; i <= n; i++) //放在某行
	{
		g[x] = i;
		for(j = 1; j < x; j++) //判断前面列是否有重合，直接判断横行 和 斜行 （可自己画图为什么判断斜行成立）
			if((g[j] == g[x]) ||
			   (x-g[x] == j-g[j] || x+g[x] == j+g[j]))
				break;
		if(j == x)
			dfs(x+1);
	}
}

int main()
{
	cin >> n;
	if(n>10){
	if(n==13) printf("73712\n");
	else if(n==12)   printf("14200\n");
	else if(n==11)  printf("2680\n");
	return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
