/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

struct R
{
    int cnt, sx, sy;
    bool operator<(R a)const
    {
        return cnt > a.cnt;
    }
};
int n, m, k, vis[55][55], cnt = 0, ok = 0 ;
char c[55][55];
priority_queue < R > pq;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

void dfs(int sx, int sy, int t)
{
    if(t)c[sx][sy] = '*';
    if(!t)
        cnt++;
    vis[sx][sy] = 1;
    for(int i = 0; i < 4; i++)
    {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && c[tx][ty] == '.' && !vis[tx][ty])
        {
            if(tx == 0 || ty == 0 || tx == n - 1 || ty == m - 1)ok = 0;
            dfs(tx, ty, t);
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)cin >> c[i];
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(!vis[i][j] && c[i][j] == '.')
            {
                cnt = 0, ok = 1;
                dfs(i, j, 0);
                if(ok)
                    pq.push({cnt, i, j});
            }
        }
    }
    memset(vis, 0, sizeof vis);
    cnt = 0;
    while(!pq.empty() && pq.size() > k)
    {
        //cout << pq.top().sx << " " << pq.top().sy << " " << pq.top().cnt << endl;
        cnt += pq.top().cnt;
        dfs(pq.top().sx, pq.top().sy, 1);
        pq.pop();
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)cout << c[i][j];
        cout << endl;
    }
    return 0;
}
