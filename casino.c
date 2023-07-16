#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printMenu() {
	mvprintw(0, 0, "                   DISK DESTROYER · A SOUVENIR OF MALTA");
	mvprintw(2, 0, "                I have just DESTROYED the FAT on your Disk !!");
	mvprintw(3, 0, "      However, I have a copy in RAM, and I'm giving you a last chance");
	mvprintw(4, 0, "                        to restore your precious data.");
	mvprintw(5, 0, "     WARNING: IF YOU RESET NOW, ALL YOUR DATA WILL BE LOST - FOREVER !!");
	mvprintw(6, 0, "                   Your Data depends on a game of JACKPOT");
	mvprintw(8, 0, "                      CASINO DE MALTE JACKPOT");
	mvprintw(10, 0, "                        ╔═╗     ╔═╗     ╔═╗");
	mvprintw(11, 0, "                        ╫ ╫     ╫ ╫     ╫ ╫");
	mvprintw(12, 0, "                        ╚═╝     ╚═╝     ╚═╝");
	mvprintw(13, 0, "                            CREDITS : ");
	mvprintw(16, 0, "                        £££ = Your Disk");
	mvprintw(17, 0, "                        ??? = My Phone No.");
	mvprintw(19, 0, "                        ANY KEY TO PLAY");
}

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	// init ncurses window
	initscr();

	// game start
	printMenu();
	mvprintw(11, 0, "                        ╫£╫     ╫?╫     ╫¢╫");

	// slot machine
	int i = 5;
	while (i > 0) {
		// wait for key
		mvprintw(13, 0, "                            CREDITS : %d", i);
		move(11, 43);
		getch();
		i--;
		mvprintw(13, 0, "                            CREDITS : %d", i);
		move(11, 43);

		// get random result
		char *result[3];
		for (int j = 0; j <= 2; j++) {
			char *choices[] = {"£", "?", "¢"};
			int r = rand() % 3;
			result[j] = choices[r];
		}

		// spin 3, 2, 1
		int napwait = 2;
		for (int j = 0; j <= 100; j++) {
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫?╫     ╫¢╫     ╫£╫ ");
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫¢╫     ╫£╫     ╫?╫ ");
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫£╫     ╫?╫     ╫¢╫ ");
		}
		for (int j = 0; j <= 50; j++) {
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫¢╫     ╫£╫ ", result[0]);
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫£╫     ╫?╫ ", result[0]);
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫?╫     ╫¢╫ ", result[0]);
		}
		for (int j = 0; j <= 50; j++) {
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫%s╫     ╫£╫ ", result[0], result[1]);
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫%s╫     ╫?╫ ", result[0], result[1]);
			refresh();
			napms(napwait);
			mvprintw(11, 0, "                        ╫%s╫     ╫%s╫     ╫¢╫ ", result[0], result[1]);
		}

		mvprintw(11, 0, "                        ╫%s╫     ╫%s╫     ╫%s╫", result[0], result[1], result[2]);

		// turn string array to one string
		char roll[64];
		roll[0] = '\0';
		for (int j = 0; j <= 2; j++) {
			strcat(roll, result[j]);
		}

		// if win, else if phone
		if (strcmp(roll, "£££") == 0) {
			mvprintw(12, 0, "BASTARD ! You're lucky this time - but for your own sake, now");
			mvprintw(13, 0, "SWITCH OFF YOUR COMPUTER AND DON'T TURN IT ON TILL TOMORROW !!!");
			getch();
			endwin();
			return 0;
		} else if (strcmp(roll, "???") == 0) {
			mvprintw(12, 0, "No Fuckin' Chance; and I'm punishing you for trying to trace me down !");
			mvprintw(13, 0, "HA HA !! You asshole, you've lost: say Bye to your Balls ...");
			getch();
			endwin();
			return 0;
		}
	}

	// lost
	mvprintw(12, 0, "HA HA !! You asshole, you've lost: say Bye to your Balls ...");
	getch();

	// end ncurses window
	endwin();
	return 0;
}
