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
    string t = s;
    reverse(t.begin(), t.end());
    if(s == t) {
        cout << s << endl;
        exit(0);
    }
    string Ans =  s;

    for(int i = s.size() - 1; i >= 1; i--) {
        string nxt = s.substr(0, i);
        reverse(nxt.begin(), nxt.end());
        string newString = s + nxt;
        string reversed = newString;
        reverse(reversed.begin(), reversed.end());
        if(newString == reversed)Ans = newString;
    }
    cout << Ans << endl;


    return 0;
}
