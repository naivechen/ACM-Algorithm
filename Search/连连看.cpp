// http://acm.hdu.edu.cn/showproblem.php?pid=1175


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int num[1010][1010];

bool vis[1010][1010][4];

struct P
{
    int x,y,ans,dir;
};

int jx[] = {-1, 0, 1, 0};
int jy[] = { 0, 1, 0,-1};

bool bfs(P p1,P p2,int n,int m)
{
    queue <P> q;
    p1.ans = 0;
    p1.dir = -1;
    q.push(p1);

    P s,t;
    int i;

    while(q.empty() == false)
    {
        s = q.front();
        if(s.x == p2.x && s.y == p2.y)
            return true;
        q.pop();
        for(i = 0;i < 4; ++i)
        {
            t = s;
            t.x += jx[i];
            t.y += jy[i];
            t.dir = i;
            if(t.dir != s.dir && s.dir != -1)
            {
                t.ans++;
            }
            if(t.ans <= 2 && 1 <= t.x && t.x <= n && 1 <= t.y && t.y <= m && num[t.x][t.y] == 0 && vis[t.x][t.y][t.dir] == false)
            {
                vis[t.x][t.y][t.dir] = true;
                q.push(t);
            }
        }
    }
    return false;
}

int main()
{
    int i,j,n,m,q,temp;
    P p1,p2;
    while(scanf("%d %d",&n,&m) && (n||m))
    {
        for(i = 1;i <= n; ++i)
        {
            for(j = 1;j <= m; ++j)
            {
                scanf("%d",&num[i][j]);
            }
        }

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d %d %d",&p1.x,&p1.y,&p2.x,&p2.y);

            memset(vis,false,sizeof(vis));

            if(num[p1.x][p1.y] != num[p2.x][p2.y] || num[p1.x][p1.y] == 0)
            {
                printf("NO\n");
            }
            else
            {
                temp = num[p2.x][p2.y];
                num[p2.x][p2.y] = 0;
                if(bfs(p1,p2,n,m))
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
                num[p2.x][p2.y] = temp;
            }
        }
    }
    return 0;
}
