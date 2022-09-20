/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, casee = 1;
string a, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> a >> b;
        int l = a.size(), r = b.size();
        if(a.size() < b.size())for(int i = 0; i < r - l; i++)a = '0' + a;
        else if(a.size() > b.size())for(int i = 0; i < l - r; i++)b = '0' + b;
        string ans = "";
        // cout<<a<<" "<<b<<endl;
        for(int i = a.size() - 1; i >= 0; i--) {
            int num = (a[i] - '0') + (b[i] - '0');
            ans += (num % 10) + '0';
        }
        reverse(ans.begin(), ans.end());
        deque < char > dq;
        for(auto i : ans)dq.push_back(i);
        while(dq.size() && dq.front() == '0')dq.pop_front();
        if(dq.empty())dq.push_back('0');
        for(auto i : dq)cout << i;
        cout << endl;
    }


    return 0;
}
