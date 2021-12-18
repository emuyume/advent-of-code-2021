#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "test.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

struct Node{
    int val = -1;
    Node *lc = 0, *rc = 0;
    void print(){
        if (val == -1){
            cout << '[';
            lc->print();
            cout << ',';
            rc->print();
            cout << ']';
        }
        else{
            cout << val;
        }
    }
    ll eval(){
        if (val == -1){
            return lc->eval() * 3 + rc->eval() * 2;
        }
        else{
            return val;
        }
    }
} *nullnode = 0;

Node* buildtree(string s){
    Node* ret = new Node();
    if (s.size() == 1){
        ret->val = stoi(s);
        return ret;
    }
    int cnt = 0;
    for (int i = 1; i < s.size() - 1; ++i){
        if (s[i] == '[') cnt++;
        if (s[i] == ']') cnt--;
        if (cnt == 0 && s[i] == ','){
            ret->lc = buildtree(s.substr(1, i - 1));
            ret->rc = buildtree(s.substr(i + 1, s.size() - 1 - i - 1));
            return ret;
        }
    }
    return nullptr;
}

Node* buildlinks(Node* t, Node* &previous){
    if (t->val != -1){
        t->lc = previous;
        if (previous) previous->rc = t;
        previous = t;
    }
    else{
        buildlinks(t->lc, previous);
        buildlinks(t->rc, previous);
    }
    return t;
}

Node* build(string s){
    Node* previous = nullptr;
    return buildlinks(buildtree(s), previous);
}

Node*& findexplode(Node* &t, int dep = 0){
    if (t->val != -1) return nullnode;
    if (dep >= 4) return t;
    Node* &ret = findexplode(t->lc, dep + 1);
    if (ret != 0) return ret;
    else return findexplode(t->rc, dep + 1);
}

Node*& findsplit(Node* &t){
    if (t->val != -1){
        if (t->val >= 10) return t;
        else return nullnode;
    }
    Node* &ret = findsplit(t->lc);
    if (ret != 0) return ret;
    else return findsplit(t->rc);
}

void reduce(Node* t){
    bool again = 1;
    while (again){
        again = 0;
        {
            Node* &cur = findexplode(t);
            if (cur){
                if (cur->lc->lc) cur->lc->lc->val += cur->lc->val;
                if (cur->rc->rc) cur->rc->rc->val += cur->rc->val;
                cur->lc = cur->lc->lc;
                cur->rc = cur->rc->rc;
                if (cur->lc) cur->lc->rc = cur;
                if (cur->rc) cur->rc->lc = cur;
                cur->val = 0;
                again = 1;
                continue;
            }
        }
        {
            Node* &cur = findsplit(t);
            if (cur){
                int vl = cur->val / 2, vr = (cur->val + 1) / 2;
                Node *lc = new Node(), *rc = new Node();
                lc->val = vl, rc->val = vr;
                lc->lc = cur->lc; rc->rc = cur->rc;
                lc->rc = rc; rc->lc = lc;
                if (lc->lc) lc->lc->rc = lc;
                if (rc->rc) rc->rc->lc = rc;
                cur->lc = lc, cur->rc = rc, cur->val = -1;
                again = 1;
            }
        }
    }
}

Node *&findlast(Node *&t){
    if (t->val == -1) return findlast(t->rc);
    else return t;
}

Node *&findfirst(Node *&t){
    if (t->val == -1) return findfirst(t->lc);
    else return t;
}

Node* add(Node* l, Node* r){
    Node* ret = new Node();
    ret->lc = l, ret->rc = r;
    Node *lastl = findlast(ret->lc), *firstr = findfirst(ret->rc);
    lastl->rc = firstr;
    firstr->lc = lastl;
    reduce(ret);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    string s; cin >> s;
    Node* ans = build(s);
    for (int i = 2; i <= N; ++i){
        cin >> s;
        ans = add(ans, build(s));
    }
    cout << ans->eval() << '\n';
}
