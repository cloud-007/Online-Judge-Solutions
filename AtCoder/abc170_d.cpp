/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e6 + 5;
int n, a[200005], mp[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }


    int Ans = 0;
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                int one = j, two = a[i] / j;
                if(mp[one] && one != a[i]) {
                    ok = false;
                    break;
                } else if(one == a[i] && mp[one] > 1) {
                    ok = false;
                    break;
                }
                if(mp[two] && two != a[i]) {
                    ok = false;
                    break;
                } else if(two == a[i] && mp[two] > 1) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok)Ans++;

    }
    cout << Ans << endl;


    return 0;
}
