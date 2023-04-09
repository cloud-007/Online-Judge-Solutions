/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, a[N];

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c=='y');
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    string s; getline(cin, s);

    string word;

    stringstream ss(s);

    while(ss >> word) {
        if(word != "?")s = word;
    }

    if(s[s.size() - 1] == '?')cout << (isVowel(tolower(s[s.size() - 2])) ? "YES" : "NO") << endl;
    else cout << (isVowel(tolower(s[s.size() - 1])) ? "YES" : "NO") << endl;



    return 0;
}
