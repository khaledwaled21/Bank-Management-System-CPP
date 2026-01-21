Bank Management System (C++)
A specialized financial tool developed in C++ designed for secure client management, real-time transaction tracking, and advanced user administration through an intuitive console interface.

🚀 Key Features
* User Authentication: Secure login system to verify identities before accessing the system.
* Permissions Management: Granular control over user actions, allowing specific access to different modules (Admin/User).
* Client Management: Executes complete CRUD operations (Add, Delete, Update, and Find) for bank clients.
* Transactions Module: Handles deposits and withdrawals with real-time balance validation.
* User Administration: A dedicated module for administrators to Add, Delete, Update, and Find system users.
* Data Persistence: Navigates data seamlessly by loading and saving to flat-file databases (Clients.txt and Users.txt).


🛠️ Built With : 
* Language: C++

* Modular Design: Uses custom header files (UsersLibrary.h) and Namespaces for better code organization.
* Libraries: Standard Template Library (STL) - Vectors, Strings, Algorithms.
* Storage: File Streaming (fstream) for persistent data storage.

📖 How to Use : 
* Clone the repository:
git clone https://github.com/khaledwaled21/Bank-Management-System-CPP.git
* Compile the source code: Compile the Bank_Project.cpp file using any C++ compiler (G++, MSVC). Ensure UsersLibrary.h is in the same directory during compilation.
* Setup Data Files: Important: Ensure both Clients.txt and Users.txt files are in the same directory as the executable file before running to allow the program to load/save data.
* Run the application: Log in with your credentials to start managing clients and system users.

📈 Future Improvements
[ ] Transform the remaining procedural logic into Object-Oriented Programming (OOP)
[ ] Implement a Transaction History log file to track all financial activities.
[ ] Enhance input validation to handle non-numeric data and prevent runtime errors.
