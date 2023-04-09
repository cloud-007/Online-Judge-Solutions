/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc;
char c;
string s;
int ans = 0;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc >> c;
    tc *= 4;
    while(tc--) {
        cin >> s;
        if(s[1] == c) {
            if(s[0] == '7')ans += 0;
            if(s[0] == '8')ans += 0;
            if(s[0] == '9')ans += 14;
            if(s[0] == 'T')ans += 10;
            if(s[0] == 'J')ans += 20;
            if(s[0] == 'Q')ans += 3;
            if(s[0] == 'K')ans += 4;
            if(s[0] == 'A')ans += 11;
        } else {
            if(s[0] == '7')ans += 0;
            if(s[0] == '8')ans += 0;
            if(s[0] == '9')ans += 0;
            if(s[0] == 'T')ans += 10;
            if(s[0] == 'J')ans += 2;
            if(s[0] == 'Q')ans += 3;
            if(s[0] == 'K')ans += 4;
            if(s[0] == 'A')ans += 11;
        }
    }
    cout << ans << endl;


    return 0;
}
