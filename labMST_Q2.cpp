#include <bits/stdc++.h>
using namespace std;

int maxProd(vector<string> &words)
{
    int n = words.size();
    vector<int> bitmask(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (char c : words[i])
        {
            bitmask[i] |= (1 << (c - 'a'));
        }
    }



    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((bitmask[i] & bitmask[j]) == 0)
            {
                ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout << maxProd(words) << endl;
    return 0;
}