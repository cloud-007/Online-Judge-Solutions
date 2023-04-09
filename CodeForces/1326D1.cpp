/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, l, r;
string s, x, y;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        x = "", y = "";
        cin >> s;
        string z=s;
        reverse(z.begin(), z.end());
        if(s==z) {
            cout << s << endl;
            continue;
        }
        l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                x += s[l], y += s[r];
                l++, r--;
            } else {
                break;
            }
        }
        string temp = "", temp1, fin = "";
        for(int i = l; i < r; i++) {
            temp += s[i];
            temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            if(temp == temp1) {
                fin = temp;
            }
        }
        temp = "";
        for(int i = r; i > l; i--) {
            temp += s[i];
            temp1 = temp;
            reverse(temp1.begin(), temp1.end());
            if(temp == temp1 && temp.size() > fin.size()) {
                fin = temp;
            }
        }
        reverse(y.begin(), y.end());
        if(fin==""){

        }
        cout << x+fin+y<<endl;
    }


    return 0;
}
