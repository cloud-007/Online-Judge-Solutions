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
    string s;
    cin >> n >> s;
    int S = 0, F = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'S' && s[i + 1] == 'F')S++;
        else if(s[i] == 'F' && s[i + 1] == 'S')F++;
    }
    cout << (S > F ? "YES" : "NO") << endl;

    return 0;
}
