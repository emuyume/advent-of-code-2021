#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
map<char, int> mp = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
map<char, char> rev = {{'(', ')'}, {')', '('}, {'[', ']'}, {']', '['}, {'<', '>'}, {'>', '<'}, {'{', '}'}, {'}', '{'}};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    vector<ll> scores;
    while (N--){
        string s; cin >> s;
        vector<char> stk;
        bool skip = 0;
        for (char c : s){
            if (!mp.count(c)) stk.push_back(c);
            else{
                if (stk.back() != rev[c]){
                    skip = 1;
                    break;
                }
                else stk.pop_back();
            }
        }
        if (skip) continue;
        ll ans = 0;
        while (!stk.empty()){
            ans = (ans * 5) + mp[rev[stk.back()]];
            stk.pop_back();
        }
        scores.push_back(ans);
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2] << '\n';
}
