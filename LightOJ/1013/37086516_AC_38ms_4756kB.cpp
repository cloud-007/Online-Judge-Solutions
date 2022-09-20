/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 60 + 5;
int tc, n, casee = 1, a[N];
pair < int, ll > dp[N][N][N];
string x, y;

pair < int, ll > rec(int i, int j, int cnt) {
    if(i >= x.size() && j >= y.size()) {
        return {cnt, 1};
    }
    pair < int, ll > &ret = dp[i][j][cnt];
    if(~ret.F)return ret;
    ret.F = INT_MAX;
    if(i < x.size() && j < y.size()) {
        if(x[i] == y[j]) {
            ret = rec(i + 1, j + 1, cnt + 1);
        } else {
            pair < int, ll > one = rec(i + 1, j, cnt + 1);
            pair < int, ll > two = rec(i, j + 1, cnt + 1);
            if(one.F < two.F)ret = one;
            else if(one.F > two.F)ret = two;
            else {
                ret = {one.F, one.S + two.S};
            }
        }
    } else if(i < x.size()) {
        ret = rec(i + 1, j, cnt + 1);
    } else {
        ret = rec(i, j + 1, cnt + 1);
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
        cin >> x >> y;
        for(int i = 0; i <= 60; i++) {
            for(int j = 0; j <= 60; j++) {
                for(int k = 0; k <= 60; k++) {
                    dp[i][j][k].F = dp[i][j][k].S = -1;
                }
            }
        }
        pair < int, ll > Ans = rec(0, 0, 0);
        cout << "Case " << casee++ << ": " << Ans.F << " " << Ans.S << endl;
    }


    return 0;
}
