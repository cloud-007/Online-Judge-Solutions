/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string s; cin >> s;
    int Ans = 0;
    for(int i = 2; i < s.size(); i += 2) {
        int cur = s.size() - i;
        cur /= 2;
        string one = s.substr(0, cur);
        string two = s.substr(cur, cur);
        if(one == two)Ans = max(cur*2, Ans);
    }
    cout << Ans << endl;


    return 0;
}
