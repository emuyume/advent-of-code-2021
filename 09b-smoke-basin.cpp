#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 102; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int g[MN][MN];
vector<int> sizes;
void flood(int x, int y){
    g[x][y] = 9;
    sizes.back()++;
    if (g[x][y] > g[x][y + 1]) flood(x, y + 1);
    if (g[x][y] > g[x][y - 1]) flood(x, y - 1);
    if (g[x][y] > g[x + 1][y]) flood(x + 1, y);
    if (g[x][y] > g[x - 1][y]) flood(x - 1, y);
}

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
            if (g[i][j] == 9) continue;
            sizes.push_back(0);
            flood(i, j);
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    cout << sizes[0] * sizes[1] * sizes[2] << '\n';
}
