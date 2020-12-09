#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> data(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
            if (i)
                sum += abs(data[i] - data[i - 1]);
        }
        ll ans = sum;
        ans = min(ans, sum - abs(data[0] - data[1]));
        ans = min(ans, sum - abs(data[n - 1] - data[n - 2]));
        for (int i = 1; i < n - 1; i++)
        {
            ans = min(ans, sum - abs(data[i] - data[i - 1]) - abs(data[i + 1] - data[i]) + abs(data[i + 1] - data[i - 1]));
        }
        cout << ans << '\n';
    }
}