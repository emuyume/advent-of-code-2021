#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1, B = 13e4; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
struct Cuboid{
    int s, l[3], r[3];
} a[MN];
int cnt[2 * MN], lz[2 * MN];
void push(int v, int l, int r){
    if (lz[v] == -1) return;
    cnt[v] = (r - l + 1) * lz[v];
    if (l != r){
        lz[lc] = lz[v];
        lz[rc] = lz[v];
    }
    lz[v] = -1;
}
void upd(int ql, int qr, int val, int v = 1, int l = 0, int r = MN - 1){
    push(v, l, r);
    if (r < ql || l > qr) return;
    if (l >= ql && r <= qr) lz[v] = val, push(v, l, r);
    else{
        upd(ql, qr, val, lc, l, mid); upd(ql, qr, val, rc, mid + 1, r);
        cnt[v] = cnt[lc] + cnt[rc];
    }
}
int qry(){ return cnt[1]; }
void reset(){ upd(0, MN - 1, 0); }
struct Event{
    int x, id, c;
    bool operator<(const Event &other) const{
        return x < other.x;
    }
};
ll solve(int d, int active[]){
    if (d == 0){
        reset();
        for (int i = 1; i <= N; ++i){
            if (active[i]){
                upd(a[i].l[0] + B, a[i].r[0] + B, a[i].s);
            }
        }
        return qry();
    }
    vector<Event> v;
    for (int i = 1; i <= N; ++i){
        if (active[i]){
            v.push_back({a[i].l[d], i, 1});
            v.push_back({a[i].r[d] + 1, i, 0});
        }
    }
    int lst = -inf;
    sort(v.begin(), v.end());
    int nxt[N + 1] = {0};
    ll ret = 0;
    for (auto [x, id, c] : v){
        ret += solve(d - 1, nxt) * (x - lst);
        nxt[id] = c;
        lst = x;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    for (int k = 1; k <= N; ++k){
        string s; getline(cin, s);
        a[k].s = s[1] == 'n';
        // on x=-54112..-39298,y=-85059..-49293,z=-27449..7877
        int i = s.find('='), j = s.find('.');
        a[k].l[0] = stoi(s.substr(i + 1, j - i - 1)); s = s.substr(j + 2);
        // -39298,y=-85059..-49293,z=-27449..7877
        i = s.find(',');
        a[k].r[0] = stoi(s.substr(0, i)); s = s.substr(i + 3);
        // -85059..-49293,z=-27449..7877
        i = s.find('.');
        a[k].l[1] = stoi(s.substr(0, i)); s = s.substr(i + 2);
        // -49293,z=-27449..7877
        i = s.find(',');
        a[k].r[1] = stoi(s.substr(0, i)); s = s.substr(i + 3);
        // -27449..7877
        i = s.find('.');
        a[k].l[2] = stoi(s.substr(0, i)); s = s.substr(i + 2);
        // 7877
        a[k].r[2] = stoi(s);
    }
    int active[N + 1];
    for (int i = 1; i <= N; ++i) active[i] = 1;
    cout << solve(2, active) << '\n';
}
