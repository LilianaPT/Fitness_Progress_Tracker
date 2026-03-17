# Fitness Progress Tracker 🏃‍♀️

A C++ console application designed to help users log and analyze multiple running sessions. The program calculates performance metrics like pace and calories burned, while providing a comprehensive final report of the user's fitness journey.

## 🌟 Key Features

- **Multi-Session Logging:** Log between 1 to 10 workout sessions in a single run.
- **Real-time Calculations:** 
  - **Pace:** Calculates minutes per mile for every session.
  - **Calories:** Estimates energy expenditure based on body weight and distance.
- **Robust Input Validation:** Uses `do-while` loops to ensure distance, time, and weight are always positive numbers.
- **Cumulative Reporting:** Aggregates total distance, total time, and total calories burned across all sessions.
- **Average Performance:** Calculates an overall average pace for the entire workout period.

## 🧮 Calculation Logic

The program uses the following formulas to provide fitness insights:


| Metric | Formula |
| :--- | :--- |
| **Pace** | `Time / Distance` |
| **Calories** | `0.75 * Weight * Distance` |
| **Average Pace** | `Total Time / Total Distance` |

## 🛠️ Technical Highlights

This project demonstrates several intermediate C++ concepts:
- **Pass-by-Reference:** Efficiently updating total values using reference parameters (`double&`).
- **Modular Programming:** Clean organization using function prototypes and specific definitions for data collection, calculation, and display.
- **Formatting:** Utilizing `<iomanip>` to ensure all fitness data is displayed to exactly two decimal places for a professional look.
- **System Control:** Uses `system("cls")` to maintain a clean user interface between rounds.

## 🚀 How to Use

1. Run the program.
2. Enter the number of sessions you wish to log (1-10).
3. Provide your weight, distance run, and time for each session.
4. Review the **Session Summary** after each entry.
5. Analyze your **Final Report** to see your total progress!

---
**Author:** Liliana Pantoja  
CIS-121 - Spring 2026  
Assignment 2, Problem 1
