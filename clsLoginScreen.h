#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "Global.h"
#include "clsMainScreen.h"


class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        short count = 1;
        bool LoginFaild = false;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " << 3 - count << " Trials\n";
                if (count == 3)
                {
                     cout << "\nYou are locked after 3 failed trials\n";
                    exit(0);
                }
                count++;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "                                                      Login  screen                                              \n";
        cout << "========================================================================================================================\n";
        _Login();

    }

};



