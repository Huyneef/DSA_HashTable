#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        a[i] = tolower(a[i]);
    }
    
    int ans[26] = {};
    for (int i = 0; i < n; i++)
    {
        ans[(int)a[i] - (int)'a'] = 1;
    }
    int ans2 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (ans[i] == 0)
            ans2++;
    }
    cout << ans2 << endl;
}