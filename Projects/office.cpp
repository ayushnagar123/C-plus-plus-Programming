/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                     PROJECT OFFICE MANAGEMENT                         º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                           HEADER FILES                                º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                      CONSTANT DECLARATION                             º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
			  const int MAX=20;
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                           CLASS AIR                                   º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
class air
{
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                      PRIVATE DECLARATIONS                             º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
	  private:
	       long code;
	       char fname[MAX];
	       char mname[MAX];
	       char lname[MAX];
	       char gender[MAX];
	       char language[MAX];
	       char street[MAX];
	       char city[MAX];
	       double zcode;
	       char country[MAX];
	       double telecom;
	       char salutation[MAX];
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                       PUBILC DECLARATIONS                             º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
	  public:
		void get_data();
		void display_data();
		void display_rec();
		void append_record();
		void search_record(int code);
		void salary_slip();
		int found_code(int ccode);
		int delete_record(int dcode);
		int modify_data();
		int modify_record(int ,char ,char,char,int,int);
		int count(int);
 };
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                TO CHECK WHETHER THE RECORD EXISTS                     º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
 int air::found_code(int ccode)
 {      air A;
        fstream file;
        file.open("pro.dat",ios::in);
        file.seekg(0);
        int found=0;
        while(!file.eof())
		{
			file.read((char*)&A,sizeof(A));
			if(code==ccode)
			{
				found=1;
				break;
			}
		}
	file.close();
	if(found==1)
		{
			return code;
		}
	else
		{
			return 0;
		}
 }
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                      TO COUNT NO. OF RECORDS                          º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
 int air::count(int)
 {    air A;
      fstream file;
      file.open("pro.dat",ios::in|ios::out);
      int co=0;
      while( file.read((char*)&A,sizeof (A)))
	    {
		   co=code;
	    }
      file.close();
      return co ;
 }
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                         GETS EMPLOYEE DATA                            º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
void air ::get_data()
{
   cout<<"\n  ENTER USER NUMBER             :";
   cin>>code;
a1:cout<<"    ENTER FIRST NAME              :";
   cin>>fname;
   if(strlen(fname)<1||strlen(fname)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a1;
     }
    else
    { goto a2;}
   a2:cout<<"     ENTER MIDDLE NAME             :";
    cin>>mname;
    if(strlen(mname)<1||strlen(mname)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a2;
     }
    else{ goto a3; }
a3:cout<<"      ENTER LAST NAME               :";
   cin>>lname;
    if(strlen(lname)<1||strlen(lname)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a3;
     }
   else{ goto a4;}
a4:cout<<"       ENTER GENDER...(M/F)          :";
   cin>>gender;
a5:cout<<"        ENTER LANGUAGE                :";
   cin>>language;
    if(strlen(language)<1||strlen(language)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a5;
     }
    else{goto a6;}
a6:cout<<"         ENTER STREET                  :";
   cin>>street;
    if(strlen(street)<1||strlen(street)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a6;
     }
   else{ goto a7;}
a7:cout<<"          ENTER CITY                    :";
    cin>>city;
    if(strlen(city)<1||strlen(city)>25)
     {    cout<<"ENTER CORRECTLY (RANGE:1..25)";
	  getch();
	  goto a7;
     }
a8:cout<<"            ENTER ZIP CODE                :";
   cin>>zcode;
a9:cout<<"             ENTER COUNTRY                 :";
   cin>>country;
    if(strlen(country)<1||strlen(country)>15)
     {    cout<<"ENTER CORRECTLY (RANGE:1..15)";
	  getch();
	  goto a9;
     }
    else{goto a10;}
a10:cout<<"    		       ENTER TELECOM NUMBER          :";
   cin>>telecom;
   cout<<"    			ENTER SALUTATION(MR.,MRS.,MS.):";
   cin>>salutation;
}
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    DISPLAYS DATA OF AN EMPLOYEE                       º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
void air ::display_data()
{
cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
cout<<"º                      EMPLOYEES DATA                        º";
cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	cout<<"\nUSER NUMBER       :"<<code<<endl;
	cout<<"\nNAME              :"<<fname << mname<< lname<<endl;
	cout<<"\nLETTER SALUTATION :"<<salutation<<endl;
	cout<<"\nGENDER            :"<<gender<<endl;
	cout<<"\nLANGUAGE          :"<<language<<endl;
cout<<"\nÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
cout<<"\nº                         ADDRESS                            º";
cout<<"\nÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	cout<<"\nSTREET            :"<<street<<endl;
	cout<<"\nZIP CODE          :"<<zcode<<endl;
	cout<<"\nCITY              :"<<city<<endl;
	cout<<"\nCOUNTRY           :"<<country<<endl;
	cout<<"\nTELECOM NUMBER    :"<<telecom<<endl;
}
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                            MAIN MENU                                  º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
void main()
 {               clrscr();
	       air A;
	       int ans;
	       fstream file;
	       file.open("pro.DAT",ios::in|ios::out);
	       if(!file)
	       gotoxy(5,10);
	       {
		 cout<<"CANNOT OPEN THE FILE !!!\n"<<endl;
	       }
	       do
	       {
		 int choice;
		 char ans;
		 int dcode, ccode;
	      d10:  clrscr();
cout<<"\n\n\n\n\n";
cout<<"\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
cout<<"\tº                      MAIN MENU                             º"<<endl;
cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
cout<<"\tº               1.ADD RECORD.                                º"<<endl;
cout<<"\tº               2.SEARCH RECORD. 		              º"<<endl;
cout<<"\tº               3.DELETE RECORD.                             º"<<endl;
cout<<"\tº               4.DISPLAY RECORDS.                           º"<<endl;
cout<<"\tº               5.SALARY SLIP.                               º"<<endl;
cout<<"\tº               6.EXIT.                                      º"<<endl;
cout<<"\tº                                                            º"<<endl;
cout<<"\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
cout<<"\t\t\t";
		  cout<<"ENTER YOUR CHOICE...(1-6)..";
		  cin>>choice;
		  switch(choice)
		  {   case 1:
			   A.append_record();
			   getch();
			   clrscr();
			 goto d10;

		      case 2:
			   c10: cout<<"ENTER CODE NO. TO BE SEARCHED :";
			   cin>>ccode;
			   A.search_record(ccode);
			   goto d10;

		      case 3:
			  b10:cout<<"ENTER CODE TO BE DELETED :";
			  cin>>dcode;
			  A.delete_record(dcode);

		      case 4:
			  A.display_rec();
			  getch();
			  goto d10;

		     case 5:
			  A.salary_slip();
			  goto d10;
					      case 6:
			  break;
		     default:
			  cout<<"\n\t\t\tWRONG ENTRY !!!"<<endl;
			  cout<<"\t\t\tPRESS ANY KEY TO CONTINUE....."<<endl;
			  getch();
			  goto d10;
		   }
	}  while(ans==6);
 }
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    APPENDS DATA TO AN EMPLOYEE FILE                   º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
 void air::append_record()
 {
	 clrscr();
	 fstream file;
	 file.open("PRO.DAT",ios::trunc|ios::in|ios::out);
	 char c;
	 air A;
	 do
	 {
	   A.get_data();
	   file.write((char*)&A,sizeof(A));
	   cout<<"DO YOU WANT TO CONTINUE......(Y/N)"<<endl;
	   cin>>c;
	 }while(c=='y'||c=='Y');
	 file.close();
 }
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    SEARCHS DATA OF AN EMPLOYEE                        º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
 void air::search_record(int ccode)
 { fstream file;
   fstream nfile;
   air A;
   clrscr();
   file.open("pro.dat",ios::in|ios::out);
   nfile.open("new.dat",ios::in|ios::out|ios::trunc);
   file.read((char*)&A,sizeof(A));
   while(!file.eof())
   {         if(code==ccode)
	   nfile.write((char*)&A,sizeof(A));
	   file.read((char*)&A,sizeof(A));
   }
   nfile.close();
   nfile.open("new.dat",ios::in|ios::out);
   clrscr();
   nfile.read((char*)&A,sizeof(A));
   while(nfile);
   {
	A.display_data();
	nfile.read((char*)&A,sizeof(A));
   }
   getch();
}
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    DELETES RECORD OF AN EMPLOYEE                      º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
int air::delete_record(int dcode)
{  fstream file;
   fstream nfile;
   air A;
   clrscr();
   file.open("pro.dat",ios::in|ios::out);
   nfile.open("new.dat",ios::in|ios::out);
   file.read((char*)&A,sizeof(A));
   while(!file.eof())
   {         if(code!=dcode)
	   nfile.write((char*)&A,sizeof(A));
	   file.read((char*)&A,sizeof(A));
   }
   nfile.close();
   nfile.open("new.dat",ios::in|ios::out);
   clrscr();
   nfile.read((char*)&A,sizeof(A));
   while(!nfile.eof())
   {
	clrscr();
	A.display_data();
	nfile.read((char*)&A,sizeof(A));
	getch();
   }
   getch();
   return 0;
}
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    DISPLAYS RECORDS OF AN EMPLOYEE                    º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
void air::display_rec()
{  clrscr();
   air A;
   fstream file;
   file.open("pro.dat",ios::in|ios::out);
   while(!file.eof())
   {
      clrscr();
      A.display_data();
      file.read((char*)&A,sizeof(A));
      getch();
   }
   file.close();
}
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º                    MODIFIES DATA OF AN EMPLOYEE                       º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
/*int air::modify_data()
{
 air A;
 int mcode,res,re;
 int valid;
 char ename,eaddress,ress;
 cout<<"ENTER CODE OF THE RECORD TO BE MODIFIED :";
 cin>>mcode;
 A.found_code(mcode);
 fstream file;
 file.open("pro.dat",ios::in|ios::out);
 file.seekg(0);
 file.read((char*)&A,sizeof(A));
 while(!file.eof())
 {
  if(code==mcode)
  break;
  }
  file.close();
  cout<<"ENTER CODE "<<mcode;
  gotoxy(5,6);
  cout<<"NAME      :";
  gotoxy(40,5);
  cout<<"ADDRESS   :";
  gotoxy(55,6);
  cout<<"STREET    :";
    gotoxy(5,9);
  cout<<"CITY      :";
    gotoxy(5,10);
  cout<<"ZIP CODE  :";
    gotoxy(5,11);
  cout<<"TELECOM NO.:";
    gotoxy(5,14);
    do
    {int valid=1;
    gotoxy(20,7);
    cout<<"ENTER NAME OR <ENTER> FOR NO CHANGE "<<endl;
    cin>>ename;
    ename=strupr(ename);
    if(ename[0]=='0')
    return ;
    if(strlen(ename)>25)
    {
     valid=0;
     gotoxy(5,25);
     cout<<"ENTER CORRECTLY (RANGE :1-25) ";
     getch();
    }
  }while(!valid);
  if(strlen(ename)==0)
  {
  strcpy(ename,name);
  gotoxy(20,7);
  cout<<ename;
  }
  do
 {
  valid=1;
  gotoxy(5,25);
  cout<<"ENTER STREET OR <ENTER> FOR NO CHANGE";
  gotoxy(20,8);
  cin>>eaddress;
  eaddress=strupr(eaddress);
  if(eaddress[0]=='0')
  return ;
  if(strlen(eaddress)>30)
  {
  valid=0;
  gotoxy(5,25);
  cout<<"ENTER CORRECTLY (RANGE:1-30)";
  getch();
  }
  }while(!valid);
  if(strlen(eaddress)==0)
  {
  strcpy(eaddress,address);
  gotoxy(20,7);
  cout<<eaddress;
  }
   do
 {
  valid=1;
  gotoxy(5,25);
  cout<<"ENTER CITY OR <ENTER> FOR NO CHANGE";
  gotoxy(20,8);
  cin>>ress;
  ress=strupr(ress);
  if(ress[0]=='0')
  return ;
  if(strlen(ress)>30)
  {
  valid=0;
  gotoxy(5,25);
  cout<<"ENTER CORRECTLY (RANGE:1-30)";
  getch();
  }
  }while(!valid);
  if(strlen(ress)==0)
  {
  strcpy(ress,aress);
  gotoxy(20,7);
  cout<<ress;
  }
 do
 {
  valid=1;
  gotoxy(5,25);
  cout<<"ENTER ZIP CODE OR <ENTER> FOR NO CHANGE";
  gotoxy(20,8);
  cin>>res;
  if(res[0]=='0')
  return ;
  if(strlen(res)>30)
  {
  valid=0;
  gotoxy(5,25);
  cout<<"ENTER CORRECTLY (RANGE:1-30)";
  getch();
  }
  }while(!valid);
  if(strlen(res)==0)
  {
  strcpy(res,ares);
  gotoxy(20,7);
  cout<<res;
  }
do
 {
  valid=1;
  gotoxy(5,25);
  cout<<"ENTER TELECOM NO. OR <ENTER> FOR NO CHANGE";
  gotoxy(20,8);
  cin>>re;
  if(re[0]=='0')
  return ;
  if(strlen(re)>12)
  {
  valid=0;
  gotoxy(5,25);
  cout<<"ENTER CORRECTLY (RANGE:1-12)";
  getch();
  }
  }while(!valid);
  if(strlen(re)==0)
  {
  strcpy(re,are);
  gotoxy(20,7);
  cout<<re;
  }
}
do
{
  gotoxy(5,18);
  cout<<"DO YOU WANT TO SAVE...(Y/N)";
  cin>>ans;
}while(ans=='n'&& ans=='y');
if(ans=='n')
return ;
else
{
modify_record(mcode,ename,eaddress,ress,res,re);
clrscr();
cout<<"\n\n\n\nRECORD MODIFIED"<<endl;
cout<<"\n\n\n\nPRESS ANY KEY TO CONTINUE........."<<endl;
getch();
return ;

int air::modify_record(int mcode,char ename,char eaddress,char ress,int res,int re);
{
 air A;
 int codno;
 fstream file;
 file.open("pro.dat",ios::out|ios::ate);
 strcpy(name,ename);
 strcpy(street,eaddress);
 strcpy(city,ress);
 strcpy(zcode,res);
 strcpy(telecom,re);
 int loc;
 file.write((char*)&A,sizeof(A));
 file.close();
}*/
/*ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
  º             CALCULATES SALARY SLIP OF AN EMPLOYEE                     º
  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼*/
void air :: salary_slip()
{   clrscr();
    get_data();
    int le,lea;
    long bas,hra,ta,pf,net,enet,loan,lo,allow,deduct;
    clrscr();
    cout<<"\nENTER BASIC SALARY : Rs.";
    cin>>bas;
    cout<<"LEAVES TAKEN DURING THE MONTH :";
    cin>>le;
c25:cout<<"\nENTER LOAN IF ISSUED ( < 50,000) : Rs.";
    cin>>loan;
    if(loan>50000)
    {
      cout<<"WRONG ENTRY !!!"<<endl;
      cout<<"ENTER BETWEEN RANGE ( 0-50,000) "<<endl;
      cout<<"PRESS ANY KEY TO CONTINUE ..........."<<endl;
      getch();
      clrscr();
      goto c25;
    }
    else
    {
      hra=(5*bas)/100;
      ta=(5*bas)/100;
      pf=(2*bas)/100;
      lo=(15*loan)/100;
      allow =hra+ta;
      deduct=pf+lo;
      net=(bas+allow)-deduct;
      lea=(le*150);
      enet=(net-lea);
      clrscr();
      cout<<"\n\n\n\n\n";
      cout<<"\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
      cout<<"\tº             LUFTHANSA MILES AND MORE PVT. LTD.             º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tº                        SALARY SLIP                         º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tº!!!!!!!!!!!!!!!!!!!!!!!!1ALLOWANCE!!!!!!!!!!!!!!!!!!!!!!!!!!º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tºHOUSE RENT ALLOWANCE(H.R.A): Rs."<<setw(7)<<hra <<"\t\t     º"<<endl;
      cout<<"\tºTRAVEL ALLOWANCE (T.A)     : Rs."<<setw(7)<<ta  <<"\t\t     º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tº!!!!!!!!!!!!!!!!!!!!!!!!!DEDUCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tºPROVIDENT FUND (P.F)       : Rs."<<setw(7)<<pf  <<"\t\t     º"<<endl;
      cout<<"\tºLEAVES TAKEN               :    "<<le           <<"\t\t     º"<<endl;
      cout<<"\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
      cout<<"\tºNET SALARY                 : Rs."<<setw(7)<<enet<<"\t\t     º"<<endl;
      cout<<"\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
      cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE............";
      getch();
}
}
