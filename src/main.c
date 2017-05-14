#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <malloc.h>
#include <mem.h>

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char* time = asctime(tm);
    char* savedTime = malloc(sizeof(char)*strlen(time));
    strcpy(savedTime, asctime(tm));
    printf("%s\n", savedTime);
    return 0;
}
