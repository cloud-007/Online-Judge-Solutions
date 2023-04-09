/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1;

struct node {
    int endmark;
    node* next[52 + 1];
    node() {
        endmark = 0;
        for(int i = 0; i < 53; i++)
            next[i] = NULL;
    }
} * root;

int check(char c) {
    if(c >= 'A' && c <= 'Z')return c - 'A';
    else return c - 'a' + 27;
}

void insert(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = check(str[i]);
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark++;
}

int search(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = check(str[i]);
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for(int i = 0; i < 53; i++)
        if(cur->next[i])
            del(cur->next[i]);

    delete(cur);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        root = new node();
        cin >> n;
        while(n--) {
            string s; cin >> s;
            if(s.size() > 2)sort(s.begin() + 1, s.begin() + (s.size() - 1));
            insert(s, s.size());
        }
        cout << "Case " << casee++ << ":" << endl;
        int q; cin >> q;
        cin.ignore();
        while(q--) {
            string word; getline(cin, word);
            stringstream ss(word);
            string s;
            int Ans = 1;
            while(ss >> s) {
                if(s.size() > 2)sort(s.begin() + 1, s.begin() + (s.size() - 1));
                Ans *= search(s, s.size());
            }
            cout << Ans << endl;
        }
        del(root);
    }


    return 0;
}
