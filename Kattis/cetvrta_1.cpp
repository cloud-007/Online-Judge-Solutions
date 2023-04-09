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
int tc, n, x, y;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    tc = 3;
    map < int, int > mp, mp1;
    while(tc--) {
        cin >> x >> y;
        mp[x]++, mp1[y]++;
    }
    for(auto i : mp){
        if(i.S&1){
            cout<<i.F<<" ";
            break;
        }
    }

    for(auto i : mp1){
        if(i.S&1){
            cout<<i.F<<endl;
            break;
        }
    }


    return 0;
}
