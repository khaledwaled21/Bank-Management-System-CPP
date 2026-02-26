#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
         
        cout << "                                        _________________________________________\n";
        
        cout << "\n                                               " << Title;
        if (SubTitle != "")
        {
            

            cout << "\n                                           " << SubTitle;
        }
        cout << "\n                                        _________________________________________\n\n";
     
        cout << "\t\t\t\t\t              User: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\t              Date: " << clsDate::DateToString(clsDate()) << "\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }



};


 
