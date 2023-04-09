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
int tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int x, y; cin >> x >> y;
        ll sum = 1, sum1 = 1;
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) {
                sum += i;
                if(x / i != i)sum += x / i;
            }
        }
        for(int i = 2; i * i <= y; i++) {
            if(y % i == 0) {
                sum1 += i;
                if(y / i != i)sum1 += y / i;
            }
        }
        cout << (sum1 == x && sum == y ? "Friendship is ideal" : "Friendship is not ideal") << endl;
    }


    return 0;
}
