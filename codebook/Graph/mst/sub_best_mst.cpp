const int INF = 0x3f3f3f3f;
const int MAX_V = 100;
const int MAX_LOG_V = 7;
int V, E; // 記得初使化

struct Dsu {
    int par[MAX_V];

    void init() {
        fill(par, par + V, -1);
    }

    int root(int a) {
        return ((par[a] < 0) ? a : (par[a] = root(par[a])));
    }

    void unite(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return; // already in same set
        if (-par[a] > -par[b]) swap(a, b); // if (size[a] > size[b])
        par[b] += par[a]; // size[b] += size[a]
        par[a] = b;
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    int size(int a) {
        return -par[root(a)];
    }
};

Dsu dsu;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;

// btn[i][u] = u 前往它 2^i parent 的路上經過的最大權重
// par[i][u] = u 的 2^i parent 是誰
int dep[MAX_V]; // should be init to -1
int btn[MAX_LOG_V][MAX_V];
int par[MAX_LOG_V][MAX_V];

// mst
struct AdjE {
    int to, w;
};
vector<AdjE> g[MAX_V];

void dfs(int u, int p, int d) {
    dep[u] = d;
    par[0][u] = p;
    for (auto e : g[u]) {
        if (e.to != p) {
            btn[0][e.to] = e.w;
            dfs(e.to, u, d + 1);
        }
    }
}

void build() {
    for (int u = 0; u < V; u++) {
        if (dep[u] == -1) {
            dfs(u, -1, 0);
        }
    }

    for (int i = 0; i + 1 < MAX_LOG_V; i++) {
        for (int u = 0; u < V; u++) {
            if (par[i][u] == -1 || par[i][par[i][u]] == -1) {
                par[i + 1][u] = -1;
                btn[i + 1][u] = 0;
            }
            else {
                par[i + 1][u] = par[i][par[i][u]];
                btn[i + 1][u] = max(btn[i][u], btn[i][par[i][u]]);
            }
        }
    }
}

int lca(int u, int v) { // 回傳 u, v 之間的最大權重
    int mx = -INF; // u, v 之間的最大權重

    if (dep[u] > dep[v]) swap(u, v);
    int diff = dep[v] - dep[u];
    for (int i = MAX_LOG_V - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            mx = max(mx, btn[i][v]);
            v = par[i][v];
        }
    }

    if (u == v) return mx;

    for (int i = MAX_LOG_V - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            mx = max(mx, btn[i][u]);
            mx = max(mx, btn[i][v]);
            u = par[i][u];
            v = par[i][v];
        }
    }
    // lca = par[0][u] = par[0][v];
    mx = max(mx, max(btn[0][u], btn[0][v]));

    return mx;
}

int main() {
    int TC; scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &V, &E);
        printf("Case #%d : ", tc);

        dsu.init();
        edges.clear();
        fill(dep, dep + V, -1);
        for (int u = 0; u < V; u++) {
            g[u].clear();
        }

        for (int _ = 0; _ < E; _++) {
            int u, v, w; scanf("%d %d %d", &u, &v, &w); u--; v--;
            edges.push_back((Edge) {u, v, w});
        }

        // mst
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
            return e1.w < e2.w;
        });
        int total_w = 0;
        vector<Edge> non_mst_edges;
        for (auto e : edges) {
            if (!dsu.same(e.u, e.v)) {
                total_w += e.w;
                dsu.unite(e.u, e.v);
                g[e.u].push_back((AdjE) {e.v, e.w});
                g[e.v].push_back((AdjE) {e.u, e.w});
            }
            else {
                non_mst_edges.push_back(e);
            }
        }

        if (dsu.size(0) != V) {
            puts("No way");
            continue;
        }

        // second mst
        build();
        int ans = INF;
        for (auto e: non_mst_edges) {
            int mx_w = lca(e.u, e.v);
            ans = min(ans, (total_w + e.w - mx_w));
        }

        if (ans == INF) {
            puts("No second way");
            continue;
        }

        printf("%d\n", ans);
    }

    return 0;
}