/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

string s, ans = "9999999";

void permute(string str, string out) {
    if(str.size() == 0) {
        if(out > s) {
            ans = min(ans, out);
        }
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        permute(str.substr(1), out + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> s) {
        permute(s, "");
        if(ans == "9999999")ans = "0";
        cout << ans << endl;
    }


    return 0;
}
