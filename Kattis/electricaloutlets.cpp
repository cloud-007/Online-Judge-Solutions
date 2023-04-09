/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, ans = 0, a;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--){
        ans = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a;
            ans+=a;
        }
        --n;
        cout << ans-n << endl;
    }
    return 0;
}
