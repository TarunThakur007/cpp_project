#include<iostream>
#include<time.h>
using namespace std;
void banner(){
    cout<<"\t |--------------------------|" <<endl;
    cout<<"\t |Rock Papper Scissor|" << endl;
    cout<<"\t |--------------------------|" <<endl;
}
char getUserInput(){
    char choice;
    cout<<"Choose Your Option:"<<endl;
    cout<<"(r) for Rock" <<"(p) for Papper" <<"(s) for Scissor"<< endl << "->";
    cin>> choice;
    while(choice !='r' && choice!='p' && choice!='s'){
        system("cls");
        banner();
        cout<<"Invalid choice:";
        cout<<"(r) for Rock" <<"(p) for Papper" <<"(s) for Scissor"<< endl << "->";
        cin>> choice;
    }
    return choice;
}
void showChoice(char input){
    if(input== 'r'){
        cout<< "Rock" <<endl;
    }
    if(input== 'p'){
        cout<< "Papper" <<endl;
    }
    if(input== 's'){
        cout<< "Scissors" <<endl;
    }
}
char getComputerInput(){
    srand(time(0));
    int choice = rand() % 3;
    if(choice==1){
        return 'r';
    }
    else if(choice==2){
        return 'p';
    }
    return 's';
    
}
void showWinner(char user, char computer){
    if(user == 'r' && computer =='s'){
        cout<<"You win! "<< endl;
    }
    else if(user == 's' && computer == 'p'){
        cout<<"You win!"<< endl;
    }
    else if(user == 'p' && computer == 'r'){
        cout<<"You win!";
    }
    else if(user == 'p' && computer =='s'){
        cout<<"Computer win! "<< endl;
    }
    else if(user == 'r' && computer == 'p'){
        cout<<"Computer win!"<< endl;
    }
    else if(user == 's' && computer == 'r'){
        cout<<"Computer win!";
    }
    else{
        cout<<"Tie! Play again..."<<endl;
    }
}
int main(){
    banner();
    // User Choice
    char user_input, computer_input;
    user_input = getUserInput();
    cout<<" Your choice is:"<< endl;
    showChoice(user_input);
    //computer choice
    computer_input = getComputerInput();
    cout<< "Computer's choice:"<< endl;
    showChoice(computer_input);
    // comperision
    showWinner(user_input,computer_input);
    return 0;
}