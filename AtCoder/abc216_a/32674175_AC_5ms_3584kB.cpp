/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    string s, x;
    cin >> s;
    int i = 0, sz = s.size() - 1;
    while(s[i] != '.')x += s[i++];
    cout<<x;
    if(s[sz] >= '0' && s[sz] <= '2')cout << "-" << endl;
    else if(s[sz] >= '7' && s[sz] <= '9')cout << "+" << endl;



    return 0;
}
