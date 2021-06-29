#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct tm * gettime(){
    time_t raw_time;
    struct tm * time_info;
    time_info = malloc(sizeof(struct tm));
    time(&raw_time);
    time_info = localtime(&raw_time);
    return time_info;
}

int main(int argc, char *argv[]){
    FILE * fp, * temp;
    struct tm * current_time;
    fp = fopen("/home/yanci/Documents/C Projects/REMINDER/.tasks", "r");		/*change this line according to your directory*/
    temp = fopen("/home/yanci/Documents/C Projects/REMINDER/.temp", "w");		/*change this line according to your directory*/

    current_time = malloc(sizeof(struct tm));    
    current_time = gettime();

    while (1){
        int day, month, year, hour, minute, second, weekday;
        char name[50], repeat;
        fscanf(fp, "%d %d %d   %d %d %d %d %s   %c", &day, &month, &year, &hour, &minute, &second, &weekday, name, &repeat);

        if (!day){
            break;
        }

        fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
    }

    if (argv[1][0] == '-'){
        switch (argv[1][1])
        {
        case 't':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", 1, 1, 1, atoi(argv[3]), atoi(argv[4]), 0, 0, argv[2], 't');
            break;

        case 'y':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, argv[2], 'y');
            break;

        case 'h':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, argv[2], 'h');
            break;

        case 'm':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, argv[2], 'm');
            break;

        case 'w':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, argv[2], 'w');
            break;

        case 'd':
            fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, argv[2], 'd');
            break;
        }
    }

    else {
        fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), current_time->tm_sec, current_time->tm_wday, argv[1], 'n');
    }

    fprintf(temp, "%d %d %d   %d %d %d %d %s   %c", 0, 0, 0, 0, 0, 0, 0, "NULL", '0');
    fclose(temp);
    fclose(fp);
    system("mv '/home/yanci/Documents/C Projects/REMINDER/.temp' '/home/yanci/Documents/C Projects/REMINDER/.tasks'"); 		/*change this line according to your directory*/
    return 0;
}










