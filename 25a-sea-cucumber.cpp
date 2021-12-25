#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 200; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
char g[MN][MN];
bool yes[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int M;
    for (int i = 0; i < N; ++i){
        string s; cin >> s;
        M = s.size();
        for (int j = 0; j < M; ++j){
            g[i][j] = s[j];
        }
    }
    bool moved = 1; 
    int ans = 0;
    while (moved){
        moved = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if (g[i][j] == '>'){
                    if (g[i][(j + 1) % M] == '.'){
                        yes[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if (yes[i][j]){
                    moved = 1;
                    g[i][j] = '.';
                    g[i][(j + 1) % M] = '>';
                    yes[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if (g[i][j] == 'v'){
                    if (g[(i + 1) % N][j] == '.'){
                        yes[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if (yes[i][j]){
                    moved = 1;
                    g[i][j] = '.';
                    g[(i + 1) % N][j] = 'v';
                    yes[i][j] = 0;
                }
            }
        }
        ans++;
        if (ans % 100 == 0) cout << ans << '\n';
    }
    cout << ans << '\n';
}
