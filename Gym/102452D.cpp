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
int x, k, tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> k >> x;
        vector < int > v;
        for(int i = 10 - k; i <= 9; i++)v.push_back(i);

        n = v.size();

        string s = "";
        while(x) {
            int div = x % n;
            if(div == 0)s += (v[n - 1] + '0'), x--;
            else s += (v[div - 1] + '0');
            x /= n;
        }

        reverse(s.begin(), s.end());

        cout << s << endl;
    }


    return 0;
}
