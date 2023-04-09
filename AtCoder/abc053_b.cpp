/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
vector < int > x[150];
string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> s;
    int i = 0, j = s.size() - 1;
    while(i < s.size() && s[i] != 'A')i++;
    while(j > i && s[j] != 'Z')j--;
    cout << (j - i + 1) << endl;

    return 0;
}
