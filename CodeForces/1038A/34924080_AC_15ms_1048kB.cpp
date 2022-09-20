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
    int k; string s;
    cin >> n >> k >> s;
    map < char, int > mp;
    for(auto i : s)mp[i]++;
    vector < int > v;
    for(auto i : mp)v.push_back(i.S);
    sort(v.rbegin(), v.rend());
    if(v.size() >= k) {
        cout << k * v[k - 1] << endl;
    } else cout << 0 << endl;


    return 0;
}
