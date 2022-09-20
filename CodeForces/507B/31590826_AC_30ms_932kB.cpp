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

double mul(double x, double y) {
    return (x - y) * (x - y);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    double r, x1, x2, y1, y2;

    cin >> r >> x1 >> y1 >> x2 >> y2;
    double dis = mul(x1, x2) + mul(y2, y1);

    dis = sqrt(dis);
    int Ans = ceil(dis / (2 * r));

    cout << Ans << endl;


    return 0;
}
