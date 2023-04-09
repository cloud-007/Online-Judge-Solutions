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
    int st = 0;
    for(auto i : s) {
        if(i == ')') {
            if(st)--st;
            else {
                cout << "No" << endl;
                exit(0);
            }
        } else st++;
    }
    if(st)cout << "No" << endl;
    else cout << "Yes" << endl;


    return 0;
}
