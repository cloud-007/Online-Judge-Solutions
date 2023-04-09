/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define i64 int64_t

int n, a, cnt = 0, ans = 0, id = 0;
vector < int > x[43];
int arr[] = {4, 8, 15, 16, 23, 42};

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        x[a].push_back(i);
    }
    for(int i = 0; i < 6; i++)reverse(x[arr[i]].begin(), x[arr[i]].end());
    int last = 0;
    while(true) {
        if(x[arr[id]].empty())break;
        if(arr[id] == 4)last = 0;
        while(x[arr[id]].size() && x[arr[id]].back() <= last)x[arr[id]].pop_back();
        if(x[arr[id]].empty())break;
        last = x[arr[id]].back();
        x[arr[id]].pop_back();
        cnt++, id++;
        if(cnt == 6)ans++, cnt = 0;
        if(id > 5)id = 0;
    }
    cout << n - (ans * 6) << endl;
}
