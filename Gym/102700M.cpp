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
string s, temp, ans = "";
set < int > x[sz];
int n;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> s;
    for(int i = 0; i < s.size(); i++)x[s[i] - 'a'].insert(i);
    cin >> n;
    while(n--) {
        cin >> temp;
        ans = "";
        int last = -1;
        for(auto i : temp) {
            auto pos = x[i - 'a'].lower_bound(last);
            if(pos == x[i - 'a'].end())break;
            ans += i;
            last = *pos + 1;
        }
        if(ans.empty())ans = "IMPOSSIBLE";
        cout << ans << endl;
    }

    return 0;
}
