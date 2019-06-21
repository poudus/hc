
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/time.h>

#include "board.h"
#include "state.h"
#include "database.h"
#include "book.h"

//
// main
//
int main(int argc, char* argv[])
{
char	buffer_error[512], mode[32], database_name[32], flipped_moves[128], root[128], buf[128];
PGconn *pgConn = NULL;
int     nb_players = 10, start_hour = 15;

	if (argc > 1)
	{
        strcpy(mode, argv[1]);
		sprintf(database_name, "hw_", mode);
		pgConn = pgOpenConn(database_name, "hw", "", buffer_error);
		//printf("database connection     = %p %s\n", pgConn, database_name);
		if (argc > 2)
			start_hour = atoi(argv[2]);
		if (argc > 3)
			nb_players = atoi(argv[3]);

        int largeur = 7 * sqrt(nb_players);
        int hauteur = 5 * sqrt(nb_players);
        int period = 1;
        int begin_time = 10000 * start_hour;
        int end_time = 0;
        if (strcmp(mode, "blitz") == 0)
        {
            period = 1;
            end_time = 10000 * (start_hour + 2);
        }
        else if (strcmp(mode, "medium") == 0)
        {
            period = 2;
            end_time = 10000 * (start_hour + 4);
        }
        else if (strcmp(mode, "slow") == 0)
        {
            period = 5;
            end_time = 10000 * (start_hour + 10);
        }
        
	}
	else
	{
		printf("error.invalid-database-name\n");
		return -1;
	}
}

