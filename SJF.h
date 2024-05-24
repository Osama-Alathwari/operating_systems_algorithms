#include "FCFS.h"

class SJF
{
private:
    Process s;
    int wt;

public:
    SJF(Process ss);
    ~SJF();
    void reOrder();
    void calculateWaitingTime();
    void Chartt();
    void printAverageWaitingTime();
};

SJF::SJF(Process ss)
{
    wt = 0;
    s = ss;
}

SJF::~SJF()
{
}

void SJF::reOrder()
{
    int startShortestCounter = 0, sum = 0;
    // Reorder by arrival time
    for (int i = 0; i < s.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < s.getNumOfProcesses() - 1; j++)
        {
            if (s.getArrivalTime(j) > s.getArrivalTime(j + 1))
            {
                s.Swap(j, j + 1);
            }
        }
        sum += s.getArrivalTime(i);
    }

    //To check where to start the counter from
    if (sum != 0)
        startShortestCounter = 1;

    //Then Reorder by burst time
    for (int i = startShortestCounter; i < s.getNumOfProcesses(); i++)
    {
        for (int j = startShortestCounter; j < s.getNumOfProcesses() - 1; j++)
        {
            if (s.getBurstTime(j) > s.getBurstTime(j + 1))
            {
                s.Swap(j, j + 1);
            }
        }
    }
}

void SJF::Chartt()
{
    cout << "Process Name " << setw(10) << "Arrival Time " << setw(10) << "Burst Time " << setw(10) << endl;
    for (int i = 0; i < s.getNumOfProcesses(); i++)
    {
        cout << s.getProcessName(i) << setw(10) << s.getArrivalTime(i) << setw(10) << s.getBurstTime(i) << setw(10) << endl;
    }
}

void SJF::calculateWaitingTime()
{
    reOrder();
    s.setWaitingTime(0, wt);
    for (int i = 1; i < s.getNumOfProcesses(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            wt += s.getBurstTime(j);
        }
        s.setWaitingTime(i, wt - s.getArrivalTime(i));
        wt = 0;
    }
}

void SJF::printAverageWaitingTime()
{
    float avg = 0;
    for (int i = 0; i < s.getNumOfProcesses(); i++)
    {
        cout << "Waiting Time For [ " << s.getProcessName(i) << " ] = " << s.getWaitingTime(i) << endl;
        avg += s.getWaitingTime(i);
    }
    cout << "Waiting average time = " << avg / s.getNumOfProcesses() << " ms " << endl;
}
