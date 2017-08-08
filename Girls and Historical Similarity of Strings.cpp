#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "YES" << endl;
        return;
    }

    set<char> st;
    for (char c : s1)
        st.insert(c);
    if (st.size() == 'z'-'a'+1)
    {
        cout << "NO" << endl;
        return;
    }

    vector<char> change('z'-'a'+1, 0);
    for (int i = s1.length()-1; i >= 0; i--)
    {
        if (s1[i] != s2[i])
        {
            if (change[s1[i]-'a'] != 0 && change[s1[i]-'a'] != s2[i])
            {
                cout << "NO" << endl;
                return;
            }
            change[s1[i]-'a'] = s2[i];
        }
    }

    for (int i = change.size()-1; i >= 0; i--)
        if (change[i] != 0)
            for (int j = i-1; j >= 0; j--)
                if (change[i] == change[j])
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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
