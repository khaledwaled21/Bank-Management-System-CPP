#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateCurrencyRateScreen : public clsScreen
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

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\Update Currency Rate Screen");
		cout << "\nPlease , Enter Currency Code : ";
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist_Code(CurrencyCode))
		{
			cout << "\nCurrency Code was not found , Please choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		if (!Currency.IsEmpty())
		{
			_PrintCurrencyCard(Currency);

		}
		else
		{
			cout << "\nCurrency is not exist :)\n";
		}
		cout << "\nAre you sure you want to update this currency rate y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate : \n";
			cout << "____________________________\n";
			cout << "\nEnter New Rate : ";
			float Rate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(Rate);
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);
	
		}
		else
		{
			cout << "\nOperation is Canceled\n";
		}
		 

	}


};

