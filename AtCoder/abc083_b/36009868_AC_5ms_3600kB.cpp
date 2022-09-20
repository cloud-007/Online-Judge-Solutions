/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a, b;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> a >> b;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int cur = i, curSum = 0;
        while(cur) {
            curSum += cur % 10;
            cur /= 10;
        }
        if(curSum >= a && curSum <= b)sum += i;
    }
    cout << sum << endl;


    return 0;
}
