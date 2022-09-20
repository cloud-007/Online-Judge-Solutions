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
int n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];
    int last = 0;
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        if(a[i] - 1 >= last)a[i]--;
        else if(a[i] < last) {
            ok = false;
            break;
        }
        last = a[i];
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
