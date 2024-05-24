#include "MENU.h"

int main()
{
    int pn, choice;
    cout << "enter Number of Processes : ";
    cin >> pn;
    Process p(pn);

    do
    {
        MENU m;
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
        {
            p.setProcessName();
            p.setArrivalTime();
            p.setBurstTime();
            cout << endl;
            FCFS f(p);
            system("clear");
            f.calculateWaitingTime();
            f.printAverageWaitingTime();
            f.Chartt();
            cout << endl;
            break;
        }

        case 2:
        {
            p.setProcessName();
            p.setArrivalTime();
            p.setBurstTime();
            cout << endl;
            SJF s(p);
            system("clear");
            s.calculateWaitingTime();
            s.printAverageWaitingTime();
            s.Chartt();
            cout << endl;
            break;
        }

        case 3:
        {
            p.setProcessName();
            p.setArrivalTime();
            p.setBurstTime();
            p.setPriority();
            cout << endl;
            Priority pt(p);
            system("clear");
            pt.calculateWaitingTime();
            pt.printAverageWaitingTime();
            pt.Chartt();
            cout << endl;
            break;
        }
        default:
            system("clear");
            cout << "Invalid Number , Please Try Again" << endl;
        }
    } while (true);

    return 0;
}