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
    string s;
    cin >> n >> s;
    if(n == 1) {
        cout << 1 << endl;
        cout <<  s << endl;
    } else {
        int one = 0, zero = 0;
        for(auto i : s) {
            one += i == '1';
            zero += i == '0';
        }
        if(one != zero) {
            cout << 1 << endl;
            cout << s << endl;
            exit(0);
        }
        cout << 2 << endl;

        int newOne = 0, newZero = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                newOne++; one--;
            } else {
                newZero++, zero--;
            }
            if(newOne != newZero && one != zero) {
                cout << s.substr(0, i + 1) << " " << s.substr(i + 1, s.size()) << endl;
                exit(0);
            }
        }
    }


    return 0;
}
