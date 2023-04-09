/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int mod = 1e6 + 3;
string s, sum = "";

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> s;
    for(auto i : s) {
        ll now;
        if(i == '>')now = 1000;
        else if(i == '<')now = 1001;
        else if(i == '+')now = 1010;
        else if(i == '-')now = 1011;
        else if(i == '.')now = 1100;
        else if(i == ',')now = 1101;
        else if(i == '[')now = 1110;
        else now = 1111;
        sum += to_string(now);
    }

    ll ans = 0, n = sum.size();
   // cout <<sum<<" "<<n<<endl;
    for(auto i : sum) {
        if(i == '1') {
            ll j = 1, val = 1;
            while(j < n) {
                val *= 2;
                val %= mod;
                ++j;
            }
            ans += val;
            ans %= mod;
        }
        --n;
    }

    cout << ans << endl;


    return 0;
}
