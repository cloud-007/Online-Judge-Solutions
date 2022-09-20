/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 50 + 5;
int tc, n, casee = 1, dp[N][4][6];
string s;

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int rec(int idx, int vowel, int con) {
    if(vowel >= 3 || con >= 5)return 1;
    if(idx > n)return 2;
    int &ret = dp[idx][vowel][con];
    if(~ret)return ret;
    ret = 0;
    if(s[idx] == '?') {
        ret |= rec(idx + 1, vowel + 1, 0);
        ret |= rec(idx + 1, 0, con + 1);
    } else if(isVowel(s[idx])) {
        ret |= rec(idx + 1, vowel + 1, 0);
    } else {
        ret |= rec(idx + 1, 0, con + 1);
    }
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> s;
        n = s.size(); s = "#" + s;
        memset(dp, -1, sizeof dp);
        int Ans = rec(1, 0, 0);
        string put;
        if(Ans == 3)put = "MIXED";
        else if(Ans == 2)put = "GOOD";
        else put = "BAD";
        cout << "Case " << casee++ << ": " << put << Endl;
    }


    return 0;
}
