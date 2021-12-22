#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101, B = 50; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
bool a[MN][MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    while (N--){
        string s; getline(cin, s);
        bool b = s[1] == 'n';
        int x1, x2, y1, y2, z1, z2;
        // on x=-54112..-39298,y=-85059..-49293,z=-27449..7877
        int i = s.find('='), j = s.find('.');
        x1 = stoi(s.substr(i + 1, j - i - 1)); s = s.substr(j + 2);
        // -39298,y=-85059..-49293,z=-27449..7877
        i = s.find(',');
        x2 = stoi(s.substr(0, i)); s = s.substr(i + 3);
        // -85059..-49293,z=-27449..7877
        i = s.find('.');
        y1 = stoi(s.substr(0, i)); s = s.substr(i + 2);
        // -49293,z=-27449..7877
        i = s.find(',');
        y2 = stoi(s.substr(0, i)); s = s.substr(i + 3);
        // -27449..7877
        i = s.find('.');
        z1 = stoi(s.substr(0, i)); s = s.substr(i + 2);
        // 7877
        z2 = stoi(s);
        x1 = max(x1, -50); x2 = min(x2, 50);
        y1 = max(y1, -50); y2 = min(y2, 50);
        z1 = max(z1, -50); z2 = min(z2, 50);
        for (int x = x1; x <= x2; ++x){
            for (int y = y1; y <= y2; ++y){
                for (int z = z1; z <= z2; ++z){
                    a[x + B][y + B][z + B] = b;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MN; ++i){
        for (int j = 0; j < MN; ++j){
            for (int k = 0; k < MN; ++k){
                ans += a[i][j][k];
            }
        }
    }
    cout << ans << '\n';
}
