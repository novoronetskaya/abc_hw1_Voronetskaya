//------------------------------------------------------------------------------
// cartoon.cpp - содержит функции обработки мультфильма
//------------------------------------------------------------------------------

#include "cartoon.h"

//------------------------------------------------------------------------------
// Ввод параметров мультфильма
void In(cartoon &cr, std::ifstream &ifst) {
    int tp;
    ifst >> cr.name >> cr.publication_year >> tp;
    switch (tp) {
        case 1:
            cr.cr_tp = cartoon::DRAWN;
            break;
        case 2:
            cr.cr_tp = cartoon::PUPPET;
            break;
        case 3:
            cr.cr_tp = cartoon::PLASTICINE;
            break;
        default:
            return;
    }
}

// Случайный ввод параметров мультфильма
void InRnd(cartoon &cr) {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    cr.publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        cr.name[i] = 'a' + rand() % 26;
    }
    cr.name[name_length] = '\0';
    int tp = rand() % 3 + 1;
    switch(tp) {
        case 1:
            cr.cr_tp = cartoon::DRAWN;
            break;
        case 2:
            cr.cr_tp = cartoon::PUPPET;
            break;
        case 3:
            cr.cr_tp = cartoon::PLASTICINE;
            break;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров мультфильма
void Out(cartoon &cr, std::ofstream &ofst) {
    ofst << "\nIt is Cartoon:\n" << "publication year = " << cr.publication_year << "\nfilm name = " << cr.name << "\ntype = ";
    switch(cr.cr_tp) {
        case cartoon::DRAWN:
            ofst << "drawn\n";
            break;
        case cartoon::PUPPET:
            ofst << "puppet\n";
            break;
        case cartoon::PLASTICINE:
            ofst << "plasticine\n";
            break;
    }
    double result = DivideYearByLength(cr);
    ofst << "Division result = " << result << "\n";
}
