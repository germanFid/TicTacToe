//
// Created by German Fidarov on 09/09/2021.
//

#include <stdio.h>
#include "graphics.h" // библиотека для отрисовки интерфейса игры
#include "getter.h" // для получения данных в нужном формате / "защита от дурака"
#include "gameLogic.h" // Игровая логика

void game(const char n1[], const char n2[])
{
    drawGame(n1, n2);

    int type = 1;
    char possible[][9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int sum[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    const short toInc[9][4] = {{0, 6, 3, -1}, {0, 5, -1, -1}, {0, 4, 7, -1},
                               {1, 6, -1, -1}, {1, 5, 3, 7}, {1, 4, -1, -1},
                               {2, 6, 7, -1}, {2, 5, -1, -1}, {2, 4, 3, -1}};

    int turns[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            turns[i][j] = -1;
        }
    }

    int turnN = 0;
    char name[28];
    strcpy(name, n1);
    int inc = 1;

    while (1)
    {
        int turn = get_int_choice(9, possible); // получаем номер клетки, в которую ходит игрок
        if (turn != -1)
        {
            if (turns[CordMap[turn - 1][0]][CordMap[turn - 1][1]] == -1)
            {
                Update(turn - 1, type);
                turns[CordMap[turn - 1][0]][CordMap[turn - 1][1]] = type;

                for (int i = 0; i < 4; i++)
                {
                    short e = toInc[turn - 1][i];
                    if (e != -1)
                    {
                        sum[toInc[turn - 1][i]] += inc;
                    }
                }

                clearStr(10);
                for (int i = 0; i < 8; i++)
                {
                    printf("%d", sum[i]);
                    if (sum[i] == 3 || sum[i] == -3)
                    {
                        drawWin(name);
                        return;
                    }
                }

                turnN++;
                if (turnN >= 9)
                {
                    drawDraw();
                    return;
                }

                if (type == 1) type = 2;
                else type = 1;

                if (type == 1)
                {
                    strcpy(name, n1);
                    inc = 1;
                }

                else
                {
                    strcpy(name, n2);
                    inc = -1;
                }

                clearStr(13);
                clearStr(12);
                printf("Ход %s> ", name);
            }

            else
            {
                clearStr(13);
                printf("Сюда ходить нельзя !");
                clearStr(12);
                printf("Ход %s> ", name);
            }
        }
        else
        {
            clearStr(13);
            printf("Неправильный формат ввода !");
            clearStr(12);
            printf("Ход %s> ", name);
        }
    }
}

int getNicknames()
{
    clear();
    gotoxy(1,1);

    char nick1[19];
    char nick2[19];
    printf("Длина ника не более 15 символов!\n\n");
    while(1)
    {
        printf("Введите никнейм игрока 1: ");

        readn(16, nick1);
        if (strlen(nick1) < 16)
        {
            break;
        }

        gotoxy(0,2);
        printf("Неверный формат ввода!");
        clearFrom(3);
    }

    clearStr(2);
    gotoxy(0,5);
    printf("\n");

    while(1)
    {
        printf("Введите никнейм игрока 2: ");
        readn(16, nick2);
        if (strlen(nick2) < 16)
        {
            break;
        }

        gotoxy(0,2);
        printf("Неверный формат ввода!");
        clearFrom(5);
    }

    printf("\n\n%s\n%s\n", nick1, nick2);
    game(nick1, nick2);
    return 0;
}

void menu() { // отрисовка меню
    restart: drawMenu();
    char to_ch[][2] = {"1", "2"};
    int choice;

    while (1) {
        choice = get_int_choice(2, to_ch);

        if (choice == -1) {
            clearStr(7);
            printf("Неправильный формат ввода !");

//            clearStr(8);
            clearFrom(8);
            printf("> ");
        }

        else break;
    }
    if (choice == 1) {
        getNicknames();
        goto restart;
    }
}

int main(void) {
    menu();
    return 0;
}
