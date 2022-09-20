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
int tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        string s, x; cin >> s >> x;
        map < char, int > mp;
        for(int i = 0; i < s.size(); i++)mp[s[i]] = i;
        int pre = -1, Ans = 0;
        for(auto i : x) {
            if(~pre)Ans += abs(mp[i] - pre);
            pre = mp[i];
        }
        cout << Ans << endl;
    }


    return 0;
}
