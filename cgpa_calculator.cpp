#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<string> courseNames(n);
    vector<double> grades(n), credits(n);

    double totalCredits = 0, totalPoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter course name: ";
        cin >> courseNames[i];
        cout << "Enter grade (on 10-point scale): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalPoints += grades[i] * credits[i];
    }

    double cgpa = totalPoints / totalCredits;
    cout << fixed << setprecision(2);
    cout << "\n----- CGPA Report -----\n";
    for (int i = 0; i < n; i++) {
        cout << courseNames[i] << " -> Grade: " << grades[i]
             << ", Credits: " << credits[i] << endl;
    }
    cout << "Overall CGPA: " << cgpa << endl;
    return 0;
}