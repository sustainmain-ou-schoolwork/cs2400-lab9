/**
 *    @file: lab9.cc
 *  @author: Josh Marusek
 *    @date: 2021-10-22
 *   @brief: Reads temperature data then prints the highest, lowest and average
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int getLowest(const int numbers[], int length);
int getHighest(const int numbers[], int length);
double getAverage(const int numbers[], int length);

int main()
{
    int temperatures[30];
    int nextTemp;
    ifstream dataFile;

    dataFile.open("athens_low_temps.txt");

    if (dataFile.fail()) {
        cout << "Failed to open file." << endl;
    }
    else {
        // load the array with values from the file
        for (int i = 0; i < 30; i++) {
            dataFile >> nextTemp;
            temperatures[i] = nextTemp;
        }
        dataFile.close();  // close the file

        cout << "Lowest temperature: " << getLowest(temperatures, 30) << endl;
        cout << "Highest temperature: " << getHighest(temperatures, 30) << endl;
        cout << "Average temperature: " << getAverage(temperatures, 30) << endl;
    }

    return (EXIT_SUCCESS);
}

/**
 *  Function: getLowest
 *  @brief Returns the lowest value of an array.
 * 
 *  @param numbers the array of numbers to check
 *  @param length the number of elements in the array
 *  @return the lowest value from the array
 */
int getLowest(const int numbers[], int length) {
    int lowest = numbers[0];
    for (int i = 0; i < length; i++) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }

    return lowest;
}

/**
 *  Function: getHighest
 *  @brief Returns the highest value of an array.
 * 
 *  @param numbers the array of numbers to check
 *  @param length the number of elements in the array
 *  @return the highest value from the array
 */
int getHighest(const int numbers[], int length) {
    int highest = numbers[0];
    for (int i = 0; i < length; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }

    return highest;
}

/**
 *  Function: getAverage
 *  @brief Returns the average value of an array.
 * 
 *  @param numbers the array of numbers to check
 *  @param length the number of elements in the array
 *  @return the average value from the array
 */
double getAverage(const int numbers[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += numbers[i];
    }

    return (static_cast<double>(sum) / length);
}