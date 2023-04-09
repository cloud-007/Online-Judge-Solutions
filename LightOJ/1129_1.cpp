/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

struct node {
    bool endmark;
    node* next[10 + 1];
    node() {
        endmark = false;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;

bool insert(string str, int len) {
    node* curr = root;
    bool ret = true;
    for(int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL) {
            ret = false;
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
    return ret;
}

int search(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for(int i = 0; i < 10; i++)
        if(cur->next[i])
            del(cur->next[i]);

    delete(cur);
}

///set root = new node() in the main function

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
        bool ok = false;

        string s[n + 5];
        for(int i = 1; i <= n; i++)cin >> s[i];

        auto cmp = [](string a, string b) {
            if(a.size() == b.size())return a < b;
            return a.size() > b.size();
        };

        sort(s + 1, s + n + 1, cmp);

        for(int i = 1; i <= n; i++){
            ok |= insert(s[i], s[i].size());
        }

        cout << "Case " << casee++ << ": " << (ok ? "NO" : "YES") << endl;
        del(root);
    }


    return 0;
}
