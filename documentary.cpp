//------------------------------------------------------------------------------
// documentary.cpp - содержит функции обработки документального фильма
//------------------------------------------------------------------------------

#include "documentary.h"

//------------------------------------------------------------------------------
// Ввод параметров документального фильма
void In(documentary &doc, std::ifstream &ifst) {
    ifst >> doc.name >> doc.publication_year >> doc.length;
}

// Случайный ввод параметров документального фильма
void InRnd(documentary &dc) {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    dc.publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        dc.name[i] = 'a' + rand() % 26;
    }
    dc.name[name_length] = '\0';
    // Возможный для получения год - от 1 до 14400 минут (длительность самого долгого в мире фильма)
    dc.length = rand() % 14400 + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров документального фильма
void Out(documentary &dc, std::ofstream &ofst) {
    ofst << "\nIt is Documentary:\n" << "publication year = " << dc.publication_year << "\nfilm name = "
         << dc.name << "\nfilm length = " << dc.length << "\nDivision result = " << DivideYearByLength(dc) << "\n";
}
