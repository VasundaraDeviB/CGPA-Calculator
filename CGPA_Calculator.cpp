#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    string studentName;
    int n;

    vector<string> subjectNames;
    vector<float> gradePoints;
    vector<float> credits;

    float totalCredits = 0;
    float totalGradePoints = 0;

    cout << "======================================" << endl;
    cout << "        CGPA CALCULATOR" << endl;
    cout << "======================================" << endl;

    cout << "Enter Student Name: ";
    getline(cin >> ws, studentName);

    cout << "Enter number of subjects: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of subjects must be greater than 0." << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        string subject;
        float gradePoint, credit;

        cout << "\nSubject " << i << endl;

        cout << "Subject Name: ";
        getline(cin >> ws, subject);

        do
        {
            cout << "Enter Grade Point (0-10): ";
            cin >> gradePoint;

            if (gradePoint < 0 || gradePoint > 10)
            {
                cout << "Invalid Grade Point! Please enter between 0 and 10." << endl;
            }

        } while (gradePoint < 0 || gradePoint > 10);

        do
        {
            cout << "Enter Credits: ";
            cin >> credit;

            if (credit <= 0)
            {
                cout << "Credits must be greater than 0." << endl;
            }

        } while (credit <= 0);

        subjectNames.push_back(subject);
        gradePoints.push_back(gradePoint);
        credits.push_back(credit);

        totalCredits += credit;
        totalGradePoints += gradePoint * credit;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n======================================" << endl;
    cout << "Student Name : " << studentName << endl;

    cout << "\nCourse Details:" << endl;
    cout << left << setw(20) << "Subject"
         << setw(15) << "Grade Point"
         << setw(10) << "Credits" << endl;

    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < subjectNames.size(); i++)
    {
        cout << left << setw(20) << subjectNames[i]
             << setw(15) << gradePoints[i]
             << setw(10) << credits[i] << endl;
    }

    cout << "\nTotal Credits : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;

    cout << fixed << setprecision(2);
    cout << "CGPA : " << cgpa << endl;

    cout << "======================================" << endl;

    return 0;
}
