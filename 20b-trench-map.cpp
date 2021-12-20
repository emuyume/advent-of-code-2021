#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 500, B = 200; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
int a[512];
int g[MN][MN][51];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    N -= 2;
    for (int i = 0; i < 512; ++i){
        char c; cin >> c;
        a[i] = c == '#';
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            char c; cin >> c;
            g[i + B][j + B][0] = c == '#';
        }
    }
    for (int k = 1; k <= 50; ++k){
        for (int i = 1; i < MN - 1; ++i){
            for (int j = 1; j < MN - 1; ++j){
                int msk = 0;
                for (int dx = -1; dx <= 1; ++dx){
                    for (int dy = -1; dy <= 1; ++dy){
                        msk = msk * 2 + g[i + dx][j + dy][k - 1];
                    }
                }
                g[i][j][k] = a[msk];
            }
        }
    }
    int cnt = 0;
    for (int i = 50; i < MN - 50; ++i){
        for (int j = 50; j < MN - 50; ++j){
            cnt += g[i][j][50];
        }
    }
    cout << cnt << '\n';
}
