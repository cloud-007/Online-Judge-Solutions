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
int tc, n, k,  a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    if(k == n)cout << "-1" << endl;
    else {
        k = n - k;
        int i;
        if(k % 2 == 0)i = 1;
        else i = 2, --k;
        for(int i = 1; i <= n; i++)a[i] = i;
        for(i; i < n && k; i += 2, k -= 2) {
            swap(a[i], a[i + 1]);
        }
        for(int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    }


    return 0;
}
