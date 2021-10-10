#ifndef ABC_CARTOON_H
#define ABC_CARTOON_H

#include <stdio.h>
#include "film.h"

//------------------------------------------------------------------------------
// мультфильм
struct cartoon: film {
    enum cr_type {DRAWN, PUPPET, PLASTICINE};
    cr_type cr_tp;
};

// Ввод параметров мультфильма
void In(cartoon &t, std::ifstream &ifst);

// Случайный ввод параметров мультфильма
void InRnd(cartoon &е);

// Вывод параметров мультфильма
void Out(cartoon &t, std::ofstream &ofst);

#endif //ABC_CARTOON_H
