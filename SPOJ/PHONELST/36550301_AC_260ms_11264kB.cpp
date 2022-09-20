/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n;

struct node {
    bool endmark;
    node* next[15 + 1];
    node() {
        endmark = false;
        for(int i = 0; i < 15; i++)
            next[i] = NULL;
    }
} * root;

bool insert(string str, int len) {
    node* curr = root;
    bool found = false;
    for(int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        if(curr->endmark)found = true;
        curr = curr->next[id];
    }
    curr->endmark = true;
    return found;
}


void del(node* cur) {
    for(int i = 0; i < 15; i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}


int main() {
    cin >> tc;
    while(tc--) {
        root = new node();
        cin >> n;
        vector < string > v(n);
        for(auto &x : v)cin >> x;
        sort(v.begin(), v.end());

        bool flag = false;

        for(auto i : v) {
            flag |= insert(i, i.size());
        }

        cout << (flag ? "NO" : "YES") << endl;

        del(root);
    }
    return 0;
}
