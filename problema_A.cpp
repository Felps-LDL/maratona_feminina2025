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

int N, M, qtd, pos = 0;
vector<int> v;

int main()
{
    optimize;

    cin >> N >> M;
    qtd = N;

    v.resize(N);

    for(auto &x : v) cin >> x;

    sort(ALL(v));

    for(int i = 0; i < M; i++)
    {
        while(v[pos] < i + 1 && pos < N)
        {
            qtd--;
            pos++;
        }

        if(i == M - 1) break;
        cout << qtd << " ";
    }

    cout << qtd << endl;
    
    return 0;
}