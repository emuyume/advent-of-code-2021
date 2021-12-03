#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e4 + 1; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int trie[MN][2], cnt[MN][2], T;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int M;
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        M = s.size();
        int v = 0;
        for (int j = 0; j < M; ++j){
            if (!trie[v][s[j] - '0']){
                trie[v][s[j] - '0'] = ++T;
            }
            cnt[v][s[j] - '0']++;
            v = trie[v][s[j] - '0'];
        }
    }
    int o2 = 0, co2 = 0, vo2 = 0, vco2 = 0;
    for (int i = M - 1; i >= 0; --i){
        int o2c = cnt[vo2][1] >= cnt[vo2][0];
        int co2c = cnt[vco2][1] < cnt[vco2][0];
        if (cnt[vco2][co2c] == 0) co2c ^= 1;
        o2 += o2c * (1 << i);
        co2 += co2c * (1 << i);
        vo2 = trie[vo2][o2c];
        vco2 = trie[vco2][co2c];
    }
    cout << o2 * co2 << '\n';
}
