#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 30; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
map<string, vector<string>> adj;
set<string> vis;
bool small(string s){ return s[0] >= 'a' && s[0] <= 'z'; }
int ans;

void dfs(string v){
    if (v == "end"){
        ans++;
        return;
    }
    if (small(v)) vis.insert(v);
    for (string to : adj[v]){
        if (small(to) && vis.count(to)) continue;
        dfs(to);
    }
    vis.erase(v);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        int idx = s.find('-');
        string a = s.substr(0, idx);
        string b = s.substr(idx + 1);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs("start");
    cout << ans << '\n';
}
