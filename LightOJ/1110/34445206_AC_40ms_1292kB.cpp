/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, m, casee = 1;
bool vis[N][N];
string Ans[N][N], a, b, retVal;

string rec(int i, int j) {
    if(i >= n || j >= m) {
        return "";
    }
    if(vis[i][j])return Ans[i][j];
    vis[i][j] = true;
    string ret = "";
    if(a[i] == b[j]) {
        ret += a[i];
        ret += rec(i + 1, j + 1);
    } else {
        string ret1 = rec(i + 1, j);
        string ret2 = rec(i, j + 1);
        if(ret1.size() > ret2.size())ret = ret1;
        else if(ret1.size() < ret2.size()) ret = ret2;
        else ret = min(ret1, ret2);
    }
    Ans[i][j] = ret;
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;

    for(int i = 0; i < N; i++)retVal += "z";

    cin >> tc;
    while(tc--) {

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                vis[i][j] = false;
                Ans[i][j] = "";
            }
        }

        cin >> a >> b;
        n = a.size(), m = b.size();

        string finalAnswer = rec(0, 0);
        if(finalAnswer.empty())finalAnswer = ":(";

        cout << "Case " << casee++ << ": " << finalAnswer << endl;

    }


    return 0;
}
