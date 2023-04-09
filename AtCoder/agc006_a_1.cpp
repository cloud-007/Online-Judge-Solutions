/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) {
        string cur = x.substr(i, n);
        string temp = y.substr(0, n - i);
        if(cur == temp) {
            cout << ((i) * 2) + (n - i)  << endl;
            exit(0);
        }
    }

    cout << n *  2 << endl;


    return 0;
}