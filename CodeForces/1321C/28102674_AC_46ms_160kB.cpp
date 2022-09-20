/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n;
string s, temp;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> s;

    for(char c = 'z'; c >= 'b'; c--) {
        if(s.size() == 1) {
            break;
        }
        unordered_map < char, int > mp;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == c) {
                if(j + 1 < s.size() && s[j + 1] == c - 1) {
                    int pos = j;
                    while(pos>= 0 && s[pos] == c) {
                        mp[pos] = 1;
                        pos--;
                    }
                } else if(j - 1 >= 0 && s[j - 1] == c - 1) {
                    mp[j] = 1;
                    s[j] = s[j-1];
                }
            }
        }
        string x = "";
        for(int j = 0; j < s.size(); j++) {
            if(!mp[j])x += s[j];
        }
        s = x;
    }

    cout << n - s.size() << endl;


    return 0;
}
