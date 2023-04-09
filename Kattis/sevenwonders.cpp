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
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    map < char, int > mp;
    string s;
    cin >> s;
    for(auto i : s)mp[i]++;
    int ans = 0;
    if(mp.size() == 3){
        int mn = INT_MAX;
        for(auto i : mp)mn=min(mn, i.S);
        ans=mn*7;
    }
    for(auto i : mp) {
        ans += pow(i.S, 2);
    }

    cout << ans << endl;


    return 0;
}
