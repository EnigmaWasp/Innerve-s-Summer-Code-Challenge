#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

const int MaxN = 10;
const int INF = 1000000;
const pii inf = {INF, INF};
int pf[MaxN+5][MaxN+5];
int pt[MaxN+5][MaxN+5];
pii dp[MaxN+5][MaxN+5];

void check(int i, int j, int i1, int j1, queue<pii> &q)
{
    pii p = dp[i][j];
    p.first += pf[i1][j1];
    p.second += pt[i1][j1];
    if (p < dp[i1][j1])
    {
        dp[i1][j1] = p;
        q.push({i1, j1});
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = MaxN+1; i >= 0; i--)
        for (int j = MaxN+1; j >= 0; j--)
    {
        pf[i][j] = INF;
        pt[i][j] = INF;
        dp[i][j] = inf;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> pf[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> pt[i][j];

    dp[1][1] = {pf[1][1], pt[1][1]};

    queue<pii> q;
    q.push({1,1});
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;

        check(i, j, i+1, j, q);
        check(i, j, i-1, j, q);
        check(i, j, i, j+1, q);
        check(i, j, i, j-1, q);


    }

    cout << dp[n][m].first << " " << dp[n][m].second << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
        solve();

	return 0;
}
