#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 12; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct Point{ int x, y; };
int g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    ms(g, -0x3f);
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            char c; cin >> c;
            g[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int day = 1; day <= 100; ++day){
        queue<Point> q;
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (++g[i][j] == 10) q.push({i, j});
            }
        }
        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 8; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if (++g[nx][ny] == 10) q.push({nx, ny});
            }
        }
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (g[i][j] >= 10) g[i][j] = 0, ans++;
            }
        }
    }
    cout << ans << '\n';
}
