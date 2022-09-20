/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int v, a, b, c;
    cin >> v >> a >> b >> c;
    v %= (a + b + c);
    if(a > v) {
        cout << "F" << endl;
        exit(0);
    }
    v -= a;
    if(b > v) {
        cout << "M" << endl;
        exit(0);
    }
    v -= b;
    if(c > v) {
        cout << "T" << endl;
        exit(0);
    }


    return 0;
}
