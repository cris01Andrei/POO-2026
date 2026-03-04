#include "GlobalFunctions.h"

int movie_compare_name(const Movie& m1, const Movie& m2) {
    const char* n1 = m1.get_name();
    const char* n2 = m2.get_name();
    int i = 0;
    while (n1[i] != '\0' && n2[i] != '\0') {
        if (n1[i] < n2[i]) return -1;
        if (n1[i] > n2[i]) return 1;
        i++;
    }
    if (n1[i] == n2[i]) return 0;
    return (n1[i] == '\0') ? -1 : 1;
}

int movie_compare_year(const Movie& m1, const Movie& m2) {
    if (m1.get_year() == m2.get_year()) return 0;
    return (m1.get_year() > m2.get_year()) ? 1 : -1;
}

int movie_compare_score(const Movie& m1, const Movie& m2) {
    if (m1.get_score() == m2.get_score()) return 0;
    return (m1.get_score() > m2.get_score()) ? 1 : -1;
}

int movie_compare_length(const Movie& m1, const Movie& m2) {
    if (m1.get_length() == m2.get_length()) return 0;
    return (m1.get_length() > m2.get_length()) ? 1 : -1;
}

int movie_compare_passed_years(const Movie& m1, const Movie& m2) {
    if (m1.get_passed_years() == m2.get_passed_years()) return 0;
    return (m1.get_passed_years() > m2.get_passed_years()) ? 1 : -1;
}