/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

map < int, ordered_set > added, deleted;

const int sz = 1e5 + 5;
int tc, type, Time, value;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> type >> Time >> value;
        if(type == 1) added[value].insert(Time);
        else if(type == 2)deleted[value].insert(Time);
        else cout << added[value].order_of_key(Time) - deleted[value].order_of_key(Time) << endl;
    }



    return 0;
}
