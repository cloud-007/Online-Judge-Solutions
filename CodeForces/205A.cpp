/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int Ans = -1, mn = INT_MAX;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < mn) {
            mn = a[i];
            Ans = i;
        } else if(a[i] == mn) {
            Ans = -1;
        }
    }

    cout << (Ans != -1 ? to_string(Ans) : "Still Rozdil") << endl;


    return 0;
}
