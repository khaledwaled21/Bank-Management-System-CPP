# 🏦 Bank Management System (OOP Version)

A professional financial administration tool entirely refactored from procedural C++ to a robust, modular **Object-Oriented Architecture**. The system now includes a fully functional **Currency Exchange** module and advanced search logic.

## 🚀 Key Features

* **Currency Exchange System (NEW):** * View a comprehensive list of global currencies and their current rates.
  * Find specific currencies accurately by Country Name or Currency Code.
  * Update currency exchange rates dynamically.
  * Calculate and convert amounts between any two international currencies using a built-in Currency Calculator.

* **Object-Oriented Architecture:** Entirely redesigned using core OOP principles: Inheritance, Abstraction, and Encapsulation.

* **Modular Screen System:** Every functionality (Login, Transactions, User Management, Currency Exchange) is isolated in its own dedicated class for maximum scalability.

* **User Authentication & Permissions:** Secure login system with a granular permissions bit-mask to control user access levels across banking and currency menus.

* **Comprehensive Logging:** Automated registration system for all Login activities and Transfer transactions into dedicated log files.

* **Advanced Utility Libraries:** Custom-built classes for robust input validation (`clsInputValidate`), complex date handling (`clsDate`), and advanced string manipulation (`clsString`).

## 🛠️ Built With

* **Language Standard:** C++20
* **Architecture:** Modular Object-Oriented Programming (OOP)
* **IDE:** Developed using Microsoft Visual Studio 2022

## 📖 How to Use

1. **Clone the repository:**
   `git clone https://github.com/khaledwaled21/Bank-Management-System-CPP.git`

2. **Setup Data Files:**
   **Important:** Ensure the following text files are present in the executable directory to load the system data successfully:
   * `Clients.txt`
   * `Users.txt`
   * `TransfersLog.txt`
   * `Currencies.txt`

3. **Compile and Run:**
   Open the `Bank_Project(OOP).slnx` or `.vcxproj` file in Visual Studio 2022 and run the project.

## 📈 Future Improvements

* [ ] Integrate a **Database Management System** (like SQLite) to replace flat-file storage.
* [ ] Develop a **Graphical User Interface (GUI)** using Qt or SFML.
* [ ] Implement **Advanced Encryption** algorithms for all stored data files.
