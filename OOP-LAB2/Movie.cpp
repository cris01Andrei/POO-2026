#include "Movie.h"

void Movie::set_name(const char* n) {
    int i = 0;
    while (n[i] != '\0' && i < 256) {
        this->name[i] = n[i];
        i++;
    }
    this->name[i] = '\0';
}

const char* Movie::get_name() const {
    return this->name;
}

void Movie::set_year(int y) {
    this->year = y;
}

int Movie::get_year() const {
    return this->year;
}

void Movie::set_score(double s) {
    if (s >= 1.0 && s <= 10.0)
        this->score = s;
}

double Movie::get_score() const {
    return this->score;
}

void Movie::set_length(int l) {
    this->length = l;
}

int Movie::get_length() const {
    return this->length;
}

int Movie::get_passed_years() const {
    return 2026 - this->year;
}