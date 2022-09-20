#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, row, col, vis[21][21], dis[21][21], x, y, casee = 1, ans;
char a[21][21];
vector < pair < int, int >> vp;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

void clr()
{
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);
    vp.clear();
}

bool valid(int tx, int ty)
{
    if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && a[tx][ty] != '#' && a[tx][ty] != 'm')
        return true;
    return false;
}

void bfs(int sx, int sy)
{
    queue < pair < int, int >> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while(!q.empty())
    {
        sx = q.front().first, sy=q.front().second, q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(valid(tx, ty))
            {
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[sx][sy] + 1;
                q.push({tx, ty});
            }
        }
    }
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
            for(int j = 1; j <= col; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'h')
                    x = i, y = j;
                else if(a[i][j] == 'a' || a[i][j] == 'b' || a[i][j] == 'c')
                    vp.push_back({i, j});
            }
        bfs(x, y);
        ans = 0;
        for(auto i : vp)
            ans = max(ans, dis[i.first][i.second]);
        cout << "Case " << casee++ << ": " << ans << endl;
    }
}
