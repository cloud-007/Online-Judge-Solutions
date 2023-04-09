/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, same = 0, diff = 0;
string a, b;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> a >> b;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[i])same++;
        else diff++;
    }
    int ans = min(n, same);
    if(n != ans)
    {
        diff -= abs(ans - n);
    }
    ans += diff;
    cout << ans << endl;
}
