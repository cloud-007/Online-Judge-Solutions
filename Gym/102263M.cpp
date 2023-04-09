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
    map < char, int > mp;
    for(auto i : s)mp[i]++;

    for(char c = 'a'; c < 'z'; c++) {
        int add = mp[c] / 2;
        mp[c + 1] += add;
        mp[c] & 1 ? mp[c] = 1 : mp[c] = 0;
    }

    string Ans = "";

    for(char c='z';c>='a';c--){
        int total = mp[c];
        while(total>0){
            Ans += c; --total;
        }
    }

    cout << Ans << endl;


    return 0;
}
