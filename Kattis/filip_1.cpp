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

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    string a, b;
    cin >>a  >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a>b)cout<<a<<endl;
    else cout<<b<<endl;

    return 0;
}
