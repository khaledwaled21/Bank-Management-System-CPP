#pragma once
#pragma warning(disable : 4996)
#include <cctype>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <limits>
#include <conio.h>
#include <windows.h>
using namespace std;
void Start_screen();

namespace UsersLibrary
{
    void Perform_ManageUsers_Screen();


    const string UsersFileName = "Users.txt";

    enum ManageUsers
    {
        ListUsers = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4
        , Find_User = 5, MainMenue = 6
    };

    struct sUsers
    {
        string Username;
        int Password = 0;
        int Permissions = 0;
        bool MarkForDelete = false;
        bool MarkForUpdate = false;
    };

    void ReturnToManageUsersMenue()
    {
        cout << "\n\nPress any key to return to Manage Users menue...";
        _getch();
         
        
    }

    vector<string> SplitString_ForUsers(string S1, string Delim)
    {
        vector<string> vString;
        short pos = 0;
        string sWord;
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }
        if (S1 != "")
        {
            vString.push_back(S1);
        }
        return vString;
    }
    sUsers ConvertLinetoRecord_ForUsers(string Line, string Seperator = "#//#")

    {
        sUsers User;
        vector<string> vUsersData;
        vUsersData = SplitString_ForUsers(Line, Seperator);
        User.Username = vUsersData[0];
        User.Password = stoi(vUsersData[1]);
        User.Permissions = stoi(vUsersData[2]);
        return User;
    }
    vector <sUsers> LoadUsersDataFromFile(string FileName)
    {
        vector <sUsers> vUsers;
        fstream MyFile;
        MyFile.open(FileName, ios::in); 
        if (MyFile.is_open())
        {
            string Line;
            sUsers User;
            while (getline(MyFile, Line))
            {
                User = ConvertLinetoRecord_ForUsers(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }
    bool FindUser_WithUsername(string Username, const vector<sUsers> & vUsers, sUsers& User)
    {
        for (sUsers U : vUsers)
        {
            if (U.Username == Username)
            {
                User = U;
                return true;
            }
        }
        return false;
    }
    bool FindUser_WithPasswordAndUsername(string Username,const vector<sUsers> &vUsers, sUsers User, int password)
    {
        for (sUsers U : vUsers)
        {
            if (U.Username == Username && U.Password == password)
            {
                User = U;
                return true;
            }
        }
        return false;
    }
    sUsers ReadNewUser(string& Username , int count)
    {
        cout << "User data : \n";
        sUsers User;

       
        User.Username = Username;

         
        

        cout << "Enter Password ";
        cin >> User.Password;

        char check;

        cout << "Do you want to give full access ? [y] or [n] ";
        cin >> check;
        if (check == 'y' || check == 'Y')
        {
            User.Permissions = -1;

        }
        else
        {
            cout << "Do you want to give access to : \n\n";
            cout << "Show Clients list ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = 1;
            }
            cout << "Add New Client ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 2);
            }
            cout << "Delete Clients ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 4);
            }
            cout << "Update Clients ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 8);
            }
            cout << "Find Client ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 16);
            }
            cout << "Transactions ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 32);
            }
            cout << "Manage Users ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 64);
            }




        }
        return User;
    }
    string ConvertRecordToLine_forUsers(sUsers User, string Seperator = "#//#")

    {
        string stUserRecord = "";
        stUserRecord += User.Username + Seperator;
        stUserRecord += to_string(User.Password) + Seperator;
        stUserRecord += to_string(User.Permissions);

        return stUserRecord;
    }
    void PrintUserCard(sUsers &User)
    {
        cout << "\nThe following are the User details:\n";
        cout << "\nUsername    : " << User.Username;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;

    }
    vector <sUsers> SaveUsersDataToFile(string FileName, vector <sUsers>& vUsers)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        string DataLine;
        if (MyFile.is_open())
        {
            for (sUsers C : vUsers)
            {
                if (C.MarkForDelete == false)
                {


                    DataLine = ConvertRecordToLine_forUsers(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
        return vUsers;
    }


 
    void Read_User(string& username, int& password)
    {
         
        cout << "Enter Username : ";
        cin >> username;

    
        cout << "Enter Password : ";
            cin >> password;

        
      
    }


    

// Print Users List Code : 
    void PrintUserRecord(sUsers &User)
    {
        cout << "| " << setw(15) << left << User.Username;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(40) << left << User.Permissions;

    }
    void PrintAllUsersData(vector <sUsers> & vUsers)
    {
        cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") Users(s).";

        cout <<
            "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(40) << "Permissions";

        cout <<
            "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        for (sUsers User : vUsers)
        {
            PrintUserRecord(User);
            cout << endl;
        }
        cout <<
            "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }







// Deleting Users Code : 
    void MarkUserForDelete(string Username, vector <sUsers>& vClients)
    {
        for (sUsers& C : vClients)
        {
            if (C.Username == Username)
            {
                C.MarkForDelete = true;

            }
        }

    }
    void DeleteUsers(string& Username, vector  <sUsers>& vUsers)
    {
        sUsers User;
        char Answer = 'n';
        if (FindUser_WithUsername(Username, vUsers, User))
        {
            PrintUserCard(User);
            cout << "\n\nAre you sure you want delete this User? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                MarkUserForDelete(Username, vUsers);

                SaveUsersDataToFile(UsersFileName, vUsers);
                vUsers = LoadUsersDataFromFile(UsersFileName);
                cout << "\n\nUser Deleted Successfully.";

            }
        }
    }
    void DELETING_USERS(sUsers Users, vector <sUsers> vUsers)
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "                                               Deleting Users Screen                                         \n";
        cout << "========================================================================================================================\n";
        cout << "Enter Username ";
        string username;
        cin >> username;
        if (username == "Admin")
        {
            cout << "Admin cannot be deleted ! ";
            ReturnToManageUsersMenue();
            return;
        }



        while (!FindUser_WithUsername(username, vUsers, Users))
        {
            cout << "User (" << username << ") does not exist , Please enter another Username.....\n";
            cout << "Enter Username ";
            string username;
            cin >> username;
            cout << "\n";
        }
        DeleteUsers(username, vUsers);
        ReturnToManageUsersMenue();

    }




// Adding Users Code : 
    bool checkagain_ForUsers()
    {
        char check;
        cout << "Do you want to add more Users ? \n";
        cin >> check;
        if (check == 'y' || check == 'Y')
        {

            return true;
        }
        return false;
    }
    void Save_NewUser_date(string UUSer, string Filename)
    {
        fstream MyFile;
        MyFile.open(Filename, ios::out | ios::app); 
        if (MyFile.is_open())
        {
            MyFile << UUSer;
            MyFile << endl;
            MyFile.close();
        }
        cout << "\n\ndata has been saved successfully \n\n";
    }
    void Perform_Adding_Users(string& Username , vector <sUsers> vUsers)
    {
        sUsers User;
        string UUsers;

        int count = 1;
        while ( count >=  1 )
        {


            User = ReadNewUser(Username, count);
            UUsers = ConvertRecordToLine_forUsers(User, "#//#");
            Save_NewUser_date(UUsers, UsersFileName);
            count++;
            if (checkagain_ForUsers())
            {
                cout << "\n\nEnter Username : ";
                cin >> Username;
                while (FindUser_WithUsername(Username, vUsers, User))
                {
                    cout << "User (" << Username << ") is already exist , Please Enter another Username.....\n";
                    cin >> Username;
                 }

            }
            else
            {
                break;
            }
        }

    }
    void ADDING_USERS(sUsers Users, vector <sUsers> vUsers)
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "                                               Adding Users Screen                                         \n";
        cout << "========================================================================================================================\n";
        cout << "Enter Username : ";
        string username;
        cin >> username;

        while (FindUser_WithUsername(username, vUsers, Users))
        {
            cout << "User (" << username << ") is already exist , Please enter another Username.....\n";
            cout << "Enter Username : ";
            string username;
            cin >> username;
            cout << "\n";
        }
        Perform_Adding_Users(username ,  vUsers);
        ReturnToManageUsersMenue();
    }


// Updating Users Code : 
    void Change_User_data(sUsers& User)
    {
        cout << "User data : \n";
        cout << "Enter Password ? ";
        cin >> User.Password;
        char check;

        cout << "Do you want to give full access ? [y] or [n] ";
        cin >> check;
        if (check == 'y' || check == 'Y')
        {
            User.Permissions = -1;

        }
        else
        {
            cout << "Do you want to give access to : \n\n";
            cout << "Show Clients list ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = 1;
            }
            cout << "Add New Client ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 2);
            }
            cout << "Delete Clients ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 4);
            }
            cout << "Update Clients ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 8);
            }
            cout << "Find Client ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 16);
            }
            cout << "Transactions ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 32);
            }
            cout << "Manage Users ? [y] or [n] ";
            cin >> check;
            if (check == 'y' || check == 'Y')
            {
                User.Permissions = (User.Permissions | 64);
            }




        }
        




    }
    vector <sUsers> Save_changesOf_User(string FileName, vector <sUsers> vUsers)

    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        string DataLine;
        if (MyFile.is_open())
        {
            for (sUsers C : vUsers)
            {
                if (C.MarkForUpdate == true)
                {
                    Change_User_data(C);

                }
                DataLine = ConvertRecordToLine_forUsers(C);
                MyFile << DataLine << endl;
            }
            MyFile.close();
        }
        return vUsers;
    }
    void Mark_User_ForUpdate(string Username, vector <sUsers>& vUsers)
    {
        for (sUsers& C : vUsers)
        {
            if (C.Username == Username)
            {
                C.MarkForUpdate = true;

            }
        }

    }
    void Updating_User_Data(string Username, vector  <sUsers>& vUsers)
    {
        sUsers User;
        char Answer = 'n';
        if (FindUser_WithUsername(Username, vUsers, User))
        {
            PrintUserCard(User);
            cout << "\n\nAre you sure you want to update this User? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Mark_User_ForUpdate(Username, vUsers);
                Save_changesOf_User(UsersFileName, vUsers);
                vUsers = LoadUsersDataFromFile(UsersFileName);
                cout << "\n\nChanges saved Successfully.";

            }
        }
    }
    void UPDATING_USER_INFO(sUsers Users, vector <sUsers> vUsers)
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "                                               Updating Users Screen                                         \n";
        cout << "========================================================================================================================\n";
        cout << "Enter Username : ";
        string username;
        cin >> username;
 


        while (!FindUser_WithUsername(username, vUsers, Users ))
        {
            cout << "User (" << username << ") does not exist , Please enter another Username.....\n";
            cin >> username;
            cout << "\n";
        }
        Updating_User_Data(username, vUsers);
        ReturnToManageUsersMenue();

    }




    void FIND_USERS(sUsers User, vector <sUsers> vUsers)
    {
        system("cls");
        cout << "Enter Username ";
        string Username;
        cin >> Username;
        if (FindUser_WithUsername(Username, vUsers, User))
        {
            PrintUserCard(User);
            ReturnToManageUsersMenue();
        }
        else
        {
            cout << "User (" << Username << ") does not exist ! ";
            ReturnToManageUsersMenue();

        }
    }


    void returnToMainMenu()
    {
        cout << "\n\nPress any key to return to main menue...";
        _getch();
        system("cls");
        Start_screen();
    }
    int ManageUsersOptioin()
    {
        int option;
        cout << "\t\t\t\t  Choose what do you want to do ? from [1] to [6]  ";
        cin >> option;
        return option;

    }
    void Perform_Managing_Options(ManageUsers option)
    {
        sUsers users;
        vector <sUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

        switch (option)
        {
        case 1:
        {
            system("cls");
            PrintAllUsersData(vUsers);
            ReturnToManageUsersMenue();
            break;
        }
        case 2:
        {
            ADDING_USERS(users, vUsers);
            break;
        }
        case 3:
        {
            DELETING_USERS(users, vUsers);
            break;
        }
        case 4:
        {
            UPDATING_USER_INFO(users, vUsers);
            break;
        }
        case 5:
        {
            FIND_USERS(users, vUsers);
            break;
        }
         
        }
    }
    bool Find_User_To_Login(vector <sUsers>& vUsers, sUsers &User , string &Username)
    {

         
        int password;
        Read_User(Username, password);


        if (FindUser_WithPasswordAndUsername(Username, vUsers, User, password))
        {
            return true;

        }
        else
            return false;



    }
    void Perform_ManageUsers_Screen()
    {
        while (true)
        {

            system("cls");
            cout << "========================================================================================================================\n";
            cout << "                                                Manage Users Menue Screen                                         \n";
            cout << "========================================================================================================================\n";
            cout << "                                                [1] Show Users List.\n";
            cout << "                                                [2] Add New User.\n";
            cout << "                                                [3] Delete User.\n";
            cout << "                                                [4] Update User.\n";
            cout << "                                                [5] Find User.\n";
            cout << "                                                [6] Main Menue.\n";
            cout << "========================================================================================================================\n";

            int option = ManageUsersOptioin();

            if (option == 6) 
                return;
            Perform_Managing_Options(ManageUsers(ManageUsersOptioin()));
        }    
    
    }


}


