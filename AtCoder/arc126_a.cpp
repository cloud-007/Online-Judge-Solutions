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
int tc, n, casee = 1, a[N];
ll two, three, four;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> two >> three >> four;

        ll minFourThree = min(three / 2, four);
        ll Ans = minFourThree; three -= minFourThree * 2; four -= minFourThree;

        ll minFourTwo = min(four / 2, two);
        Ans += minFourTwo; four -= minFourTwo * 2; two -= minFourTwo;

        ll minThreeTwo = min(three / 2, two / 2);
        Ans += minThreeTwo; three -= minThreeTwo * 2; two -= minThreeTwo * 2;

        minFourTwo = min(four, two / 3);
        Ans += minFourTwo; two -= minFourTwo * 3;

        Ans += two / 5;

        cout << Ans << endl;
    }


    return 0;
}
