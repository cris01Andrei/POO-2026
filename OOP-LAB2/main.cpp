#include <iostream>
#include "Student.h"
#include "Comparison.h"

using namespace std;

int main() {
    Student s1, s2;

    s1.SetName("Popescu");
    s1.SetMathGrade(9.5);
    s1.SetEnglishGrade(8.0);
    s1.SetHistoryGrade(7.0);

    s2.SetName("Ionescu");
    s2.SetMathGrade(8.0);
    s2.SetEnglishGrade(9.0);
    s2.SetHistoryGrade(7.0);

    cout << "Comparare nume: " << CompareByName(s1, s2) << endl;
    cout << "Comparare Mate: " << CompareByMath(s1, s2) << endl;
    cout << "Comparare Medie: " << CompareByAverage(s1, s2) << endl;

    return 0;
}