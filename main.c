#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void printDisplay() {
    const char display[18][42] = {
        "|______________________________________|\n",
        "|     ...                              |\n",
        "|       ...                            |\n",
        "|         ...                          |\n",
        "|           ...                        |\n",
        "|             ..                       |\n",
        "|           ___##___                   |\n",
        "|          /---##---\\                  |\n",
        "|         /----------\\            X    |\n",
        "|        /------------\\          XXX   |\n",
        "|       /______________\\        XXXXX  |\n",
        "|        |            |        XXXXXXX |\n",
        "|        | ___        |       XXXXXXXXX|\n",
        "|        | | |   ___  |      XXXXXXXXXX|\n",
        "|        | |_|   | |  |     XXXXXXXXXXX|\n",
        "|        |_______| |__|           X    |\n",
        "|--------------------------------------|\n"
    };

    for(int i = 0; i < 18; i++) {
        char* thisLine = display[i];

        for (int j = 0; thisLine[j] != '\0'; j++) {
            if (i >= 10 && i <= 14 && j >= 10 && j <= 23) {
                putchar(thisLine[j]);
            } else if (thisLine[j] == ' ') {
                if (rand() % 10 == 0) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
            } else {
                putchar(thisLine[j]);
            }
        }
    }
    printf("\n\n");
}

int main(void)
{
    int runSeconds = 15;
    float elapsedSeconds = 0;
    int runIntervall = 500;

    srand(time(NULL));

    while (runSeconds > elapsedSeconds) {
        system("cls");
        printDisplay();

        usleep(runIntervall * 1000);
        elapsedSeconds += runIntervall / 1000.0;
    }
}
