/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int x; cin >> n >> x;
    for(int i=1;i<=n;i++)cin >> a[i];
    ll sum = 0,Ans = 0;
    for(int i=1;i<=n;i++){
        if(sum + a[i]>x){
            int del = sum + a[i] - x;
            Ans += del;
            a[i] = max(0ll, a[i] - del);
        }
        sum = a[i];
    }

    cout << Ans << endl;


    return 0;
}
