/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, Ans, n, casee = 1, a[N];

struct node {
    int endmark;
    node* next[4 + 1];
    node() {
        endmark = 0;
        for(int i = 0; i < 4; i++)
            next[i] = NULL;
    }
} * root;

int check(char c) {
    if(c == 'A')return 0;
    if(c == 'C')return 1;
    if(c == 'G')return 2;
    return 3;
}

void insert(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = check(str[i]);
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr->endmark++;
        Ans = max(Ans, i * curr->endmark);
        curr = curr->next[id];
    }
    curr->endmark++;
    Ans = max(Ans, (len) * curr->endmark);
}

int search(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = str[i] - 'A';
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for(int i = 0; i < 4; i++)
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
        Ans = 0;
        while(n--) {
            string s; cin >> s;
            insert(s, s.size());
        }
        cout << "Case " << casee++ << ": " << Ans << endl;
        del(root);
    }


    return 0;
}
