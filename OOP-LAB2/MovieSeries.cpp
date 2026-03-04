#include "MovieSeries.h"
#include <stdio.h>

void MovieSeries::init() {
    this->count = 0;
}

void MovieSeries::add(Movie* m) {
    if (this->count < 16) {
        this->movies[this->count] = m;
        this->count++;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < this->count; i++) {
        printf("Name: %s | Year: %d | Score: %.1f | Length: %d min | Passed: %d\n",
               movies[i]->get_name(),
               movies[i]->get_year(),
               movies[i]->get_score(),
               movies[i]->get_length(),
               movies[i]->get_passed_years());
    }
}

void MovieSeries::sort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (movies[i]->get_passed_years() < movies[j]->get_passed_years()) {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}