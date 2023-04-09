/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 105;
int x, n, a;
unordered_map < int, int > mp;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> x >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        mp[a] = 1;
    }
    int l = x, r = x;
    while(true){
        if(!mp[l]){
            cout << l << endl;
            return 0;
        }if(!mp[r]){
            cout<<r<<endl;
            return 0 ;
        }
        --l, ++r;
    }


    return 0;
}
