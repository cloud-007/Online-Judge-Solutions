/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int x, y;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> x >> y;
    int id = 0, ok = false;
    if(x * 4 == y)ok = true;
    while(x) {
        int now = (y - (id * 4));
        if(now % 2 == 0 && now / 2 == x) {
            ok = true;
            break;
        }
        id++, x--;
    }
    cout << (ok ? "Yes" : "No") << endl;


    return 0;
}
