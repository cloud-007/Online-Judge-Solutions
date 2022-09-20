/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e8;
bool status[N + 5];

void sieve() {
    status[0] = status[1] = true;
    for(int i = 4; i <= N; i += 2)status[i] = true;
    for(int i = 3; i * i <= N; i += 2) {
        if(status[i] == 0) {
            for(int j = i * i; j <= N; j += i * 2)
                status[j] = true;
        }
    }
    for(int i = 2, cnt = 1; i <= N; i++) {
        if(status[i] == 0) {
            if(cnt % 100 == 1)cout << i << endl;
            ++cnt;
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();


    return 0;
}
