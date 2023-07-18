#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int time_accumulation(vector<int> time, vector<bool> &status, bool torch)
{
    int sum = accumulate(status.begin(), status.end(), 0);
    if (sum == status.size())
    {
        return 0;
    }

    if (!torch)
    {
        int minNum = INT_MAX;
        for (int i = 0; i < status.size(); i++)
        {
            for (int j = i + 1; j < status.size(); j++)
            {
                if (status[i] == 0 && status[j] == 0)
                {
                    status[i] = 1;
                    status[j] = 1;
                    minNum = min(minNum, max(time[i], time[j]) + time_accumulation(time, status, 1));
                }
            }
        }
        return minNum;
    }
    else
    {
        int minNum = INT_MAX;
        for (int i = 0; i < status.size(); i++)
        {
            if (status[i] == 1)
            {
                status[i] = 0;
                minNum = min(minNum, time[i] + time_accumulation(time, status, 0));
            }
        }
        return minNum;
    }

    return 0;
}

int main()
{
    vector<int> time = {1, 2, 5, 10};
    vector<bool> status(4, 0);
    bool torch = 0;
    cout << time_accumulation(time, status, torch) << endl;
    return 0;
}