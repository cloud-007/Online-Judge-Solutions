/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int len, n, a, temp_sum;
vector < int > v, ans, temp;


void rec(int idx, int cnt, int sum) {
    if(idx >= n) {
        if(sum > temp_sum) {
            temp_sum = sum;
            ans.clear();
            for(auto i : temp)ans.push_back(i);

        }
        return ;
    }
    for(idx; idx < n; idx++) {
        if(sum + v[idx] <= len && cnt<20) {
            temp.push_back(v[idx]);
            rec(idx + 1, cnt + 1, sum + v[idx]);
            temp.pop_back();
        } else {
            if(sum > temp_sum) {
                temp_sum = sum;
                ans.clear();
                for(auto i : temp)ans.push_back(i);

            }
            break;
        }
    }
    rec(idx + 1, cnt, sum);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> len) {
        temp_sum = 0;
        cin >> n;
        v.resize(n);
        for(auto &x : v)cin >> x;
        rec(0, 0, 0);
        for(auto i : ans)cout << i << " ";
        cout << "sum:" << temp_sum << endl;
    }

    return 0;
}
