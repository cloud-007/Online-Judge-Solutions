/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 5 + 5;
int tc, n, casee = 1;
char a[N][N], c[N][N];
bool vis[N][N];
map < string, int > mp, mp1;

int fx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int fy[] = {-1, 1, 1, -1, 1, -1, 0, 0};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= 4 && ty <= 4 && !vis[tx][ty]);
}

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

void dfs(int sx, int sy, string s, int vowel, bool type) {
    if(s.size() == 4) {
        if(vowel == 2) {
            if(type)mp[s]++;
            else mp1[s]++;
        }
        return;
    }
    for(int i = 0; i < 8; i++) {
        int tx = sx + fx[i];
        int ty = sy + fy[i];
        if(valid(tx, ty)) {
            vis[tx][ty] = true;
            if(type)dfs(tx, ty, s + a[tx][ty], vowel + isVowel(a[tx][ty]), type);
            else dfs(tx, ty, s + c[tx][ty], vowel + isVowel(c[tx][ty]), type);
            vis[tx][ty] = false;
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> a[1][1] && a[1][1] != '#') {
        cin >> a[1][2] >> a[1][3] >> a[1][4];
        cin >> c[1][1] >> c[1][2] >> c[1][3] >> c[1][4];
        for(int i = 2; i <= 4; i++) {
            for(int j = 1; j <= 8; j++) {
                char x; cin >> x;
                if(j <= 4)a[i][j] = x;
                else c[i][j - 4] = x;
            }
        }

        memset(vis, false, sizeof vis);
        mp.clear(); mp1.clear();

        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                string s = "";
                s += a[i][j];
                vis[i][j] = true;
                dfs(i, j, s, isVowel(a[i][j]), true);
                vis[i][j] = false;
            }
        }

        memset(vis, false, sizeof vis);

        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                string s = "";
                s += c[i][j];
                vis[i][j] = true;
                dfs(i, j, s, isVowel(c[i][j]), false);
                vis[i][j] = false;
            }
        }

        vector < string > Ans;

        if(casee > 1)cout << endl;

        for(auto i : mp)if(mp1[i.F])Ans.push_back(i.F);

        if(Ans.empty())cout << "There are no common words for this pair of boggle boards." << endl;
        else {
            for(auto i : Ans)cout << i << endl;
        }
        ++casee;

    }


    return 0;
}
