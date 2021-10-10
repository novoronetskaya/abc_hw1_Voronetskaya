//------------------------------------------------------------------------------
// game.cpp - содержит функции обработки игрового фильма
//------------------------------------------------------------------------------

#include "game.h"

//------------------------------------------------------------------------------
// Ввод параметров игрового фильма
void In(game &game, std::ifstream &ifst) {
    ifst >> game.name >> game.publication_year >> game.director;
}

// Случайный ввод параметров игрового фильма
void InRnd(game &gm) {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    gm.publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        gm.name[i] = 'a' + rand() % 26;
    }
    gm.name[name_length] = '\0';
    int director_length = rand() % 19 + 1;
    for (int i = 0; i < director_length; ++i) {
        gm.director[i] = 'a' + rand() % 26;
    }
    gm.director[name_length] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров игрового фильма
void Out(game &gm, std::ofstream &ofst) {
    ofst << "\nIt is Game Film:\n" << "publication year = " << gm.publication_year << "\nfilm name = " << gm.publication_year <<
         "\ndirector name =  " << gm.director << "\nDivision result = " << DivideYearByLength(gm) << "\n";
}
