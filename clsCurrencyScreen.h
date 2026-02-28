#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iomanip>
#include <conio.h>
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMenue {eListCurrencies = 1 , eFindCurrencies = 2 , eUpdateRate = 3 , eCurrencyCalculator = 4 , eMainMenue = 5 };

    static short _ReadCurencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\t\t\t            Number is not within range [1,5], Enter again:");
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\nPress any key to go back to Currency Exchange Menue...\n";

        _getch();
    }

    static void _ShowAllCurrenciesList()
    {
        clsCurrenciesListScreen::ShowCurrencyList();
    }

    static void _FindCurrency()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    
    static void _UpdateCurrencyRate()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _CurrencyCalculator()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeOptions(enCurrencyExchangeMenue CurrencyExchangeOption)
    {
        switch (CurrencyExchangeOption)
        {
        case enCurrencyExchangeMenue::eListCurrencies:
        {
            system("cls");
            _ShowAllCurrenciesList();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenue::eFindCurrencies:
        {
            system("cls");
            _FindCurrency();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenue::eUpdateRate:
        {
            system("cls");
            _UpdateCurrencyRate();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenue::eCurrencyCalculator:
        {
            system("cls");
            _CurrencyCalculator();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenue::eMainMenue:
        {

        }
        }


    }


public:
    static void ShowCurrencyExchangeMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            cout << "\n\nPress any key to go back to Main Menue...";
            _getch();
            return;
        }

        while (true)
        {
            system("cls");
            _DrawScreenHeader("\tCurency Exchange Main Screen");
            cout << "========================================================================================================================\n";
            cout << "                                                    Curency Exchange Menue                                              \n";
            cout << "========================================================================================================================\n";
            cout << "                                                    [1]Show Currencies List.\n";
            cout << "                                                    [2]Find Currency.\n";
            cout << "                                                    [3]Update Currncy Rate.\n";
            cout << "                                                    [4]Currency Calculator.\n";
            cout << "                                                    [5]Main Menue.\n";
            cout << "========================================================================================================================\n";
            short Option = _ReadCurencyExchangeMenueOption();
            if (Option == 5)
                break;
            _PerformCurrencyExchangeOptions(enCurrencyExchangeMenue(Option));
        }
    }

};

