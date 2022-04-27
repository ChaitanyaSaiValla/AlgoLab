#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
template <class T1, class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair()
    {
        first = 0;
        second = 0;
    }
    Pair(T1 a, T2 b)
    {
        first = a;
        second = b;
    }
};
void swap(Pair<float, int> *x, Pair<float, int> *y)
{
    Pair<float, int> temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int n, cap;
    cin >> n >> cap;
    int weights[n], profits[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }
    auto start = high_resolution_clock::now();
    Pair<float, int> profits_per_weight[n];
    for (int i = 0; i < n; i++)
    {
        float p = (float)profits[i] / (float)weights[i];
        profits_per_weight[i] = Pair<float, int>(p, i);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profits_per_weight[j].first > profits_per_weight[j + 1].first)
                swap(&profits_per_weight[j], &profits_per_weight[j + 1]);
        }
    int ans_profit = 0;
    vector<int> a, b;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cap)
        {
            if (cap >= weights[profits_per_weight[i].second])
            {
                cap -= weights[profits_per_weight[i].second];
                ans_profit += profits[profits_per_weight[i].second];
                a.push_back(weights[profits_per_weight[i].second]);
                b.push_back(i);
            }
            else
            {
                ans_profit += profits_per_weight[i].first * cap;
                a.push_back(cap);
                b.push_back(i);
                cap = 0;
            }
        }
        else
        {
            break;
        }
    }
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "Profit : " << ans_profit << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << "item no: " << b[i] + 1 << ", weight = " << a[i] << "\n";
    }
    cout << "Time taken : " << timetaken << " microseconds";
    return 0;
}
