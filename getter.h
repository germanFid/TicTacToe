//
// Created by German Fidarov on 09/09/2021.
//

#ifndef HELLOPOLY_GETTER_H
#define HELLOPOLY_GETTER_H

#include "stdio.h"
#include <string.h>
#include "stdlib.h"

int get_int_choice(int nCh, const char choices[][nCh]) // Считывает выбор типа int и проверяет его на соответствие формату
{
    char str[30];
    scanf("%30s", str); // получаем строку
    for (int i = 0; i < nCh; i++) // идем по массиву возможных выборов
    {
        if (strcmp(str, choices[i]) == 0) // если нашли совпадение...
        {
            return atoi(choices[i]); // Возвращаем нужную строчку, приводя к int
        }
    }

    return -1; // Иначе возвращаем -1, что означает неверный формат
}

void clear_extra_input()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

#endif //HELLOPOLY_GETTER_H