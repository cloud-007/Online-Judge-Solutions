/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    int n = 5, id = 1, mx = 0;
    for(int i = 1; i <= n; i++) {
        int x, sum = 0;
        int tot = 4;
        while(tot--) {
            cin >> x;
            sum += x;
        }
        if(mx < sum) {
            mx = sum, id = i;
        }
    }

    cout << id << " " << mx << endl;


    return 0;
}
