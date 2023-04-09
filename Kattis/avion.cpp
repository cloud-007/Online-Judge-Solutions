/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, x, y;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    tc = 5;
    string s;
    vector < int > v;
    for(int k = 1; k <= tc; k++) {
        cin >> s;
        for(int i = 0; i < s.size() - 2; i++) {
            if(s[i] == 'F' && s[i + 1] == 'B' && s[i + 2] == 'I') {
                v.push_back(k);
                break;
            }
        }
    }
    if(v.empty())cout << "HE GOT AWAY!" << endl;
    else for(auto i : v)cout << i << " ";


    return 0;
}
