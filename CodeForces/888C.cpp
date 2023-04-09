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
string s;
set < int > x[30];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> s;

    for(int i = 0; i < s.size(); i++)x[s[i] - 'a'].insert(i);

    int Ans = INT_MAX;

    for(char c = 'a'; c <= 'z'; c++) {
        int pre = -1, mx = -INT_MAX;
        for(auto j : x[c - 'a']) {
            if(pre == -1)mx = max(mx, j + 1);
            else mx = max(mx, j - pre);
            pre = j;
        }
        mx = max(mx, (int)s.size() - pre);
        if(mx != -INT_MAX)Ans = min(Ans, mx);
    }

    cout << Ans << endl;


    return 0;
}
