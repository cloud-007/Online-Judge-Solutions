/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, casee = 1, a[N];

int main() {
    freopen("alimagde.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> tc;
    while(tc--) {
        ll n, sum = 0;
        cin >> n;
        ll Ans = n;
        for(ll i = 1;; i++) {
            sum += i;
            if(sum > n)break;
            --Ans;
        }
        cout << Ans << endl;
    }


    return 0;
}
