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
int tc, n, a[N], casee = 1;
map < int, int > mp;
int Find(int x) {
    int l = 1, r = n, Ans = - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] < x)l = mid + 1;
        else if(a[mid] > x)r = mid - 1;
        else Ans = mid, r = mid - 1;
    }
    return Ans;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    int q;
    while(cin >> n >> q && (n || q)) {
        for(int i = 1; i <= n; i++)cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            if(!mp[a[i]]) mp[a[i]] = i;
        }
        cout << "CASE# " << casee++ << ":" << endl;
        while(q--) {
            int x; cin >> x;
            int Ans = Find(x);
            cout << x << " ";
            if(mp[x])cout << "found at " << mp[x] << endl;
            else cout << "not found" << endl;
        }
        mp.clear();
    }


    return 0;
}
