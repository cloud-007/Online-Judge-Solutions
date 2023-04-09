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
    cin >> n;
    if(n <= 2)cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        if(n & 1)cout << n - 1 << " ";
        else cout << n - 2 << " ";

        if(n & 1) {
            for(int i = 1; i <= n; i++) {
                if(i == (n + 1) / 2)continue;
                cout << i << " ";
            }
            cout << endl;
            cout << 1 << " " << (n + 1) / 2 << endl;
        } else {
            for(int i = 2; i < n; i++)cout << i << " ";
            cout << endl;
            cout << 2 << " " << 1 << " " << n << endl;
        }

    }

//    1 2 3 4 5 6
//    1 2 3 4 5 6 7

    return 0;
}
