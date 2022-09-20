/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int a, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> a >> b) {
        if(a == 0 && b == 0) {
            return 0;
        }
        int res = a / b;
        a -= (res * b);
        cout << res << " " << a << " / " << b << endl;
    }


    return 0;
}
