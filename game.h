#ifndef ABC_GAME_H
#define ABC_GAME_H

#include <stdio.h>
#include "film.h"

//------------------------------------------------------------------------------
// игровой фильм
struct game: film {
    char director[20];
};

// Ввод параметров игрового фильма
void In(game &game, std::ifstream &ifst);

// Случайный ввод параметров игрового фильма
void InRnd(game &е);

// Вывод параметров игрового фильма
void Out(game &t, std::ofstream &ofst);

#endif //ABC_GAME_H
