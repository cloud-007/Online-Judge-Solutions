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
    string s; cin >> s;
    int i = 0, j = s.size() - 1;
    int Ans = 0;
    while(i <= j) {
        Ans += (s[i] != s[j]);
        ++i; --j;
    }
    cout << Ans << endl;


    return 0;
}
