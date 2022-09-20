/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, a[1005];
ll sum = 0, mx_sum = -1, mx_id = -1;

void solve_left(int idx, int last, int fin) {
    while(idx >= 1) {
        last = min(last, a[idx]);
        if(fin)a[idx] = last;
        sum += last;
        idx--;
    }
}

void solve_right(int idx, int last, int fin) {
    while(idx <= n) {
        last = min(last, a[idx]);
        if(fin)a[idx] = last;
        sum += last;
        idx++;
    }
}

void solve(int id, int wo) {
    sum = a[id];
    if(!wo) {
        if(id > 1)solve_left(id - 1, a[id], 0);
        if(id < n)solve_right(id + 1, a[id], 0);
        if(sum > mx_sum) {
            mx_sum = sum;
            sum = 0;
            mx_id = id;
        }
    } else {
        if(id > 1)solve_left(id - 1, a[id], 1);
        if(id < n)solve_right(id + 1, a[id], 1);
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++)solve(i, 0);

    solve(mx_id, 1);

    for(int i=1;i<=n;i++)cout<<a[i]<<" ";


    return 0;
}
