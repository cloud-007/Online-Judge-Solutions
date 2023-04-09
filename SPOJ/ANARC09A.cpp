/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
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
    To_Infinity_And_Beyond;
    string s;
    while(cin >> s && s[0] != '-') {
        int st = 0, Ans = 0;
        for(auto i : s) {
            if(i == '{')st++;
            else {
                if(st)st--;
                else {
                    st++, Ans++;
                }
            }
        }
        Ans += st / 2;
        cout << casee++ << ". " << Ans << endl;
    }


    return 0;
}
