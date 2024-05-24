#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>
using namespace std;

class Process
{
private:
    struct ProcessInfo
    {
        string processName;
        int processArrivalTime;
        int processBurstTime;
        int waitingTime;
        int processPriority;
    } * pr;
    int numberOfProcesses;

public:
    Process() {}

    Process(int pn)
    {
        pr = new ProcessInfo[pn];
        numberOfProcesses = pn;
        pr->waitingTime = 0;
    }

    ~Process() {}

    void setProcessName()
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            cout << "Enter process number [ " << i + 1 << " ] name : ";
            cin >> pr[i].processName;
        }
    }

    void setArrivalTime()
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            cout << "Enter arrival time for [ " << pr[i].processName << " ] : ";
            cin >> pr[i].processArrivalTime;
        }
    }

    void setBurstTime()
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            cout << "Enter Burst time for [ " << pr[i].processName << " ] : ";
            cin >> pr[i].processBurstTime;
        }
    }

    void setPriority()
    {
        for (int i = 0; i < numberOfProcesses; i++)
        {
            cout << "Enter Priority for [ " << pr[i].processName << " ] : ";
            cin >> pr[i].processPriority;
        }
    }

    void setWaitingTime(int i, int t)
    {
        pr[i].waitingTime = t;
    }

    /* int sumofBurstTime()
    {
        int i = 0, sum = 0;
        while (i < numberOfProcesses)
        {
            sum += pr[i].processBurstTime;
            i++;
        }
        return sum;
    } */

    int getNumOfProcesses()
    {
        return numberOfProcesses;
    }

    int getBurstTime(int i)
    {
        return pr[i].processBurstTime;
    }

    int getArrivalTime(int i)
    {
        return pr[i].processArrivalTime;
    }

    string getProcessName(int i)
    {
        return pr[i].processName;
    }

    int getWaitingTime(int i)
    {
        return pr[i].waitingTime;
    }

    int getPriority(int i)
    {
        return pr[i].processPriority;
    }

    void Swap(int i, int j)
    {
        ProcessInfo temp;
        temp = pr[i];
        pr[i] = pr[j];
        pr[j] = temp;
    }
};