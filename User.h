#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class User
{
long int UserId;
string UserName;
string Name;
int UserBirthday;
string UserPassword;
int LoginData;

public:

User(long int UserId,string UserName="",string Name="",int UserBirthday=0,string UserPassword="",int LoginData=0)
: UserId(UserId), UserName(UserName), Name(Name), UserBirthday(UserBirthday) , UserPassword(UserPassword), LoginData(LoginData){}

virtual~User(){};


long int getUserId() const{return UserId;}
string getUserName() const { return UserName; }
string getName() const { return Name; }
int getUserBirthday() const { return UserBirthday; }
string getUserPassword() const { return UserPassword; }
int getLoginData() const { return LoginData; }

void print()const
{
    cout<< "UserId:"<<UserId<<"\n"
    <<"UserName:"<<UserName<<"\n"
    <<"Name:"<<Name<<"\n"
    <<"UserBirthday:"<<UserBirthday<<"\n"
    <<"UserPassword:"<<UserPassword<<"\n"
    <<"LoginData:"<<LoginData<<endl;
}
bool checkPassword(const string& Password )const
{
    if(UserPassword==Password)
    return true;
return false;
}

};