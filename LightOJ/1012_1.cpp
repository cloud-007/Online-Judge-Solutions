#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, row, col, vis[21][21], x, y, casee = 1;
char a[21][21];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty)
{
    if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && a[tx][ty] != '#')
        return true;
    return false;
}

int dfs(int sx, int sy)
{
    int ans = 1;
    vis[sx][sy] = 1;
    for(int i = 0; i < 4; i++)
    {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(valid(tx, ty))
        {
            ans += dfs(tx, ty);
        }
    }
    return ans;
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
        memset(vis, 0, sizeof vis);
        cin >> col >> row;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == '@')
                    x = i, y = j;
            }
        cout << "Case " << casee++ << ": " << dfs(x, y) << endl;
    }
}

