#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef long long LL;
typedef int LL;

const int MaxM = 1000;

LL binPow(LL a, LL n, LL m)
{
    if (n == 0) return 1LL;
    if (n == 1) return a % m;
    
    LL t = binPow(a, n/2, m);
    LL ans = (t * t) % m;
    if (n%2 == 1)
    {
        ans *= a;
        ans %= m;
    }
    
    ans += m;
    ans %= m;
    return ans;
}

LL rem[MaxM+5];

LL getSumBrut(LL first, LL q, LL n, LL m)
{
    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + first) % m;
        first = (first * q) % m;
    }
    
    return sum;
}

LL findLoopSum(LL first, LL q, LL m, LL &loopStart, LL &loopLeng, LL &loopStartValue)
{
    LL t = first;
    int i = 1;
    while (1)
    {
        t = (t * q) % m;
        i++;
        if (rem[t]==0)
        {
            rem[t] = i;
        }
        else
        {
            loopStartValue = t;
            loopStart = rem[t];
            loopLeng = i - loopStart;
            break;
        }
    }
    
    return getSumBrut(t, q, loopLeng, m);
}

LL getSum(LL first, LL q, LL n, LL m)
{
    for (int i = 0; i <= m; i++)
        rem[i] = 0;
    
    rem[first] = 1;
    LL loopStart, loopLeng, loopStartValue;
    LL loopSum = findLoopSum(first, q, m, loopStart, loopLeng, loopStartValue);
    if (n <= loopStart + loopLeng)
        return getSumBrut(first, q, n, m);
    
    LL preSum = getSumBrut(first, q, loopStart - 1, m);
    LL afterSum = getSumBrut(loopStartValue, q, (n - loopStart + 1) % loopLeng, m);
    LL loopRepeats = ((n - loopStart + 1) / loopLeng) % m;
    loopSum = (loopSum * loopRepeats) % m;
    
    LL sum = preSum + loopSum + afterSum;
    sum %= m;
    sum += m;
    sum %= m;
    return sum;
}

void solve()
{
    LL n, m;
    cin >> n >> m;
    
    LL k = n / m;
    LL r = n % m;
    LL sum = 1;
    for (int i = 1; i <= r; i++)
    {
        LL first = binPow(i, i, m);
        LL q = binPow(i, m, m);
        LL t = getSum(first, q, k + 1, m);
        sum = (sum + t) % m;
    }
    for (int i = r+1; i < m; i++)
    {
        LL first = binPow(i, i, m);
        LL q = binPow(i, m, m);
        LL t = getSum(first, q, k, m);
        sum = (sum + t) % m;
    }
    
    sum %= m;
    sum += m;
    sum %= m;
    
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
        solve();
    
    return 0;
}
