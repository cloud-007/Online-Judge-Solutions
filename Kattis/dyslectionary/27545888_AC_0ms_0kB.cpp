/*One touch and i IGNITE*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

string s;
vector < string > v;
int mx = 0;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;

    while(getline(cin, s)) {
        if(s.size() == 0) {
            sort(v.begin(), v.end());
            for(auto i : v) {
                s = i;
                reverse(s.begin(), s.end());
                for(int i = 0; i < mx - s.size(); i++)cout << " ";
                cout << s << endl;
            }
            cout << endl;
            mx = 0;
            v.clear();
        } else {
            reverse(s.begin(), s.end());
            v.push_back(s);
            mx = max(mx, (int)s.size());
        }
    }
    sort(v.begin(), v.end());
    for(auto i : v) {
        s = i;
        reverse(s.begin(), s.end());
        for(int i = 0; i < mx - s.size(); i++)cout << " ";
        cout << s << endl;
    }

    return 0;
}
