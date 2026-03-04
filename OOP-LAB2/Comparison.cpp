#include "Comparison.h"

int CompareByName(const Student& s1, const Student& s2) {
    const char* n1 = s1.GetName();
    const char* n2 = s2.GetName();
    int i = 0;
    while (n1[i] != '\0' && n2[i] != '\0') {
        if (n1[i] < n2[i]) return -1;
        if (n1[i] > n2[i]) return 1;
        i++;
    }
    if (n1[i] == '\0' && n2[i] == '\0') return 0;
    return (n1[i] == '\0') ? -1 : 1;
}

int CompareByMath(const Student& s1, const Student& s2) {
    if (s1.GetMathGrade() == s2.GetMathGrade()) return 0;
    return (s1.GetMathGrade() > s2.GetMathGrade()) ? 1 : -1;
}

int CompareByEnglish(const Student& s1, const Student& s2) {
    if (s1.GetEnglishGrade() == s2.GetEnglishGrade()) return 0;
    return (s1.GetEnglishGrade() > s2.GetEnglishGrade()) ? 1 : -1;
}

int CompareByHistory(const Student& s1, const Student& s2) {
    if (s1.GetHistoryGrade() == s2.GetHistoryGrade()) return 0;
    return (s1.GetHistoryGrade() > s2.GetHistoryGrade()) ? 1 : -1;
}

int CompareByAverage(const Student& s1, const Student& s2) {
    float a1 = s1.GetAverage();
    float a2 = s2.GetAverage();
    if (a1 == a2) return 0;
    return (a1 > a2) ? 1 : -1;
}