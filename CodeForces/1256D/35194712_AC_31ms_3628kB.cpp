/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, k, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        string s; cin >> n >> k >> s;
        int firstZero = 0;
        for(int i = 0; i < n && k > 0; i++) {
            if(s[i] == '1')continue;
            int distance = i - firstZero;
            int minSwap = min(k, (ll)distance);
            swap(s[i], s[i - minSwap]);
            ++firstZero; k -= minSwap;
        }
        cout << s << endl;
    }


    return 0;
}
