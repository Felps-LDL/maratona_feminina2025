#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << "x = " << x << endl;
#define ll long long
#define pii pair<int, int> 
#define piii pair<pair<int,int>, int>
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
 
using namespace std;

int N, M, compo = 0, destroyed;
vector<vector<int>> ve;
vector<bool> visitados;

void dfs(int u);

int main()
{
    optimize;

    cin >> N >> M;

    ve.resize(N + 1);
    visitados.resize(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int u, v;

        cin >> u >> v;

        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    for(int i = 1; i <= N; i++)
    {
        if(!visitados[i])
        {
            dfs(i);
            compo++;
        }
    }

    destroyed = (M + compo - 1) - (N - 1);

    if(compo == 1 && destroyed == 0) cout << "BOM" << endl;
    else cout << "RUIM " << destroyed << " " << compo - 1 << endl;

    // arestas cons = compo - 1
    // arestas removidas = (M + compo - 1) - (N - 1) 
    
    return 0;
}

void dfs(int u)
{
    visitados[u] = true;

    for(auto v : ve[u])
    {
        if(!visitados[v]) dfs(v);
    }
}