/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string s; cin >> s >> k;
    vector < string > v;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; i + j < s.size() && j <= 5; j++) {
            string newString = s.substr(i, j + 1);
            v.push_back(newString);
        }
    }
    sort(v.begin(), v.end());

    auto ip = unique(v.begin(), v.end());

    v.resize(distance(v.begin(), ip));

    cout << v[k - 1] << endl;


    return 0;
}
