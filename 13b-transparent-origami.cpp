#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3001; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

bool g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    string s;
    while (true){
        getline(cin, s);
        int idx = s.find(',');
        if (idx == string::npos) break;
        int c = stoi(s.substr(0, idx));
        int r = stoi(s.substr(idx + 1));
        g[r][c] = 1;
    }
    N = 3000; int M = 3000;
    while (getline(cin, s)){
        int b = stoi(s.substr(13));
        if (s[11] == 'y'){
            N = b - 1;
            for (int i = 0; i <= N; ++i){
                for (int j = 0; j <= M; ++j){
                    g[i][j] |= g[2 * b - i][j];
                }
            }
        }
        if (s[11] == 'x'){
            M = b - 1;
            for (int i = 0; i <= N; ++i){
                for (int j = 0; j <= M; ++j){
                    g[i][j] |= g[i][2 * b - j];
                }
            }
        }
    }
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= M; ++j){
            cout << (g[i][j] ? '#' : '.');
        }
        cout << '\n';
    }
}
