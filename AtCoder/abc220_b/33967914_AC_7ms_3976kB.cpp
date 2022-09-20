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
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    string a, b;
    int k; cin >> k >> a >> b;
    ll Ans = 0, Ans1 = 0;
    for(int j = a.size() - 1, i = 0; i < a.size(); i++, j--) {
        int now = a[i] - '0';
        Ans += now * pow(k, j);
    }
    for(int j = b.size() - 1, i = 0; i < b.size(); i++, j--) {
        int now = b[i] - '0';
        Ans1 += now * pow(k, j);
    }

    cout << Ans*Ans1 << endl;


    return 0;
}
