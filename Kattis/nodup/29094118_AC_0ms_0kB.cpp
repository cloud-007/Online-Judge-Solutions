/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    string s, word;
    getline(cin, s);
    stringstream ss(s);
    int cnt = 0;
    set < string > st;
    while(ss>>word) {
        st.insert(word);
        cnt++;
    }
    cout << (st.size() == cnt ? "yes" : "no") << endl;


    return 0;
}
