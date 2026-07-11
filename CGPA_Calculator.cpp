#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    string studentName;
    vector<string> subjectNames;
    int n;
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

    for(int i = 1; i <= n; i++)
    {
        float gradePoint, credit;

        cout << "\nSubject " << i << endl;

        string subject;
        
        cout << "Subject Name: ";
        getline(cin >> ws, subject);
        
        subjectNames.push_back(subject);

        do
        {            
            cout << "Enter Grade Point (0-10): ";
            cin >> gradePoint;
            
            if (gradePoint < 0 || gradePoint > 10)
            {
                cout << "Invalid Grade Point! Please enter between 0 and 10.\n";
            }
        } while (gradePoint < 0 || gradePoint > 10);

        do
        {
            cout << "Enter Credits: ";
            cin >> credit;

            if (credit <= 0)
            {
                cout << "Credits must be greater than 0.\n";
            }
        
        } while (credit <= 0);

        totalCredits += credit;
        totalGradePoints += gradePoint * credit;
    }

    float cgpa = totalGradePoints / totalCredits;
    
    cout << "\n======================================" << endl;
    cout << "Student Name : " << studentName << endl;
    cout << "\nSubjects:" << endl;
    for(int i = 0; i < subjectNames.size(); i++)
    {
        cout << i + 1 << ". " << subjectNames[i] << endl;
    }
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << fixed << setprecision(2);
    cout << "CGPA         : " << cgpa << endl;
    
    cout << "======================================" << endl;

    return 0;
}