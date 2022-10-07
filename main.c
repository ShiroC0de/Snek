#include <stdio.h>
#include "console.h"

void credits() {
    setCursorType(0);
    puts(
            "               (        (     (           (     \n"
            "          (    )\\ )     )\\ )  )\\ )  *   ) )\\ )  \n"
            "          )\\  (()/( (  (()/( (()/(` )  /((()/(  \n"
            "        (((_)  /(_)))\\  /(_)) /(_))( )(_))/(_)) \n"
            "        )\\___ (_)) ((_)(_))_ (_)) (_(_())(_))   \n"
            "       ((/ __|| _ \\| __||   \\|_ _||_   _|/ __|  \n"
            "        | (__ |   /| _| | |) || |   | |  \\__ \\  \n"
            "         \\___||_|_\\|___||___/|___|  |_|  |___/  \n"
            "                                                \n"
    );
//anim
    for (int i = 24; i > 8; i--) {

        gotoxy(25, i--);
        printf("Programmed by:  Alex");
        Sleep(10);

        for (int j = 25; j > 10; j--) {
            gotoxy(25, j);
            Sleep(2);

            printf("                     ");
            Sleep(2);

        }
    }
    for (int i = 24; i > 10; i--) {

        gotoxy(25, i--);
        Sleep(50);
        printf("Designed by:  Alex");
        Sleep(0);

        for (int j = 25; j > 12; j--) {
            gotoxy(25, j);
            Sleep(2);

            printf("                     ");
            Sleep(2);

        }
    }
    for (int i = 24; i > 12; i--) {

        gotoxy(25, i--);
        Sleep(50);
        printf("Bitte geben Sie mir wenigstens ne 2 :)");
        Sleep(0);

        for (int j = 25; j > 14; j--) {
            gotoxy(25, j);
            Sleep(2);

            printf("                                       ");
            Sleep(2);

        }
    }
}

void nameanim() {
    int rnbw;
    textcolor(9);
    //printet mit puts mein "Snek "logo
    puts(
            "  ___  _                 _____            _    \n"
            " / _ \\| |               /  ___|          | |   \n"
            "/ /_\\ \\ | _____  _____  \\ `--. _ __   ___| | __\n"
            "|  _  | |/ _ \\ \\/ / __|  `--. \\ '_ \\ / _ \\ |/ /\n"
            "| | | | |  __/>  <\\__ \\ /\\__/ / | | |  __/   < \n"
            "\\_| |_/_|\\___/_/\\_\\___/ \\____/|_| |_|\\___|_|\\_\\\n\n\n"
            " _____                                         \n"
            "|  __ \\                                        \n"
            "| |  \\/ __ _ _ __ ___   ___                    \n"
            "| | __ / _` | '_ ` _ \\ / _ \\                   \n"
            "| |_\\ \\ (_| | | | | | |  __/                   \n"
            " \\____/\\__,_|_| |_| |_|\\___|                   \n"
            "\n"
            "\n"

    );

    //loading animation
    for (int i = 1; i < 50; i++) {
        //rainbow anim
        if (rnbw >= 10) {
            rnbw = 1;
        } else
            rnbw++;

        textcolor(rnbw);

        printf("#");
        Sleep(60);

    }
    //100% rainbow anzeige
    //wollte rnbw restten aber war nd nötig
    //rnbw = 1;
    for (int i = 1; i < 10; i++) {
        if (rnbw >= 10) {
            rnbw = 1;
        } else
            rnbw++;
        textcolor(rnbw);

        gotoxy(21, 19);
        Sleep(100);
        printf("  100%%");
        Sleep(100);
        gotoxy(21, 19);
        printf("      ");

    }
    Sleep(500);
    system("cls");

}

void mainscreen() {
    char input = 'w';
    int cs = 1;
    int selection = 1;
    int posy1 = 10, posy2 = 10;

    textcolor(1);

    puts(
            "\n\n"
            "                    ___  ____   __    ____  ____ \n"
            "                   / __)(_  _) /__\\  (  _ \\(_  _)\n"
            "                   \\__ \\  )(  /(__)\\  )   /  )(  \n"
            "                   (___/ (__)(__)(__)(_)\\_) (__) \n"
    );


    puts(
            "                       ____  _  _  ____  ____ \n"
            "                      ( ___)( \\/ )(_  _)(_  _)\n"
            "                       )__)  )  (  _)(_   )(  \n"
            "                      (____)(_/\\_)(____) (__) \n"

    );
    gotoxy(24, 14);
    printf("select with w or s.\n ");
    gotoxy(24, 15);

    printf("press k for selection");
    do {
        switch (getch()) {

            case 'w':
                input = 'w';
                break;
            case 's':
                input = 's';
                break;
            case 'k':
                input = 'k';
            default :
                break;
        }
        switch (input) {
            case 'w':
                posy1 = 4;
                gotoxy(4, posy1);
                printf("---->");
                gotoxy(4, posy2);
                printf("      ");
                cs = 1;
                break;
            case 's':
                posy2 = 9;
                gotoxy(4, posy2);
                printf("---->");
                gotoxy(4, posy1);
                printf("      ");
                cs = 0;

                break;
            case 'k':
                selection = 0;
            default :
                break;
        }

    } while (selection == 1);

    if (cs == 0) {
        system("cls");
        credits();
        Sleep(2000);
        exit(0);
    } else {
        system("cls");
        Sleep(1000);
    }
}

void spielfeld() {
    for (int x = 3; x < 41; x++) {

        gotoxy(x, 1);
        textcolor(RED);
        printf("_");

        gotoxy(x, 19);
        printf("_");

    }
    for (int y = 2; y < 20; y++) {

        gotoxy(2, y);
        printf("|");

        gotoxy(41, y);
        printf("|");

    }
    textcolor(WHITE);

}

int main() {

    int posx = 5, posy = 5;
    char richtung = 'd';
    int ONbutton = 1;
    int punkte = 0;
    int zuckerl[2];
    setCursorType(0);

    nameanim();
    mainscreen();


    gotoxy(5, 5);

    do {
        gotoxy(posx, posy);
        printf("0");
        Sleep(200);
        gotoxy(posx, posy);
        printf(" ");

        if (kbhit() == 1)  // Richtungswechsel?
        {
            switch (getch()) {
                case 'w':
                    richtung = 'w';
                    break;
                case 'a':
                    richtung = 'a';
                    break;
                case 's':
                    richtung = 's';
                    break;
                case 'd':
                    richtung = 'd';
                    break;
                case 'x' :
                    richtung = 'x';
                    break;
                default :
                    break;

            }
        }
        switch (richtung) {
            case 'w':
                posy--;
                break;
            case 'a':
                posx--;
                break;
            case 's':
                posy++;
                break;
            case 'd':
                posx++;
                break;
            case 'x' :
                ONbutton = 0;
                break;

        }
        //infinity map
        if (posx > 40) {
            posx = 3;
        }
        if (posx < 3) {
            posx = 40;
        }
        if (posy > 18) {
            posy = 2;
        }
        if (posy < 2) {
            posy = 18;
        }

        spielfeld();

    } while (ONbutton == 1);

    return 0;
}
