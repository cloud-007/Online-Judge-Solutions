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
ll tc, n, x, y, sum[sz], even[sz], odd[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    for(int i = 1, j = 1, k = 1; i < sz; i++) {
        sum[i] = sum[i - 1];
        sum[i] += i;
        if(i & 1) {
            odd[j] = odd[j - 1];
            odd[j] += i;
            j++;
        } else {
            even[k] = even[k - 1];
            even[k] += i;
            k++;
        }
    }
    cin >> tc;
    while(tc--) {
        cin >> n >> x;
        cout << n << " " << sum[x] << " " << odd[x] << " " << even[x] << endl;
    }


    return 0;
}
