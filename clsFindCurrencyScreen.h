#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;


class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency& Currency)
	{
		cout << "\nCurrency Card : ";
		cout << "\n___________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n___________________\n";
	}


public:


	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		string code;
		string Country;
		short Option;
		cout << "Find by : [1] Code , [2] Country ? ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 2, "\nNumber is not within range [1,2], Enter again:");
		if (Option == 1)
		{
			cout << "\nPlease Enter Currency Code : ";
			code = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist_Code(code))
			{
				cout << "\nCurrency Code was not found , Please choose another one : ";
				code = clsInputValidate::ReadString();
			}

			clsCurrency Currency1 = clsCurrency::FindByCode(code);
			if (!Currency1.IsEmpty())
			{
				cout << "\nCurrency is not exist :)\n";

			}
			else 
			{
				cout << "\nCurrency is exist :)\n";
			}

			_PrintCurrencyCard(Currency1);

		}
		else
		{
			cout << "\nPlease Enter Country Name : ";
			Country = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist_CountryName(Country))
			{
				cout << "\nCountry Name was not found , Please choose another one : ";
				code = clsInputValidate::ReadString();
			}

			clsCurrency Currency1 = clsCurrency::FindByCountry(Country);
			if (!Currency1.IsEmpty())
			{
				cout << "\nCurrency is not exist :)\n";

			}
			else
			{
				cout << "\nCurrency is exist :)\n";
			}

			_PrintCurrencyCard(Currency1);

		}




	}


};

