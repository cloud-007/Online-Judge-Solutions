/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, w, a, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> w >> a >> b;
    if(a>b)swap(a, b);
    int ra = a + w, ans;
    if(b >= a && b <= ra)ans = 0;
    else if(b > ra)ans = abs(ra - b);
    else ans = abs(a - b);
    cout << ans << endl;


    return 0;
}
