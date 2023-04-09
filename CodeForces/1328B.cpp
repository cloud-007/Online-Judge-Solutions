/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        int total = (n * (n - 1)) / 2;

        string Ans = string(n, 'a');

        ll sum = 0;

        for(int i = n - 1, cur = 1; i >= 1; i--, ++cur) {
            sum += cur;
            if(sum >= k) {
                Ans[i - 1] = 'b';
                sum -= k;
                Ans[i + sum] = 'b';
                cout << Ans << endl;
                break;
            }
        }
    }


    return 0;
}
