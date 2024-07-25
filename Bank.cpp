#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class bank{

  private:
     
     float  balance;
     string id, pass, name, fname, address, phone, pin;

    public: 
      void menu();
      void bank_management();
      void atm_management();
      void new_user();
      void already_user();
      void deposit();
      void withdraw();
      void transfer();
      void payment();
      void search();
      void edit();
      void del();
      void show_records();
      void show_payment();
      void user_balance();
      void withdraw_atm();
      void check_detail();

};

void introduction()
{
    cout<<"\n\t";
    for(int i=1; i<= 60; i++)
    cout<<"*";
    cout<<"\n\t ";
    for(int i=1; i<= 58; i++)
    cout<<"*";
    cout<<"\n\t  ";
    for(int i=1; i<= 56; i++)
    cout<<"*";
    
    cout<<"\n\n\t   Bank & ATM Management System \n\n\t ";
    for(int i=1; i<= 56; i++)
    cout<<"*";
     cout<<"  \n\t";
    for(int i=1; i<= 58; i++)
    cout<<"*";
     cout<<" \n\t";
     for(int i=1; i<= 60; i++)
    cout<<"*";
     cout<<"\n\t";

     getch();
     system("cls");
   

}

void bank :: menu(){

    p:       // this is a label it will repeat again and again 
    system("cls");
    int choice;
    int ch;
    string pin, pass, email;

    cout<< "\n\n\t\t\tcontrol panel";
    cout<< " \n\n 1. Bank Management";
     cout<< " \n\n 2. ATM Mangement";
      cout<< " \n\n 3. Exit";
       cout<< " \n\n enter your choice : ";

       cin>> choice;
       switch(choice){

        case 1:
         cout<< " \n\n\t\t\tlogin Account";
          cout<< " \n\n E-mail : ";
          cin >> email;
           cout<< " \n\n\t\t Pin Code";
           for(int i=1; i<5; i++){

            ch = getch();
            pin += ch;
            cout<< " *";

           }
           
           cout<<"\n\n Password : ";
           for(int i=1; i<5; i++){

            ch = getch();
            pass  += ch;
            cout<< "*";
           }

           if(email == "abc@gmail.com"  && pin == "1234" && pass == "1234"){
              bank_management();
           }
           
           else{
           cout<< " your email.pass is wrong ";
           }  
            break;

        case 2:
        atm_management();
        break;

        case 3:
          exit(0);

        default:
        cout<<"\n\n Invalide value ...... please try again";

       }
       getch();
       goto p;

}

void bank:: bank_management(){

  p:
  system("cls");
  int choice;
  cout<<"\n\n\t\t\tBanking Managament System";
  cout<<"\n\n 1. New User";
  cout<<"\n2.  Already User";
  cout<<"\n3.  Deposit Option ";
  cout<<"\n4.  Withdraw Option";
  cout<<"\n5.  Transfer Option";
  cout<<"\n6.  Payment Option";
  cout<<"\n7.  Search User Record";
  cout<<"\n8.  Edit User Record";
  cout<<"\n9.  Delete User Record";
  cout<<"\n10. show All Record ";
  cout<<"\n11. Payment All Record ";
  cout<<"\n12. Go Back ";
  cout<<"\n\n Enter your choice : ";
  cin>>choice;
  switch(choice){
    case 1:
    new_user();
    break;

    case 2:
    already_user();
     break;

    case 3:
    deposit();
      break;

    case 4:
    withdraw();
     break;

    case 5:
    transfer();
     break;

    case 6:
    payment();
     break;

    case 7:
    search();
     break;

    case 8:
    edit();
     break;

    case 9:
    del();
     break;
   
   case 10:
   show_records();
    break;

    case 11:
    show_payment();
     break;

    case 12:
    break;

   default:
        cout<<"\n\n Invalide value ...... please try again";

  }
  getch();
  goto p;

}

void bank:: atm_management(){


  p:
  system("cls");
  int choice;
  cout<<"\n\n\t\t\tATM Managament System";
  cout<<"\n\n 1. User Login & check Balance";
  cout<<"\n2.Withdraw Amount";
  cout<<"\n3.Account Details ";
  cout<<"\n4.Go Back";
  cout<<"\n\n Enter your choice : ";
  cin>>choice;
  switch(choice){
    case 1:
     user_balance();
    break;

    case 2:
    withdraw_atm();
     break;

     case 3:
     check_detail();
      break;

    case 4:
    menu();
   
   default:
        cout<<"\n\n Invalide value ...... please try again";
  }
  getch();
  goto p;
}

void bank:: new_user(){
  p:
  system("cls");
  fstream file;
  int p;
  float b;
  string n,f,pa,a,ph,i;

  cout<<"\n\n\t\tdd New User";
  cout<<"\n\n User ID : ";
  cin>> id;
  cout<<"\n\n\tName : ";
  cin>> name;
  cout<<"\n\n Father Name: ";
  cin>> fname;
  cout<<"\n\n\t Address : ";
  cin>> address;
  cout<<"\n\n\t Pin Code(5 digit) : ";
  cin>> pin;
  cout<<"\n\n\t Paasword(5 digit) : ";
  cin>> pass;
  cout<<" \n\n\t Phone no. :";
  cin>> phone;
  cout<<"\n\n\t Current Balance : ";
  cin >> balance;
  file.open("bank.txt", ios::in);
  if(!file){

    file.open("bank.text",ios::app|ios::out);
    file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
    file.close();
  }
  else{

    file>>i>>n>>f>>a>>p>>pa>>ph>>b;
    while(!file.eof())
    {
      if(i ==id)
      {
        cout<<"\n\n User Id already exist ... "<<endl;
        getch();
        goto p;
      }
       file>>i>>n>>f>>a>>p>>pa>>ph>>b;
    }
    file.close();
    file.open("bank.text",ios::app|ios::out);
    file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
    file.close();

  }
  cout<<"\n\n New User Account Created Succesflly... "<<endl;
}

void bank:: already_user(){
  system("cls");
  fstream file;
  string t_id;
  int found =0;

  cout<<"\n\nAlready User Acount "<<endl;
  file.open("bank.text", ios::in);
  if(!file)
  {
    cout<<"\n\n File Opening Error..."<<endl;
  }

  else
  {
    cout<<" User Id : ";
    cin>>t_id;
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id){
        system("cls");
        cout<<"\n\n Already a User Account "<<endl;
        cout<<"\n\n User ID : "<<id<<"    Pin code : "<<pin<<"   Password : "<<pass <<endl;
        found++;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
 
    }
    file.close();
    if(found ==0)
     cout<<"\n\n User id Cannot found...";
  }

}

void bank:: deposit()
{ 
  fstream file, file1;
  string t_id;
  float dep;
  int found =0;
  system("cls");
  cout<<"\n\n\tDeposit Amount Option   "<<endl;
  file.open("bank.text", ios::in);
  if(!file){
    cout<<"\n\n File Opening Error..."<<endl;
  }
  else{
        
    cout<<" User ID"<<endl;
    cin>>t_id;
    file1.open("bank1.text", ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      if(t_id == id){
      cout<<"\n\n Amount For Deposit : ";
      cin>>dep;
      balance += dep;
      file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
        found++;
        cout<<"\n\n Your Amount "<<dep<<" has succesfully deposited...";
      }
      else{
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
 
    }
    file.close();
    file1.close();
    remove("bank.text");
    rename("bank1.text","bank.text");
    if(found ==0)
     cout<<"\n\n User id Cannot found..."<<endl;
  

  }
}


void bank:: withdraw()
{ 
  fstream file, file1;
  string t_id;
  float with;
  int found =0;
  system("cls");
  cout<<"\n\n\t withdraw Amount Option "<<endl;
  file.open("bank.text", ios::in);
  if(!file){
    cout<<"\n\n File Opening Error..."<<endl;
  }
  else{
        
    cout<<" User ID : ";
    cin>>t_id;
    file1.open("bank1.text", ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){

      if(t_id == id)
      {
      cout<<"\n\n Amount For withdraw : ";
      cin>>with;

      if(with <= balance){
        balance -= with;
       
      file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";

        cout<<"\n\n Your Amount "<<with<<" has succesfully withdraw..."<<endl;
      }
      else{
        
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";

        cout<<"\n\n Your current balance "<<balance<<" is insufficient"<<endl;
      }
      found++;
      }

      else
      {
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.text");
    rename("bank1.text","bank.text");
    if(found ==0)
     cout<<"\n\n User id Cannot found..."<<endl;
  

  }
}

void bank::transfer()
{
  fstream file, file1;
  system("cls");
  string s_id, r_id;
  float amount;
  int found=0;
  cout<<"\n\n\t Payment Transfer Option"<<endl;

  file.open("bank.text", ios::in);
  if(!file){
    cout<<"\n\n File Opening Error..."<<endl;
  }
  else
  {
    cout<<"Enter sender user id for transaction : ";
    cin>>s_id ;
    cout<<endl;
    cout<<"Reciever ID for trancation : ";
    cin>>r_id;
    cout<<" \n\n Enter transfer amount : ";
    cin>>amount;
  
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof())
    {
      if(s_id == id && amount <= balance)
      found++;
      else if(r_id == id)
      found++;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found == 2)
    {
      file.open("bank.text", ios::in);
       file1.open("bank1.text", ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while(!file.eof())
       {
        if(s_id == id )
        {
           balance -= amount;
            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
        }
        else if(r_id == id){
          balance += amount;
           file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
        }
        else
        {
           file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
        }
          file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.text");
        rename("bank1.text","bank.text");
       }
    
    else{
       cout<<"\n\nBoth transaction user id and balance  is invalid... ";
    }
}
    
  }

void bank::payment()
{
  system("cls");
  fstream file, file1;
  int found=0;
  string t_id, b_name;
  float amount;
  SYSTEMTIME x;
  cout<<"\n\n\t Bills Payment Option ";
  file.open("bank.text", ios::in);
  if(!file){
    cout<<"\n\n File openeing error... ";
  }
  else{
     cout<<"\n\n Use ID : ";
     cin>>t_id;
     cout<<"\n\n Bill Name : ";
     cin>>b_name;
     cout<<"\n\n Bill Amount : ";
     cin>> amount;

     file1.open("bank1.text", ios::app| ios::out);

      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      while(!file.eof())
      {
        if(t_id == id && amount <= balance)
        {

           balance -= amount;
          file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
          found++;
      }
      else
      {
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
      }
      file.close();
      file1.close();
         remove("bank.text");
         rename("bank1.text","bank.text");
        
      if(found == 1)
      { 
        GetSystemTime(&x);
        file.open("bill.text", ios::app|ios::out);
        file<<t_id<<" "<<b_name<<" "<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<" \n";
        file.close();
        cout<<"\n\n Bill  " <<b_name<<" succesfully paid..";
      }
      else{
        cout<<"\n\n User ID or Amount is Invalid..";
      }
  }

}

void bank::search()
{

  system("cls");
  fstream file;
  string t_id;
  int found =0;
  cout<<"\n\n\t\t Search User Record";
  file.open("bank.text" , ios::in);
  if(!file){
    cout<<"\n\nfile opening error....";
   
  }
  else{
    cout<<"\n\n User ID : "<<endl;
    cin>>t_id;
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof())
    {
      if(t_id == id)
      {
        system("cls");
        cout<<"\n\n Search User Record";
        cout<<"\n\n User ID : "<<id<<" Name : "<<name<<"    Father's name : "<<fname;
        cout<<"\n\n Address : "<< address<<"    Pin: "<<pin<< "     Password : "<<pass;
        cout<<"\n Phone no. : "<<phone<<"   Current Balance : "<<balance;
        found++;
      }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found == 0)
     cout<<"\n\n User ID can't found ...";
  }
}

void bank::edit()
{
  system("cls");
  fstream file, file1;
  string t_id,n,f,a,p,ph;
  int found =0, pi;
 
  cout<<"\n\n Edit user record ";
  file.open("bank.text", ios::in);
  if(!file)
  {
    cout<<"\n\n File opening error...";
  }

  else
  {
    cout<<"\n\n user ID: ";
    cin>>t_id;
    file1.open("bank1.text", ios::app|ios::out); /////

    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof())
    {
      if(t_id == id)
      {
         cout<<"\n\n\tName : ";
         cin>> n;
         cout<<"\n\n Father Name: ";
         cin>> f;
         cout<<"\n\n\t Address : ";
         cin>> a;
         cout<<"\n\n\t Pin Code(5 digit) : ";
         cin>> pi;
         cout<<"\n\n\t Paasword : ";
         cin>> p;
         cout<<" \n\n\t Phone no. :";
         cin>> ph;
        
         file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<"  "<<pi<<" "<<p<<" "<<ph<<" "<< balance<<"\n";
      
         cout<<"\n\n Your record edited succesfully..";
         found++;
      }
      else
      {
         file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.text");
    rename("bank1.text", "bank.text");
    if(found == 0)
     cout<<"\n\n User ID can't found ...";
  }

  }

  void bank::del()
  {
    
  system("cls");
  fstream file, file1;
  string t_id;
  int found =0;
 
  cout<<"\n\n Edit user record ";
  file.open("bank.text", ios::in);

  if(!file)
  {
    cout<<"\n\n File opening error...";
  }

  else
  {
    cout<<"\n\n user ID: ";
    cin>>t_id;
    file1.open("bank.text", ios::app|ios::out);

    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof())
    {
      if(t_id == id)
      {
        
         cout<<"\n\n Your record deleted succesfully..";
         found++;
      }
      else
      {
         file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.text");
    rename("bank1.text", "bank.text");
    if(found == 0)
     cout<<"\n\n User ID can't found ...";
  }
  }

  void bank:: show_records()
  {
    system("cls");
    fstream file;
    int found =0;
    cout<<"\n\n  Show all user records";
    file.open("bank.text",ios::in);
    if(!file)
    {
      cout<<"\n\n file opening error";
    }
    else
    {  
     
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

    while(!file.eof())
    {   
      cout<<"\n\n\n User ID :"<<id;
      cout<<"\n\n\n User name :"<<name;
      cout<<"\n\n\n User father name  :"<<fname;
      cout<<"\n\n\n User address :"<<address;
      cout<<"\n\n\n User Pin :"<<pin;
      cout<<"\n\n\n User password :"<<pass;
      cout<<"\n\n\n User phone n.:"<<phone;
      cout<<"\n\n\n User current balance:"<<balance;
      cout<<"\n\n************************************************";

        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        found++;
    }
    file.close();
    if(found ==0){
      cout<<"data base is empty....";
    }

    }
    
  }
  
  void bank::show_payment()
  {
    system("cls");
    fstream file;
    int found =0;
    float amount;
    string c_date;
    cout<<"\n\n  Show all user bill's record";
    file.open("bill.text",ios::in);
    if(!file)
    {
      cout<<"\n\n file opening error";
    }
    else
    {  

     
      file>>id>>name>>amount>> c_date;

    while(!file.eof())
    {   
      cout<<"\n\n\n User ID : "<<id;
      cout<<"\n\n\n User bill name : "<<name;
      cout<<"\n\n\n Bill Amounr : "<<amount;
      cout<<"\n\n\n Date :"<<c_date;
      
     
      cout<<"\n\n************************************************";

         file>>id>>name>>amount>> c_date;
        found++;
    }
    file.close();
    if(found ==0){
      cout<<"data base is empty....";
    }

    }
  }

void bank::user_balance()
{
  system("cls");
  fstream file;
  string t_id, t_pin, t_pass;
  char ch;
  int found =0;

  cout<<"\n\n User Login and check balance";
  file.open("bank.text", ios::in);
  if(!file)
  {
    cout<<"file opening error...";
  }

  else
  {
      cout<<"\n\n user ID : ";
      cin>>t_id;
      cout<<"\n\n Pin Code : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pin += ch;
        cout<<"*";
      }
      cout<<"Password : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pass += ch;
        cout<<"*";
      }
           file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
           while(!file.eof())
           {
            if(t_id == id && t_pin == pin && t_pass == pass)
            {
              cout<<"\n\n  Your current balance is : "<<balance;
              found++;
            }
                 file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
           }
           file.close();
           if(found == 0)
           {
            cout<<"\n\n User Id  and Password invalid...";
           }
  }
}
  void bank::withdraw_atm()
  {
    
  fstream file, file1;
  string t_id, t_pass, t_pin;
  float with;
  char ch;
  int found =0;
  system("cls");
  cout<<"\n\n withdraw Amount Option "<<endl;
  file.open("bank.text", ios::in);
  if(!file){
    cout<<"\n\n File Opening Error..."<<endl;
  }
  else{
        
    cout<<" User ID";
    cin>>t_id;
    cout<<"\n\n Pin Code : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pin += ch;
        cout<<"*";
      }
      cout<<"Password : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pass += ch;
        cout<<"*";
      }
    
    file1.open("bank1.text", ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof()){
      
         if(t_id == id && t_pin == pin && t_pass == pass)
     // if(t_id == id && t_pass = pass && t_pin = pin)
      {
      cout<<"\n\n Amount For withdraw : ";
      cin>>with;

      if(with <= balance){
        balance -= with;
       
      file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";

        cout<<"\n\n Your Amount "<<with<<" has succesfully withdraw..."<<endl;
         cout<<"\n\n Your current balance is : "<<balance;
      }
      else{
        
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";

        cout<<"\n\n Your current balance "<<balance<<" is insufficient"<<endl;
      }
      found++;
      }

      else
      {
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<"  "<<pin<<" "<<pass<<" "<<phone<<" "<< balance<<"\n";
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    file1.close();
    remove("bank.text");
    rename("bank1.text","bank.text");
    if(found ==0)
     cout<<"\n\n User id Cannot found..."<<endl;
  
  }
  }


  void bank:: check_detail()
  {
  fstream file;
  string t_id, t_pass, t_pin;
  char ch;
  int found =0;
  system("cls");
  cout<<"\n\n Check Details option "<<endl;
  file.open("bank.text", ios::in);
  if(!file)
  {
    cout<<"\n\n File Opening Error..."<<endl;
  }
  else
  {
        
    cout<<" User ID";
    cin>>t_id;
    cout<<"\n\n Pin Code : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pin += ch;
        cout<<"*";
      }
      cout<<"Password : ";
      for(int i=1; i<= 5; i++)
      {
        ch = getch();
        t_pass += ch;
        cout<<"*";
      }
    
    file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    while(!file.eof())
    {
         if(t_id == id && t_pin == pin && t_pass == pass)
     // if(t_id == id && t_pass = pass && t_pin = pin)
      {
      
      system("cls");
      cout<<"\n\n Check Details option "<<endl;
      cout<<"\n\n\n User ID :"<<id;
      cout<<"\n\n\n User name :"<<name;
      cout<<"\n\n\n User father name  :"<<fname;
      cout<<"\n\n\n User address :"<<address;
      cout<<"\n\n\n User Pin :"<<pin;
      cout<<"\n\n\n User password :"<<pass;
      cout<<"\n\n\n User phone n.:"<<phone;
      cout<<"\n\n\n User current balance:"<<balance;
      
      found++;
      }
      file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
    }
    file.close();
    if(found ==0)
     cout<<"\n\n User id Cannot found..."<<endl;
  
  }
  }

 main(){

      bank obj;
      introduction();
      obj.menu();
      
 }