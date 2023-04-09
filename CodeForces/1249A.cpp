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
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        sort(a+1, a+n+1);
        int Ans = 1;
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]==1)Ans = 2;
        }
        cout << Ans << endl;
    }


    return 0;
}
