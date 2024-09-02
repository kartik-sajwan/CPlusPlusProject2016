#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<windows.h>

fstream userlst;
fstream caltable;
fstream userinfo;
fstream foodrec;
fstream obj;

int mainpage();
int postlogin(char[]);
void tableeditor();

struct mydate
{
	int day;
	int mon;
	int year;
};
struct foodinfo
{
	char fname[30],type;
	int cal, qty;
	float totcal;
	struct date d1;
};
struct caltab
{
	char fname[30],type;	
	int cal, qty;	
};
struct data
{
	char uname[20], name[30], pass[10];
	float height ,weight, bmi;
	char bg[2];
	struct mydate d1;
};

class enter
{
	private:
	data *data1;
	data *data2;
	char *x;
	char tname[20];
	char tpass[10];
	public:
	enter()
	{	*x='O';	}
	char* login();
	char* signup();
	void expert(int);
	void about();
	void printhelp();
};
char* enter::login()
{
	norec:
	clrscr();
	gotoxy(10,30);
	cout<<"Press 0 to go back.";
	data1=new data;
	gotoxy(52,5);
	cout<<"LOGIN";
	gotoxy(40,8);
	cout<<"Enter User name ";	gets(tname);
	if(strcmp(tname,"0")==0)
	{
		*tname='0';
		return tname;
	}
	gotoxy(40,9);
	cout<<"Password ";	gets(tpass);
	if(strcmp(tpass,"0")==0)
	{
		*tname='0';
		return tname;
	}
	userlst.open("Userlist.hcorp",ios::in,ios::binary);
	while(userlst)
	{
		userlst.read((char*)data1,sizeof(data));
		if(strcmp(tname,data1->uname)==0 && strcmp(tpass,data1->pass)==0)
		{
			clrscr();
			gotoxy(48,5);
			cout<<"Welcome "<<tname;
			sleep(1);
			userlst.close();
			return tname;
		}
	}
	gotoxy(20,20);
	cout<<"No record found. Press any key to try again.";
	*x=getch();
	if(*x=='0')
	{	
		userlst.close();
		return x;	
	}
	userlst.close();
	goto norec;
}
char* enter::signup()
{
	clrscr();
	data1=new data;
	data2=new data;
	gotoxy(10,30);
	cout<<"Press 0 to go back.";
	gotoxy(52,5);
	cout<<"SIGNUP"<<endl;
	gotoxy(40,8);
	cout<<"Enter Name :"<<"\t";	gets(data1->name);
	if(strcmp(data1->name,"0")==0)
	{
		*tname='0';
		return tname;
	}
	gotoxy(40,9);
	cout<<"Enter User name :"<<"\t";	gets(data1->uname);
	if(strcmp(data1->uname,"0")==0)
	{
		*tname='0';
		return tname;
	}
	if(strcmp(data1->uname,"")==0)
	{
		gotoxy(40,11);
		cout<<"No User name entered. Please try again.";
		sleep(2);
		goto exists;
	}
	gotoxy(40,10);
	cout<<"Password :"<<"\t";;	gets(data1->pass);
	if(strcmp(data1->pass,"0")==0)
	{
		*tname='0';
		return tname;
	}
	if(strcmp(data1->pass,"")==0)
	{
		gotoxy(40,11);
		cout<<"No password entered. Please try again.";
		sleep(2);
		goto password;
	}
	gotoxy(40,11);
	cout<<"Re-Enter Password :"<<"\t";	gets(tpass);
	if(strcmp(tpass,"0")==0)
	{
		*tname='0';
		return tname;
	}
	if(*x==1)
	{
		password:
		clrscr();
		gotoxy(52,5);
		cout<<"SIGNUP"<<endl;
		gotoxy(40,8);
		cout<<"Enter Name :"<<"\t"<<data1->name;
  	 	gotoxy(40,9);
		cout<<"Enter Username :"<<"\t"<<data1->uname;
		gotoxy(40,10);
		cout<<"Password :"<<"\t";	gets(data1->pass);
		if(strcmp(data1->pass,"0")==0)
		{
			*tname='0';
			return tname;
		}
		if(strcmp(data1->pass,"")==0)
		{
			gotoxy(40,11);
			cout<<"No password entered. Please try again.";
			sleep(2);
			goto password;
		}
		gotoxy(40,11);
		cout<<"Re-Enter Password :"<<"\t";	gets(tpass);
	}
	if(*x==2)
	{
		exists:
		clrscr();
		gotoxy(52,5);
		cout<<"SIGNUP"<<endl;
		gotoxy(40,8);
		cout<<"Enter Name :"<<"\t"<<data1->name;
		gotoxy(40,9);
		cout<<"Enter User name :"<<"\t";	gets(data1->uname);
		if(strcmp(data1->uname,"0")==0)
		{
			*tname='0';
			return tname;
		}
		if(strcmp(data1->uname,"")==0)
		{
			gotoxy(40,11);
			cout<<"No User name entered. Please try again.";
			sleep(2);
			goto exists;
		}
		gotoxy(40,10);
		cout<<"Password :"<<"\t";;	gets(data1->pass);
		if(strcmp(data1->pass,"0")==0)
		{
			*tname='0';
			return tname;
		}
		if(strcmp(data1->pass,"")==0)
		{
			gotoxy(40,11);
			cout<<"No password entered. Please try again.";
			sleep(2);
			goto password;
		}
		gotoxy(40,11);
		cout<<"Re-Enter Password :"<<"\t";	gets(tpass);
	}
	if(strcmp(data1->pass,tpass)!=0)
	{
		cout<<"Password Mismatch. "<<endl<<"Please Re-Enter"<<endl;
		sleep(2);
		goto password;
	}
	userlst.open("Userlist.hcorp",ios::in,ios::binary);
	while(userlst)
	{
		userlst.read((char*)data2,sizeof(data));
		if(strcmp(data1->uname,data2->uname)==0)
		{
			clrscr();
			gotoxy(48,5);
			cout<<"User name already in use. ";
			sleep(1);
			userlst.close();
			goto exists;
		}
	}
	userlst.close();
	clrscr();
	for(int j=1;j<=1;j++)
	{
		clrscr();
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait .";
		Sleep(100);
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait . .";
		Sleep(100);
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait . . .";
		Sleep(100);
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait . . . .";
		Sleep(100);
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait . . . . .";
		Sleep(100);
		gotoxy(35,15);
		cout<<"Creating Profile. Please Wait . . . . . . ";
		Sleep(100);
	}
	gotoxy(45,17);
	cout<<"Profile Created."<<endl;
	sleep(1);
	cout<<"Press any key to proceed.";
	getch();
	userlst.open("Userlist.hcorp",ios::app,ios::binary);
	userlst.write((char*)data1,sizeof(data));
	strcpy(tname,data1->uname);
	userlst.close();
	return tname;
}
void enter::expert(int diff)
{
	clrscr();
	pass:
	system("show.exe");
	char opt;
	data *passphrase, *check;
	passphrase=new data;
	check=new data;
	if(diff==1)
	{
		userlst.open("admin.bin",ios::out,ios::binary);
		gotoxy(2,20);
		cout<<"Your password cannot contain special characters like !,@,#,$,%,^,&,*,(,),_,+,=,<,>,?,:,,{,},|,\,/,.,;,',/,*,-,";
		gotoxy(2,21);
		cout<<"~,`, ,.";		
		gotoxy(50,2);
		cout<<"Enter pass phrase "<<endl;
		gotoxy(50,5);
		gets(passphrase->pass);
		if(strcmp(passphrase->pass,"")==0)
		{
			gotoxy(40,11);
			cout<<"No password entered. Please try again.";
			sleep(2);
			userlst.close();
			goto pass;
		}
		userlst.write((char*)passphrase,sizeof(data));
		userlst.close();
		system("backup.exe");
		goto first;
		
	}
	gotoxy(50,2);
	cout<<"Enter Pass phrase ";
	gotoxy(50,5);
	gets(passphrase->pass);
	userlst.open("admin.bin",ios::in);
	userlst.read((char*)check,sizeof(data));
	if(strcmp(passphrase->pass,check->pass)==0)
	{
		clrscr();
		gotoxy(50,2);
		cout<<"Welcome Administrator "<<endl;
		gotoxy(25,7);
		cout<<"1. Create backup "<<endl;
		gotoxy(25,8);
		cout<<"2. Restore backup "<<endl;
		gotoxy(25,9);
		cout<<"3. Edit calorie tables "<<endl;
		cin>>opt;
		if(opt=='1')
		{	system("backup.exe");	}
		else if (opt=='2')
		{	system("restore.exe");	}
		else if(opt=='3')
		{	tableeditor();	}
		userlst.close();
	}
	else
	{
		cout<<"Unidentified pass phrase. Cannot allow access.";
		sleep(2);
		userlst.close();
	}
	first:
	system("hide.exe");
}
void enter::about()
{
	clrscr();
	system("show.exe");
	char ch;
	obj.open("about.hcorp",ios::in);
	while(obj.get(ch))
	{
		cout<<ch;
		Sleep(random(100));
	}
	obj.close();
	system("hide.exe");
	getch();
}
void enter::printhelp()
{
	clrscr();
	system("show.exe");
	char ch;
	obj.open("help.hcorp",ios::in);
	while(obj.get(ch))
	{
		cout<<ch;
		Sleep(random(100));
	}
	obj.close();
	system("hide.exe");
	getch();
}

class core
{
	private:
	mydate *tempdate1,*tempdate2;
	caltab *calobj;
	data *udata;
	foodinfo *finfo;
	char *tname;
	char filename[100];
	char cont;
	int opt, j, i, l;
	float remcal,averagecal;
	float calsum;
	float bmi;
	long position;
	public:
	core()
	{
		i=0;
		opt=0;
		j=0;
		calsum=0;
	}
	char* uget(char*);
	char* uput(char*);
	char* newrec(char*);
	char* viewrec(char*);
	char* suggest(char*);
	void calculator(float, float);
};
char* core::uget(char *tname)
{
	strcpy(filename,tname);
	udata=new data;
	strcpy(udata->uname,tname);
	l=strlen(filename);
	filename[l]='.';
	filename[l+1]='h';
	filename[l+2]='c';
	filename[l+3]='o';
	filename[l+4]='r';
	filename[l+5]='p';
	filename[l+6]='\0';
	clrscr();
	gotoxy(10,30);
	cout<<"Press 0 to go back.";
	gotoxy(78,5);
	cout<<tname;
	gotoxy(25,5);
	cout<<"Enter Your name ";	gets(udata->name);
	if(strcmp(udata->name,"0")==0)
	{
		return tname;
	}
	gotoxy(25,6);
	cout<<"Enter Height(in cm) ";		cin>>udata->height;
	if(udata->height==0)
	{
		return tname;
	}
	gotoxy(25,7);
	cout<<"Enter Blood Group ";	gets(udata->bg);
	if(udata->bg=="0")
	{	
		return tname;
	}
	gotoxy(25,8);
	cout<<"Enter Weight(in kg) ";	cin>>udata->weight;
	if(udata->weight==0)
	{
		return tname;
	}
	gotoxy(25,9);
	cout<<"Enter Date Of Birth"<<endl;
	gotoxy(25,11);
	cout<<"Enter day	";	cin>>udata->d1.day;
	if(udata->d1.day==0)
	{
		return tname;
	}
	gotoxy(25,12);
	cout<<"Enter Month 	";	cin>>udata->d1.mon;
	if(udata->d1.mon==0)
	{
		return tname;
	}
	gotoxy(25,13);
	cout<<"Enter Year ";	cin>>udata->d1.year;
	if(udata->d1.year==0)
	{
		return tname;
	}
	gotoxy(25,14);
	udata->bmi=udata->weight/((udata->height/100)*(udata->height/100));
	gotoxy(25,16);
	cout<<"BMI "<<udata->bmi<<endl;
	if(udata->bmi<=18)
	{	cout<<"You are Underweight";	}
	else if(udata->bmi>18 && udata->bmi<=24)
	{	cout<<"You are Healthy";	}
	else if (udata->bmi>24)
	{	cout<<"You are overweight";	}
	getch();
	userinfo.open(filename,ios::out,ios::binary);
	userinfo.write((char*)udata,sizeof(data));
	userinfo.close();
	return tname;
}
char* core::uput(char *tname)
{
	strcpy(filename,tname);
	clrscr();
	udata=new data;
	gotoxy(10,30);
	cout<<"Press 0 to go back.";
	gotoxy(78,5);
	cout<<filename;
	l=strlen(filename);
	filename[l]='.';
	filename[l+1]='h';
	filename[l+2]='c';
	filename[l+3]='o';
	filename[l+4]='r';
	filename[l+5]='p';
	filename[l+6]='\0';
	userinfo.open(filename,ios::in,ios::binary);
	userinfo.read((char*)udata,sizeof(data));
	gotoxy(25,5);
	cout<<"Name "<<udata->name<<endl;
	gotoxy(25,6);
	cout<<"Height "<<udata->height<<" cm"<<endl;
	gotoxy(25,7);
	cout<<"Weight "<<udata->weight<<" kg"<<endl;
	gotoxy(25,8);
	cout<<"Blood Group "<<udata->bg<<endl;
	gotoxy(25,10);
	cout<<"Body Mass Index "<<udata->bmi<<endl;
	gotoxy(25,12);
	if(udata->bmi<=18)
	{	cout<<"You are Underweight";	}
	else if(udata->bmi>18 && udata->bmi<=24)
	{	cout<<"You are Healthy";	}
	else if (udata->bmi>24)
	{	cout<<"You are overweight";	}
	userinfo.close();
	getch();
	return tname;
}
char* core::newrec(char *tname)
{
	strcpy(filename,tname);
	l=strlen(filename);
	filename[l]='.';
	filename[l+1]='d';
	filename[l+2]='a';
	filename[l+3]='t';
	filename[l+4]='\0';
	back:
	clrscr();
	j=0;
	gotoxy(10,30);
	cout<<"Press 0 to go back";
	gotoxy(55,2);
	cout<<"Choose Category "<<endl;
	cout<<" 1.Vegetables"<<endl;
	cout<<" 2.Fruits"<<endl;
	cout<<" 3.Miscellaneous"<<endl;
	cout<<" 4.Dairy Products"<<endl;
	cin>>opt;
	switch(opt)
	{
		case 0:
		{
			goto end;
		}
		case 1:
		{
			do
			{
				in1:
				clrscr();
				finfo = new foodinfo;
				calobj=new caltab;
				getdate(&finfo->d1);
				foodrec.open(filename,ios::app,ios::binary);
				if(!foodrec)
				{	
					gotoxy(45,12);
					cout<<"Food record is missing."<<endl;
					gotoxy(43,18);
					cout<<"Press any key to continue.";
					getch();
					foodrec.close();
					goto back;
				}
				gotoxy(10,30);
				cout<<"Press 0 to go back";
				gotoxy(55,2);
				cout<<endl<<"Vegetables"<<endl;
				caltable.open("vegetables.dat",ios::in,ios::binary);
				if(!caltable)
				{	gotoxy(45,12);
					cout<<"Calorie Table is missing."<<endl;
					gotoxy(43,18);
					cout<<"Press any key to continue.";
					getch();
					foodrec.close();
					caltable.close();
					goto back;
				}
				i=0;
				while(caltable)
				{
					i++;
					caltable.read((char*) calobj,sizeof(caltab));
					cout<<i<<"."<<calobj->fname<<endl;
				}

				cout<<"Enter Your Choice ";	cin>>j;
				if(j==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				if(j>i)
				{	
					cout<<"Invalid choice. Enter again";
					sleep(1);	
					foodrec.close();
					caltable.close();
					goto in1;
				}
				cout<<"Enter quantity (in gms) ";	cin>>finfo->qty;
				caltable.close();
				if(finfo->qty==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				caltable.open("vegetables.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					caltable.close();
					goto back;
				}
				position=(j-1)*sizeof(caltab);
				caltable.seekg(position,ios::beg);
				caltable.read((char*)calobj,sizeof(caltab));
				strcpy(finfo->fname,calobj->fname);
				finfo->totcal=calobj->cal*finfo->qty/100;
				calsum=calsum+finfo->totcal;
				finfo->type=calobj->type;
				caltable.close();
				foodrec.write((char*)finfo,sizeof(foodinfo));
				foodrec.close();
				caltable.close();
				gotoxy(25,25);
				cout<<"Want to add another ?? Press y to enter another.";
				gotoxy(25,27);
				cout<<"Press any other key to continue.";
				cont=getch();

			}
			while(cont=='y'||cont=='Y');
			goto back;
		}
		case 2:
		{
			do
			{
				in2:
				clrscr();
				finfo = new foodinfo;
				calobj=new caltab;
				getdate(&finfo->d1);
				foodrec.open(filename,ios::app,ios::binary);
				if(!foodrec)
				{	
					cout<<"Food record is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					goto back;
				}
				gotoxy(10,30);
				cout<<"Press 0 to go back";
				gotoxy(55,2);
				cout<<endl<<"Fruits"<<endl;
				caltable.open("fruits.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					caltable.close();
					goto back;
				}
				i=0;
				while(caltable)
				{
					i++;
					caltable.read((char*) calobj,sizeof(caltab));
					cout<<i<<"."<<calobj->fname<<endl;
				}

				cout<<"Enter Your Choice ";	cin>>j;
				if(j==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				if(j>i)
				{	
					cout<<"Invalid choice. Enter again";
					sleep(1);	
					foodrec.close();
					caltable.close();
					goto in2;
				}
				cout<<"Enter quantity (in gms) ";	cin>>finfo->qty;
				caltable.close();
				if(finfo->qty==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				caltable.open("fruits.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					caltable.close();
					goto back;
				}
				position=(j-1)*sizeof(caltab);
				caltable.seekg(position,ios::beg);
				caltable.read((char*)calobj,sizeof(caltab));
				strcpy(finfo->fname,calobj->fname);
				finfo->totcal=calobj->cal*finfo->qty/100;
				calsum=calsum+finfo->totcal;
				finfo->type=calobj->type;
				caltable.close();
				foodrec.write((char*)finfo,sizeof(foodinfo));
				foodrec.close();
				caltable.close();
				gotoxy(25,25);
				cout<<"Want to add another ?? Press y to enter another.";
				gotoxy(25,27);
				cout<<"Press any other key to continue.";
				cont=getch();

			}
			while(cont=='y'||cont=='Y');
			goto back;
		}
		case 3:
		{
			do
			{
				in3:
				clrscr();
				finfo = new foodinfo;
				calobj=new caltab;
				getdate(&finfo->d1);
				foodrec.open(filename,ios::app,ios::binary);
				if(!foodrec)
				{	
					cout<<"Food record is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					goto back;
				}
				gotoxy(10,30);
				cout<<"Press 0 to go back";
				gotoxy(55,2);
				cout<<endl<<"Miscellaneous"<<endl;
				caltable.open("misc.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					caltable.close();
					goto back;
				}
				i=0;
				while(caltable)
				{
					i++;
					caltable.read((char*) calobj,sizeof(caltab));
					cout<<i<<"."<<calobj->fname<<endl;
				}

				cout<<"Enter Your Choice ";	cin>>j;
				if(j==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				if(j>i)
				{	
					cout<<"Invalid choice. Enter again";
					sleep(1);	
					foodrec.close();
					caltable.close();
					goto in3;
				}
				cout<<"Enter quantity (in gms) ";	cin>>finfo->qty;
				caltable.close();
				if(finfo->qty==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				caltable.open("misc.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					caltable.close();
					goto back;
				}
				position=(j-1)*sizeof(caltab);
				caltable.seekg(position,ios::beg);
				caltable.read((char*)calobj,sizeof(caltab));
				strcpy(finfo->fname,calobj->fname);
				finfo->totcal=calobj->cal*finfo->qty/100;
				calsum=calsum+finfo->totcal;
				finfo->type=calobj->type;
				caltable.close();
				foodrec.write((char*)finfo,sizeof(foodinfo));
				foodrec.close();
				caltable.close();
				gotoxy(25,25);
				cout<<"Want to add another ?? Press y to enter another.";
				gotoxy(25,27);
				cout<<"Press any other key to continue.";
				cont=getch();

			}
			while(cont=='y'||cont=='Y');
			goto back;
		}
		case 4:
		{
			do
			{
				in4:
				clrscr();
				finfo = new foodinfo;
				calobj=new caltab;
				getdate(&finfo->d1);
				foodrec.open(filename,ios::app,ios::binary);
				if(!foodrec)
				{	
					cout<<"Food record is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					goto back;
				}
				gotoxy(10,30);
				cout<<"Press 0 to go back";
				gotoxy(55,2);
				cout<<endl<<"Dairy Products"<<endl;
				caltable.open("dairy.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					foodrec.close();
					caltable.close();
					goto back;
				}
				i=0;
				while(caltable)
				{
					i++;
					caltable.read((char*) calobj,sizeof(caltab));
					cout<<i<<"."<<calobj->fname<<endl;
				}

				cout<<"Enter Your Choice ";	cin>>j;
				if(j==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				if(j>i)
				{	
					cout<<"Invalid choice. Enter again";
					sleep(1);	
					foodrec.close();
					caltable.close();
					goto in4;
				}
				cout<<"Enter quantity (in gms) ";	cin>>finfo->qty;
				caltable.close();
				if(finfo->qty==0)
				{
					foodrec.close();
					caltable.close();
					goto back;
				}
				caltable.open("dairy.dat",ios::in,ios::binary);
				if(!caltable)
				{	
					cout<<"Calorie Table is missing."<<endl<<"Press any key to continue.";
					getch();
					caltable.close();
					goto back;
				}
				position=(j-1)*sizeof(caltab);
				caltable.seekg(position,ios::beg);
				caltable.read((char*)calobj,sizeof(caltab));
				strcpy(finfo->fname,calobj->fname);
				finfo->totcal=calobj->cal*finfo->qty/100;
				calsum=calsum+finfo->totcal;
				finfo->type=calobj->type;
				caltable.close();
				foodrec.write((char*)finfo,sizeof(foodinfo));
				foodrec.close();
				caltable.close();
				gotoxy(25,25);
				cout<<"Want to add another ?? Press y to enter another.";
				gotoxy(25,27);
				cout<<"Press any other key to continue.";
				cont=getch();

			}
			while(cont=='y'||cont=='Y');
			goto back;
		}
		default:
		{
			cout<<" Invalid Choice ";	goto back;
		}
	}
	end:
	return tname;
}
char* core::viewrec(char *tname)
{
	j=0;
	calsum=0;
	strcpy(filename,tname);
	l=strlen(filename);
	filename[l]='.';
	filename[l+1]='d';
	filename[l+2]='a';
	filename[l+3]='t';
	filename[l+4]='\0';
	udata=new data;
	clrscr();
	cout<<"Enter Date To Search The Record For ";
	gotoxy(20,7);
	cout<<"Enter day ";			cin>>udata->d1.day;
	gotoxy(20,9);
	cout<<"Enter Month ";		cin>>udata->d1.mon;
	gotoxy(20,11);
	cout<<"Enter Year ";		cin>>udata->d1.year;
	foodrec.open(filename,ios::in,ios::binary);
	foodrec.read((char*)finfo,sizeof(foodinfo));
	clrscr();
	while(foodrec)
	{
		if(finfo->d1.da_day==udata->d1.day&&finfo->d1.da_mon==udata->d1.mon&&finfo->d1.da_year==udata->d1.year)
		{
			gotoxy(10,5);
			cout<<"Item";
			gotoxy(30,5);
			cout<<"Quantity";
			gotoxy(50,5);
			cout<<"Calories consumed";
			
			gotoxy(10,7+j);
			cout<<finfo->fname;
			gotoxy(30,7+j);
			cout<<finfo->qty;
			gotoxy(50,7+j);
			cout<<finfo->totcal<<endl; 
			calsum=calsum+finfo->totcal;
			j++;
		}
		foodrec.read((char*)finfo,sizeof(foodinfo));
	}
	if(j==0)
	{
		gotoxy(20,20);
		cout<<"Record Does Not Exist. Press any key to continue.";
		foodrec.close();
		getch();
		return tname;
	}
	else
	{
		gotoxy(20,10+j);
		cout<<"Total Calories "<<calsum;
		getch();
		foodrec.close();
		return tname;
	}
}
char* core::suggest(char *tname)
{
	j=1;
	calsum=0;
	remcal=0;
	averagecal=0;
	tempdate1=new mydate;
	tempdate2=new mydate;
	strcpy(filename,tname);
	clrscr();
	udata=new data;
	gotoxy(60,35);
	cout<<"Press 0 to Logout";
	gotoxy(78,5);
	cout<<filename;
	int l=strlen(filename);
	filename[l]='.';
	filename[l+1]='h';
	filename[l+2]='c';
	filename[l+3]='o';
	filename[l+4]='r';
	filename[l+5]='p';
	filename[l+6]='\0';
	userinfo.open(filename,ios::in,ios::binary);
	userinfo.read((char*)udata,sizeof(data));
	strcpy(filename,tname);
	l=strlen(filename);
	filename[l]='.';
	filename[l+1]='d';
	filename[l+2]='a';
	filename[l+3]='t';
	filename[l+4]='\0';
	foodrec.open(filename,ios::in,ios::binary);
	foodrec.read((char*)finfo,sizeof(foodinfo));
	if(!foodrec)
	{
		gotoxy(20,7);
		cout<<"No record found. Cannot estimate the required field.";
		gotoxy(20,10);
		cout<<"Press any key to continue.";
		getch();
		return tname;
	}
	tempdate2->day=finfo->d1.da_day;
	tempdate2->mon=finfo->d1.da_mon;
	tempdate2->year=finfo->d1.da_year;
	while(foodrec)
	{
		calsum=calsum+finfo->totcal;
		
		tempdate1->day=tempdate2->day;
		tempdate1->mon=tempdate2->mon;
		tempdate1->year=tempdate2->year;
			
		tempdate2->day=finfo->d1.da_day;
		tempdate2->mon=finfo->d1.da_mon;
		tempdate2->year=finfo->d1.da_year;
			
		if(tempdate1->day!=tempdate2->day || tempdate1->mon!=tempdate2->mon || tempdate1->year!=tempdate2->year)
		{	j++;	}
		
		foodrec.read((char*)finfo,sizeof(foodinfo));
	}
	averagecal=calsum/j;
	remcal=averagecal-2361;
	if(j==0)
	{
		gotoxy(20,7);
		cout<<"No record found. Cannot estimate the required field.";	getch();
	}
	if(j>0&&remcal<0)
	{
		gotoxy(25,5);
		cout<<"No need for any physical exercise."<<endl;
		gotoxy(20,7);
		cout<<"	Your average calorie intake is lower than it should be."<<endl<<endl;
		gotoxy(20,9);
		cout<<"Press any key to continue";
		getch();
	}
	if(j>0&&remcal>0)
	{
		calculator(remcal,udata->weight);
	}
	userinfo.close();
	foodrec.close();
	return tname;
}
void core::calculator(float remcal,float tempweight)
{
	int opt;
	float etime, ltime, gtime;
	etime=0;	ltime=0;	gtime=0;
	clrscr();
	gotoxy(55,2);
	cout<<"Physical activities"<<endl;
	cout<<"1. Golf (Using Cart)"<<endl;
	cout<<"2. Walk"<<endl;
	cout<<"3. Kayoing"<<endl;
	cout<<"4. Softball/Baseball"<<endl;
	cout<<"5. Swimming	"<<endl;
	cout<<"6. Tennis"<<endl;
	cout<<"7. Running"<<endl;
	cout<<"8. Bicycling"<<endl;
	cout<<"9. Soccer"<<endl;
	cout<<"10. Basketball"<<endl;
	cout<<"Enter Option ";
	cin>>opt;
	switch(opt)
	{
		case 1:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/210;
				ltime=((remcal+1000.0)*60)/210;
				gtime=((remcal-1000.0)*60)/210;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/260;	
				ltime=((remcal+1000.0)*60)/260;
				gtime=((remcal-1000.0)*60)/260;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/310;	
				ltime=((remcal+1000.0)*60)/310;
				gtime=((remcal-1000.0)*60)/310;
			}
			cout<<"To maintain your weight you should play Golf for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least play golf for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not play golf for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 2:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/240;
				ltime=((remcal+1000.0)*60)/240;
				gtime=((remcal-1000.0)*60)/240;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/300;	
				ltime=((remcal+1000.0)*60)/300;
				gtime=((remcal-1000.0)*60)/300;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/360;	
				ltime=((remcal+1000.0)*60)/360;
				gtime=((remcal-1000.0)*60)/360;
			}
			cout<<"To maintain your weight you should walk for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least walk for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not walk for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 3:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/300;
				ltime=((remcal+1000.0)*60)/300;
				gtime=((remcal-1000.0)*60)/300;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/370;	
				ltime=((remcal+1000.0)*60)/370;
				gtime=((remcal-1000.0)*60)/370;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/440;	
				ltime=((remcal+1000.0)*60)/440;
				gtime=((remcal-1000.0)*60)/440;
			}
			cout<<"To maintain your weight you should kayak for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least kayak for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not kayak for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 4:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/300;
				ltime=((remcal+1000.0)*60)/300;
				gtime=((remcal-1000.0)*60)/300;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/370;	
				ltime=((remcal+1000.0)*60)/370;
				gtime=((remcal-1000.0)*60)/370;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/440;	
				ltime=((remcal+1000.0)*60)/440;
				gtime=((remcal-1000.0)*60)/440;
			}
			cout<<"To maintain your weight you should play softball/baseball for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least play softball/baseball for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not play baseball/softball for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 5:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/360;
				ltime=((remcal+1000.0)*60)/360;
				gtime=((remcal-1000.0)*60)/360;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/440;	
				ltime=((remcal+1000.0)*60)/440;
				gtime=((remcal-1000.0)*60)/440;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/530;	
				ltime=((remcal+1000.0)*60)/530;
				gtime=((remcal-1000.0)*60)/530;
			}
			cout<<"To maintain your weight you should swim for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least swim for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not swim for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 6:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/420;
				ltime=((remcal+1000.0)*60)/420;
				gtime=((remcal-1000.0)*60)/420;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/520;	
				ltime=((remcal+1000.0)*60)/520;
				gtime=((remcal-1000.0)*60)/5200;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/620;	
				ltime=((remcal+1000.0)*60)/620;
				gtime=((remcal-1000.0)*60)/620;
			}
			cout<<"To maintain your weight you should play tennis for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least play tennis for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not play tennis for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 7:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/480;
				ltime=((remcal+1000.0)*60)/480;
				gtime=((remcal-1000.0)*60)/480;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/600;	
				ltime=((remcal+1000.0)*60)/600;
				gtime=((remcal-1000.0)*60)/600;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/710;	
				ltime=((remcal+1000.0)*60)/710;
				gtime=((remcal-1000.0)*60)/710;
			}
			cout<<"To maintain your weight you should run for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least run for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not run for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		
		case 8:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/480;
				ltime=((remcal+1000.0)*60)/480;
				gtime=((remcal-1000.0)*60)/480;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/600;	
				ltime=((remcal+1000.0)*60)/600;
				gtime=((remcal-1000.0)*60)/600;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/710;	
				ltime=((remcal+1000.0)*60)/710;
				gtime=((remcal-1000.0)*60)/710;
			}
			cout<<"To maintain your weight you should cycle for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least cycle for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not cycle for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 9:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/480;
				ltime=((remcal+1000.0)*60)/480;
				gtime=((remcal-1000.0)*60)/480;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/600;	
				ltime=((remcal+1000.0)*60)/600;
				gtime=((remcal-1000.0)*60)/600;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/710;	
				ltime=((remcal+1000.0)*60)/710;
				gtime=((remcal-1000.0)*60)/710;
			}
			cout<<"To maintain your weight you should play soccer for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least play soccer for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not play soccer for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
		case 10:
		{
			if(tempweight<=70.0)
			{	
				etime=(remcal*60)/480;
				ltime=((remcal+1000.0)*60)/480;
				gtime=((remcal-1000.0)*60)/480;
			}
			else if(tempweight>70.0&&tempweight<=84.0)
			{	
				etime=(remcal*60)/600;	
				ltime=((remcal+1000.0)*60)/600;
				gtime=((remcal-1000.0)*60)/600;
			}
			else if(tempweight>84.0)
			{	
				etime=(remcal*60)/710;	
				ltime=((remcal+1000.0)*60)/710;
				gtime=((remcal-1000.0)*60)/710;
			}
			cout<<"To maintain your weight you should play basketball for a minimum of "<<etime<<" minutes"<<" or "<<etime/60<<" hours"<<endl<<endl;
			cout<<"To lose 1 kg of weight you should at least play basketball for "<<ltime<<" minutes"<<" or "<<ltime/60<<" hours"<<endl<<endl;
			if(gtime<0)
			{
				cout<<"You do not need any extra physical activity at current rate to gain weight."<<endl<<endl;
			}
			else
			{
				cout<<"To gain 1 kg of weight you should not play basketball for more than "<<gtime<<" minutes"<<" or "<<gtime/60<<" hours"<<endl<<endl;
			}
			cout<<"These figures are for steadily losing/gaining weight per week.";
			break;
		}
	}
	cout<<endl<<endl<<"Press any key to continue";
	getch();
}

void main()
{
	clrscr();
	int diff;
	char *tname;
	char opt;
	enter enter1;
	core core1;
	userlst.open("Userlist.hcorp",ios::in,ios::binary);
	if(!userlst)
	{
		diff=1;
		clrscr();
		system("show.exe");
		char ch;
		obj.open("firstrun.hcorp",ios::in);
		while(obj.get(ch))
		{
			cout<<ch;
			Sleep(random(100));
		}
		obj.close();
		system("hide.exe");
		enter1.expert(diff);
		cout<<"Press 0 to skip help page ";
		ch=getch();
		if(ch!='0')
		{
			sleep(1);
			enter1.printhelp();
		}
	}
	userlst.close();
	logout:
	opt=mainpage();
	if(opt=='1')
	{
		tname=enter1.login();
		if(*tname=='0')
		{
			goto logout;
		}
	}
	else if (opt=='2')
	{
		tname=enter1.signup();
		if(*tname=='0')
		{
			goto logout;
		}
		core1.uget(tname);
	}
	else if (opt=='3')
	{
		enter1.about();
		goto logout;
	}
	else if (opt=='8')
	{
		enter1.printhelp();
		goto logout;
	}
	else if (opt=='9')
	{
		diff=0;
		enter1.expert(diff);
		goto logout;
	}
	repeat:
	opt=postlogin(tname);
	if(opt=='0')
	{	goto logout;		}
	else if(opt=='1')
	{	
		tname=core1.newrec(tname);
		goto repeat;
	}
	else if(opt=='2')
	{	
		tname=core1.viewrec(tname);	
		goto repeat;
	}
	else if(opt=='3')
	{	
		tname=core1.uput(tname);	
		goto repeat;
	}
	else if(opt=='4')
	{	
		tname=core1.uget(tname);	
		goto repeat;
	}
	else if(opt=='5')
	{	
		tname=core1.suggest(tname);
		goto repeat;
	}
	getch();
}

int mainpage()
{
	char opt;
	err:
	clrscr();
	gotoxy(35,18);
	cout<<"Want to modify how the program works?"<<endl;
	gotoxy(38,20 );
	cout<<"Press 9 to enter Expert mode";
	gotoxy(25,5);
	cout<<"Already a Member?";
	gotoxy(25,7);
	cout<<"Press 1 to Login";
	gotoxy(65,5);
	cout<<"New Member? Join Now.";
	gotoxy(65,7);
	cout<<"Press 2 to Register ";
	gotoxy(5,24);
	cout<<"Press 3 to know more.";
	gotoxy(8,26);
	cout<<"About Us";
	gotoxy(80,24);
	cout<<"Press 8 to view help page.";
	gotoxy(45,30);
	cout<<"Press zero to exit.";
	cin>>opt;
	clrscr();
	if(opt=='0')
	{
		clrscr();
		gotoxy(52,3);
		cout<<"Goodbye.";
		sleep(1);
		gotoxy(48,16);
		cout<<"Exiting .";
		sleep(1);
		gotoxy(48,16);
		cout<<"Exiting . .";
		sleep(1);
		gotoxy(48,16);
		cout<<"Exiting . . .";
		sleep(1);
		exit(0);
	}
	else if(opt=='1'||opt=='2'||opt=='3'||opt=='8'||opt=='9')
	{
		return opt;
	}
	else
	{	goto err;	}
}
int postlogin(char *ch)
{
	char opt;
	err:
	clrscr();
	gotoxy(10,30);
	cout<<"Press 0 to Logout";
	gotoxy(84,3);
	cout<<ch;
	gotoxy(25,10);
	cout<<"1. Enter today's record"<<endl;
	gotoxy(25,12);
	cout<<"2. View previous record"<<endl;
	gotoxy(25,14);
	cout<<"3. View personal details"<<endl;
	gotoxy(25,16);
	cout<<"4. Edit personal details"<<endl;
	gotoxy(25,18);
	cout<<"5. Suggestions for you"<<endl;
	gotoxy(25,24);
	cin>>opt;
	if(opt>='0' || opt<='5')
	{	return opt;	}
	else
	{	goto err;	}
}
void tableeditor()
{
	int opt;
	char n;
	caltab *edit;
	edit =new caltab;
	cout<<"Please enter carefully as we currently do not have the option to modify or delete the entries."<<endl;
	getch();
	do 
	{
		clrscr();
		cout<<"Enter Type ( v/V=Vegetables, f/F=Fruits, m/M=Meat, e/E=Miscellaneous Items, d/D for Dairy Products)";	cin>>edit->type;
		cout<<"Enter item ";	gets(edit->fname);
		cout<<"Enter Calories per 100gm ";	cin>>edit->cal;
		edit->qty=1;
		if(edit->type=='v'||edit->type=='V')
		{
			caltable.open("vegetables.dat",ios::app,ios::binary);
			caltable.write((char*)edit,sizeof(caltab));
			caltable.close();
		}
		else if(edit->type=='f'||edit->type=='F')
		{
			caltable.open("fruits.dat",ios::app,ios::binary);
			caltable.write((char*)edit,sizeof(caltab));
			caltable.close();
		}	
		else if(edit->type=='m'||edit->type=='M')
		{
			caltable.open("misc.dat",ios::app,ios::binary);
			caltable.write((char*)edit,sizeof(caltab));
			caltable.close();
		}
		else if(edit->type=='e'||edit->type=='E')
		{
			caltable.open("dairy.dat",ios::app,ios::binary);
			caltable.write((char*)edit,sizeof(caltab));
			caltable.close();
		}
		cout<<"Press y/Y to to enter other."<<endl<<"Press any other key to exit";		n=getch();
	}	
	while(n=='y'||n=='Y');
}