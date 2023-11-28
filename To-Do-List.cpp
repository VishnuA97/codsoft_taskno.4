#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

string task;

ifstream read;
ofstream file;

int menu(){
    system("cls");
    int choice;
    cout<<"\t\t\t\t\t\tTo-Do List\n\n\n";
    cout<<"1.  Add a new task\n";
    cout<<"2.  View the list\n";
    cout<<"3.  Mark a task as completed\n";
    cout<<"4.  Delete a task\n";
    cout<<"5.  Quit\n\n\n";
    cout<<"Enter a choice:";
    cin >> choice;
    return(choice);
}

void back(){
    char cho;
    cout << "Press M to go to Main menu..." << endl;
    cin>>cho;
    if(cho == 'm' || cho == 'M'){
       return;
    }
    else{
        cout <<"Invalid command!!!\n";
        back();
    }
}


void add(){
    system("cls");
    
    char ch;
    cout << "Enter Task:";
    getline(cin>>ws,task);
    cin.get();
   
    file.open("task.txt", ios::app | ios::binary); 
    file << task<<"\n";
    file.close();
    
    cout<<"Do you want to add more task? y/n"<<endl;
    cin>> ch;

    if(ch == 'y' || ch == 'Y'){
        add();
    }
    else if(ch=='n' || ch=='N'){
        back();
    }
    else{
        cout<<"Invalid command!!!\n";
        back();
    }
}
    
void view_task(){
    int count=0;
    system("cls");
    read.open("task.txt", ios::in | ios::binary);
    if(!read){
        cout << "File Not Found\n";
    }
    else{
        while(read.peek()!=EOF) {
            getline(read, task);
            count++;
            cout<<count<<". "<<task<<"\n";
        }
    }
    read.close();
}
void complete(){
    int count=0;
    int num,i;
    view_task();
    cout<<"Enter the Task Number to mark as complete:\n";
    cin>>num;
    file.open("temp.txt", ios::app | ios::binary);
    read.open("task.txt", ios::in | ios::binary);
    while(read.peek()!=EOF) {
        getline(read, task);
        count++;
        if(count!=num){
            file<<task<<"\n";
        }
        else if(count==num){
            file<<task<<"------------------------(Complete)\n";
        }
    }    
    file.close();
    read.close();
    remove("task.txt");
    rename("temp.txt", "task.txt");
    back();

}

void delete_task(){
    int count=0;
    int num,i;
    view_task();
    cout<<"Enter the Task Number to delete that task:\n";
    cin>>num;
    file.open("temp.txt", ios::app | ios::binary);
    read.open("task.txt", ios::in | ios::binary);
    while(read.peek()!=EOF) {
        getline(read, task);
        count++;
        if(count!=num){
            file<<task<<"\n";
        }
    }    
    file.close();
    read.close();
    remove("task.txt");
    rename("temp.txt", "task.txt");
    back();
}

int main(){
    while(true){
        switch (menu()) 
        {
            case 1:
                add();
                break;
            case 2:
                view_task();
                back();
                break;
            case 3:
                complete();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Error!!! Wrong choice!";
                back();
                break;
        }
    }
   
    return 0;
}