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
    if(s.size() == 1) {
        cout << s << endl;
        exit(0);
    }
    map <char, int>mp;
    for(auto i : s)mp[i]++;

    for(char c = 'z'; c >= 'a'; c--) {
        if(mp[c] % 2 == 0)continue;
        for(char d = 'a'; d < c; d++) {
            if(mp[d] & 1) {
                mp[d]++;
                mp[c]--;
                break;
            }
        }
    }

    string Ans = "";

    char last = '-';
    for(auto i : mp) {
        int cnt = i.S / 2;
        while(cnt--)Ans += i.F;
        if(i.S & 1)last = i.F;
    }

    string rev = Ans;
    reverse(rev.begin(), rev.end());
    if(last != '-')Ans += last;
    Ans += rev;

    cout << Ans << endl;



    return 0;
}
