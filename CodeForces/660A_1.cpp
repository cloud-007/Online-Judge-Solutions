/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector < int > v;
    v.push_back(a[1]);
    for(int i = 2; i <= n; i++) {
        int curGcd = __gcd(a[i], a[i - 1]);
        if(curGcd == 1) {
            v.push_back(a[i]);
        } else {
            v.push_back(1);
            v.push_back(a[i]);
        }
    }
    cout << v.size() - n << endl;
    for(auto i : v)cout << i << " ";
    cout << endl;


    return 0;
}
