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
    if(s.size() == 1) {
        cout << 0 << endl;
        exit(0);
    }
    int cnt = 0;
    for(auto i : s)cnt += i == '1';
    int Ans = (s.size() - 1) / 2 + 1;
    if(cnt == 1 && s.size() & 1)Ans--;

    cout << Ans << endl;


    return 0;
}
