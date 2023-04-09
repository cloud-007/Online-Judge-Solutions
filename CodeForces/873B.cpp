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
    string s; cin >> n >> s;
    map<int, int>mp;
    mp[0] = -1;
    int Ans = 0, sum = 0;
    for(int j = 0; j < n; j++) {
        char i = s[j];
        if(i == '0')sum--;
        else sum++;
        if(mp.count(sum))Ans = max(Ans, j - mp[sum]);
        else mp[sum] = j;
    }
    cout << Ans << endl;


    return 0;
}
