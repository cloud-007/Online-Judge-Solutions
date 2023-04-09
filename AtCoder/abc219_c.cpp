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
int tc, n;
string x[N], reversed[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    map < char, char > mp, rev;
    string s; cin >> s;
    char c = 'a';
    for(auto i : s) {
        mp[i] = c;
        rev[c] = i;
        c++;
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        reversed[i] = x[i];
        for(int j = 0; j < x[i].size(); j++) {
            reversed[i][j] = mp[x[i][j]];
        }
    }
    sort(reversed + 1, reversed + n + 1);
    for(int i = 1; i <= n; i++) {
        string now = "";
        for(int j = 0; j < reversed[i].size(); j++) {
            now += rev[reversed[i][j]];
        }
        cout << now << Endl;
    }


    return 0;
}
