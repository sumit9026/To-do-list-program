#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
int ID;

struct todo {
    int ID;
    string task;
};

void addtodo(){
    system("cls");
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t               WELCOME TO Your ToDo List                          "<<endl;
    cout<<"\t\t\t********************************************************************"<<endl<<endl<<endl;
    todo todo;
    cout <<"\n\tEnter new task:";
    cin.get();
    getline(cin,todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt",ios::app);
    write<<"\n"<<ID;
    write<<"\n"<<todo.task;
    write.close();

    write.open("ID.txt");
    write<<ID;
    write.close();

    char ch;
    cout<<"Do you want to add more task? y/n"<<endl;
    cin>>ch;

    if(ch == 'y'){
        addtodo();
    }
    else{
        cout<<"\n\tTask has been added successfully";
        return;

    }
}

void print(todo s) {
    cout<<"\n\tID is:"<<s.ID;
    cout<<"\n\tTask is:"<<s.task;
}

void readData(){
    system("cls");
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t               WELCOME TO Your ToDo List                          "<<endl;
    cout<<"\t\t\t********************************************************************"<<endl<<endl<<endl;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout<<"\n\t-----------------Your current Tasks in the list-------------------";

    while (!read.eof()){
        read>>todo.ID;
        read.ignore();
        getline(read,todo.task);
        print(todo);
    }
    read.close();
}

int searchData(){
    system("cls");
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t               WELCOME TO Your ToDo List                          "<<endl;
    cout<<"\t\t\t********************************************************************"<<endl<<endl<<endl;
    int ID;
    cout<<"\n\tEnter task ID:";
    cin>>ID;
    todo todo;
    ifstream read;
    read.open("todo.txt");

    while(!read.eof()) {
        read>>todo.ID;
        read.ignore();
        getline(read,todo.task);
        if(todo.ID==ID) {
            print(todo);
            return ID;
         }
     }
}

void deleteData() {
    system("cls");
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t               WELCOME TO Your ToDo List                          "<<endl;
    cout<<"\t\t\t********************************************************************"<<endl<<endl<<endl;
    int ID = searchData();
    cout<<"\n\tDo you want to delete this task(y/n):";
    char choice;
    cin>>choice;
       if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

             while (!read.eof()) {
            read >> todo.ID;
            read.ignore();
            getline(read, todo.task);
            if (todo.ID != ID) {
                tempFile << "\n" << todo.ID;
                tempFile <<"\n"<<todo.task;
            }         
}

read.close();
     tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
       }
       else {
        cout<<"\n\tRecord not deleted";
       }
} 


void updateData() {
    system("cls");
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t               WELCOME TO Your ToDo List                          "<<endl;
    cout<<"\t\t\t********************************************************************"<<endl<<endl<<endl;
       int id = searchData();
    cout << "\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

             while (!read.eof()) {
            read >> todo.ID;
            read.ignore();
            getline(read, todo.task);
            if (todo.ID != ID) {
                tempFile << "\n" << todo.ID;
                tempFile << "\n" << newData.task;
            }        
       }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfuly";
    }
    else {
        cout<<"\n\tRecord not deleted";
    }
}
int main()
{
    system("cls");
    system("Color E0");
    system("title todoapp @sumittripathi");
       cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t*                                                *"<<endl;
	cout<<"\t\t\t*                      WELCOME TO Your ToDo List                      *"<<endl;
	cout<<"\t\t\t*                                                *"<<endl;
    cout<<"\t\t\t***************************************************************************"<<endl<<endl<<endl<<endl;
       ifstream read;
    read.open("ID.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.Add student data";
        cout << "\n\t2.See student data";
        cout << "\n\t3.Search student data";
        cout << "\n\t4.Delete student data";
        cout << "\n\t5.Update student data";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}

