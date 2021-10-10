#include "cartoon.h"
#include "documentary.h"
#include "game.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного фильма из файла
film* In(std::ifstream &ifst) {
    int k;
    ifst >> k;
    switch(k) {
        game *gm;
        cartoon *cr;
        documentary  *dc;
        case 1:
            gm = new game;
            gm->k = film::GAME;
            In(*gm, ifst);
            return gm;
        case 2:
            cr = new cartoon;
            cr->k = film::CARTOON;
            In(*cr, ifst);
            return cr;
        case 3:
            dc = new documentary;
            dc->k = film::DOCUMENTARY;
            In(*dc, ifst);
            return dc;
        default:
            return 0;
    }
}

// Случайный ввод обобщенного фильма
film *InRnd() {
    auto rand_k = rand() % 3 + 1;
    switch(rand_k) {
        game *gm;
        cartoon *cr;
        documentary  *dc;
        case 1:
            gm = new game;
            gm->k = film::GAME;
            InRnd(*gm);
            return gm;
        case 2:
            cr = new cartoon;
            cr->k = film::CARTOON;
            InRnd(*cr);
            return cr;
        case 3:
            dc = new documentary;
            dc->k = film::DOCUMENTARY;
            InRnd(*dc);
            return dc;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего фильма в поток
void Out(film &s, std::ofstream &ofst) {
    switch(s.k) {
        case film::GAME:
            Out(*((game*)&s), ofst);
            break;
        case film::CARTOON:
            Out(*((cartoon*)&s), ofst);
            break;
        case film::DOCUMENTARY:
            Out(*((documentary*)&s), ofst);
            break;
        default:
            ofst << "Incorrect film!\n";
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года выхода на длину названия обобщенного фильма
double DivideYearByLength(film &film) {
    return (double)(film.publication_year) / strlen(film.name);
}

//------------------------------------------------------------------------------
// Удаление обобщённого фильма
void DeleteFilm(film *s) {
    switch(s->k) {
        case film::GAME:
            delete (game*)s;
            break;
        case film::CARTOON:
            delete (cartoon*)s;
            break;
        case film::DOCUMENTARY:
            delete (documentary*)s;
            break;
        default:
            break;
    }
}
