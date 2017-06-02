/*
 * InputTool.c
 *
 *  Created on: 29 may. 2017
 *      Author: Ignacio Gilardoni
 *	reads user console input,
 *	then allocates that input into a char array (buff)
 *	returns 0 if everything went ok,
 *	returns 1 if there was no input,
 *	returns 2 if input was longer than the buffer size
 *  Created on: 29 may. 2017
 */
#include "InputTool.h"
#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2
#include <ctype.h>
void trim(char *str) {
    int len = strlen(str);
    char *frontp = str;
    char *endp = str + len;

    while(isspace((unsigned char) *frontp)) ++frontp;
    if(endp != frontp){
        while(isspace((unsigned char) *(--endp)) && endp != frontp);
    }

    if(str + len - 1 != endp) *(endp + 1) = '\0';
    else if(frontp != str &&  endp == frontp)*str = '\0';

    endp = str;
    if(frontp != str) {
        while(*frontp) {*endp++ = *frontp++;}
        *endp = '\0';
    }
}
/*
 * function: getLine
 * description: gets a string from console input
 * parameters:
 * prmpt is the text to be displayed when prompting for user input
 * buff is the pointer in which input will be stored
 * sz is the maximum amount of characters to read
 * returns:
 * 0 if everything went ok
 * 1 ifthere was no input
 * 2 if text entered is longer than  maximum characters allowed
 */
int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;
    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL || buff[0]=='\n'){
    	printf ("enter something\n");
        return NO_INPUT;
    }
    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        if (extra == 1){
        	printf ("Please enter less than %d characters. \n", sz);
        	return TOO_LONG;
        }else{
        	return OK;
        }
    }
    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    trim(buff);
    return OK;
}
/*
 * function: getOption
 * description: get an integer from console input
 * parameters: prmpt is the text to be displayed when prompting for user input
 * returns: the integer entered by the user
 */
int getOption(char *prmpt){
	    // Get line with buffer overrun protection.
	    char line[9];
	    int i = -1;
	    int NaN = 1;
	    while(NaN) {
	        if (getLine (prmpt, line, 9)==0 ) {
	            if (1 == sscanf(line, "%d", &i)) {
	                NaN = 0;
	            }
	            else {
	                printf("Please enter an integer\n");
	            }
	        }
	    }
	    fflush(stdin);
	   return i;
}
