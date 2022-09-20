/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"


const int sz = 1e5 + 10;
int n, k, q, a, mp[sz];
deque < int > dq;
char c;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> q >> k;
    set < int > st;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a)cnt++;
        else {
            if(cnt)dq.push_back(cnt), st.insert(cnt), mp[cnt]++;
            cnt = 0;
            dq.push_back(0);
        }
    }

    if(cnt)st.insert(cnt), dq.push_back(cnt), mp[cnt]++;

    if(dq.size() == 1) {
        while(q--) {
            cin >> c;
            if(c == '?')cout << min(k, dq.front()) << endl;
        }
        return 0;
    }

    while(q--) {
        cin >> c;
        if(c == '?') {
            int val = 0;
            if(st.size())
                val = *st.rbegin();
            if(val >= k)cout << k << endl;
            else cout << val << endl;
        } else {
            int bck = dq.back(), fr = dq.front();

            if(bck && fr) {
                mp[dq.back()]--;
                mp[dq.front()]--;
                if(!mp[bck])st.erase(bck);
                if(!mp[fr])st.erase(fr);
                dq.back()--;
                dq.front()++;
                mp[dq.front()]++;
                st.insert(dq.front());
                if(dq.back() == 0)dq.pop_back();
                else mp[dq.back()]++, st.insert(dq.back());

            } else if(bck) {
                mp[bck]--;
                if(!mp[bck])st.erase(bck);
                dq.push_front(1);
                mp[1]++, st.insert(1);
                dq.back()--;
                if(dq.back() == 0)dq.pop_back();
                else mp[dq.back()]++, st.insert(dq.back());
            } else {
                dq.push_front(0);
                dq.pop_back();
            }

        }
    }

    return 0;
}
