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

int main(){
    FILE * fp, * temp;
    struct tm * current_time;
    int day, month, year, hour, minute, second, weekday;
    char name[30], repeat, close[] = "'";

    current_time = malloc(sizeof(struct tm));    
    current_time = gettime();

    fp = fopen("/home/yanci/Documents/C Projects/REMINDER/.tasks", "r+");       /*change this line according to your directory*/
    temp = fopen("/home/yanci/Documents/C Projects/REMINDER/.temp", "w");       /*change this line according to your directory*/

    while (1){
        char notif_command[55] = "notify-send 'Reminder' '";
        fscanf(fp, "%d %d %d   %d %d %d %d %s   %c", &day, &month, &year, &hour, &minute, &second, &weekday, name, &repeat);

        if (!day){
            break;
        }

        switch (repeat){

        case 'd':
            if (current_time->tm_wday != weekday){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, name, repeat);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }

            break;

        case 'w':
            if ((current_time->tm_wday == weekday) && (current_time->tm_mday != day)){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, name, repeat);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }
            break;

        case 'm':
            if (current_time->tm_mon != month){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, name, repeat);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }
            break;

        case 'h':
            if (current_time->tm_hour != hour){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, name, repeat);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }
            break;

        case 'y':
            if (current_time->tm_year != year){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", current_time->tm_mday, current_time->tm_mon, current_time->tm_year, current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_wday, name, repeat);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }
            break;

        case 't':
            if (current_time->tm_hour == hour && current_time->tm_min == minute){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
            }
            break;

        case 'n':
        	if (current_time->tm_mday == day && current_time->tm_mon == month && current_time->tm_hour == hour && current_time->tm_min == minute){
                strcat(notif_command, name);
                strcat(notif_command, close);
                system(notif_command);
            }

            else{
                fprintf(temp, "%d %d %d   %d %d %d %d %s   %c\n", day, month, year, hour, minute, second, weekday, name, repeat);
                }
            break;

        default:
            break;
        }
    }

    fprintf(temp, "%d %d %d   %d %d %d %d %s   %c", 0, 0, 0, 0, 0, 0, 0, "NULL", '0');
    fclose(temp);
    fclose(fp);
    system("mv '/home/yanci/Documents/C Projects/REMINDER/.temp' '/home/yanci/Documents/C Projects/REMINDER/.tasks'");          /*change this line according to your directory*/
    return 0;
}


