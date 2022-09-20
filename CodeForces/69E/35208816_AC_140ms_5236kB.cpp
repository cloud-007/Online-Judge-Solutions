/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k = 1, a[N];
set < int > st;
map < int, int > mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i <= k) {
            mp[a[i]]++;
            if(mp[a[i]] == 1)st.insert(a[i]);
            else if(st.count(a[i]))st.erase(a[i]);
        }
    }
    if(st.size())cout << *st.rbegin() << endl;
    else cout << "Nothing" << endl;
    for(int i = 1, j = k + 1; j <= n; j++, i++) {
        mp[a[i]]--;
        if(mp[a[i]] == 1)st.insert(a[i]);
        else if(st.count(a[i]))st.erase(a[i]);

        mp[a[j]]++;
        if(mp[a[j]] == 1)st.insert(a[j]);
        else if(st.count(a[j]))st.erase(a[j]);

        if(st.size())cout << *st.rbegin() << endl;
        else cout << "Nothing" << endl;
    }

    return 0;
}
