/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, l, x, y, a[100005], done_x = 0, done_y = 0;
map < int, int > mp;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> l >> x >> y;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if(mp[x])done_x = 1;
        if(mp[y])done_y = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mp[a[i] + x])done_x = 1;
        if(mp[a[i] + y])done_y = 1;
    }
    if(done_x && done_y)
    {
        cout << 0 << endl;
        return 0;
    }
    else if(done_x)
    {
        cout << "1\n" << y << endl;
    }
    else if(done_y)
    {
        cout << "1\n" << x << endl;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] + x <= l && (mp[a[i] + x - y] || mp[a[i] + x + y]))
            {
                cout << 1 << endl;
                cout << a[i] + x << endl;
                return 0;
            }
            if(a[i] + y <= l && (mp[a[i] + y - x] || mp[a[i] + x + y]))
            {
                cout << 1 << endl;
                cout << a[i] + y << endl;
                return 0;
            }
            if(a[i] - x >=0 && (mp[a[i] - x - y] || mp[a[i] - x + y]))
            {
                cout << 1 << endl;
                cout << a[i] - x << endl;
                return 0;
            }
            if(a[i] - y >=0 && (mp[a[i] - y - x] || mp[a[i] - x + y]))
            {
                cout << 1 << endl;
                cout << a[i] - y << endl;
                return 0;
            }
        }
        cout << 2 << endl;
        cout << x << " " << y << endl;
    }
    return 0;
}
