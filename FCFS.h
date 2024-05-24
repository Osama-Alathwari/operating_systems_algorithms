#include "Process.h"

class FCFS
{
private:
    Process p;
    int wt;

public:
    FCFS(Process P);
    void calculateWaitingTime();
    void reOrder();
    void printAverageWaitingTime();
    void Chartt();
};

FCFS::FCFS(Process P)
{
    wt = 0;
    this->p = P;
}

void FCFS::reOrder()
{
    for (int i = 0; i < p.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < p.getNumOfProcesses() - 1; j++)
        {
            if (p.getArrivalTime(j) > p.getArrivalTime(j + 1))
            {
                p.Swap(j, j + 1);
            }
        }
    }
}

void FCFS::calculateWaitingTime()
{
    reOrder();
    p.setWaitingTime(0, wt);
    for (int i = 1; i < p.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            wt += p.getBurstTime(j);
        }
        p.setWaitingTime(i, wt - p.getArrivalTime(i));
        wt = 0;
    }
}

void FCFS::Chartt()
{
    cout << "Process Name " << setw(10) << "Arrival Time " << setw(10) << "Burst Time " << setw(10) << endl;
    for (int i = 0; i < p.getNumOfProcesses(); i++)
    {
        cout << p.getProcessName(i) << setw(10) << p.getArrivalTime(i) << setw(10) << p.getBurstTime(i) << setw(10) << endl;
    }
}

void FCFS::printAverageWaitingTime()
{
    float avg = 0;
    for (int i = 0; i < p.getNumOfProcesses(); i++)
    {
        cout << "Waiting Time For [ " << p.getProcessName(i) << " ] = " << p.getWaitingTime(i) << endl;
        avg += p.getWaitingTime(i);
    }
    cout << "Waiting average time = " << avg / p.getNumOfProcesses() << " ms " << endl;
}