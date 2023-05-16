
#include<windows.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost1,cost2;


}b;

int seat = 60 ;

void insert_details();
void viewAll(); 
void find();
void book_ticket(); 
void old_transaction();
void delete_transaction(); 
void delete_movie();
void menu()
{

	 int ch;
 	do{
	printf("\n====================================================================");
	printf("\n");	    
	printf("\t       Movie Ticket Booking System                    ");
	printf("\n");
	printf("\n====================================================================");
	
	printf("\nPress <1> Insert Movie");
	printf("\nPress <2> Delete Movie ");
   	printf("\nPress <3> View All Movie");
	printf("\nPress <4> Find Movie ");
	printf("\nPress <5> Book Ticket");
	printf("\nPress <6> View All Transactions");
    printf("\nPress <7> Delete All Transactions");
   	printf("\nPress <0> Exit ");
   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 	
	system("cls");
   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 3:
    		viewAll();
   		break;
    		
		case 4:
    		find();
   		break;

		case 5:
		book_ticket();
		break;
		
		case 6:
		old_transaction();
		break;
		case 7:
		delete_transaction();
		break;
    		case 2:
			delete_movie();
			break;
			case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);
}
void main()
{
	menu();
}
void insert_details()
{
	int a;
	do{
		printf("Continue?");
		printf("\n1.Yes");
		printf("\n2.Back to menu");
		
		printf("\nEnter your Choice:");
	   	scanf("%d",&a); 	
		system("cls");
	switch(a)
	{
		case 1: {FILE *fp;
	
    char password[] = "alo1234";
    char pass[50]; 
 
 	fflush (stdin);
    printf("Enter your password: ");
    gets(pass);
 
    while( strcmp(pass, password) != 0) {
		
        printf("\n Password incorrect\n");
 

 
        printf("Enter your password: ");
        gets(pass);
    }
 
    printf("Login success!\n");
 
	struct book b;
	printf("Enter movie code :- ");	
	scanf("%s",&b.code);
	printf("Enter the movie's name :- ");	
	scanf("%s",b.name);
	printf("Enter the movie's release Date:- ");	
	scanf("%s",b.date);
	printf("Enter Ticker Price for Normal Seat : -");
	scanf("%d", &b.cost1);
	printf("Enter Ticket Price for Double Seat(VIP) : -");
	scanf("%d", &b.cost2);

	fp=fopen("data.txt","a");
		fprintf(fp,"%s %s %s %d %d  \n",b.code,b.name,b.date,b.cost1,b.cost2);
		system("cls");
		printf("Record insert Sucessfull");
		printf("\n");
      
				printf("\n\t\tMovie's code :%s",b.code);
				printf("\n\t\tMovie's name :%s",b.name);
				printf("\n\t\tRelease date :%s",b.date);
				printf("\n\t\tTicket pricing (per seat): ");
				printf("\n\t\t  [Row 1-3]:%d",b.cost1);
				printf("\n\t\t  [Double seat row (VIP)]:%d",b.cost2);
				printf("\nContinue in:_");
				Sleep(1000);
                printf("3_");
                Sleep(1000);
                printf("2_");
        		Sleep(1000);
        		printf("1");
        		Sleep(1000);
          		system("cls");
		
	fclose(fp);
	};break;


	case 2: menu();break;

}

	
	}while(a!=0);
			
	}
void find()
{
	struct book b;
	FILE *fp;
	
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		menu();

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d %d",b.code,b.name,b.date,&b.cost1,&b.cost2);
			if(strcmp(b.code,ch) == 0)
			{	
				
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tMovie date ::%s",b.date);
				printf("\n\t\tTicket price of normal seat ::%d",b.cost1);
				printf("\n\t\tTicket price of double seat(VIP) ::%d",b.cost2);
			}
		}
		
		
	}
int c=0;
	printf("\nPress <0> to return to menu: ");
	scanf ("%d", &c);
if (c==0) 
		printf("Back to menu in: _");
		Sleep(1000);
   		printf("3_");
		Sleep(1000);
        printf("2_");
        Sleep(1000);
        printf("1");
        Sleep(1000);
        system("cls");
	menu();}
	
void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		menu();

	}
	else{
			while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	

	fclose(fp);
	int b=0;
	printf("\nPress <0> to return to menu: ");
	scanf ("%d", &b);
	if (b==0) 
		printf("Back to menu in: _");
		Sleep(1000);
   		printf("3_");
		Sleep(1000);
        printf("2_");
        Sleep(1000);
        printf("1");
        Sleep(1000);
        system("cls");
	menu();}
}

void book_ticket()
{
 int a;
    do{
        printf("You must have the movie's code to process. Do you want to continue ?");
        printf("\n1.Yes");
        printf("\n2.Back to menu");
       
        printf("\nEnter your Choice:");
        scanf("%d",&a);    
        system("cls");
    switch(a)
    {
        case 1: {
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_amount,total_seat;
	char name[20];
	int row,vip;
	long int mobile;
	char ch; 
	char movie_code[20];

	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		menu();
	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d %d",b.code,b.name,b.date,&b.cost1,&b.cost2);
			
			if(strcmp(b.code,movie_code) == 0)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tCode :%s",b.code);
				printf("\n\t\tMovie name :%s",b.name);
				printf("\n\t\tdate name :%s",b.date);
				printf("\n\t\tTicket pricing (per seat): ");
				printf("\n\t\t   [Row 1-3]:%d",b.cost1);
				printf("\n\t\t   [Double seat row (VIP)]:%d",b.cost2);
	
	row:
	printf("\nChoose your row (choose 4 for VIP): ");
    scanf("%d",&row);
    if(row==1 );
    else if(row==2);
	else if(row==3);
	else if(row==4);
	else
     {
    printf("\nWrong Choice!!!");
    goto row;
    }
	
	seat: 
	printf("\nChoose your number of seats: ");
	scanf("%d",&total_seat);
	if(total_seat>20){
	printf("One row has maximum of 20 seats! ");
	goto seat;}
	else{}
	printf("\n* Fill Details  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);

	
	printf("\nCOMPLETED ! ENJOY THE MOVIE \n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobile);
	printf("\n\t\tMovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	switch(row)
	{
		case 1:
		total_amount= total_seat * b.cost1;
		break;
		case 2:
		total_amount= total_seat * b.cost1;
		break;
		case 3:
		total_amount= total_seat * b.cost1;
		break;
		case 4: 
		total_amount= total_seat * b.cost2;
		break;
	}
	printf("\n\t\tTotal Amount : %d",total_amount);
	if(row=4)
	printf("\n\t\tRow: VIP");
	else{
	printf("\n\t\tRow: %d",row);
	}
	ufp=fopen("oldTransaction.txt","a");

		fprintf(ufp,"Name of client: %s \nClient's mobile number: %d \nRow: %d \nNumber of seat: %d \nTotal cost: %d \nMovie's name: %s \n\n"
		,name,mobile,row,total_seat,total_amount,b.name);
	fclose(ufp);
	fclose(fp);
		printf("\n Ticket purchase Successful !");
		printf("\nGoing back to menu in :");
		Sleep(1000);
   		printf("6_");
		Sleep(1000);
   		printf("5_");
		Sleep(1000);
   		printf("4_");
		Sleep(1000);
   		printf("3_");
		Sleep(1000);
        printf("2_");
        Sleep(1000);
        printf("1");
        Sleep(1000);
        system("cls");
	menu();
	break;
			}}}
}
	break;
	case 2: menu();break;
 
}
 
   
    }while(a!=0);
           
    



}

void old_transaction()

{int a;
    do{
        printf("Continue?");
        printf("\n1.Yes");
        printf("\n2.Back to menu");
       
        printf("\nEnter your Choice:");
        scanf("%d",&a);    
        system("cls");
    switch(a)
    {
        case 1: {
	char ch;
	FILE *fp;
	char password[] = "alo1234";
    char pass[50]; 
 
 	fflush (stdin);
    printf("Enter your password: ");
    gets(pass);
 
    while( strcmp(pass, password) != 0) {
		
        printf("\n Password incorrect\n");
 

 
        printf("Enter your password: ");
        gets(pass);
    }
 
    printf("Login success!\n");
 
	system("cls");
	
	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		menu();

	}
	else
	{	

		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}	

	int b=0;
	printf("\nPress <0> to return to menu: ");
	scanf ("%d", &b);
	if (b==0) 
		printf("Back to menu in: _");
		Sleep(1000);
   		printf("3_");
		Sleep(1000);
        printf("2_");
        Sleep(1000);
        printf("1");
        Sleep(1000);
        system("cls");
	menu();}
	break;
	case 2: menu();break;
 
}
 
   
    }while(a!=0);
           
    



}
void delete_transaction()
{int a;
    do{
        printf("Continue?");
        printf("\n1.Yes");
        printf("\n2.Back to menu");
       
        printf("\nEnter your Choice:");
        scanf("%d",&a);    
        system("cls");
    
	switch(a)
    {
        case 1: {
    int l;
    FILE *fp;
    char password[] = "alo1234";
    char pass[50]; 
 
 	fflush (stdin);
    printf("Enter your password: ");
    gets(pass);
    while( strcmp(pass, password) != 0) {
        printf("\n Password incorrect\n");
     printf("Enter your password: ");
        gets(pass);
    }
    printf("Login success!\n");
            if(strcmp(pass,password)==0)
            {
                printf("\nPassword matched...");
                fp = fopen("oldTransaction.txt","w");
                if(fp == NULL)
                {
                    printf("file does not found!");
                    menu();
                }
                else
                {					  
					  printf("\nDeleting old transactions");                  
				    printf("\nOld transactions Deleted Successfully!!!\n");		
				printf("Back to menu in:_");
				Sleep(1000);
                printf("3_");
                Sleep(1000);
                printf("2_");
        		Sleep(1000);
        		printf("1");
        		Sleep(1000);
          		system("cls");
                    main();
                }
            }	      
    fclose(fp);
		}
		break;
		case 2: menu();break;
 
} 
    }while(a!=0);
}
void delete_movie()
{
	FILE *fp, *fp2;
	char ch;
	int del_line, temp =1;
	int choice;
	do{
		printf("Enter your choice:");
		printf("\n1.Detele a single movie");
		printf("\n2.Detele all movie");
		printf("\n3.Back to menu");
		
		printf("\nEnter your Choice:");
	   	scanf("%d",&choice); 	
		system("cls");
		
	switch(choice)
	{
	case 1:	
	{
		char password[] = "alo1234";
    char pass[50]; 
 
 	fflush (stdin);
    printf("Enter your password: ");
    gets(pass);
    while( strcmp(pass, password) != 0) {
        printf("\n Password incorrect\n");
     printf("Enter your password: ");
        gets(pass);
    }
    printf("Login success!\n");
            if(strcmp(pass,password)==0)
            {
				system("cls");
	        fp = fopen("data.txt", "r");
         if(fp == NULL)
		 {
			printf("file does not found!");
                    menu();
		 }
		 else{
			while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
			rewind(fp);
        printf(" \n Enter movie number you want to delete:");
        scanf("%d", &del_line);
        fp2 = fopen("copy.ch", "w");
        ch = getc(fp);
	    while (ch != EOF) {
            ch = getc(fp);
          if (ch == '\n')
          temp++;
          if (temp != del_line)
          {
            putc(ch, fp2);
          }
	   }
        fclose(fp);
        fclose(fp2);
        remove("data.txt");
        rename("copy.ch", "data.txt");
        printf("\n Deleted successful, this is the current movie list: \n");
        fp = fopen("data.txt", "r");
       while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
			
		printf("\n\nBack to menu in:_");
				Sleep(1000);
                printf("4_");
				Sleep(1000);
                printf("3_");
                Sleep(1000);
                printf("2_");
        		Sleep(1000);
        		printf("1");
        		Sleep(1000);
          		system("cls");
		 }
		menu();
			}
		break;

}
		case 2:
		{
			char password[] = "alo1234";
    char pass[50]; 
 
 	fflush (stdin);
    printf("Enter your password: ");
    gets(pass);
    while( strcmp(pass, password) != 0) {
        printf("\n Password incorrect\n");
     printf("Enter your password: ");
        gets(pass);
    }
    printf("Login success!\n");
            if(strcmp(pass,password)==0)
            {
		fp = fopen("Data.txt","w");
                if(fp == NULL)
                {
                    printf("file does not found!");
                    menu();
                }
                else
                {					  
					  printf("\nDeteleting all Movie");                  
				printf("\nProcess will be done in :");
				Sleep(1000);
                printf("3_");
                Sleep(1000);
                printf("2_");
        		Sleep(1000);
        		printf("1");
        		Sleep(1000);
          		system("cls");
                    menu();	
		}
		}
		fclose(fp);
		}
		break;
	case 3 :
	menu();break;
	
}
	}while(choice!=0);
			
	}
