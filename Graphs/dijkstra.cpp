using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
using ll = long long;
using lli = long long int;
const ll INF = LONG_LONG_MAX;
const ll MOD = 1e9 + 7;
// #define int long long
#define mem(array, val) memset(array, val, sizeof(array))
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
#define pf push_front
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
int Knightdx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int Knightdy[] = {2, -2, 2, -2, 1, -1, 1, -1};
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

const int N = 5e5 + 5;
vector<vector<pair<ll, int> > > adj(N);
vector<ll> dist(N, 1e18), par(N, -1);

void dijkstra(int st) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
    pq.push({0, st});
    dist[st] = 0;
    while (!pq.empty()) {
        int curr = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (dist[curr] != d)
            continue;
        for (auto &ch: adj[curr]) {
            if (dist[ch.second] > d + ch.first) {
                dist[ch.second] = d + ch.first;
                pq.push({dist[ch.second], ch.second});
                par[ch.second] = curr;
            }
        }
    }
}


void RIP() {
    int n, m;
    cin >> n >> m ;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    dijkstra(1);

    //To get Parent of Every node for the route From 1 to N 
    int c = n;
    vector<int> ans;
    while (c != -1) {
        ans.pb(c);
        c = par[c];
    }
    if (dist[n] == 1e18) {
        cout << -1;
        return;
    }
    reverse(all(ans));
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    IO();
    NeedForSpeed();
    int t = 1;
    // cin >> t;
    while (t--) {
        RIP();
    }
    return 0;
}
