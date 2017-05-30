/*
 * InputTool.c
 *	reads user console input,
 *	then allocates that input into a char array (buff)
 *	returns 0 if everything went ok,
 *	returns 1 if there was no input,
 *	returns 2 if input was longer than the buffer size
 *  Created on: 29 may. 2017
 *      Author: Ignacio Gilardoni

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

static int getLine (char* prmpt, char* buff) {
	int sz = sizeof(char)*strlen(buff)+1;
    int ch, extra;
    buff[0] = '\0';
    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL || buff[0] == '\n')
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}

