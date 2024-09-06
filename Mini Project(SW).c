

#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("1.Stop watch\n2.Timer\n3.Add note\n4.Show date and time\n5.End program\n");
    int choice;
    do
    {
        printf("Main Menu - Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
        {
            printf("\033[?25l");
            int hour=0, minute=0, second=0;
            time_t current=time(NULL);
            struct tm now=*localtime(&current);
            int temp=now.tm_sec;
            while(1)
            {
                current=time(NULL);
                now=*localtime(&current);
                printf("%dhr : %dmin : %dsec \r", hour, minute, second );
                if(temp!=now.tm_sec)
                {
                    second++;
                    temp=now.tm_sec;
                }
                if(second==60)
                {
                    minute++;
                    second=0;
                }
                if(minute==60)
                {
                    hour++;
                    minute=0;
                }
            }
            printf("\033[?25h");

        }
        break;
        case 2:
        {
            printf("\033[?25l");
            int hour, minute, second ;
            printf("Enter hour :");
            scanf("%d", &hour);
            printf("Enter minute :");
            scanf("%d", &minute);
            printf("Enter second :");
            scanf("%d", &second);
            time_t current = time(NULL);
            struct tm now = *localtime(&current);
            int temp = now.tm_sec;
            while (hour > 0 || minute > 0 || second > 0)
            {
                current = time(NULL);
                now = *localtime(&current);
                printf("%dhr : %dmin : %dsec \r", hour, minute, second);
                if (temp != now.tm_sec)
                {
                    second--;
                    temp = now.tm_sec;
                }
                if (second < 0)
                {
                    if (minute > 0)
                    {
                        minute--;
                        second = 59;
                    }
                    else if (hour > 0)
                    {
                        hour--;
                        minute = 59;
                        second = 59;
                    }
                }
            }
            printf("0hr : 0min : 0sec ");
            printf("\nTime's up!\n");
            printf("\033[?25h");
        }
        break;
        case 3:
        {
            FILE *file = fopen("note.txt", "a");
            char note[2000];
            printf("Enter your note :");
            getchar();
            gets(note);
            char abc[200];
            time_t now=time(NULL);
            strftime(abc,200,"written on %I:%M:%S %p  %d-%m-%Y",localtime(&now));
            fprintf(file, "%s\n%s\n", abc, note);
            printf("Note is recorded at note.txt\n");
            fclose(file);
        }
        break;

        case 4:
            {
             // Get the current time
            time_t now;
            time(&now);

            // Convert it to local time representation
            struct tm *local = localtime(&now);

            // Format and print the current date and time
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", local);

            printf("Current Date and Time: %s\n", buffer);

            }
            break;

        case 5:
        {
            printf("Terminating program........");
        }
        break;
        default:
            printf("Invalid choice");
        }
    }
    while(choice!=5);
    return 0;
}
