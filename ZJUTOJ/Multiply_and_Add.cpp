// http://acm.zjut.edu.cn/onlinejudge/problem.php?id=1101

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
const int maxn=100010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
struct Tree
{
    int left,right;
    LL sum,mul,add;
}tree[maxn<<2];
int n,m;
void build(int u,int left,int right)
{
    tree[u].left=left;
    tree[u].right=right;
    tree[u].mul=1;
    tree[u].add=0;
    if(left==right)
    {
        tree[u].sum=left-1;
        return;
    }
    int mid=(left+right)/2;
    build(L(u),left,mid);
    build(R(u),mid+1,right);
    tree[u].sum=(tree[L(u)].sum+tree[R(u)].sum)%mod;
}
void pushdown_mul(int u)
{
    if(tree[u].mul==1) return ;
    tree[L(u)].mul=(tree[L(u)].mul*tree[u].mul)%mod;
    tree[L(u)].sum=(tree[L(u)].sum*tree[u].mul)%mod;
    tree[L(u)].add=(tree[L(u)].add*tree[u].mul)%mod;
    tree[R(u)].mul=(tree[R(u)].mul*tree[u].mul)%mod;
    tree[R(u)].sum=(tree[R(u)].sum*tree[u].mul)%mod;
    tree[R(u)].add=(tree[R(u)].add*tree[u].mul)%mod;
    tree[u].mul=1;
}
void pushdown_add(int u)
{
    if(!tree[u].add) return ;
    tree[L(u)].add=(tree[L(u)].add+tree[u].add)%mod;
    tree[L(u)].sum=(tree[L(u)].sum+tree[u].add*(tree[L(u)].right-tree[L(u)].left+1))%mod;
    tree[R(u)].add=(tree[R(u)].add+tree[u].add)%mod;
    tree[R(u)].sum=(tree[R(u)].sum+tree[u].add*(tree[R(u)].right-tree[R(u)].left+1))%mod;
    tree[u].add=0;
}
void update(int u,int ql,int qr,LL val,int flag)
{
    if(tree[u].left==ql && tree[u].right==qr)
    {
        if(flag==1)
        {
            tree[u].add+=val;
            tree[u].add%=mod;
            tree[u].sum+=val*(qr-ql+1);
            tree[u].sum%=mod;
        }
        else if(flag==2)
        {
            tree[u].mul*=val;
            tree[u].mul%=mod;
            tree[u].add*=val;
            tree[u].add%=mod;
            tree[u].sum*=val;
            tree[u].sum%=mod;
        }
        return;
    }
    pushdown_mul(u);
    pushdown_add(u);
    int mid=(tree[u].left+tree[u].right)/2;
    if(qr<=mid) update(L(u),ql,qr,val,flag);
    else if(ql>mid) update(R(u),ql,qr,val,flag);
    else
    {
        update(L(u),ql,mid,val,flag);
        update(R(u),mid+1,qr,val,flag);
    }
    tree[u].sum=(tree[L(u)].sum+tree[R(u)].sum)%mod;
}
LL query(int u,int ql,int qr)
{
    if(tree[u].left==ql && tree[u].right==qr)
        return tree[u].sum;
    pushdown_mul(u);
    pushdown_add(u);
    int mid=(tree[u].left+tree[u].right)/2;
    if(qr<=mid) return query(L(u),ql,qr);
    else if(ql>mid) return query(R(u),ql,qr);
    else return (query(L(u),ql,mid)+query(R(u),mid+1,qr))%mod;
    tree[u].sum=(tree[L(u)].sum+tree[R(u)].sum)%mod;
}
int main()
{
    LL x,y,val;
    char c[10];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        build(1,1,n);
        while(m--)
        {
            scanf("%s %lld %lld",c,&x,&y);
            x++;y++;
            if(c[0]=='a')
            {
                scanf("%lld",&val);
                update(1,x,y,val,1);  // 1 -> add
            }
            else if(c[0]=='m')
            {
                scanf("%lld",&val);
                update(1,x,y,val,2);  // 2 -> mul
            }
            else
                printf("%lld\n",query(1,x,y)%mod);
        }
        printf("\n");
    }
}
