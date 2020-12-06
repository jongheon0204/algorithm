#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

vector<vi> stat;
vector<bool> left_team;
int ans = 0;
int left_stat = 0;
int right_stat = 0;

void find_min_dif(int depth)
{
    if (depth == stat.size())
        return;
    int sum_left = 0, sum_right = 0;
    for (int i = 0; i < left_team.size(); i++)
    {
        if (left_team[i])
            sum_left += (stat[depth][i] + stat[i][depth]);
        else
            sum_right += (stat[depth][i] + stat[i][depth]);
    }
    left_stat += sum_left;
    right_stat -= sum_right;
    left_team[depth] = true;
    ans = min(ans, abs(right_stat - left_stat));
    if (right_stat > left_stat)
    {
        find_min_dif(depth + 1);
    }
    left_team[depth] = true;
    right_stat += sum_right;
    left_stat -= sum_left;
    find_min_dif(depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    left_team = vector<bool>(n);
    stat = vector<vi>(n, vi(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> stat[i][j];
            right_stat += stat[i][j];
        }
    }

    ans = right_stat;
    find_min_dif(0);
    cout << ans;
}