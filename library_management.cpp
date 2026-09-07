#include<iostream>
#include<fstream>
using namespace std;
class temp{
    string id , name , author , search;
    fstream file;
    public:
    void addbook();
    void showall();
    void extractbook();
}obj;

int main(){
    char choice;
    cout<<"-------------------------------------\n";
    cout<<"1. Show all books:\n";
    cout<<"2. Extract book:\n";
    cout<<"3. Add book(ADMIN)\n";
    cout<<"4. Exit\n";
    cout<<"-------------------------------------\n";
    cout<<"Enter Your choice:";
    cin>> choice;
    cin.ignore();
    switch(choice){
        case '1':
            obj.showall();
        break;

        case '2':
            obj.extractbook();
        break;
        
        case '3':
            obj.addbook();
        break;

        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid choice!\n";
    }
    return 0;
}


void temp :: addbook(){
    cout<<"\n Enter Book ID:";
    getline(cin,id);
    cout<<"Enter book name:";
    getline(cin,name);
    cout<<"Enter Book's author name:";
    getline(cin,author);

    file.open("bookdata.txt",ios :: out| ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}


void temp :: showall(){
    file.open("bookdata.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    if(!file){
        cout<<"File not found!\n";
        return;
    }
        cout<<"\n\n";
        cout<<"\t\t Book ID \t\t\t Book Name  \t\t\t Author's Name";
    while(getline(file,id,'*')){
        getline(file,name,'*');
        getline(file,author,'\n');

        cout<<id<<"\t"<<name<<"\t"<<author<<endl;
    }
    file.close();
}


void temp :: extractbook(){

    showall();
    cout<<"Enter book Id:";
    getline(cin,search);

    if(!file){
        cout<<"File not found!\n";
        return;
    }
    bool found = false;

    file.open("bookdata.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t Book ID \t\t\t Book Name  \t\t\t Author's Name";
    while(getline(file,id,'*')){
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    // if(search==id){
    //     cout<<id<<"\t"<<name<<"\t"<<author<<endl;
    //     cout<<"Book Extract Successfully.....";
    //     break;
    // } 
    if(search==id){
        cout<<"\nBook ID : "<<id<<endl;
        cout<<"Book Name : "<<name<<endl;
        cout<<"Author : "<<author<<endl;
        found=true;
    }
    //break;
    file.close();   
}