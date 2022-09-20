/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

string s, l;


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;

    while(cin >> s) {
        if(s == "0")return 0;
        cin >> l;
        int ty1 = 0, ty2 = 0, ty3 = 0;
        for(int i = 0; i < l.size(); i++) {
            string x = "";
            if(i + s.size() - 1 < l.size()) {
                for(int j = i; j < i + s.size(); j++)x += l[j];
                if(x == s)ty1++;
            }
        }

        set < string > st1, st2;

        for(int i = 0; i < s.size(); i++) {
            string x = "";
            for(int j = 0; j < i; j++)x += s[j];
            for(int j = i + 1; j < s.size(); j++)x += s[j];
            st1.insert(x);
        }

        char tx[] = {'A', 'G', 'C', 'T'};

        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < 4; j++) {
                string x = "";
                for(int k = 0; k < i; k++)x += s[k];
                x += tx[j];
                for(int k = i; k < s.size(); k++)x += s[k];
                st2.insert(x);
                st2.insert(s+tx[j]);
            }
        }

        for(auto j : st1) {
            for(int i = 0; i < l.size(); i++) {
                string x = "";
                if(i + j.size() - 1 < l.size()) {
                    for(int k = i; k < i + j.size(); k++)x += l[k];
                    if(x == j)ty2++;
                }
            }
        }

        for(auto j : st2) {
            for(int i = 0; i < l.size(); i++) {
                string x = "";
                if(i + j.size() - 1 < l.size()) {
                    for(int k = i; k < i + j.size(); k++)x += l[k];
                   // cout << x <<" "<<j <<endl;
                    if(x == j)ty3++;
                }
            }
        }

        cout << ty1 << " " << ty2 << " " << ty3 << endl;

    }


    return 0;
}
