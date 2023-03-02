#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsloggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;
    ifstream read("d:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int choice;
    cout << "1: Register\n2: Login\nChoose one option: "; cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "Select username: "; cin >> username;
        cout << "Select password: "; cin >> password;
        ofstream file;
        file.open("d:\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = IsloggedIn();
        if (status == false)
        {
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}