// http://www.spoj.com/problems/ONP/


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
char stack1[400];
char stack2[400];
int top1, top2;

void deal(char *p) {
    int i, len;
    memset(stack1, 0, sizeof(stack1));
    memset(stack2, 0, sizeof(stack2));
    top1 = 0;
    top2 = 0;
    len = strlen(p);
    for(i = 0; i < len; i++) {
        if(p[i] >= 'a' && p[i] <= 'z')
            printf("%c", p[i]);
        if(p[i] == '(')
            stack1[top1++] = p[i];
        if(p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '^')
            stack2[top2++] = p[i];
        if(p[i] == ')' && stack1[top1-1] == '(') {
            printf("%c", stack2[--top2]);
            top1--;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        char str[600];
        gets(str);
        deal(str);
        printf("\n");
    }
}
