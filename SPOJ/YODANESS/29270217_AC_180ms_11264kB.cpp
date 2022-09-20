/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set os;
const int sz = 3e4 + 5;;
int tc, n, id;
string s[sz], a[sz];
map < string, int > mp;
vector < int > x[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        os.clear(), mp.clear(), id = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            if(!mp[s[i]]) {
                mp[s[i]] = ++id;
                x[id].clear();
            }
        }
        for(int i = 0; i < n; i++)cin >> a[i];
        for(int i = n - 1; i >= 0; i--)x[mp[s[i]]].push_back(i);
        ll ans = 0;

        for(int i = 0; i < n ; i++) {
            int pos = x[mp[a[i]]].back();
            x[mp[a[i]]].pop_back();
            int id = n - 1 - i, res = os.order_of_key(pos);
            res = os.size() - res;
            os.insert(pos);
            ans += pos - id + res;
        }

        cout << ans << endl;

    }


    return 0;
}
