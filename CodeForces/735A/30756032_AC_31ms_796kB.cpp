/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, k, a[sz];
string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    bool ok = false;
    cin >> n >> k >> s;
    int g, t;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'G')g = i;
        else if(s[i] == 'T')t = i;
    }

    int i = g;
    while(i < n) {
        if(s[i] == 'T')ok = true;
        if(i + k < n && s[i + k] != '#') {
            i += k;
        } else break;
    }
    i = g;
    while(i >= 0) {
        if(s[i] == 'T')ok = true;
        if(i - k >= 0 && s[i - k] != '#') {
            i -= k;
        } else break;
    }

    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
