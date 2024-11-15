/*  Lab 32: Toll Booth
    Objective: Write a program that will simulate a line of cars lined up to pay their toll at a toll booth. We will start with a certain number of cars in the line, and repeatedly perform these line operations until the line is empty:
        1. 55% probability that the car at the head of the line pays its toll and leaves the toll booth
            45% probability that another car joins the line for the toll booth

    Requirements:
        1. Use an std::deque. This means our program structure will be a deque of Cars.
        2. Use a constant and initialize it to 2 to determine the initial size of the deque when the simulation starts (representing how many cars are already in line to pay the toll when the simulation starts).
        3. Use the Car class to create Car objects, which are placed in the std::deque representing the toll booth lane.
        4. Do not alter the Car class.
        5. Run the simulation until the queue is empty.
        6. After each time period, display the queue using the .print() method in the Car class.
*/

#include <iostream>
#include <string>
#include <deque>
#include "Car.h"
using namespace std;

bool FrontCustomerHelped();
bool NewCustomerJoinsLine();
bool CustomerEndOfLineLeaves();
bool AnyCustomerLeaves();
bool VipStraightToFront();
unsigned long RandCustomerInt();

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // seed current time to rand()
    deque<Car> tollBooth = {}; // empty toll booth line

    while (getline(inputFile, fileLine))
    {
        names.push_back(fileLine);
    }
    inputFile.close();
    // Names are now in vector

    // Start line
    cout << "Initial queue:" << endl;
    for (int i = 0; i < 5; i++)
    {
        name = names.at(RandCustomerInt());
        coffeeLine.push_back(name);
        cout << "\t" << name << " joins the line" << endl;
    }

    cout << "Resulting list: ";

    return 0;
}

bool FrontCustomerHelped()
{
    return ((rand() % 100) + 1) <= 40;
}
bool NewCustomerJoinsLine()
{
    return ((rand() % 100) + 1) <= 60;
}
bool CustomerEndOfLineLeaves()
{
    return ((rand() % 100) + 1) <= 20;
}
bool AnyCustomerLeaves()
{
    return ((rand() % 100) + 1) <= 10;
}
bool VipStraightToFront()
{
    return ((rand() % 100) + 1) <= 10;
}
unsigned long RandCustomerInt()
{
    return (rand() % 99) + 1;
}