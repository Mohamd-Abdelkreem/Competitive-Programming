using namespace std;
#include <bits/stdc++.h>
using ll = long long;
using lli = long long int;
const ll INF = LONG_LONG_MAX;

const ll MOD = 1e9 + 7;

// #define int long long
#define SetPre(n, x)  cout << fixed << setprecision(n) << x
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define pii pair<int, int>
#define pil pair<ll, ll>
#define vpii vector<pair<int, int>>
#define vpil vector<pair<ll, ll>>
#define vi vector<int>
#define vl vector<ll>
#define M_PI 3.141592653589793
#define ull unsigned long long
#define all(v) v.begin(), v.end()
#define Rall(v) v.rbegin(), v.rend()
#define L '\n'
#define pb push_back
#define EPS 1e-9
#define OO LONG_LONG_MAX
#define sz(x) int(x.size())
#define rz(n) resize(n)
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define eb emplace_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define addMod(a, b, m) (((a % m) + (b % m)) % m)
#define subMod(a, b, m) (((a % m) - (b % m)) % m)
#define mulMod(a, b, m) (((a % m) * (b % m)) % m)
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / gcd(a, b) * (b))
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define per1(i, n) for (int i = n; i >= 1; i--)
string di[] = {"D", "L", "U", "R", "UL", "UR", "DL", "DR"};
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
#define ceil_i(a, b) (((ll)(a)+(ll)(b-1))/(ll)(b))
#define floor_i(a, b) (a/b)
#define round_i(a, b) ((a+(b/2))/b)

void NeedForSpeed() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const auto &x: v) {
        out << x << " ";
    }
    return out;
}

vector<vector<int> > adj;
vector<int> vis(100001);
vector<int> color(100001, 0);
int n, m,f = 1;

void bfs(int u) {
    queue<int> q;
    color[u] = 1;
    vis[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto &i: adj[top]) {
            if (vis[i] == 0) {
                vis[i] = vis[top] + 1;
                q.push(i);
                color[i] = !color[top];
            } else {
                if (color[top] == color[i]) {
                    f = 0;
                    return;
                }
            }
        }
    }
}

void RIP() {
    cin >> n >> m;
    adj = vector<vector<int> >(n + 1);
    vis = vector<int>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
            if (!f) {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << color[i] + 1 << " ";
    }
}


signed main() {
    IO();
    NeedForSpeed();
    int t = 1;

    // cin >> t;

    while (t--) {
        RIP();
        // cout << L;
    }
    return 0;
}