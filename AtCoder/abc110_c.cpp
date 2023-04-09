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
    map < char, int > mp1, mp2;
    map < int, int > cnt1, cnt2;
    string s, t; cin >> s >> t;
    for(auto i : s)mp1[i]++;
    for(auto i : t)mp2[i]++;
    for(auto i : mp1)cnt1[i.S]++;

    bool ok = true;
    for(auto i : mp2) {
        if(cnt1[i.S])--cnt1[i.S];
        else {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;


    return 0;
}
