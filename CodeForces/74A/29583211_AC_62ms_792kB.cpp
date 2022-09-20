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
int tc, n, a[sz], suc, unsuc;
string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    int mx = -INT_MAX;
    string ans = "";
    while(n--) {
        cin >> s >> suc >> unsuc;
        int sum = suc * 100 - (unsuc * 50);
        for(int i = 1; i <= 5; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum > mx) {
            mx = sum;
            ans = s;
        }

    }
    cout << ans << endl;


    return 0;
}
