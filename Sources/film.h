#ifndef ABC_FILM_H
#define ABC_FILM_H

#include <stdlib.h>
#include <string.h>
#include <fstream>

struct film {
    int publication_year;
    enum key {GAME, CARTOON, DOCUMENTARY};
    key k;
    char name[20];
};

// Ввод
film *In(std::ifstream &ifdt);

// Случайный ввод
film *InRnd();

// Вывод
void Out(film &s, std::ofstream &ofst);

// Вычисление частного от деления года выхода на длину названия обобщённого фильма
double DivideYearByLength(film &film);

// Удаление обобщенного фильма
void DeleteFilm(film *s);

#endif //ABC_FILM_H
