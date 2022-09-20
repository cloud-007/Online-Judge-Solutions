/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> m;
    vector < int > a(n);
    for(auto &x : a)cin >> x;
    sort(a.begin(), a.end());

    int Ans = 0;

    for(auto i : a) {
        Ans += n - (upper_bound(a.begin(), a.end(), i) - a.begin()) ;
    }
    cout << Ans << endl;


    return 0;
}
