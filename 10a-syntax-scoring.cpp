#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
map<char, int> mp = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
map<char, char> rev = {{'(', ')'}, {')', '('}, {'[', ']'}, {']', '['}, {'<', '>'}, {'>', '<'}, {'{', '}'}, {'}', '{'}};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int ans = 0;
    while (N--){
        string s; cin >> s;
        vector<char> stk;
        for (char c : s){
            if (!mp.count(c)) stk.push_back(c);
            else{
                if (stk.back() != rev[c]){
                    ans += mp[c];
                    break;
                }
                else stk.pop_back();
            }
        }
    }
    cout << ans << '\n';
}
