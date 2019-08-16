#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int menu,x,y,z,m,n,o,p;
void setcolor(int ForgC)
{ 
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
	{
		wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut,wColor);
	}
}

void TotalPatient();
int backfunction(){
	char back;
	printf ("\nPress b to back ");
	fflush(stdin);
	scanf ("%c",&back);
	system("cls");
	if (back=='b'){
		return 1;
	}else{
		return 0;
	}
}

struct pat{
	char RegistrationNo[20];
	char FirstName[10];
	char LastName[10];
	char sex;
	int Age;
	char Address[20];
	struct DateRegister{
		int year;
		int month;
		int date;
	}DOB,DateRegi;
	long int PhoneNo;
	float DocCharge;
	float TicketCharge;
};
struct patii{
	char RegistrationNo[20];
	double X_Ray;
	double laboratory;
	double bedcharge;
	int NoOfDay;
	double Total;
};
void feedvalue();
void searchvalue();
void displayall();
void del();
void modify();
void Bill();
void FeedBill();
int Bill_print();
void ViewBill();
void heading(){
	setcolor(11);
	
	printf ("                  MADAN BHANDARI MEMORIAL COLLEGE                   ");
	printf ("   					 Anamnagar,Kathmandu\n     ");
	printf ("        WELCOME TO HOSPITAL PATIENT MANAGEMENT SYSTEM        ");
}
int login()
{
	int i;
	char c;
	char username[20];
	char password[20];
	system("cls");
	printf("******************************************************************************* \n");
	printf("****************************** USER AUTHENTICATION ****************************\n");
	printf(" \n\n\n ENTER USERNAME:-");
	gets(username);
	printf(" \n\n ENTER PASSWORD:-");
	while (i<=9)
	{
   		password[i]=getch();
    	c=password[i];
	    if(c==13)
			break;
    	else printf("*");
    	i++;
	}
	password[i]='\0';
	i=0;
	if((strcmp(username,"admin")==0) && (strcmp(password,"admin")==0))
	{
		printf("\n\n\n USERNAME & PASSWORD HAS BEEN MATCHED !!!! YOU ARE NOW LOGIN !!!!!");
		getch();
	}
	else
	{
		printf("\n\n\nUSERNAME OR PASSWORD  IS  INCORRECT !!! RE-ENTER YOUR USERNAME AND PASSWORD !!!!");
		getch();
		login();		
	}
}
void clrscr(){
	system("cls");
}
int main(){
  login();
  clrscr();
  B:
  heading();
  printf ("\n\n\t\tPress 1 to enter new patient record");
  printf ("\n\t\tPress 2 to display all the record");
  printf ("\n\t\tPress 3 to display specified patient record");
  printf ("\n\t\tPress 4 to delete the specified record");
  printf ("\n\t\tPress 5 to modify the specified record");
  printf ("\n\t\tPress 6 for custom charge and bill of different patient");
  printf ("\n\t\tPress 7 to view total no of patient visited at specified date");
  printf ("\n\t\tPress 8 to know about program ");
  printf ("\n\t\tPress 9 to exit ");
  
  scanf ("%d",&menu);
  clrscr();
  //heading();
  switch (menu){
  	case 1:
  		printf ("\n\n\t");
  		feedvalue();
  		x=backfunction();
  		if (x==1){
		  
  			goto B;
	}
	
  		break;
	case 2:
		printf ("\n\n\t");
		
  		displayall();
  		y=backfunction();
  		if (y==1){
  			goto B;
		  }
  		break;
  	case 3:
		printf ("\n\n\t");
  		searchvalue();
  		z=backfunction();
  		if (z==1){
  			goto B;
		  }
		break;
	case 4:
		printf ("\n\n\t");	
  		del();
  		m=backfunction();
  		if (m==1){
  			goto B;
		  }
		  break;
	case 5:
	printf ("\n\n\t");
	modify();	
  	n=backfunction();
  	if (n==1){
  		goto B;
		  }	
  		break;
  	case 6:
  	printf ("\n\n\t");
	 Bill_print();	
  	o=backfunction();
  	if (o==1){
  		goto B;
	  }	
  		break;
  	case 7:
  	printf ("\n\n\t");
	 TotalPatient();	
  	o=backfunction();
  	if (o==1){
  		goto B;
	  }	
  	case 8:
  	printf ("\n\tWelcome to Hospital Patient Record Management system\n\tThis program is developed by team members\n\t->Sagar Sigdel\n\t->Bibhusan Dahal\n\t->Kuber Adhakari\n\t->Sabin Pokhrel");
	p=backfunction();
  	if (p==1){
  		goto B;
	  }	
  	
	 break;
  	//	exit(0);
  	default:
  		printf ("\nInvalid option");
  		break;
  getch();
return 0;
}
}
void feedvalue(){
	FILE *fp;
	char RegNo[20],y;
	struct pat t;
	fp=fopen("hospital.dat","rb+");
	if (fp==NULL){
		fp=fopen("hospital.dat","wb+");
		if (fp==NULL){
		printf ("\nFile cannot be created");
		exit(0);	
		}
		
	}
	W:
	printf ("\nRegistrationNo : ");
	scanf ("%s",RegNo);
	rewind(fp);
	while (1){
	fread(&t,sizeof(t),1,fp);
	if (feof(fp)){
		break;
	}
	if (strcmp(t.RegistrationNo,RegNo)==0){
		printf ("\nTHIS REGISTRATION NUMBER ALREADY EXISTS.ENTER ANOTHER ONE");
		goto W;
	}
	}
	strcpy(t.RegistrationNo,RegNo);
	fflush(stdin);
	printf ("\nFirstName : ");
	scanf ("%s",t.FirstName);
	printf ("\nLastName : ");
	scanf ("%s",t.LastName);
	printf ("\nSex : ");
	fflush(stdin);
	scanf ("%c",&t.sex);
	printf ("\nAge : ");
	scanf ("%d",&t.Age);
	printf ("\nDOB(yy/mm/dd) : ");
	scanf ("%d %d %d",&t.DOB.year,&t.DOB.month,&t.DOB.date);
	printf ("\nAddress : ");
	fflush(stdin);
	scanf ("%s",t.Address);
	printf ("\nPhoneNo : ");
	scanf ("%ld",&t.PhoneNo);
	fflush(stdin);
	printf ("\nDate of Registration : ");
	scanf ("%d %d %d",&t.DateRegi.year,&t.DateRegi.month,&t.DateRegi.date);
	printf ("\nDoctor Charge : ");
	scanf ("%f",&t.DocCharge);
	printf ("\nTicket Charge : ");
	scanf ("%f",&t.TicketCharge);
	
	printf ("\n---------------------------------------------");
	printf ("\n---------------------------------------------");
	fwrite(&t,sizeof(t),1,fp);
	printf ("\nDo you want to enter again(y/n) ");
	fflush(stdin);
	scanf ("%c",&y);
	if (y=='y'){
		goto W;
	}
	fclose(fp);
}
void displayall(){
	FILE *fp;
	struct pat t;
	fp=fopen("hospital.dat","rb");
	if (fp==NULL){
		printf ("\nNo initial file");
		exit(0);
	}
	while(1){
	fread(&t,sizeof(t),1,fp);
	if (feof(fp)){
		break;
	}
	printf ("\nRegistrationNo : ");
	printf ("%s",t.RegistrationNo);
	printf ("\nFirstName : ");
	printf ("%s",t.FirstName);
	printf ("\nLastName : ");
	printf ("%s",t.LastName);
	printf ("\nSex : ");
	printf ("%c",t.sex);
	printf ("\nAge : ");
	printf ("%d",t.Age);
	printf ("\nDOB(yy/mm/dd) : ");
	printf ("%d / %d / %d",t.DOB.year,t.DOB.month,t.DOB.date);
	printf ("\nAddress : ");
	printf ("%s",t.Address);
	printf ("\nPhoneNo : ");
	printf ("%ld",t.PhoneNo);
	printf ("\nDate of Registration : ");
	printf ("%d / %d / %d",t.DateRegi.year,t.DateRegi.month,t.DateRegi.date);

	printf ("\nDoctor Charge in : Rs");
	printf ("%f",t.DocCharge);
	printf ("\nTicket Charge in : Rs");
	printf ("%f",t.TicketCharge);
	printf ("\n---------------------------------------------");
	printf ("\n---------------------------------------------");
		
	}
	
	fclose(fp);
//	}
	
}
void del()
{
FILE *fp,*fp1;
struct pat t,t1;
char id[20],count=0,y;
int found=0;
fp=fopen("hospital.dat","rb");
if (fp==NULL){
		printf ("\nNo initial file");
		exit(1);
	}
fp1=fopen("temp.dat","wb");
printf("\nEnter the Patient ID you want to Delete:");
scanf("%s",id);
rewind(fp);
while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(strcmp(t.RegistrationNo,id)==0)
{
found=1;
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("hospital.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
printf ("\nRecord has been sussefully deleted");
getch();
system("cls");
}
printf ("\nDo you want to delete any other record again(y/n) ");
		fflush(stdin);
		scanf ("%c",&y);
		if (y=='y'){
			del();
		}	
  		

fclose(fp);
fclose(fp1);
}
void searchvalue(){
	FILE *fp;
	char id[20],y;
	int found=0;
	struct pat t;
	fp=fopen("hospital.dat","rb");
	if (fp==NULL){
		printf ("\nTher no initial file to search for ");
		exit(2);
	}
	X:
		
	printf ("\nEnter a RegistrationNO to search for ");
	scanf ("%s",id);
	rewind(fp);
	while(1){
		fread(&t,sizeof(t),1,fp);
		if (feof(fp)){
			break;
		}
		if (strcmp(t.RegistrationNo,id)==0){
			found=1;
				printf ("\nRegistrationNo : ");
				printf ("%s",t.RegistrationNo);
				printf ("\nFirstName : ");
				printf ("%s",t.FirstName);
				printf ("\nLastName : ");
				printf ("%s",t.LastName);
				printf ("\nSex : ");
				printf ("%c",t.sex);
				printf ("\nAge : ");
				printf ("%d",t.Age);
				printf ("\nDOB(yy/mm/dd) : ");
				printf ("%d/%d/%d",t.DOB.year,t.DOB.month,t.DOB.date);
				printf ("\nAddress : ");
				printf ("%s",t.Address);
				printf ("\nPhoneNo : ");
				printf ("%ld",t.PhoneNo);
				printf ("\nlatest Date of ticket taken : ");
				printf ("%d/%d/%d",t.DateRegi.year,t.DateRegi.month,t.DateRegi.date);

				printf ("\nDoctor Charge : ");
				printf ("%f",t.DocCharge);
				printf ("\nTicket Charge : ");
				printf ("%f",t.TicketCharge);
			
				break;
		}
	}
		if (found==0){
			printf ("\n\aSorry RegistrationNo not found");
		}
			printf ("\nDo you want to search again(y/n) ");
	fflush(stdin);
	scanf ("%c",&y);
	if (y=='y'){
		goto X;
	}
	fclose(fp);
}
void modify()
{
FILE *fp,*fp1;
struct pat t,t1;
char RegID[20],count=0,y;
char RegNo[20];
int found=0;
fp=fopen("hospital.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Patient RegistationNO you want to Modify:");
scanf("%s",RegID);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if (strcmp(t.RegistrationNo,RegID)==0)
{
found=1;


	printf ("\nRegistrationNo : ");
	printf ("%s",t.RegistrationNo);
	fflush(stdin);
	printf ("\nFirstName : ");
	scanf ("%s",t.FirstName);
	printf ("\nLastName : ");
	scanf ("%s",t.LastName);
	printf ("\nSex : ");
	fflush(stdin);
	scanf ("%c",&t.sex);
	printf ("\nAge : ");
	scanf ("%d",&t.Age);
	printf ("\nDOB(yy/mm/dd) : ");
	scanf ("%d %d %d",&t.DOB.year,&t.DOB.month,&t.DOB.date);
	printf ("\nAddress : ");
	fflush(stdin);
	scanf ("%s",t.Address);
	printf ("\nPhoneNo : ");
	scanf ("%ld",&t.PhoneNo);	
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("hospital.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
printf ("\nRecord has been sucessfully modified");
getch();
system("cls");
}
printf ("\nDo you want to modify any other record again(y/n) ");
		fflush(stdin);
		scanf ("%c",&y);
		if (y=='y'){
			modify();
		}	
  		
fclose(fp);
fclose(fp1);
}
int Bill_print(){
	int a,b,c;
	G:
	printf ("\nPress 1 to draw ticket and doc charge");
	printf ("\nPress 2 for patient admission");
	printf ("\nPress 3 to view bill of admitted patient");
	printf ("\nPress any number to go back to main menu");
	scanf ("%d",&menu);
	switch(menu)
	{
		case 1:
		Bill();
		if ((a=backfunction())==1){
			goto G;
		}
		else{
			exit(0);
		}
		break;
		case 2:
		FeedBill();
		if ((b=backfunction())==1){
			goto G;
		}else{
			exit(0);
		}
		break;
		case 3:
		ViewBill();
		if ((c=backfunction())==1){
			goto G;
		}else{
			exit(0);
		}	
		break;
		default:
		printf ("\nInvalid option");
		getch();
		return 0;
		break;		
	}
}
void Bill(){
	FILE *fp,*fp1;
	struct pat t,t1;
	char RegID[20],count=0,y;
	char RegNo[20];
	int found=0;
	fp=fopen("hospital.dat","rb");
	fp1=fopen("temp.dat","wb");
	printf("\nEnter the Patient RegistationNO :");
	scanf("%s",RegID);
	while(1)
	{
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
	break;
}
	if (strcmp(t.RegistrationNo,RegID)==0)	
	{	
	found=1;
	printf ("\nTicket Charge : ");
	scanf ("%f",&t.TicketCharge);
	printf ("\nDoctor Charge : ");
	scanf ("%f",&t.DocCharge);	
	fwrite(&t,sizeof(t),1,fp1);
}
	else
	{
	fwrite(&t,sizeof(t),1,fp1);
}
}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
	printf("Sorry No Record Found\n\n");
}
	else
	{	
	fp=fopen("hospital.dat","wb");
	fp1=fopen("temp.dat","rb");
	while(1)
	{
	fread(&t,sizeof(t),1,fp1);
	if(feof(fp1))
	{
	break;
}
	fwrite(&t,sizeof(t),1,fp);
}
	printf ("\nTicket is finally drawn ready for checkup");
	getch();
}  		
	fclose(fp);
	fclose(fp1);
	//return 1;
}
void FeedBill(){
	FILE *fp,*fptr;
	char RegNo[20],y;
	struct pat t;
	int found=0;
	struct patii paty;
	fp=fopen("hospital.dat","rb+");
		if (fp==NULL){
		printf ("\nFile cannot be created");
		exit(0);	
}
		fptr=fopen("bill.dat","wb+");
		if (fp==NULL){
		printf ("\nFile cannot be created");
		exit(0);	
}
		printf ("\nRegistrationNo : ");
		scanf ("%s",RegNo);
		rewind(fp);
		while (1){
		fread(&t,sizeof(t),1,fp);
		if (feof(fp)){
		break;
}
		if (strcmp(t.RegistrationNo,RegNo)==0){
		found=1;	
		strcpy(paty.RegistrationNo,RegNo);
		fflush(stdin);
		printf ("\nX_Ray : ");
		scanf ("%lf",&paty.X_Ray);
		printf ("\nBed Charge : ");
		scanf ("%lf",&paty.bedcharge);
		printf ("\nNo of Day  : ");
		scanf ("%d",&paty.NoOfDay);
		printf ("\nLaboratory Charge : ");
		scanf ("%lf",&paty.laboratory);
		printf ("\n---------------------------------------------");
		printf ("\n---------------------------------------------");
		fwrite(&paty,sizeof(paty),1,fptr);
}
}
if (found==0){
	printf ("\nRegistration no donot match or doesnot exist.Try again(y/n)");
	fflush(stdin);
	scanf ("%c",&y);
	if (y=='y'){
		FeedBill();
	}
}

	fclose(fp);
	fclose(fptr);
	//return 1;
}
void ViewBill(){
	FILE *fptr;
	struct patii t;
	char RegNo[20];
	fptr=fopen("bill.dat","rb");
	if (fptr==NULL){
		printf ("\nNo initial file");
		exit(0);
}
	printf ("\nRegistrationNo : ");
	scanf ("%s",RegNo);
	while(1){
	fread(&t,sizeof(t),1,fptr);
	if (feof(fptr)){
		break;
}
		if (strcmp(t.RegistrationNo,RegNo)==0){
		system("cls");	
		printf ("\n\t\t\t\t\tRegistrationNo : ");
		printf ("%s",t.RegistrationNo);
		fflush(stdin);
		printf ("\n\tBill Heads  ");
		printf ("---------------------------------------------------------");
		printf ("\n\tX_Ray charge        : %f",t.X_Ray);
		printf ("\n\tBed Charge(per day) : %f No of Day : %d",t.bedcharge,t.NoOfDay);
		printf ("\n\tLaboratory test     : %f ",t.laboratory);
		printf ("\n\tTotal               : Rs %f",(t.bedcharge*t.NoOfDay+t.X_Ray+t.laboratory));	
		printf ("\n-------------------------------------------------------");
		printf ("\n-------------------------------------------------------");		
}
}
	fclose(fptr);
	//return 1;
}
void TotalPatient(){
	FILE *fp;
	struct pat t;
	int date,month,year,count=0,found=0;
	char y;
	U:
	fp=fopen("hospital.dat","rb+");
		if (fp==NULL){
			printf ("\nFile couldnot be opened or there is no record initially");
			exit(1);
		}
	printf ("\nEnter a date/month/year to find number of patient visited ");
	scanf ("%d/%d/%d",&date,&month,&year);
	rewind(fp);	
			while(1){
	fread(&t,sizeof(t),1,fp);
	if (feof(fp)){
		break;
	}
	if (t.DateRegi.date==date && t.DateRegi.month==month && t.DateRegi.year==year){
			found=1;
			count=count+1;
	}
		
}
if (found==0){
		printf ("\nRegistration Donot match..Try Again(y/n) ");
		fflush(stdin);
		scanf ("%c",&y);
		if (y=='y'){
			goto U;
		
}}
printf ("\nThe totoal number of patient visiteds : %d",count);
	fclose(fp);

}



	

