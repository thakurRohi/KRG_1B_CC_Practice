#include <bits/stdc++.h>
using namespace std;

static int cmp(vector<int> &a, vector<int> &b)
{
    return (b[1] - b[0]) < (a[1] - a[0]);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> energy(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> energy[i][0] >> energy[i][1];
    }

    sort(energy.begin(), energy.end(), cmp);

    int curr = 0;
    int ans = 0;

    for (int i = 0; i < energy.size(); i++)
    {
        int mini = energy[i][1];
        int act = energy[i][0];

        if (curr < mini)
        {
            ans += mini - curr;
            curr = mini;
        }
        curr -= act;
    }
    cout << ans << endl;
    return 0;
}