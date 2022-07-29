// LoginAndRegistration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
using std::cerr;

bool isLoggedIn()
{
    string username, password, un, pw;

    // un - line 1
    // pw - line 2

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    ifstream read;
    read.open("source.txt");

    getline(read, un);
    getline(read, pw);
    
    cout << un << endl;
    cout << pw << endl;

    if (un == username && pw == password)
    {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int choice;

    ofstream file;

    //if (!file)
    //{
    //    cerr << "Error: file could not be opened" << endl;
    //    exit(1);
    //}

    cout << "1:Register \n 2:Login \n Your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        file.open("source.txt");

        string un, pw;

        cout << "Select a username: ";
        cin >> un;

        cout << "Select a password: ";
        cin >> pw;

        file << un << endl << pw << endl;
        main();
    }
    else if(choice == 2) {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "Invalid username or password:" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successfully Logged in" << endl;
            system("PAUSE");
            return 1;
        }
    }

    file.close();
}
