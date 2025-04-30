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
#define MOD 1e-6
using namespace std;

double pi = 3.14159265359;
int N, Q;
int C1, L1, C2, L2;
vector<int> R(3);

int main()
{
    optimize;

    cin >> R[0] >> R[1] >> R[2];
    cin >> N >> Q;

    while(Q--)
    {
        cin >> C1 >> L1 >> C2 >> L2;

        C1--;
        C2--;

        int dist_circular = min(abs(L1 - L2), N - abs(L1 - L2));

        double delta_maior = 2 * pi * R[2] * dist_circular / N;
        double delta_menor = 2 * pi * R[0] * dist_circular / N; 
        double delta_meio = 2 * pi * R[1] * dist_circular / N;
        double ans;
        
        if(C1 == C2)
        {
            if(C1 == 0) ans = delta_menor;
            else if(C1 == 1) ans = min(delta_meio, delta_menor + 2 * (R[1] - R[0]));
            else ans = min(delta_maior, min(delta_meio + 2 * (R[2] - R[1]), delta_menor + 2 * (R[2] - R[0])));
        }
        else
        {
            int menor_caso = min(C1, C2), maior_caso = max(C1, C2);

            if(menor_caso == 0) ans = R[maior_caso] - R[0] + delta_menor;
            else if(menor_caso == 1)
            {
                int reta = R[maior_caso] - R[1];
                double aux = min(delta_meio, delta_menor + 2 * (R[1] - R[0]));
                ans = reta + aux;
            }
        }
        
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }

    return 0;
}