//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        DeleteFilm(c.cont[i]);
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    while(!ifst.eof()) {
        if((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements.\n";
    for(int i = 0; i < c.len; i++) {
        ofst << i << " ";
        Out(*(c.cont[i]), ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего значения функции нахождения частного
// от деления года выхода на длину названия для всех фильмов в контейнере
double DivideYearByLengthAverage(container &c) {
    double sum = 0.0;
    for(int i = 0; i < c.len; i++) {
        sum += DivideYearByLength(*(c.cont[i]));
    }
    return sum / c.len;
}

void FilterContainer(container &c) {
    double average = DivideYearByLengthAverage(c);
    int k = 0;
    for (int i = 0; i < c.len - k;) {
        if (DivideYearByLength(*(c.cont[i])) < average) {
            DeleteFilm(c.cont[i]);
            for (int j = i; j < c.len - k - 1; ++j) {
                c.cont[j] = c.cont[j + 1];
            }
            ++k;
        } else {
            ++i;
        }
    }
    for (int i = c.len - k; i < c.len; ++i) {
        DeleteFilm(c.cont[i]);
    }
    c.len -= k;
}
