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
        if(odd.size() & 1) {
            odd.pop_back();
            even.pop_back();
        } else {
            if(even.size() >= 2) {
                even.pop_back();
                even.pop_back();
            } else {
                odd.pop_back();
                odd.pop_back();
            }
        }
        for(int i = 0; i < odd.size(); i += 2) {
            cout << odd[i] << " " << odd[i + 1] << endl;
        }
        for(int i = 0; i < even.size(); i += 2) {
            cout << even[i] << " " << even[i + 1] << endl;
        }
    }


    return 0;
}
