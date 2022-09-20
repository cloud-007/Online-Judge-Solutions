/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        string s; cin >> s;
        int last = -1, ok = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                if(~last && i-last>1)ok=false;
                last = i;
            }
        }
        cout << (ok && ~last ? "YES" : "NO") << endl;
    }


    return 0;
}
