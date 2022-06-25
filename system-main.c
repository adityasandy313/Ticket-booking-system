/*Ticket Reservation System*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>


void login();
void train();
void printtrain(char train[], int price,int date,int month,int year);
void traindetail();
void status();
void cancel();
char train1[][50]= {"NZM RAJDHANI SPL (02753)","KDCY MAS SPECIAL (07120)","CSMT HWH SPL (02257)","HWH RAJ SPL (02302)","NDLS MAS SPL (02434)","MAS SRC AC EXP (02607)","CSMT RAJDNI SPL (01222)","MAS KDCY SF SPL (06115)","HWH LTT SPECIAL (02102)","HWH NDLS SPL (02371)","CAPE NZM EXP (06011)","MAS HWH SPL (02722)"};
int time1[24]={5,17,6,18,7,19,8,20,9,21,10,22,10,20,30,40,50};                               //Departure Time
int time2[24]={23,10,8,20,4,16,1,13,13,1,13,1,10,20,30,40,50};                               //Arrival Time
int ticket1[12] = {2990,3000,2436,2536,2035,2235,3045,3145,2140,2540,1845,2045};             //Ticket Price
char passengername[100][100];
char passengername2[100][100];
char passengergender[100][100];
int passengerage[100];
char trainnumber[12][12] = {"02753","07120","02257","02302","02434","02607","01222","06115","02102","02371","06011","02722"};
int seatnumber[100];
int _pnr[100];

int main()
{
    //Local Variable
    int mode;
    int x=1;
    system("color 6");

    puts("\t\t================================");
    puts("\t\t|                              |");
    puts("\t\t|                              |");
    puts("\t\t|                              |");
    puts("\t\t|  TICKET RESERVATION SYSTEM   |");
    puts("\t\t|                              |");
    puts("\t\t|                              |");
    puts("\t\t|                              |");
    puts("\t\t================================");

    puts("\t\t     PRESS ENTER TO CONTINUE    \n");

    getchar();

    system("cls");

    login();

    system("cls");

    menu:
    system("cls");
    system("color 6");
    printf("\t\t======================================\n");
    printf("\t\t              WELCOME               \n");
    printf("\t\t                                      \n");
    printf("\t\t              1.TICKET RESERVATION                   \n");
    printf("\t\t              2.TRAIN DETAILS                        \n");
    printf("\t\t              3.TICKET STATUS                       \n");
    printf("\t\t              4.CANCELLATION                        \n");
    printf("\t\t              5.EXIT                   \n");
    printf("\t\t                                      \n");
    printf("\t\t           ENTER YOUR CHOICE: ");
    scanf("%d", &mode);
    printf("\n\t\t                                      \n");
    printf("\t\t======================================\n");


    switch(mode)
    {
        case 1: train();
        system("cls");
        break;

        case 2: traindetail();
        system("cls");
        break;

        case 3: status();
        break;

        case 4: cancel();
        break;

        case 5: return 0;
    }
    goto menu;
    return 0;
}

void login()
{
    //Local Variable
    char username[100];
    char password[100];
    int num;
    char c;
    int i;

    entry:

    system("cls");

    system("color 6");

    printf("\n\n\t\t-------USER LOGIN-------\n");
    printf("\t\t|                      |\n");
    printf("\t\t|                      |\n");
    printf("\t\t|  Username:");
    scanf("%s",&username);
    printf("\t\t|                      |\n");
    printf("\t\t|  Password:");
    for(i=0;i<100;i++)
    {
        password[i] = getch();
        c = password[i];
        if(c!=13)
        {
            printf("*");
        }
        if(c == 13)
        {
            break;
        }
    }
    password[i] = '\0';
    printf("\t\t------------------------\n");


        if((strcmp(username,"user"))==0 && (strcmp(password,"password"))==0)
        {
            printf("\t\t------------------------\n");
            printf("\t\t     LOGIN SUCCESSFUL   \n");
            printf("\t\t------------------------\n");
        }
        else
        {
            system("color 4");
            printf("\n\n\t\t------------------------\n");
            printf("\t\t    LOGIN UNSUCCESSFUL  \n");
            printf("\t\t------------------------\n");
            printf("\t\t   ENTER 1 TO TRY AGAIN \n");
            printf("\t\t------------------------\n");
            scanf("%d",&num);
            if(num==1)
            {
                goto entry;
            }
        }
    system("cls");

    return;
}

void train()
{
    //Local Variable
    char start[100];
    char destination[100];
    int select;
    int available;
    int back;
    int back1;
    int dd;
    int month;
    int year;
    int x[6];
    int y[12];

    srand(time(0));

    system("cls");

    z:
    printf("\t\t   FROM(IN BLOCK LETTERS):-");
    scanf("%s", &start);
    printf("\t\t   TO (IN BLOCK LETTERS):-");
    scanf("%s", &destination);
    printf("\t\t   DATE OF JOURNEY:");
    scanf("%d-%d-%d",&dd,&month,&year);

    if((strcmp(start,"MUMBAI"))==0 && (strcmp(destination,"DELHI"))==0 || (strcmp(destination,"MUMBAI"))==0 && (strcmp(start,"DELHI"))==0)
    {
        choice1:
        system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                   %4d:%d                 \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[0],time1[0],time1[12],time2[0],time2[12],ticket1[0]);
            printf("\t\t  2.%15s                   %5d:%d                 \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[6],time1[1],time1[13],time2[1],time2[13],ticket1[1]);
            printf("\t\t   SELECT THE train:");
            printf("\n\t\t   Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x1:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[0]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[0]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[0],ticket1[0],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice1;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[0]);
                    if(y[0]==1)
                    {
                        goto x1;
                    }
                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[6]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[1]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[6],ticket1[1],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice1;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[6]);
                    if(y[6]==1)
                    {
                        goto x1;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[0]);
                if(x[0]==1)
                {
                goto choice1;
                }
            }
    }

    if((strcmp(start,"MUMBAI"))==0 && (strcmp(destination,"KOLKATA"))==0 || (strcmp(destination,"MUMBAI"))==0 && (strcmp(start,"KOLKATA"))==0)
    {
        choice2:
        system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                      %4d:%d              \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[2],time1[4],time1[14],time2[4],time2[14],ticket1[4]);
            printf("\t\t  2.%15s                   %5d:%d                 \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[8],time1[5],time1[15],time2[5],time2[15],ticket1[5]);
            printf("\t\t   SELECT THE train:");
            printf("\n\n\t\t Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x2:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[2]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[4]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[2],ticket1[4],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice2;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[1]);
                    if(y[1]==1)
                    {
                        goto x2;
                    }
                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[8]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[5]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[8],ticket1[5],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice2;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[7]);
                    if(y[7]==1)
                    {
                        goto x2;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[1]);
                if(x[1]==1)
                {
                goto choice2;
                }
            }
    }

    if((strcmp(start,"MUMBAI"))==0 && (strcmp(destination,"CHENNAI"))==0 || (strcmp(destination,"MUMBAI"))==0 && (strcmp(start,"CHENNAI"))==0)
    {
        choice3:
        system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                   %4d:%d                 \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[1],time1[2],time1[16],time2[2],time2[16],ticket1[2]);
            printf("\t\t  2.%15s                   %5d:%d                 \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[7],time1[3],time1[12],time2[3],time2[12],ticket1[3]);
            printf("\t\t   SELECT THE train:");
            printf("\n\t\t   Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x3:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[1]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[2]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[1],ticket1[2],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice3;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[8]);
                    if(y[8]==1)
                    {
                        goto x3;
                    }
                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[7]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[3]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[7],ticket1[3],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice3;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[2]);
                    if(y[2]==1)
                    {
                        goto x3;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[2]);
                if(x[2]==1)
                {
                goto choice3;
                }
            }
    }

    if((strcmp(start,"DELHI"))==0 && (strcmp(destination,"KOLKATA"))==0 || (strcmp(destination,"DELHI"))==0 && (strcmp(start,"KOLKATA"))==0)
    {
        choice4:
        system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                      %4d:%d              \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[3],time1[6],time1[13],time2[6],time2[13],ticket1[6]);
            printf("\t\t  2.%15s                     %5d:%d               \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[9],time1[7],time1[14],time2[7],time2[14],ticket1[7]);
            printf("\t\t   SELECT THE train:");
            printf("\n\t\t   Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x4:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[3]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[6]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[3],ticket1[6],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice4;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[9]);
                    if(y[9]==1)
                    {
                        goto x4;
                    }
                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[9]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[7]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[9],ticket1[7],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice4;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[3]);
                    if(y[3]==1)
                    {
                        goto x4;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[3]);
                if(x[3]==1)
                {
                goto choice4;
                }
            }
    }

    if((strcmp(start,"DELHI"))==0 && (strcmp(destination,"CHENNAI"))==0 || (strcmp(destination,"DELHI"))==0 && (strcmp(start,"CHENNAI"))==0)
    {
        choice5:
            system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                      %4d:%d              \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[4],time1[8],time1[15],time2[8],time2[15],ticket1[8]);
            printf("\t\t  2.%15s                      %5d:%d              \t\t%4d:%d\t\t\t\t%5d                                 \n",train1[10],time1[9],time1[16],time2[9],time2[16],ticket1[9]);
            printf("\t\t   SELECT THE train:");
            printf("\n\t\t   Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x5:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[4]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[8]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[4],ticket1[8],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice5;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[10]);
                    if(y[10]==1)
                    {
                        goto x5;
                    }
                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[10]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[9]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[10],ticket1[9],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice5;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[4]);
                    if(y[4]==1)
                    {
                        goto x5;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[4]);
                if(x[4]==1)
                {
                goto choice5;
                }
            }
    }

    if((strcmp(start,"CHENNAI"))==0 && (strcmp(destination,"KOLKATA"))==0 || (strcmp(destination,"CHENNAI"))==0 && (strcmp(start,"KOLKATA"))==0)
    {
        choice6:
            system("cls");
        system("color 6");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\tTICKET FARE(Rs.)\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                \t%5d:%d                 \t%4d:%d\t\t\t\t%5d                                 \n",train1[5],time1[10],time1[12],time2[10],time2[12],ticket1[10]);
            printf("\t\t  2.%15s                   \t%5d:%d                 \t%4d:%d\t\t\t\t%5d                                 \n",train1[11],time1[11],time1[13],time2[11],time2[13],ticket1[11]);
            printf("\t\t   SELECT THE train:");
            printf("\n\t\t   Enter 3 to go back for selecting cities\n");
            printf("\n\t\t   ENTER 4 TO GO TO MAIN MENU\n");
            scanf("%d",&select);

            system("cls");

            x6:

            switch(select)
            {
                case 1:
                printf("\t\t         %s          \n",train1[5]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[10]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[5],ticket1[10],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice6;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[11]);
                    if(y[11]==1)
                    {
                        goto x6;
                    }

                }
                break;

                case 2:
                printf("\t\t         %s          \n",train1[11]);
                printf("\t\t                       \n");
                printf("\t\t   TOTAL SEATS: 1000     \n");
                available = rand()%101;
                printf("\t\t                       \n");
                printf("\t\t   AVAILABLE SEATS:%d   \n",available);
                printf("\t\t                       \n");
                printf("\t\t   TICKET PRICE: Rs.%d   \n",ticket1[11]);
                printf("\t\t                       \n");
                printf("\t\t   PRESS 0 TO GO BACK                   \n");
                printf("\t\t                       \n");
                printf("\t\t   PRESS 1 TO BOOK THE TICKET\n\t\t\t");
                scanf("%d",&back);

                if(back == 1)
                {
                    printtrain(train1[10],ticket1[11],dd,month,year);
                }
                if(back == 0)
                {
                    goto choice6;
                }
                if(back!=1 && back!=0)
                {
                    system("cls");
                    system("color 4");
                    printf("\n\nWrong Choice\n");
                    printf("Enter 1 to choose again");
                    scanf("%d",&y[5]);
                    if(y[5]==1)
                    {
                        goto x6;
                    }
                }
                break;

                case 3:
                goto z;
                break;

                case 4:
                return ;

                default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tWrong Train Selected\n");
                printf("\t\tEnter 1 to select again");
                scanf("%d",&x[5]);
                if(x[5]==1)
                {
                goto choice6;
                }
            }
    }
}

void printtrain(char train[], int price,int date,int month,int year)
{
    system("cls");
    int num;
    printf("\n\t\t\tEnter number of Tickets:");
    scanf("%d",&num);

    int seat[num];

    char name[num][50];
    char name2[num][50];
    char gender[num][10];
    int age[num];
    int i;
    long long int pnr[num];


    system("cls");

    for(i=0;i<num;i++)
    {
        printf("\t\t\tNAME    :");
        scanf("%s %s",&name[i],&name2[i]);

        strcpy(passengername[i],name[i]);
        strcpy(passengername2[i],name2[i]);

        printf("\t\t\tAGE     :");
        scanf("%d",&age[i]);

        passengerage[i] = age[i];

        printf("\t\t\tGENDER  :");
        scanf("%s",&gender[i]);

        strcpy(passengergender[i],gender[i]);

        seat[i] = rand()%101;

        seatnumber[i] = seat[i];

        pnr[i] = rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100 + rand()%100;

        _pnr[i] = pnr[i];

        printf("\n");
    }


    char c;
    printf("\t\t\t\t\t=============TICKET=============\t\t\n");
    printf("\t\tTrain:%s\t\t DATE:%d-%d-%d\t\t\t\n",train,date,month,year);
    printf("\t\tNAME\t\t\t\tAGE\t\t\t\tGENDER\t\t\tSEAT NUMBER\t\t\t\tPNR\n");

    for(i=0;i<num;i++)
    {
        printf("\t\t%s %s\t\t\t%d\t\t\t\t%s\t\t\t%d\t\t\t\t\t%lld\n",name[i],name2[i],age[i],gender[i],seat[i],pnr[i]);
    }

    printf("\t\t\t\t\t\tTOTAL COST: Rs.%d\t\t\t\t\t",price*num);

    printf("\n\n\t\t\tEnter 0 to return to main menu:");

    scanf("%d",&c);

    if(c=='0')
    {
        return ;
    }

}

void traindetail()
{
    char to[20];
    char from[20];
    int dd;
    int month;
    int year;
    int choice;

    system("cls");

    start:

    system("color 6");

    printf("\n\t\t\tFROM:");
    scanf("%s",&from);
    printf("\n\t\t\tTO:");
    scanf("%s",&to);
    printf("\n\t\t\tDATE OF JOURNEY:");
    scanf("%d-%d-%d",&dd,&month,&year);

    if((strcmp(from,"MUMBAI"))==0 && (strcmp(to,"DELHI"))==0 || (strcmp(to,"MUMBAI"))==0 && (strcmp(from,"DELHI"))==0)
    {
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                   %4d:%d                 \t\t%4d:%d                                 \n",train1[0],time1[0],time1[12],time2[0],time2[12]);
            printf("\t\t  2.%15s                   %5d:%d                 \t\t%4d:%d                                 \n",train1[6],time1[1],time1[13],time2[1],time2[13]);
    }
    else if((strcmp(from,"MUMBAI"))==0 && (strcmp(to,"KOLKATA"))==0 || (strcmp(to,"MUMBAI"))==0 && (strcmp(from,"KOLKATA"))==0)
    {
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                         %4d:%d           \t\t%4d:%d                                 \n",train1[2],time1[2],time1[14],time2[2],time2[14]);
            printf("\t\t  2.%15s                      %5d:%d              \t\t%4d:%d                                 \n",train1[8],time1[3],time1[15],time2[3],time2[15]);
    }
    else if((strcmp(from,"MUMBAI"))==0 && (strcmp(to,"CHENNAI"))==0 || (strcmp(to,"MUMBAI"))==0 && (strcmp(from,"CHENNAI"))==0)
    {
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                   %4d:%d                 \t\t%4d:%d                               \n",train1[1],time1[4],time1[16],time2[4],time2[16]);
            printf("\t\t  2.%15s                   %5d:%d                 \t\t%4d:%d                               \n",train1[7],time1[5],time1[12],time2[5],time2[12]);
    }
    else if((strcmp(from,"DELHI"))==0 && (strcmp(to,"CHENNAI"))==0 || (strcmp(to,"DELHI"))==0 && (strcmp(from,"CHENNAI"))==0)
    {
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                      %4d:%d              \t\t%4d:%d                                 \n",train1[4],time1[6],time1[13],time2[6],time2[13]);
            printf("\t\t  2.%15s                      %5d:%d              \t\t%4d:%d                                 \n",train1[10],time1[7],time1[14],time2[7],time2[14]);
    }
    else if((strcmp(from,"DELHI"))==0 && (strcmp(to,"KOLKATA"))==0 || (strcmp(to,"DELHI"))==0 && (strcmp(from,"KOLKATA"))==0)
    {
           printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                       %4d:%d             \t\t%4d:%d                                 \n",train1[3],time1[8],time1[15],time2[8],time2[15]);
            printf("\t\t  2.%15s                      %5d:%d              \t\t%4d:%d                                 \n",train1[9],time1[9],time1[16],time2[9],time2[16]);
    }
    else if((strcmp(from,"CHENNAI"))==0 && (strcmp(to,"KOLKATA"))==0 || (strcmp(to,"CHENNAI"))==0 && (strcmp(from,"KOLKATA"))==0)
    {
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  NAME\t\t\t\t\t\tDEPARTURE TIME\t\t\tARRIVAL TIME\t\t\t\n");
            printf("\t\t-------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t  1.%15s                    %5d:%d                \t\t%4d:%d                                 \n",train1[5],time1[10],time1[12],time2[10],time2[12]);
            printf("\t\t  2.%15s                       %5d:%d             \t\t%4d:%d                                 \n",train1[11],time1[11],time1[13],time2[11],time2[13]);
    }
    else
    {
        system("color 4");
        printf("\n\t\t NO TRAINS RUN BETWEEN THESE CITIES . PLEASE ENTER VALID CITIES NAME\n");
        goto start;
    }

    a:
    system("color 6");
    printf("\n\t\t\tEnter 1 to return to main menu");
    printf("\n\t\t\tEnter 0 to go back\n\t\t\t");
    scanf("%d",&choice);

    if(choice==1)
    {
        system("cls");
        return ;
    }
    if(choice==0)
    {
        goto start;
    }
    else
    {
        system("color 4");
        printf("\t\t\tWrong Choice.Enter again\n");
        goto a;
    }
}

void status()
{
    v:
    system("color 6");
    system("cls");
    int pnr;
    printf("\n\t\t\tENTER PNR NUMBER: ");
    scanf("%d",&pnr);
    char tn[10];            //train number
    printf("\n\t\t\tENTER TRAIN NUMBER:");
    scanf("%s",&tn);
    int e=0;
    int i,j,a=0;
    int p;

    for(i=0;i<100;i++)
    {
        if(pnr == _pnr[i])
        {
            for(j=0;j<12;j++)
            {
                if(strcmp(tn,trainnumber[j])==0)
                {
                        e=200;
                        a = i;
                        printf("\n\t\t\t\tTRAIN NUMBER : %s\n",tn);
                        printf("\tNAME\t\t\t\tAGE\t\t\t\tGENDER\t\t\tSEAT NUMBER\t\t\t\tPNR\t\tSTATUS\n");
                        printf("\t%s %s\t\t\t%d\t\t\t\t%s\t\t\t%d\t\t\t\t\t%d\t    CONFIRMED\n",passengername[a],passengername2[a],passengerage[a],passengergender[a],seatnumber[a],pnr);

                        printf("\n\t\t\tEnter 1 to go back to menu");
                        int b;
                        scanf("%d",&b);
                        if(b==1)
                        {
                            return ;
                        }
                }
            }
        }
    }

    if(e<200)
    {
        q:
        system("cls");
        system("color 4");
        printf("\n\t\t\tWRONG PNR OT TRAIN NUMBER");
        printf("\n\t\t\tENTER 1 TO GO BACK TO MAIN MENU");
        printf("\n\t\t\tENTER 0 TO WRITE AGAIN");
        int c;
        scanf("%d",&c);
        if(c==0)
        {
            goto v;
        }
        if(c==1)
        {
            return ;
        }
        else
        {
            goto q;
        }
    }
}

void cancel()
{
v:
    system("color 6");
    system("cls");
    int pnr;
    printf("\n\t\t\tENTER PNR NUMBER: ");
    scanf("%d",&pnr);
    char tn[10];            //train number
    printf("\n\t\t\tENTER TRAIN NUMBER:");
    scanf("%s",&tn);
    int e=0;
    int i,j,a=0;
    int p;

    for(i=0;i<100;i++)
    {
        if(pnr == _pnr[i])
        {
            for(j=0;j<12;j++)
            {
                if(strcmp(tn,trainnumber[j])==0)
                {
                        e=200;

                        system("color 4");
                        printf("\n\t\tARE YOU SURE YOU WANT TO CANCEL YOUR TICKET.\n");
                        printf("\t\t\t1 for Yes and 0 for No\n");
                        int ch;
                        scanf("%d",&ch);
                        if(ch==1)
                        {
                            r:
                            _pnr[a] = -170;
                            printf("\n\t\t\tYOUR TICKET HAS BEEN SUCCESSFULLY CANCELLED\n");
                            int k;
                            printf("\n\t\t\tENTER 1 TO GO BACK TO MAIN MENU");
                            scanf("%d",&k);
                            if(k==1)
                            {
                                return;
                            }
                            else
                            {
                                goto r;
                            }
                        }
                        if(ch==0)
                        {
                            return;
                        }
                }
            }
        }
    }

    if(e<200)
    {
        q:
        system("cls");
        system("color 4");
        printf("\n\t\t\tWRONG PNR OT TRAIN NUMBER");
        printf("\n\t\t\tENTER 1 TO GO BACK TO MAIN MENU");
        printf("\n\t\t\tENTER 0 TO WRITE AGAIN");
        int c;
        scanf("%d",&c);
        if(c==0)
        {
            goto v;
        }
        if(c==1)
        {
            return ;
        }
        else
        {
            goto q;
        }
    }

}
