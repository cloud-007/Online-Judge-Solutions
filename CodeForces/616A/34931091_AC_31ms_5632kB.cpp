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
    string x, y; cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    while(x.size() && x[x.size() - 1] == '0')x.pop_back();
    while(y.size() && y[y.size() - 1] == '0')y.pop_back();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if(x.size() > y.size())cout << ">" << endl;
    else if(x.size() < y.size())cout << "<" << endl;
    else {
        if(x < y)cout << "<" << endl;
        else if(x > y)cout << ">" << endl;
        else cout << "=" << endl;
    }


    return 0;
}
