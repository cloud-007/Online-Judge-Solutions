/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, x, a[100005], mp[100005], ans = -1;
map < int, int > mm;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> a[i], mp[a[i]]++, mp[a[i]] > 1 ? ans = 0 : ans;
    if(~ans)cout << ans << endl;
    else
    {
        for(int i = 1; i <= n; i++)
        {
            int now = a[i];
            mp[now]--;
            if(mp[now & x])
            {
                ans = 1;
                break;
            }
            else if(mm[now & x])
            {
                ans =  2;
            }
            mm[now & x]++;
            mp[now]++;
        }
        cout << ans << endl;
    }
    return 0;
}
