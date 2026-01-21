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
#include "UsersLibrary.h";

void Login_screen();
void Transactions_Screen();
using namespace std;
using namespace UsersLibrary;
const string ClientsFileName = "Clients.txt";

enum MainmenueOptions
{
    showlist = 1, Addnewclient = 2,
    DeleteCleint = 3, UpdateClient = 4,
    FindClient = 5, ManageUsers = 7 , Logout = 8
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

 
sClient stClients;

sUsers UsersGlobal;
vector <sUsers> vUsersGlobal = LoadUsersDataFromFile(UsersFileName);
string UsernameGlobal;


string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> & vClients, sClient& Client)

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
sClient ConvertLinetoRecord(string & Line, string Seperator = "#//#")

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
    MyFile.open(FileName, ios::in);  
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
vector <sClient> VClientsGlobal = LoadCleintsDataFromFile(ClientsFileName);
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
void PrintClientCard(sClient& Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
 
void LOGOUT()
{
    Login_screen();
}

// Show Clients List Code : 
void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientsData(vector <sClient>& vClients)
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
//...............


// Adding Clients Code : 
void Print_Data_ToFile(string CClients, string Filename)
{
    fstream MyFile;
    MyFile.open(Filename, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << CClients;
        MyFile << endl;
        MyFile.close();
    }
    cout << "\n\nData has been saved successfully \n\n";
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
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    return Client;
}
void adding_Client(string& account_number)
{
    sClient Clients;
    string CClients;
    int count = 1; 
    while (count >= 1)
    {
        Clients = ReadNewClient(account_number);
        CClients = ConvertRecordToLine(Clients, "#//#");
        Print_Data_ToFile(CClients, "Clients.txt");
        count++;
        if (checkagain())
        {
            cout << "\n\nEnter Account Number : ";
            cin >> account_number;
        }
        else
        {
            break;
        }
    }
     

}
void ADDING_CLIENTS(sClient &CClients, vector <sClient>& VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        cout << "Client (" << account_number << ") is already exist , Please enter another accout number....\n";
        cin >> account_number;
    }

    adding_Client(account_number);
    ReturnToMainMenu();
}
//...............



// Deleting Clients Code : 
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
void DeleteClientByAccountNumber(string AccountNumber, vector  <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
      
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
              
            SaveCleintsDataToFile(ClientsFileName, vClients);
           
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
             
        }
    }
     
  
}
void DELETING_CLIENTS(sClient &CClients, vector <sClient> &VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (!FindClientByAccountNumber(account_number, VClients, CClients))
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }
    if (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        DeleteClientByAccountNumber(account_number, VClients);
        ReturnToMainMenu();
        

    }
        
 }
//...............


// Updating Clients Code : 
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
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');




}
vector <sClient> SavechangingCleintsDataToFile(string FileName, vector <sClient>& vClients)

{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient& C : vClients)
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
void ChangingClientDataByAccountNumber(string AccountNumber, vector  <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))

    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to change this client date ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForchangeByAccountNumber(AccountNumber, vClients);

            SavechangingCleintsDataToFile(ClientsFileName, vClients);
          
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nData has been saved successfully.";

        }

    }
}
void UPDATING_CLIENT_INFO(sClient &CClients, vector <sClient> &VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    while (FindClientByAccountNumber(account_number, VClients, CClients) == false)
    {
        cout << "Client (" << account_number << ") does not exist , Please enter another account number....";
        cin >> account_number;
    }
     
    
        ChangingClientDataByAccountNumber(account_number, VClients);
        ReturnToMainMenu();
     
          
     
}
//...............





// Find Clinets Code : 
void FIND_CLIENT(sClient &CClients, vector <sClient> &VClients)
{
    system("cls");
    string account_number = ReadClientAccountNumber();
    if (FindClientByAccountNumber(account_number, VClients, CClients))
    {
        PrintClientCard(CClients);
        ReturnToMainMenu();
    }
    else
    {
        cout << "Client (" << account_number << ") does not exist\n";
        ReturnToMainMenu();
    }
    
}
//...............



/*
TRANSACTIONS CODE :  
*/
void ReturnToTransactionsMenu()
{
    cout << "\n\nPress any key to return to transactions menue...";
    _getch();
    system("cls");
 }

// Transactions (Depositing) Code : 
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
    ReturnToTransactionsMenu();


}


// Tranactions (Withdraw) Code : 
void WithDrawing(sClient &CClients, vector <sClient> &VClients, string account_number)
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
    ReturnToTransactionsMenu();

}


// Tansactions (Total balances) Code :  
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
void Counting_Total_Balances(vector <sClient> &VClients)
{
    double Total_Balances = 0;
    for (sClient &Client : VClients)
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
    ReturnToTransactionsMenu();
}


void Perform_Transactions_options(TransactionsMenue Menue)
{
     


    switch (Menue)
    {
    case 1:
    {
        Perform_Depositing(stClients, VClientsGlobal);
        break;
    }
    case 2:
    {
        Perform_Withdraw(stClients, VClientsGlobal);
        break;
    }
    case 3:
    {
        Perform_Total_Balances(stClients, VClientsGlobal);
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
    while (true)
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

    int option = ReadTransactionsmenueOptions();
    if (option == 4)
    {
        break;
    }
    Perform_Transactions_options((TransactionsMenue)option);


    }
}
//......................................................................................


// Main Menue Options Code : 
int ReadMainmenueOptions()
{
    int option;
    cout << "                                   Choose what do you want to do ? from [1] to [8]  ";
    cin >> option;
    return option;

}
int FindUserPermission(string Username, vector<sUsers> vUsers, sUsers& User)
{
    for (sUsers U : vUsers)
    {
        if (U.Username == Username)
        {
            User = U;
            return U.Permissions;
        }
    }

}
void PerformMainMenueOption(MainmenueOptions MenueOption , int UserPermissions)
{
    
    vector <sClient> VClients = LoadCleintsDataFromFile(ClientsFileName);

    switch (MenueOption)
    {
    case 1:
    {
        if ((UserPermissions&1) == 1)
        {
        system("cls");
        PrintAllClientsData(VClients);
        ReturnToMainMenu();
       
        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";
            ReturnToMainMenu();
             
        }
        break;
    }
    case 2:
    {
        if ((UserPermissions & 2) == 2)
        {
        ADDING_CLIENTS(stClients, VClients);

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";
            ReturnToMainMenu();
        }
        break;
    }
    case 3:
    {
        if ((UserPermissions & 4) == 4)
        {
        DELETING_CLIENTS(stClients, VClients);

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";

            ReturnToMainMenu();
        }
        break;
    }
    case 4:
    {
        if ((UserPermissions & 8) == 8)
        {
        UPDATING_CLIENT_INFO(stClients, VClients);

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";

            ReturnToMainMenu();
        }
        break;
    }
    case 5:
    {
        if ((UserPermissions & 16) == 16)
        {
        FIND_CLIENT(stClients, VClients);

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";

            ReturnToMainMenu();
        }
        break;
    }
    case 6:
    {
        if ((UserPermissions & 32) == 32)
        {
        Transactions_Screen();

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";

            ReturnToMainMenu();
        }
        break;
    }
    case 7:
    { 
        if ((UserPermissions & 64) == 64)
        {
        Perform_ManageUsers_Screen();

        }
        else
        {
            system("cls");

            cout << "Access Denied\n";
            cout << "You arenot allowed to do this , Please contact your Admin . \n";

            ReturnToMainMenu();
        }
        break;
    }
    
    
    }


}


void Start_screen()
{
    while (true)
    {

    
     system("cls");

     cout << "========================================================================================================================\n";
     cout << "                                                      Main menue screen                                              \n";
     cout << "========================================================================================================================\n";
     cout << "                                                     [1]Show Client List.\n";
     cout << "                                                     [2]Add New Client.\n";
     cout << "                                                     [3]Delete Client.\n";
     cout << "                                                     [4]Update Client Info.\n";
     cout << "                                                     [5]Find Client.\n";
     cout << "                                                     [6]Transactions Menue.\n";
     cout << "                                                     [7]Manage Users Screen.\n";
     cout << "                                                     [8]LogOut.\n";
     cout << "========================================================================================================================\n";

     int Option = ReadMainmenueOptions();

     if (Option == 8)
        break; 
          PerformMainMenueOption((MainmenueOptions)Option, FindUserPermission(UsernameGlobal, vUsersGlobal, UsersGlobal));
    }
 
}

void Login_screen()
{
    bool LoginFaild = false;
    do
    {
    system("cls");

    
    cout << "========================================================================================================================\n";
    cout << "                                                      Login  screen                                              \n";
    cout << "========================================================================================================================\n";
    if (LoginFaild)
    {
        cout << "Invlaid Username/Password!\n"; 
    }
    LoginFaild =  !Find_User_To_Login(vUsersGlobal, UsersGlobal , UsernameGlobal);
   
     
    } while (LoginFaild);
    Start_screen();
   

}



int main()
{
   
        while(true)    
        {
            Login_screen(); 
           
        }
        return 0;
    
}