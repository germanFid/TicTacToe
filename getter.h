//
// Created by German Fidarov on 09/09/2021.
//

#ifndef HELLOPOLY_GETTER_H
#define HELLOPOLY_GETTER_H

#include "stdio.h"
#include <string.h>
#include "stdlib.h"

void clear_extra_input()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int readn(const long n, char * string)
{
    int i = 0;
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF ) {
        if (i < n) {
            string[i++] = ch;
        }
    }
    string[i] = '\0';
    return 0;
}

int get_int_choice(int nCh, const char choices[][nCh]) // Считывает выбор типа int и проверяет его на соответствие формату
{
    char str[30];
    readn(30, str);
//    scanf("%30s", str); // получаем строку
    for (int i = 0; i < nCh; i++) // идем по массиву возможных выборов
    {
        if (strcmp(str, choices[i]) == 0) // если нашли совпадение...
        {
            return atoi(choices[i]); // Возвращаем нужную строчку, приводя к int
        }
    }

    return -1; // Иначе возвращаем -1, что означает неверный формат
}

int writeString(char *string, int maxSize) // Получает строчку и проверяет ее максимальную длину перед запуском
{
    char buffer[1024];
//    scanf("%1023s", buffer);
    readn(maxSize, buffer);

    if(strlen(buffer) > maxSize) // Если длина больше требуемой, то возвращаем -1
    {
        return -1;
    }

    stpcpy(string, buffer);
    string[strlen(string)] = '\0';
    clear_extra_input();
    return 0;
}

#endif //HELLOPOLY_GETTER_H