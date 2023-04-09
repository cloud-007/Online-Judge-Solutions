/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc;
string s, ans = "-1";

struct node {
    bool endmark;
    node* next[11];
    node() {
        endmark = false;
        for (int i = 0; i < 11; i++)
            next[i] = NULL;
    }
} * root;

bool insert(string str, int len) {
    node* curr = root;
    bool ok = false, ok1 = true;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr->endmark)ok = true;
        if (curr->next[id] == NULL)
            curr->next[id] = new node(), ok1=false;
        curr = curr->next[id];
    }
    curr->endmark = true;
    return ok || ok1;
}

int search(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for (int i = 0; i < 11; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    root = new node();
    cin >> tc;
    while(tc--) {
        cin >> s;
        if(insert(s, s.size())) {
            if(ans == "-1")ans = s;
        }
    }
    if(ans == "-1")cout << "GOOD SET" << endl;
    else cout << "BAD SET" << endl << ans << endl;

    return 0;
}
