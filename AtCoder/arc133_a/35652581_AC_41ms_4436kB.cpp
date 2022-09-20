/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e6 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int found = -1;
    cin >> n;
    a[n + 1] = 0;
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++) {
        if(a[i] > a[i + 1]) {
            found = a[i];
            break;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] != found)cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}
