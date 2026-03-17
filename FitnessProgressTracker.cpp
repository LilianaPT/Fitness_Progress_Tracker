/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Assn 2
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/13/2025

Purpose: This program tracks fitness progress by allowing users to 
log multiple running sessions. It validates user input for distance, 
time, and weight, calculates pace and calories burned per session, 
and provides a cumulative final report of all workouts.
********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Function Prototypes
void getSessionData(int sessionNum, int totalNumSe, double& distance, double& time, double& weight);
double calculatePace(double distance, double time);
double calculateCalories(double weight, double distance);
void updateTotals(double dist, double time, double calories, double& totalDist, double& totalTime, double& totalCals);
void displaySessionSummary(int sessionNum, double pace, double calories);
void displayFinalReport(int totalSessions, double totalDist, double totalTime, double totalCals);

int main()
{
    //Variable Declarations
    int numSessions;
    double totalDist = 0, totalTime = 0, totalCals = 0;
    double distance, time, weight;
    double currentPace, currentCals;
    char choice;

    //Set output formatting to 2 decimal places
    cout << fixed << showpoint << setprecision(2);
    do {
        cout << "Welcome to the Fitness Progress Tracker!" << endl;
        //Get and validate the number of sessions to log
        cout << "How many workout sessions would you like to log (1-10)? ";
        cin >> numSessions;

        while (numSessions < 1 || numSessions > 10) {
            cout << "Invalid input. Please enter a number between 1 and 10: ";
            cin >> numSessions;
        }

        cout << endl;
        //Main loop to process each session
        for (int i = 1; i <= numSessions; i++) {
            //Collect user input for the current session
            getSessionData(i, numSessions, distance, time, weight);

            //Perform calculations
            currentPace = calculatePace(distance, time);
            currentCals = calculateCalories(weight, distance);

            //Accumulate totals for the final report
            updateTotals(distance, time, currentCals, totalDist, totalTime, totalCals);

            //Show summary for the individual session
            displaySessionSummary(i, currentPace, currentCals);
            cout << endl;
        }
        //Show the final aggregated results
        displayFinalReport(numSessions, totalDist, totalTime, totalCals);

        cout << "\nWould you like to perform another round of sessions? (Y/N):";
        cin >> choice;
        system("pause");
        system("cls");
    } while (choice == 'Y' || choice == 'y');
    return 0;
}
//Prompts user for session-specific data with input validation loops
void getSessionData(int sessionNum, int totalNumSe, double& distance, double& time, double& weight) {
    cout << "Session " << sessionNum << " of " << totalNumSe << endl;

    do {
        cout << "Enter distance run (miles): ";
        cin >> distance;
        if (distance <= 0) {
            cout << "Error. Distance must be positive." << endl;
        }
    } while (distance <= 0);

    do {
        cout << "Enter time taken (minutes): ";
        cin >> time;
        if (time <= 0) {
            cout << "Error. Time must be positive." << endl;
        }
    } while (time <= 0);

    do {
        cout << "Enter your body weight (lbs): ";
        cin >> weight;
        if (weight <= 0) {
            cout << "Error. Weight must be positive." << endl;
        }
    } while (weight <= 0);
}
//Calculates pace in minutes per mile
double calculatePace(double distance, double time) {
    return time / distance;
}
//Calculates calories burned based on a standard MET formula
double calculateCalories(double weight, double distance) {
    return 0.75 * weight * distance;
}
//Adds current session values to the running totals using pass-by-reference
void updateTotals(double dist, double time, double calories, double& totalDist, double& totalTime, double& totalCals) {
    totalDist += dist;
    totalTime += time;
    totalCals += calories;
}
//Prints a formatted summary for a single session
void displaySessionSummary(int sessionNum, double pace, double calories) {
    cout << "\n----- Session " << sessionNum << " Summary -----" << endl;
    cout << "Pace: \t\t\t" << pace << " min/mile" << endl;
    cout << "Calories Burned: \t" << calories << " cal" << endl;
}
//Prints the final aggregated data for all logged sessions
void displayFinalReport(int totalSessions, double totalDist, double totalTime, double totalCals) {
    double avgPace;
    //Prevent division by zero if no distance was recorded
    if (totalDist > 0) {
        avgPace = totalTime / totalDist;
    }
    else {
        avgPace = 0;
    }

    cout << "\n========= FINAL REPORT =========" << endl;
    cout << "Total Sessions: \t" << totalSessions << endl;
    cout << "Total Distance: \t" << totalDist << " miles" << endl;
    cout << "Total Time: \t\t" << totalTime << " minutes" << endl;
    cout << "Total Calories: \t" << totalCals << " cal" << endl;
    cout << "Average Pace: \t\t" << avgPace << " min/mile" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
