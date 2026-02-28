#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include <conio.h>
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyScreen.h"
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8 , eCurrencyExchange = 9 ,  eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "\t\t\t            Number is not within range [1,10], Enter again:");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout <<"\nPress any key to go back to Main Menue...\n";

        _getch();
    }

    static void _ShowAllClientsScreen()
    {
         clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
         clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
         clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();


    }

    static void _ShowFindClientScreen()
    {
         clsFindClientScreen::ShowFindClientScreen();


    }

    static void _ShowTransactionsMenue()
    {
         clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
         clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    
    static void _CurrencyExchange()
    {
        clsCurrencyScreen::ShowCurrencyExchangeMenue();
    }

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");
        
    }


    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
        {

            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eDeleteClient:
        {

            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eUpdateClient:
        {

            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eFindClient:
        {

            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eShowTransactionsMenue:
        {

            system("cls");
            _ShowTransactionsMenue();
             break;
        }

        case enMainMenueOptions::eManageUsers:
        {

            system("cls");
            _ShowManageUsersMenue();
             break;
        }
        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eCurrencyExchange:
        {
            system("cls");
            _CurrencyExchange();
            break;
        }



        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }




public:


    static void ShowMainMenue()
    {
        while (true)
        {
            system("cls");
            _DrawScreenHeader("\t\tMain Screen");

            cout << "========================================================================================================================\n";
            cout << "                                                      Main menue screen                                              \n";
            cout << "========================================================================================================================\n";
            cout << "                                                     [1] Show Client List.\n";
            cout << "                                                     [2] Add New Client.\n";
            cout << "                                                     [3] Delete Client.\n";
            cout << "                                                     [4] Update Client Info.\n";
            cout << "                                                     [5] Find Client.\n";
            cout << "                                                     [6] Transactions Menue.\n";
            cout << "                                                     [7] Manage Users Screen.\n";
            cout << "                                                     [8] Show Login Register Screen\n";
            cout << "                                                     [9] Currency Exchange Screen\n";
            cout << "                                                     [10] LogOut.\n";
            cout << "========================================================================================================================\n";
            short Option = _ReadMainMenueOption();
            if (Option == 10)
                break;
           _PerfromMainMenueOption((enMainMenueOptions)Option);
        }
    }

};
