#include <iostream>
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
        ll sum = 0, max_val = 0;
        for (int i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            sum += val;
            max_val = max(val, max_val);
        }
        ll k = max(max_val, sum / (n - 1) + (sum % (n - 1) ? 1 : 0));
        cout << (k * (n - 1) - sum) << '\n';
    }
}