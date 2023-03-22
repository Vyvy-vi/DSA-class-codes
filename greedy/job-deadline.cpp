/*
* n jobs - profit, deadline

* if job done before or on deadline -> profit
* one job at a time
* first job at 0 timestamp
* every job is taking unit time for
being finished.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int count = 0;

struct Job
{
public:
    int id;
    int deadline;
    int profit;

    Job() {}
    Job(int d, int p)
    {
        id = ::count++;
        deadline = d;
        profit = p;
    }
};

bool profitCmp(Job a, Job b)
{
    return a.profit > b.profit;
}

template <size_t N>
void printJobSchedule(Job (&jobs)[N])
{
    sort(jobs, jobs + N, profitCmp);
    bool slot[N] = {false};

    int schedule[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = min(int(N), jobs[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                schedule[j] = i;
                break;
            }
        }
    }

    long profit = 0;
    cout << "Schedule: ";
    for (int i = 0; i < N; i++)
    {
        if (slot[i])
        {
            cout << char(jobs[schedule[i]].id + 97) << " ";
            profit += jobs[schedule[i]].profit;
        }
    }
    cout << endl;
    cout << "Profit: " << profit << endl;
}

int main()
{
    Job jobs[] = {
        Job(2, 100),
        Job(1, 10),
        Job(2, 27),
        Job(1, 25),
        Job(3, 15),
    };

    printJobSchedule(jobs);
}