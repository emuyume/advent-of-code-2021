#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "test.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
const int MNX = 175, MXX = 227, MNY = -134, MXY = -79;
// const int MNX = 20, MXX = 30, MNY = -10, MXY = -5;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int ans = 0;
    for (int i = 0; i <= 1000; ++i){
        for (int j = -1000; j <= 1000; ++j){
            int dx = i, dy = j;
            int x = 0, y = 0;
            int mxy = 0;
            while (true){
                x += dx, y += dy;
                mxy = max(mxy, y);
                dx = max(dx - 1, 0); dy--;
                if (x >= MNX && x <= MXX && y >= MNY && y <= MXY){
                    ans = max(ans, mxy);
                }
                if (x > MXX || y < MNY) break;
            }
        }
    }
    cout << ans << '\n';
}
