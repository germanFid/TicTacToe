//
// Created by German Fidarov on 09/09/2021.
//

#ifndef HELLOPOLY_GRAPHICS_H
#define HELLOPOLY_GRAPHICS_H

#define clear() printf("\033[H\033[J") // Очищает весь экран
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x)) // Устанавливает курсор в положение (x, y)

#include "gameLogic.h"

void clearStr(y)
{
    gotoxy(0, y);
    printf("\33[2K\r");
}

void clearFrom(y)
{
    gotoxy(0, y);
    printf("\33[J\r");
}

void drawMenu() {
    clear();
    gotoxy(1, 0);
    printf("\033[37;1;41m Крестики-нолики v1.1 \033[0m\n"
           "╔══════════════╗\n"
           "║  1. Играть   ║\n"
           "║  2. Выход    ║\n"
           "╚══════════════╝\n"
           "\n\n> "
    );
}

/*
 * ┏━━━┳━━━┳━━━┓
 * ┃   ┃   ┃   ┃
 * ┣━━━╋━━━╋━━━┫
 * ┃ X ┃ 0 ┃   ┃
 * ┣━━━╋━━━╋━━━┫
 * ┃   ┃   ┃   ┃
 * ┗━━━┻━━━┻━━━┛
 *
 * */

void drawGame(const char n1[], const char n2[]) {
    clear();
    printf("%s VS %s \n\n", n1, n2);
    printf("┏━━━┳━━━┳━━━┓\n"
           "┃ 1 ┃ 2 ┃ 3 ┃\n"
           "┣━━━╋━━━╋━━━┫\n"
           "┃ 4 ┃ 5 ┃ 6 ┃\n"
           "┣━━━╋━━━╋━━━┫\n"
           "┃ 7 ┃ 8 ┃ 9 ┃\n"
           "┗━━━┻━━━┻━━━┛\n\n");

    printf("Введите цифру, на которую желаете походить\nХод %s> ", n1);
}

/*
 *
 * ПОБЕДИЛ %s !!!
 */

void drawWin(char winner[])
{
    clear();
    printf("\t\t\033[5;7m %s ПОБЕЖДАЕТ !!!\033[0m\n"
           "                                                  \n"
           "            ░░▒▒▒▒▒▒░░░░░░░░      ░░▒▒░░          \n"
           "            ░░▒▒▒▒▒▒░░░░░░░░        ▒▒▒▒          \n"
           "    ░░▒▒▒▒  ▒▒▒▒▒▒▒▒░░░░░░░░        ▒▒▒▒  ░░░░░░  \n"
           "  ░░▒▒    ░░░░▒▒▒▒▒▒░░░░░░░░        ▒▒▒▒░░    ░░  \n"
           "  ░░          ▒▒▒▒▒▒░░░░░░░░        ▒▒░░        ░░\n"
           "  ░░░░        ▒▒▒▒▒▒░░░░░░░░      ░░▒▒░░        ░░\n"
           "  ░░▒▒        ▒▒▒▒▒▒▒▒░░░░░░      ░░▒▒▒▒        ░░\n"
           "  ░░▒▒        ▒▒▒▒▒▒▒▒░░░░░░      ░░▒▒░░      ▒▒░░\n"
           "    ▒▒▒▒      ▒▒▒▒▒▒▒▒░░░░░░      ░░▒▒░░      ░░  \n"
           "      ▒▒      ░░▒▒▒▒▒▒░░░░░░      ▒▒▒▒      ▒▒░░  \n"
           "        ▒▒      ▒▒▒▒▓▓░░░░░░░░    ▒▒▒▒      ░░    \n"
           "          ▒▒    ▒▒▒▒▓▓▒▒░░░░░░  ░░▓▓▒▒    ░░      \n"
           "            ▒▒  ░░▒▒▓▓▒▒░░░░░░░░▒▒▓▓░░  ░░        \n"
           "            ░░░░░░▒▒▓▓▒▒░░░░░░░░▒▒▒▒  ░░          \n"
           "                     ░░▒▒▒▒▒▒░░                   \n"
           "                  ░░░░▒▒▒▒▒▒▒▒▒▒░░                \n"
           "                ░░▒▒▒▒▓▓▓▓▒▒▒▒▓▓░░▒▒              \n"
           "               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒             \n"
           "               ▓▓████████▓▓▓▓▓▓▓▓▒▒▓▓             \n"
           "               ░░██████████▓▓▓▓▓▓▓▓░░             ", winner);
    gotoxy(0, 25);
    printf("Нажмите [Enter] для продолжения\n");
    getchar(); // wait for ENTER
}

void drawDraw()
{
    clear();
    printf("\033[35m            НИЧЬЯ !\n\n"
           "       _.od8888888bo._\n"
           "     .dP\"'   @#@   '\"Yb.\n"
           "   .d\"'      #@#      '\"b.\n"
           "  d\"'        @#@        '\"b\n"
           " d'          #@#          'b\n"
           "dP           @#@           Yb\n"
           "8l          oDWBo          l8\n"
           "Yb        o@#@B@#@o        dP\n"
           " YI     o@#* #P# *#@o     IP\n"
           "  YI  o@#*   @#@   *#@o  IP\n"
           "   \"9@#*     #@#     *#@P\"\n"
           "     \"8b     @#@     d8\"\n"
           "       `\"Y888888888P\"`\033[0m");
    gotoxy(0, 20);
    printf("Нажмите [Enter] для продолжения.\n");
    getchar(); // wait for ENTER
}

void Update(int n, int type) // Обновляет клеточки в UI
{
    gotoxy(CordMapUI[n][0], CordMapUI[n][1]);
    if (type == 1)
        printf("X");
    else
        printf("0");
}

#endif //HELLOPOLY_GRAPHICS_H