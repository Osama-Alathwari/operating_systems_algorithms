#include "Priority.h"

class MENU
{
public:
    MENU();
};

MENU::MENU()
{
    cout << "1 - FCFS Algorithm " << endl
         << "2 - SJF non-preemptive Algorithm " << endl
         << "3 - Priority non-preemptive Algorithm " << endl
         << "0 - Exit" << endl
         << "Enter your Choice : ";
}