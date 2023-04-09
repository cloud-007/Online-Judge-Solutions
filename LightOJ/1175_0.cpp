#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define endl "\n"

int ans, tc, n, row, col, vis[201][201], casee = 1, x, y;
char a[201][201];
queue < pair < int, int >> fire, jane, new_jane, new_fire;

void clr()
{
    memset(vis, 0, sizeof vis);
    while(!fire.empty())fire.pop();
    while(!jane.empty())jane.pop();
    while(!new_jane.empty())new_jane.pop();
    while(!new_fire.empty())new_fire.pop();
}

bool valid(int tx, int ty)
{
    if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && a[tx][ty] != '#')return true;
    return false;
}

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int bfs(int sx, int sy)
{
    int tx, ty;
    jane.push({sx, sy});
    vis[sx][sy] = 1;
    while(!jane.empty())
    {
        while(!fire.empty())
        {
            sx = fire.front().first, sy = fire.front().second, fire.pop();
            for(int i = 0; i < 4; i++)
            {
                tx = sx + fx[i], ty = sy + fy[i];
                if(valid(tx, ty))
                {
                    vis[tx][ty] = 1;
                    new_fire.push({tx, ty});
                }
            }
        }
        while(!new_fire.empty())
        {
            fire.push({new_fire.front().first, new_fire.front().second});
            new_fire.pop();
        }
        while(!jane.empty())
        {
            sx = jane.front().first, sy = jane.front().second, jane.pop();
            if(sx==1 || sy==1 || sx==row || sy==col)
                return vis[sx][sy];
            for(int i = 0; i < 4; i++)
            {
                tx = sx + fx[i], ty = sy + fy[i];
                if(valid(tx, ty))
                {
                    vis[tx][ty] = vis[sx][sy] + 1;
                    new_jane.push({tx, ty});
                }
            }
        }
        while(!new_jane.empty())
        {
            jane.push({new_jane.front().first, new_jane.front().second});
            new_jane.pop();
        }
    }
    return 0;
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--)
    {
        clr();
        cin >> row >> col;
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'F')
                {
                    fire.push({i, j});
                    vis[i][j] = 1;
                }
                else if(a[i][j] == 'J')
                {
                    x = i, y = j;
                }
            }
        }
        ans = bfs(x,y);
        if(ans)
        cout << "Case " << casee++ << ": " << ans << endl;
        else cout<<"Case "<<casee++<<": IMPOSSIBLE"<<endl;
    }
}
