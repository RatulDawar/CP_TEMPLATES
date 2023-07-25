class Solution {
public:
    static const int MAXN = 55;
    static const int LOG = 7;
    int up[MAXN][LOG];
    int h[MAXN];
    int fre[MAXN];
    void dfs(int u,int par,vector<int> *edges){
        if(par == - 1){
            h[u] = 0;
            for(int i = 0;i<LOG;i++)up[u][i] = u;
        }
        for(int v:edges[u]){
            if(v == par)continue;
            h[v] = h[u] + 1;
            up[v][0] = u;
            for(int i = 1;i<LOG;i++){
                up[v][i] = up[up[v][i-1]][i-1];
            }
            dfs(v,u,edges);
        }
    }
    int lca(int u,int v){
        if(h[v] > h[u])swap(v,u);
        int k = h[u] - h[v];
        for(int i = LOG - 1;i>=0;i--){
            if((1<<i)&k)u = up[u][i];
        }
        if(u == v)return u;
        for(int i = LOG - 1;i>=0;i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    int dfs1(int u,int par,vector<int> *edges){
        int ans = 0;
        for(int v:edges[u]){
            if(v == par)continue;
            ans += dfs1(v,u,edges);
        }
        return fre[u] += ans;
    }
    int minimumTotalPrice(int n, vector<vector<int>>& e, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> *edges = new vector<int>[n];
        for(int i = 0;i<n-1;i++){
            int a = e[i][0], b = e[i][1];
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        dfs(0,-1,edges);
        memset(fre,0,sizeof(fre));
        for(int i = 0;i<trips.size();i++){
            int a = trips[i][0], b = trips[i][1];
            int lc = lca(a,b);
            fre[lc] -= 1;fre[a]++;fre[b]++;fre[up[lc][0]] -= (lc != 0);
        }
        dfs1(0,-1,edges);
        for(int i = 0;i<n;i++){
            cout<<fre[i]<<" ";
        }
        cout<<endl;
        return 0;

    }
};