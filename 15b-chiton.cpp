#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 505; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int g[MN][MN];
int dist[MN][MN];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
struct Item{
    int x, y, d;
    bool operator<(const Item &other) const{
        return d > other.d;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            char c; cin >> c;
            g[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= 5 * N; ++i){
        for (int j = 1; j <= 5 * N; ++j){
            g[i][j] = ((i - 1) / N) + ((j - 1) / N) + g[(i - 1) % N + 1][(j - 1) % N + 1];
            g[i][j] = (g[i][j] - 1) % 9 + 1;
            dist[i][j] = inf;
        }
    }
    N *= 5;
    priority_queue<Item> pq;
    dist[1][1] = g[1][1];
    pq.push({1, 1, dist[1][1]});
    while (!pq.empty()){
        auto [x, y, d] = pq.top(); pq.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (d + g[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = d + g[nx][ny];
                pq.push({nx, ny, dist[nx][ny]});
            }
        }
    }
    cout << dist[N][N] - g[1][1] << '\n';
}
