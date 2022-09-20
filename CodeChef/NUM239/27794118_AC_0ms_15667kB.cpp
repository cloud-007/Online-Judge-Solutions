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
int tc, l, r, mp[sz];

void init() {
    for(int i = 1; i < sz; i++) {
        if(i % 10 == 2 || i % 10 == 3 || i % 10 == 9)mp[i]++;
    }
    for(int i = 1; i < sz; i++)mp[i] += mp[i - 1];
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    init();
    cin >> tc;
    while(tc--) {
        cin >> l >> r;
        cout << mp[r] - mp[l - 1] << endl;
    }

    return 0;
}
