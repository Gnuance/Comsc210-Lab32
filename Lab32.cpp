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

// variables for starting number of cars, liklihood of car paying, liklihood of new car joining line
const int NUM_INITIAL_CARS = 2, CHANCE_CAR_PAYS = 55, CHANCE_NEW_CAR_JOINS = 45;

bool FrontCarPaid();
bool NewCarJoinsQueue();
void CurrentQueueToConsole(deque<Car> &);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // seed current time to rand()
    deque<Car> tollBooth = {};                       // empty toll booth line
    int count = 0;

    // initialize toll booth with 2 vehicles and output to console
    for (int i = 0; i < NUM_INITIAL_CARS; i++)
    {
        tollBooth.push_back(Car());
    }
    cout << "Initial queue:" << endl;
    CurrentQueueToConsole(tollBooth);

    // run simulation until toll booth is empty
    while (!tollBooth.empty())
    {
        if (FrontCarPaid())
        {
            tollBooth.pop_front();
        }
        if (NewCarJoinsQueue())
        {
            tollBooth.push_back(Car());
        }  
    }

    // output list at end of period
    cout << "Resulting list: ";

    return 0;
}

// returns whether front car pays and leaves
bool FrontCarPaid()
{
    return ((rand() % 100) + 1) <= CHANCE_CAR_PAYS;
}

// returns whether a new car will join line
bool NewCarJoinsQueue()
{
    return ((rand() % 100) + 1) <= CHANCE_NEW_CAR_JOINS;
}

// outputs each element in deque
void CurrentQueueToConsole(deque<Car> &q)
{
    int count = 0;
    cout << "Queue:\n";
    for (auto it = q.begin(); it != q.end(); it++)
    {
        cout << "\t";
        it->print();
        count++;
    }
}