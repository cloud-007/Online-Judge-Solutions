/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define pi acos(-1.0)

int tc, n, k, dp[100005][25], ok = 0;
vector < int > v;

void rec(int val, int k) {
    //cout<<val<<" "<<k<<endl;
    if(ok)return;
    if(k == 0 && val == n) {
        ok = true;
        return;
    }
    if(~dp[val][k])return;

    for(int i = 2;; i++) {
        if(!ok && k && (ll)val * i <= n) {
            v.push_back(i);
            rec(val * i, k - 1);
            if(!ok) {
                v.pop_back();
            }
        }else{
            break;
        }
    }
    dp[val][k] = 1;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    rec(1, k);
    if(ok) {
        //cout << v.size() << endl;
        for(auto i : v)cout << i << " ";
    } else cout << -1 << endl;
    return 0;
}
