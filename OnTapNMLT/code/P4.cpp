#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

struct Flight {
    string airline;
    string departure;
    string destination;
    string departureDate;
    string price;
};

vector<string> splitString(const string& input, char delimiter) {
    vector<string> substrings;
    string substring;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != string::npos) {
        substring = input.substr(start, end - start);
        substrings.push_back(substring);
        start = end + 1;
        end = input.find(delimiter, start);
    }

    substring = input.substr(start);
    substrings.push_back(substring);

    return substrings;
}

void removeEmptyStrings(vector<string>& substrings) {
    substrings.erase(remove(substrings.begin(), substrings.end(), ""), substrings.end());
}

Flight parseFlight(const string& line) {
    Flight flight;
    vector<string> substrings = splitString(line, ',');

    removeEmptyStrings(substrings);
    flight.airline = substrings[0];
    flight.departure = substrings[1];
    flight.destination = substrings[2];
    flight.departureDate = substrings[3];
    flight.price = substrings[4];
    return flight;
}

int readData(FILE* f, Flight flights[]) {
    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), f)) {
        string flightStr(line);
        flights[count] = parseFlight(flightStr);
        count++;
    }

    return count;
}


int convertDateToNumber(const std::string& date) {
    if (date.length() != 8) {
        throw std::invalid_argument("Invalid date format");
    }

    std::string dayStr = date.substr(0, 2);
    std::string monthStr = date.substr(2, 2);
    std::string yearStr = date.substr(4, 4);

    int day = std::stoi(dayStr);
    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    return year * 10000 + month * 100 + day;
}

bool compareDates(const std::string& date1, const std::string& date2) {
    int dateNumber1 = convertDateToNumber(date1);
    int dateNumber2 = convertDateToNumber(date2);

    if (dateNumber1 < dateNumber2) {
        return true; 
    }
    else {
        return false;
    }
}

bool compareFlights(const Flight& flight1, const Flight& flight2) {
    if (flight1.departureDate != flight2.departureDate)
        return compareDates(flight1.departureDate, flight2.departureDate);
    else
        return flight1.price < flight2.price;
}

void sortFlights(Flight flights[], int nFlight) {
    sort(flights, flights + nFlight, compareFlights);
}

void printData(FILE* g, const Flight flights[], int nFlight) {
    for (int i = 0; i < nFlight; i++) {
        fprintf(g, "%s,%s,%s,%s,%s", flights[i].airline.c_str(), flights[i].departure.c_str(), flights[i].destination.c_str(), flights[i].departureDate.c_str(), flights[i].price.c_str());
    }
}

int main() {
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    const int maxFlights = 100;

    Flight flights[maxFlights];
    FILE* inputFilePtr;
    fopen_s(&inputFilePtr, inputFile, "r");
    if (inputFilePtr == nullptr) {
        cout << "Khong the mo file input." << endl;
        return 1;
    }

    int nFlight = readData(inputFilePtr, flights);
    fclose(inputFilePtr);

    sortFlights(flights, nFlight);

    FILE* outputFilePtr;
    fopen_s(&outputFilePtr, outputFile, "w");
    if (outputFilePtr == nullptr) {
        cout << "Khong the mo file output." << endl;
        return 1;
    }
    printData(outputFilePtr, flights, nFlight);
    fclose(outputFilePtr);

    return 0;
}