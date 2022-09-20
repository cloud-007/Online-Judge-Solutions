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
    cin >> tc;
    while(tc--) {
        string s; cin >> n >> s;
        string temp = s;
        sort(temp.begin(), temp.end());
        int Ans = 0;
        for(int i = 0; i < n; i++) {
            Ans += (temp[i] != s[i]);
        }
        cout << Ans << endl;
    }


    return 0;
}
