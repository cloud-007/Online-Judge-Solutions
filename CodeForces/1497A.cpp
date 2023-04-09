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
int tc, n, casee = 1, a[N], mp[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++)cin >> a[i];
        sort(a, a + n);
        vector < int > v, v1;
        for(int i = 0; i < n; i++) {
            if(mp[a[i]])v1.push_back(a[i]);
            else v.push_back(a[i]);
            mp[a[i]]++;
        }
        for(int i = 0; i < n; i++)mp[a[i]] = 0;
        for(auto i : v)cout << i << " ";
        for(auto i : v1)cout << i<<" ";
        cout << endl;
        v.clear(), v1.clear();
    }


    return 0;
}
