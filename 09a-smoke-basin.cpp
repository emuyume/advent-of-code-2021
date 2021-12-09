#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 102; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int M;
    ms(g, 0x3f);
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        M = s.size();
        for (int j = 1; j <= M; ++j){
            g[i][j] = s[j - 1] -'0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            bool low = 1;
            low &= g[i][j] < g[i + 1][j];
            low &= g[i][j] < g[i - 1][j];
            low &= g[i][j] < g[i][j + 1];
            low &= g[i][j] < g[i][j - 1];
            if (low) ans += g[i][j] + 1;
        }
    }
    cout << ans << '\n';
}
