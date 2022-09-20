/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        bool inc = a[2] > a[1];
        int i = 1;
        vector < int > v;
        while(i < n) {
            v.push_back(a[i]);
            if(inc) {
                while(i < n && a[i] < a[i + 1])++i;
            } else {
                while(i < n && a[i] > a[i + 1])++i;
            }
            inc = !inc;
        }
        v.push_back(a[n]);
        cout << v.size() << endl;
        for(auto i : v)cout << i <<" ";
        cout << endl;
    }


    return 0;
}
