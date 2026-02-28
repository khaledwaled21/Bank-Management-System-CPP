#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen : protected clsScreen
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

	static void ShowCurrencyCalculatorScreen()
	{
		bool Again = true;
		while (Again)
		{
			system("cls");
		    _DrawScreenHeader("\tCurrency Calculator Screen");
			cout << "\nEnter Currency1 Code : ";
			string Code1 = clsString::UpperAllString(clsInputValidate::ReadString());
			while (!clsCurrency::IsCurrencyExist_Code(Code1))
			{
				cout << "\nCurrency Code was not found , Please choose another one : ";
				Code1 = clsString::UpperAllString(clsInputValidate::ReadString());
			}
			clsCurrency Currency1 = clsCurrency::FindByCode(Code1);




			cout << "\nEnter Currency2 Code : ";
			string Code2 = clsString::UpperAllString(clsInputValidate::ReadString());
			while (!clsCurrency::IsCurrencyExist_Code(Code2))
			{
				cout << "\nCurrency Code was not found , Please choose another one : ";
				Code2 = clsString::UpperAllString(clsInputValidate::ReadString());
			}
			clsCurrency Currency2 = clsCurrency::FindByCode(Code2);




			cout << "\nEnter Amount : ";
			double Amount = clsInputValidate::ReadDblNumber();




			cout << "\nConvert From:-) \n";
			_PrintCurrencyCard(Currency1);
			cout << "\nTo:-) \n";
			_PrintCurrencyCard(Currency2);





			double NewAmount;
			if (Code2 == "USD")
			{
				NewAmount = clsCurrency::ConvertToUSD(Amount , Currency1);
				cout << Amount << " " << Code1 << " = " << NewAmount << " " << Code2 << endl;
			}
			else
			{
				NewAmount = clsCurrency::ConvertToUSD(Amount, Currency1);
				NewAmount = clsCurrency::ConvertToOtherCurrencyByUSD(NewAmount, Currency2);
				cout << Amount << " " << Code1 << " = " << NewAmount << " " << Code2 << endl;
			}
			cout << "\nDo you want to do another Calculation y/n ? ";
			char Answer;
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{

			}
			else
			{
				Again = false;
			}
		}


	}


};

