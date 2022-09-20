/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    string a, b; cin >> a >> b;
    if(a == "0" || b == "0")cout << 0 << endl;
    else {
        int s_a = 0, s_b = 0;
        string digit_a = "0", digit_b = "0";
        for(auto i : a) {
            if(i == 'S')s_a++;
            else if(i >= '0' && i <= '9')digit_a += i;
        }
        for(auto i : b) {
            if(i == 'S')s_b++;
            else if(i >= '0' && i <= '9')digit_b += i;
        }
        s_a *= s_b;
        s_b = s_a;
        while(s_a--) {
            cout << "S(";
        }
        cout << stoi(digit_a) + stoi(digit_b);
        while(s_b--)cout << ")";
        cout << endl;
    }

    return 0;
}
