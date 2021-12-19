#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 25; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
struct Point{
    int x, y, z;
    int step = 0;
    Point() = default;
    Point(string s){
        int idx1 = s.find_first_of(',');
        int idx2 = s.find_last_of(',');
        x = stoi(s.substr(0, idx1));
        y = stoi(s.substr(idx1 + 1, idx2 - idx1 - 1));
        z = stoi(s.substr(idx2 + 1));
    }
    Point(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void advance(){
        swap(x, y);
        x *= -1;
        step++;
        if (step == 4) z *= -1, y *= -1;
        else if (step == 8) z *= -1, y *= -1, swap(x, z), swap(x, y);
        else if (step == 12) z *= -1, y *= -1;
        else if (step == 16) z *= -1, y *= -1, swap(x, y), swap(x, z), swap(y, z), x *= -1;
        else if (step == 20) z *= -1, y *= -1;
        else if (step == 24) z *= -1, y *= -1, x *= -1, swap(y, z), step = 0;
    }
    void print(){
        cout << "(" << x << ", " << y << ", " << z << ")" << '\n';
    }
    Point operator+(const Point &other) const{
        Point ret(x + other.x, y + other.y, z + other.z);
        return ret;
    }
    Point operator-(const Point &other) const{
        Point ret(x - other.x, y - other.y, z - other.z);
        return ret;
    }
    Point operator-() const{
        Point ret(-x, -y, -z);
        return ret;
    }
    bool operator==(const Point &other) const{
        return tie(x, y, z) == tie(other.x, other.y, other.z);
    }
    bool operator<(const Point &other) const{
        return tie(x, y, z) < tie(other.x, other.y, other.z);
    }
    int dist(const Point &other) const{
        return abs(x - other.x) + abs(y - other.y) + abs(z - other.z);
    }
};

vector<Point> pts[MN];
bool vis[MN];
Point ans[MN];
void dfs(int v){
    vis[v] = 1;
    for (int to = 0; to < N; ++to){
        if (vis[to]) continue;
        bool end = 0;
        for (int dir = 0; dir < 24; ++dir){
            for (Point a : pts[v]){
                for (Point b : pts[to]){
                    int cnt = 0;
                    Point rel = a + -b;
                    for (Point c : pts[to]){
                        if (find(pts[v].begin(), pts[v].end(), rel + c) != pts[v].end()){
                            cnt++;
                        }
                    }
                    if (cnt >= 12){
                        ans[to] = ans[v] + rel;
                        dfs(to);
                        end = 1;
                        break;
                    }
                }
                if (end) break;
            }
            if (end) break;
            for (Point &a : pts[to]) a.advance();
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen(file.c_str(), "r", stdin);
    N = 25;
    string s;
    for (int i = 0; i < N; ++i){
        getline(cin, s);
        while (true){
            if (!getline(cin, s)) break;
            if (s.empty()) break;
            pts[i].push_back(Point(s));
        }
    }
    dfs(0);
    int dist = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < i; ++j){
            dist = max(dist, ans[i].dist(ans[j]));
        }
    }
    cout << dist << '\n';
}
