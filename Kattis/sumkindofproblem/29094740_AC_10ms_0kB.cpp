/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
ll n , tc, x ;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> x >> n;
        ll sum = (n * (n + 1)) / 2, odd = n * n, even= n*(n+1);
        cout << x << " "<<sum << " " << odd << " " << even << endl;
    }


    return 0;
}
