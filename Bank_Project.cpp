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

void Start_screen();
void Transactions_Screen();
using namespace std;
const string ClientsFileName = "Clients.txt";

enum MainmenueOptions
{
    showlist = 1, Addnewclient = 2,
    DeleteCleint = 3, UpdateClient = 4,
    FindClient = 5, Exit = 7
    , Transictions = 6
};

enum TransactionsMenue
{
    Deposite = 1, withdraw = 2
    , Total_balances = 3, Main_menue = 4
};

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0.0;
    bool MarkforDelete = false;
    bool Markforchange = false;
};

 
// Other codes of the bank proejct.
 
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)

{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")

{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}


string ConvertRecordToLine(sClient Client, string Seperator = "#//#")

{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}


bool MarkClientForchangeByAccountNumber(string AccountNumber, vector <sClient>& vClients)

{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.Markforchange = true;
            return true;
        }
    }
    return false;
}
 
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)

{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkforDelete = true;
            return true;
        }
    }
    return false;
}


vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)

{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkforDelete == false)
            {


                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

void Change_Client_data(sClient& Client)
{
    cout << "Clients data : \n";

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');




}

vector <sClient> SavechangingCleintsDataToFile(string FileName, vector <sClient> vClients)

{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.Markforchange == true)
            {
                Change_Client_data(C);

            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vClients;
}



void DeleteClientByAccountNumber(string AccountNumber, vector  <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
      
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
              
            SaveCleintsDataToFile(ClientsFileName, vClients);
            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
             
        }
    }
     
  
}


string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

sClient ReadNewClient(string &account_number)
{
    cout << "Client data : \n";
    sClient Client;

    Client.AccountNumber = account_number;

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return Client;
}

void PrintAllClientsData(vector <sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";

    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

bool checkagain()
{
    char check;
    cout << "Do you want to add more clients ? \n";
    cin >> check;
    if (check == 'y' || check == 'Y')
    {
        return true;
    }
    return false;
}


void PRint_file(string CClients, string Filename)
{
    fstream MyFile;
    MyFile.open(Filename, ios::out | ios::app);//append Mode
    if (MyFile.is_open())
    {
        MyFile << CClients;
        MyFile << endl;
        MyFile.close();
    }
    cout << "\n\ndata has been saved successfully \n\n";
}

void adding_Client(string& account_number)
{
    sClient Clients;
    string CClients;
 

    do
    {


        Clients = ReadNewClient(account_number);
        CClients = ConvertRecordToLine(Clients, "#//#");
        PRint_file(CClients, "Clients.txt");
    } while (checkagain());


}

   
void ChangingClientDataByAccountNumber(string AccountNumber, vector  <sClient>& vClients)

{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))

    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want change the data of this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForchangeByAccountNumber(AccountNumber, vClients);

            SavechangingCleintsDataToFile(ClientsFileName, vClients);
            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nData has been saved successfully.";

        }

    }
}





void returnToMainMenu() 
{
    cout << "\n\nPress any key to return to the main menue...";
    _getch();       
    system("cls");  
    Start_screen();
}

void ExitMenu()
{
    
    system("cls");
    cout << "Program ends , thanks for using our service \n";
}

int ReadMainmenueOptions()
{
    int option;
    cout << "                                   Choose what do you want to do ? from [1] to [7]  ";
    cin >> option;
    return option;

}

void ADDING_CLIENTS(sClient CClients, vector <sClient> VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        cout << "Client (" << account_number << ") is already exist , Please enter another accout number....\n";
        cin >> account_number;
    }

    adding_Client(account_number);
    returnToMainMenu();
}

void DELETING_CLIENTS(sClient CClients, vector <sClient> VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients) == false)
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }
    if (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        DeleteClientByAccountNumber(account_number, VClients);
        returnToMainMenu();
        

    }
        
 }

void UPDATING_CLIENT_INFO(sClient CClients, vector <sClient> VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients) == false)
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }
    if (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        ChangingClientDataByAccountNumber(account_number, VClients);
        returnToMainMenu();
     }
          
     
}

void FIND_CLIENT(sClient CClients, vector <sClient> VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    if (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        PrintClientCard(CClients);
        returnToMainMenu();
    }
    else
    {
        cout << "Client (" << account_number << ") does not exist\n";
        returnToMainMenu();
    }
    
}




void PrintClientRecord_BankExtension(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void Print_allCleintsData_BankExtension(vector <sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";

    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClient Client : vClients)
    {
        PrintClientRecord_BankExtension(Client);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "__________________________________________\n" << endl;
}

void returnToTransactionsMenu()
{
    cout << "\n\nPress any key to return to the main menue...";
    _getch();
    system("cls");
    Transactions_Screen();
}

void Depositing(vector <sClient>& VClients, string account_number)
{
    double Deposite_ammount;
    cout << "\n\nEnter deposite ammount : ";
    cin >> Deposite_ammount;

    char check;
    cout << "\nAre you sure you want to perform this action ? [y] or [n] ? ";
    cin >> check;
    if (check == 'Y' || check == 'y')
    {
        for (sClient& C : VClients)
        {
            if (C.AccountNumber == account_number)
            {
                C.AccountBalance += Deposite_ammount;
                break;
            }
        }

        SaveCleintsDataToFile(ClientsFileName, VClients);
        VClients = LoadCleintsDataFromFile(ClientsFileName);

    }
    cout << "\nAction completed \n";
}

void Perform_Depositing(sClient& CClients, vector <sClient>& VClients)
{
    system("cls");

    cout << "=============================================================================================================\n";
    cout << "                                              Deposite screen                                             \n";
    cout << "=============================================================================================================\n";


    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients) == false)
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }


    PrintClientCard(CClients);
    Depositing(VClients, account_number);
    returnToTransactionsMenu();


}



void WithDrawing(sClient CClients, vector <sClient> VClients, string account_number)
{
    double withdraw_ammount;
    cout << "\n\nEnter withdraw ammount : ";
    cin >> withdraw_ammount;

    while (withdraw_ammount > CClients.AccountBalance)
    {
        cout << "Amount exceeds the balance , you can withdraw up to " << CClients.AccountBalance << endl;

        cout << "\n\nEnter deposite ammount : ";
        cin >> withdraw_ammount;

    }


    char check;
    cout << "\nAre you sure you want to perform this action ? [y] or [n] ? ";
    cin >> check;
    if (check == 'Y' || check == 'y')
    {
        for (sClient& C : VClients)
        {
            if (C.AccountNumber == account_number)
            {
                C.AccountBalance -= withdraw_ammount;
                break;
            }
        }

        SaveCleintsDataToFile(ClientsFileName, VClients);
        VClients = LoadCleintsDataFromFile(ClientsFileName);

    }
    cout << "\nAction completed \n";
}

void Perform_Withdraw(sClient& CClients, vector <sClient>& VClients)
{

    system("cls");

    cout << "========================================================================================================================\n";
    cout << "                                              Withdraw screen                                                \n";
    cout << "========================================================================================================================\n";

    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients) == false)
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }


    PrintClientCard(CClients);
    WithDrawing(CClients, VClients, account_number);
    returnToTransactionsMenu();

}


void Counting_Total_Balances(vector <sClient> VClients)
{
    double Total_Balances = 0;
    for (sClient Client : VClients)
    {
        Total_Balances += Client.AccountBalance;
    }

    cout << "                                    Total balances = " << Total_Balances;
}

void Perform_Total_Balances(sClient& CClients, vector <sClient>& VCleints)
{
    system("cls");

    cout << "========================================================================================================================\n";
    cout << "                                              Total balances screen                                                \n";
    cout << "========================================================================================================================\n";

    Print_allCleintsData_BankExtension(VCleints);
    Counting_Total_Balances(VCleints);
    returnToTransactionsMenu();
}


void Perform_Transactions_options(TransactionsMenue Menue)
{
    sClient CClients;
    vector <sClient> VClients = LoadCleintsDataFromFile("Clients.txt");


    switch (Menue)
    {
    case 1:
    {
        Perform_Depositing(CClients, VClients);
        break;
    }
    case 2:
    {
        Perform_Withdraw(CClients, VClients);
        break;
    }
    case 3:
    {
        Perform_Total_Balances(CClients, VClients);
        break;
    }
    case 4:
    {
        Start_screen();
        break;
    }

    }
}

int ReadTransactionsmenueOptions()
{
    int option;
    cout << "                                   Choose what do you want to do ? from [1] to [4]  ";
    cin >> option;
    return option;

}

void Transactions_Screen()
{
    system("cls");
    cout << "========================================================================================================================\n";
    cout << "                                              Transactions menue screen                                      \n";
    cout << "========================================================================================================================\n";
    cout << "                                             [1]Deposite.\n";
    cout << "                                             [2]Withdraw.\n";
    cout << "                                             [3]Total balances.\n";
    cout << "                                             [4]Main menue.\n";
    cout << "========================================================================================================================\n";
    Perform_Transactions_options((TransactionsMenue)ReadTransactionsmenueOptions());

}












void PerformMainMenueOption(MainmenueOptions MenueOption)
{
    sClient CClients;
    vector <sClient> VClients = LoadCleintsDataFromFile("Clients.txt");

    switch (MenueOption)
    {
    case 1:
    {
        system("cls");
        PrintAllClientsData(VClients);
        returnToMainMenu();
        break;
    }
    case 2:
    {
        ADDING_CLIENTS(CClients, VClients);
        break;
    }
    case 3:
    {
        DELETING_CLIENTS(CClients, VClients);
        break;
    }
    case 4:
    {
        UPDATING_CLIENT_INFO(CClients, VClients);
        break;
    }
    case 5:
    {
        FIND_CLIENT(CClients, VClients);
        break;
    }
    case 6:
    {
        Transactions_Screen();
        break;
    }
    case 7:
    {
        ExitMenu();
        break;
    }
    
    }


}


void Start_screen()
{
    system("cls");

    cout << "========================================================================================================================\n";
    cout << "                                                      Main menue screen                                              \n";
    cout << "========================================================================================================================\n";
    cout << "                                                     [1]Show client list.\n";
    cout << "                                                     [2]Add new client.\n";
    cout << "                                                     [3]Delete client.\n";
    cout << "                                                     [4]Update client info.\n";
    cout << "                                                     [5]Find client.\n";
    cout << "                                                     [6]Transactions menue\n";
    cout << "                                                     [7]Exit.\n";
    cout << "========================================================================================================================\n";
          PerformMainMenueOption((MainmenueOptions)ReadMainmenueOptions());
 
}





int main()
{
    Start_screen();
}