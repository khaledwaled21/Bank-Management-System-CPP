#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <conio.h>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5,
        eShowMainMenue = 6

    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\t\t\t            Number is not within range [1,6], Enter again:");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
         clsDepositeScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
         clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
         clsTotalBalancesScreen::ShowTotalBalances();

    }

    static void _ShowTransferScreen()
    {
         clsTransferScreen::ShowTransferScreen();


    }

    static void _ShowTransferLogScreen()
    {
         clsTransferLogScreen::ShowTransferLogScreen();

    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        
        _getch();


    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {

            

        }
        }


    }






public:


    static void ShowTransactionsMenue()
    {


        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            cout << "\n\nPress any key to go back to Main Menue...";
            _getch();
            return;

        }

        while (true)
        {

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << "========================================================================================================================\n";
        cout << "                                              Transactions menue screen                                      \n";
        cout << "========================================================================================================================\n";
        cout << "                                             [1] Deposite.\n";
        cout << "                                             [2] Withdraw.\n";
        cout << "                                             [3] Total balances.\n";
        cout << "                                             [4] Transfer Screen.\n";
        cout << "                                             [5] Transfer Log Screen\n";
        cout << "                                             [6] Main menue.\n";
        cout << "========================================================================================================================\n";
        short Option = ReadTransactionsMenueOption();
        if (Option == 6)
            break;

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)Option);
        }
    }

};


