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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        ll s; cin >> s;
        ll root = ceil(sqrt(s * 1.0));
        ll baki = root * root - s;
        ll row, column;
        if(baki < root) {
            row = root;
            column = baki + 1;
        } else {
            column = root;
            row = s - (root - 1) * (root - 1);
        }
        if(root % 2 == 0) {
            swap(row, column);
        }
        cout << "Case " << casee++ << ": " << column << " " << row << endl;
    }


    return 0;
}
