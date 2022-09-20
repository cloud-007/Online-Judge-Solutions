/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, dp[5][10][55];
string s;

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int rec(int idx, int vowel, int cons) {
    if(vowel >= 3 || cons >= 5)return 2;
    if(idx == n)return 1;
    int &ret = dp[vowel][cons][idx];
    if(~ret)return ret;
    ret = 0;
    if(s[idx] == '?') {
        ret = rec(idx + 1, vowel + 1, 0);
        ret |= rec(idx + 1, 0, cons + 1);
    } else if(isVowel(s[idx])) {
        ret = rec(idx + 1, vowel + 1, 0);
    } else ret = rec(idx + 1, 0, cons + 1);
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
        n = s.size();
        memset(dp, -1, sizeof dp);
        int Ans = rec(0, 0, 0);
        string out;
        if(Ans == 2)out = "BAD";
        else if(Ans == 1)out = "GOOD";
        else out = "MIXED";
        cout << "Case " << casee++ << ": " << out << endl;
    }


    return 0;
}
