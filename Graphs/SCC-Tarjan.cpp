using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
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
void Tarjan(int node, int &cnt, vector<vector<int> > &adj, vector<int> &inStack, vector<int> &dfsNumber,
            vector<int> &lowLinkNumber, stack<int> &stSCC, vector<vector<int> > &FinalSCC_Componentes) {

    // Assign discovery time and low-link value to the current node
    dfsNumber[node] = lowLinkNumber[node] = ++cnt, inStack[node] = 1;
    // Push the current node onto the stack
    stSCC.push(node);

    // Traverse all children of the current node
    for (int child: adj[node]) {
        // If the child has not been visited yet
        if (dfsNumber[child] == -1) {
            // Recursively call Tarjan on the child
            Tarjan(child, cnt, adj, inStack, dfsNumber, lowLinkNumber, stSCC, FinalSCC_Componentes);
            // Update the low-link value of the current node
            lowLinkNumber[node] = min(lowLinkNumber[node], lowLinkNumber[child]);
        }
        // If the child is in the current stack (part of the current SCC)
        else if (inStack[child]) {
            // Update the low-link value of the current node
            lowLinkNumber[node] = min(lowLinkNumber[node], dfsNumber[child]);
        }
    }

    // If the current node is the root of an SCC
    if (lowLinkNumber[node] == dfsNumber[node]) {
        vector<int> elements; // To store nodes in the current SCC
        elements.clear();

        // Pop nodes from the stack until the current node is reached
        while (stSCC.top() != node) {
            elements.push_back(stSCC.top()); // Add to the SCC
            inStack[stSCC.top()] = 0; // Mark as not in the stack
            stSCC.pop(); // Remove from the stack
        }

        // Add the current node to the SCC
        elements.push_back(stSCC.top());
        inStack[stSCC.top()] = 0; // Mark as not in the stack
        stSCC.pop(); // Remove from the stack

        // Add the SCC to the list of all SCCs
        FinalSCC_Componentes.push_back(elements);
    }
}

vector<vector<int> > SCC(int n, int m) {
    const int N = 500001; // Maximum number of nodes
    int cnt = 0; // Counter for discovery time
    vector<vector<int> > adj(n + 1), FinalSCC_Componentes; // Adjacency list and SCCs
    vector<int> inStack(N), dfsNumber(N, -1), lowLinkNumber(N); // Tarjan's algorithm data structures
    stack<int> stSCC; // Stack to store nodes in the current SCC

    // Read the graph edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge to the adjacency list
    }

    // Run Tarjan's algorithm on all unvisited nodes
    for (int i = 0; i < n; ++i) {
        if (dfsNumber[i] == -1) // If the node is unvisited
            Tarjan(i, cnt, adj, inStack, dfsNumber, lowLinkNumber, stSCC, FinalSCC_Componentes);
    }

    // Return the list of SCCs
    return FinalSCC_Componentes;
}

void RIP() {
    int n, m;
    cin >> n >> m; // Read the number of nodes and edges

    // Find all SCCs using Tarjan's algorithm
    vector<vector<int> > components = SCC(n, m);

    // Reverse the SCCs to get them in topological order
    // reverse(all(components));

    // Print the number of SCCs
    cout << sz(components) << L;

    // Print each SCC
    for (const auto &component: components) {
        cout << sz(component) << " "; // Print the size of the SCC
        for (int u: component)
            cout << u << " "; // Print the nodes in the SCC
        cout << L; // Newline after each SCC
    }
}

signed main() {
    IO();
    NeedForSpeed();
    int t = 1;
    // cin >> t;

    while (t--) {
        RIP();
        cout << L;
    }
    return 0;
}
