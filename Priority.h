#include "SJF.h"

class Priority
{
private:
    Process pt;
    int wt;

public:
    Priority(Process prt);
    ~Priority();
    void reOrder();
    void calculateWaitingTime();
    void Chartt();
    void printAverageWaitingTime();
};

Priority::Priority(Process prt)
{
    wt = 0;
    pt = prt;
}

Priority::~Priority()
{
}

void Priority::reOrder()
{
    int startPriorityCounter = 0, sum = 0;
    // Reorder by arrival time
    for (int i = 0; i < pt.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < pt.getNumOfProcesses() - 1; j++)
        {
            if (pt.getArrivalTime(j) > pt.getArrivalTime(j + 1))
            {
                pt.Swap(j, j + 1);
            }
        }
        sum += pt.getArrivalTime(i);
    }

    //To check where to start the counter from
    if (sum != 0)
        startPriorityCounter = 1;

    //Then Reorder by Priority
    for (int i = startPriorityCounter; i < pt.getNumOfProcesses(); i++)
    {
        for (int j = startPriorityCounter; j < pt.getNumOfProcesses() - 1; j++)
        {
            if (pt.getPriority(j) > pt.getPriority(j + 1))
            {
                pt.Swap(j, j + 1);
            }
        }
    }
}

void Priority::Chartt()
{
    cout << "Process Name " << setw(10) << "Arrival Time " << setw(10) << "Burst Time " << setw(10) << "Priority" << setw(10) << endl;
    for (int i = 0; i < pt.getNumOfProcesses(); i++)
    {
        cout << pt.getProcessName(i) << setw(10) << pt.getArrivalTime(i) << setw(10) << pt.getBurstTime(i) << setw(10) << pt.getPriority(i) << setw(10) << endl;
    }
}

void Priority::calculateWaitingTime()
{
    reOrder();
    pt.setWaitingTime(0, wt);
    for (int i = 1; i < pt.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            wt += pt.getBurstTime(j);
        }
        pt.setWaitingTime(i, wt - pt.getArrivalTime(i));
        wt = 0;
    }
}

void Priority::printAverageWaitingTime()
{
    float avg = 0;
    for (int i = 0; i < pt.getNumOfProcesses(); i++)
    {
        cout << "Waiting Time For [ " << pt.getProcessName(i) << " ] = " << pt.getWaitingTime(i) << endl;
        avg += pt.getWaitingTime(i);
    }
    cout << "Waiting average time = " << avg / pt.getNumOfProcesses() << " ms " << endl;
}