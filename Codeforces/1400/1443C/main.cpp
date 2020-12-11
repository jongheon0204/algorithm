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
        vector<int> delivery(n);
        vector<int> pick_up(n);
        vector<int> idx;

        ll left = 0;
        ll right = 0;

        for (int i = 0; i < n; i++)
            cin >> delivery[i];
        for (int i = 0; i < n; i++)
        {
            cin >> pick_up[i];
            if (delivery[i] > pick_up[i])
            {
                idx.push_back(i);
            }
            else
            {
                left = max(left, (ll)delivery[i]);
            }
            right += pick_up[i];
        }

        ll ans = right;
        while (left <= right)
        {
            ll mid = (left + right) / 2;
            ll sum = 0;
            for (int i = 0; i < idx.size(); i++)
            {
                if (delivery[idx[i]] > mid)
                {
                    sum += pick_up[idx[i]];
                }
            }
            if (sum <= mid)
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << ans << '\n';
    }
}