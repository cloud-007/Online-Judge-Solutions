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
        vector < int > even, odd;
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            if(x & 1)odd.push_back(i);
            else even.push_back(i);
        }
        if(even.size() > 0 && even.size() % 2 == 0) {
            even.pop_back(); even.pop_back();
        } else if(odd.size() > 0 && odd.size() % 2 == 0) {
            odd.pop_back(); odd.pop_back();
        } else {
            even.pop_back(); odd.pop_back();
        }
        while(even.size()) {
            cout << even.back() << " "; even.pop_back();
            cout << even.back() << endl; even.pop_back();
        }
        while(odd.size()) {
            cout << odd.back() << " "; odd.pop_back();
            cout << odd.back() << endl; odd.pop_back();
        }
    }


    return 0;
}
