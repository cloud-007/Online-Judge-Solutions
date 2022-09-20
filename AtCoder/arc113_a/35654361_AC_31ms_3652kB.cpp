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
    cin >> n;
    int Ans = 0;
    for(int i = 1; i <= n; i++) {
        int rem = n / i;
        for(int j = 1; j <= rem; j++) {
            int rem1 = rem / j;
            for(int k = 1; k <= rem1; k++) {
                if(i * j * k <= n)++Ans;
                else cout << "found" << Endl;
            }
        }
    }

    cout << Ans << endl;


    return 0;
}
