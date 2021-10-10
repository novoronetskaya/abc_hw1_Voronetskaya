#ifndef ABC_DOCUMENTARY_H
#define ABC_DOCUMENTARY_H

#include <stdio.h>
#include "film.h"

//------------------------------------------------------------------------------
// документальный фильм
struct documentary: film {
    int length;
};

// Ввод параметров документального фильма
void In(documentary &t, std::ifstream &ifst);

// Случайный ввод параметров документального фильма
void InRnd(documentary &е);

// Вывод параметров документального фильма
void Out(documentary &t, std::ofstream &ofst);

#endif //ABC_DOCUMENTARY_H
