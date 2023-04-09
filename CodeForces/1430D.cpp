/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, cnt;
string s;
deque < int > v;
deque < pair < int, int >> pos;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        v.clear(), pos.clear();
        cin >> n >> s;
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1])cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        for(int i = 0; i < v.size(); i++) {
            if(v[i] > 1) {
                pos.push_back({v[i], i});
            }
        }

        int ans = 0, len = v.size();
        for(int i = 0; i < len; i++) {
            ans++;
            if(v[i] == 1) {
                while(pos.size() && pos.front().S < i)pos.pop_front();
                if(pos.size()) {
                    v[pos.front().S]--;
                    int val = pos.front().F, id = pos.front().S;
                    pos.pop_front();
                    if(val - 1 > 1) {
                        pos.push_front({val - 1, id});
                    }
                }else len--;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
