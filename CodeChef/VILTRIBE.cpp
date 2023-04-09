/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, a, b;
string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        a = b = 0;
        cin >> s;
        char last = '0';
        int pos = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A') {
                if(pos != -1) {
                    if(last == s[i]) {
                        a += (i - pos);
                    } else {
                        b++;
                    }
                }
                pos = i, last = s[i];
            } else if(s[i] == 'B') {
                if(pos != -1) {
                    if(last == s[i]) {
                        b += (i - pos);
                    } else a++;
                }
                pos = i, last = s[i];
            }
        }
        if(last == 'A')a++;
        else if(last == 'B')b++;
        cout << a << " " << b << endl;

    }

    return 0;
}
