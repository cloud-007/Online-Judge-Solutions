/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc;//, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        ll x, n; cin >> x >> n;
        ll rem = n % 4, add;
        if(rem == 1)add = -n;
        else if(rem == 2)add = 1;
        else if(rem == 3)add = n + 1;
        else add = 0;
        //if(x%2==0)
        cout << (x % 2 == 0 ? x + add : x - add) << endl;
    }


    return 0;
}
