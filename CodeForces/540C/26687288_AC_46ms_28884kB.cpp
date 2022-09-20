#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define endl "\n"

const int sz = 505;
char a[sz][sz];
int dis[sz][sz], row, col, from_x, from_y, to_x, to_y, ok = 0;

bool valid(int tx, int ty)
{
    if(tx >= 0 && tx < row && ty >= 0 && ty < col && a[tx][ty] != 'X')return true;
    return false;
}

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

void dfs(int sx, int sy)
{
    for(int i = 0; i < 4; i++)
    {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(tx == to_x && ty == to_y)
        {
            if(a[tx][ty] == 'X')
            {
                ok = 2;
                return;
            }
            else
            {
                a[tx][ty] = 'X';
                ok = 1;
            }
        }
        else if(ok != 2 && valid(tx, ty))
        {
            a[tx][ty] = 'X';
            dfs(tx, ty);
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    memset(dis, 0, sizeof dis);
    cin >> row >> col;
    for(int i = 0; i < row; i++)cin >> a[i];
    cin >> from_x >> from_y >> to_x >> to_y;
    to_x--, to_y--, from_x--, from_y--;
    dfs(from_x, from_y);
    if(ok == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            int tx = to_x + fx[i], ty = to_y + fy[i];
            if(valid(tx,ty))
            {
                ok = 2;
                break;
            }
        }
    }
    puts(ok == 2 ? "YES" : "NO");
}
