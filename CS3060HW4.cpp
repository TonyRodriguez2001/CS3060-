/*
 Name: Tony Rodriguez
 Instructor: Dr. Lewis
 Class: CS3060
 Date: 9/19/2022
 
 Synopsis:
    This program utilizes a menu-driven user interface to allong with
 an array of 10 account structures to allow the user to fill in
 the data for these structures. The program also allwso the user to make
 any specific changes to the data of any speciic account structure. The
 program also allows the user to kill the program and print the data
 for all account structures in the array.
 */

#include <iostream>
#include <iomanip>
#include <string>

#define NUM_ACCOUNTS 10

using namespace std;

struct account{
    
    //data fields
    string name;
    string address;
    string cityStateZip;
    string phoneNumber;
    double accBalance;
    string lastPayment;
    
    
    //prompts for and gets the name field from the user
    void getName(int accNum){
        cout << "\nPlease enter the name for account: " << accNum << endl;
        getline(cin, this->name);
    }
    
    //prompts for and gets the address data field from the user
    void getAddress(int accNum){
        cout << "Please enter the address for account: " << accNum << endl;
        getline(cin, this->address);
    }
    
    //prompts for and gets the CityStateZip data field from the user
    void getCityStateZip(int accNum){
        cout << "Please enter the City, State, and Zip for account: " << accNum << endl;
        getline(cin, this->cityStateZip);
    }
    
    //prompts for and gets the phone number data field from the user
    void getPhoneNum(int accNum){
        cout << "Please enter the phone number for account: " << accNum << endl;
        getline(cin, this->phoneNumber);
    }
    
    //prompts for and gets the account balance data field from the user
    void getAccBalance(int accNum){
        cout << "Please enter the balance for account: " << accNum << endl;
        cin  >> this->accBalance;
        cin.ignore();
        
        //Checking for invalid input
        while(this->accBalance < 0){
            cout << "No negative balances are accepted!\nPlease re-enter the balance for account:" << accNum << endl;
            cin  >> this->accBalance;
        }
    }
    void getLastPayment(int accNum){
        cout << "Please enter the last payment date for account:" << accNum << endl;
        getline(cin, this->lastPayment);
    }
};


//function prototypes
bool displayMenu(account arr[]);
void enterData(account arr[]);
void changeData(account acc[]);
void displayAccounts(account arr[]);
void searchName(account arr[]);

int main(int argc, const char * argv[]){

    account accArray[NUM_ACCOUNTS];
    
    bool quit = displayMenu(accArray);
    
    while(!quit){
        quit = displayMenu(accArray);
    }
    
    return 0;

}

//displays menu and allows the user to choose what they would like to do
bool displayMenu(account arr[]){
    
    int choice;
    bool quit = false;
    
    cout << "Customer Accounts Program.\nPlease select an option from the menu." << endl;
    cout << "\tOption 1) Enter data for accounts\n\tOption 2) Change data for a particular account\n" << "\tOption 3) Search and display accounts by part of their name\n" <<"\tOption 4) End program and display all of the accounts and their data" << endl;
    
    cin >> choice;
    
    //Clearing input buffer
    cin.ignore();
    
    while(choice < 1 || choice > 4){
        cout << "Invalid choice! Re-enter choice." << endl;
        cin >> choice;
        cin.ignore();
    }
    
    switch(choice){
        case 1:
            enterData(arr);
            break;
        case 2:
            changeData(arr);
            break;
        case 3:
            searchName(arr);
            break;
        case 4:
            displayAccounts(arr);
            quit = true;
            break;
    }
    
    return quit;
    
}

/*
 Allows the user to fill in the data for all accounts
*/
void enterData(account arr[]){
    
    for(int i = 0; i < NUM_ACCOUNTS; i++){
        cout << "-------------------------------" << endl;
        arr[i].getName(i+1);
        arr[i].getAddress(i+1);
        arr[i].getCityStateZip(i+1);
        arr[i].getPhoneNum(i+1);
        arr[i].getAccBalance(i+1);
        arr[i].getLastPayment(i+1);
    }
}

/*
 Allows the user to choose a specific account to edit
 as well as the specific data field within the selected
 account to alter.
*/
void changeData(account acc[]){
    
    int choice1, choice2;
    
    cout << "What account would you like to make changes to? (1 - 10)" << endl;
    cin >> choice1;
    cin.ignore();
    
    //verifying user input
    while(choice1 < 1 || choice1 > NUM_ACCOUNTS){
        cout << "Invalid choice! Re-enter choice." << endl;
        cin >> choice1;
        cin.ignore();
    }
    
    //Verifying that the account to be edited already exists
    //to prevent partially filled in structures
    if(acc[choice1 - 1].name.size() == 0){
        cout << "Account " << choice1 << " Does not exist yet!\n" <<
        "Please enter the data for all accounts first!" << endl;
        return;
    }
    
    //displaying menu and obtaining users request
    cout << "What change would you like to make to account:" << choice1 << endl;
    cout << "1)\tEdit name\n2)\tEdit address\n3)\tEdit city, state, and zip\n" <<
    "4)\tEdit phone number\n5)\tEdit last payment" << "6)\tEdit account balance." << "\n\nChoose 1, 2, 3, 4, 5, or 6" << endl;
    
    cin >> choice2;
    cin.ignore();
    
    //validating input
    while(choice2 < 1 || choice2 > 6){
        cout << "Invalid choice! Re-enter choice." << endl;
        cin >> choice2;
        cin.ignore();
    }
    
    
    //performing the requested change
    switch(choice2){
        case 1:
            acc[choice1 - 1].getName(choice1);
            break;
        case 2: acc[choice1 - 1].getAddress(choice1);
            break;
        case 3:
            acc[choice1 - 1].getCityStateZip(choice1);
            break;
        case 4:
            acc[choice1 - 1].getPhoneNum(choice1);
            break;
        case 5:
            acc[choice1 - 1].getLastPayment(choice1);
            break;
        case 6:
            acc[choice1 - 1].getAccBalance(choice1);
            break;
    }//switch(choice2)
    
}

/*
 Itterates through the array of account structures
 and displays each account's information
*/
void displayAccounts(account arr[]){
    
    cout << "\nINFORMATION FOR ALL ACCOUTS\n" << "-------------------------------" << endl;
    
    //itterating through the array of structures and displaying their data fields
    for(int i = 0; i < NUM_ACCOUNTS; i++){
        cout << "Account " << i + 1 << " details:" << "\n********************" << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Address: " << arr[i].address << endl;
        cout << "City, State, Zip: " << arr[i].cityStateZip << endl;
        cout << "Phone Number: " << arr[i].phoneNumber << endl;
        cout << "Last payment: " << arr[i].lastPayment << endl;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << "Account Balance: $" << arr[i].accBalance <<"\n"<< endl;
    }
    
}


/*
 Searches the array of structures for any and all structures whose
name field contains the substring provided by the user and prints
that account structure's details
*/
void searchName(account arr[]){
    
    string substring;
    int count = 0;
    
    cout << "Please enter the substring that you would like to search by:\n" << endl;
    getline(cin, substring);
    
    //Itterating through the array of structures
    for(int i = 0; i < NUM_ACCOUNTS; i++){
        
        //Checking if structure i's name field contains the substring
        if(arr[i].name.find(substring) != string::npos){
            
            //will only execute when the first match is found
            if(count == 0){
                cout << "There were matches using \"" << substring << "\" as the search substring.\n" << endl;
            }
            
            //Displaying the fields of the account structure
            cout << "Account " << i + 1 << " details:" << "\n********************" << endl;
            cout << "Name: " << arr[i].name << endl;
            cout << "Address: " << arr[i].address << endl;
            cout << "City, State, and Zip: " << arr[i].cityStateZip << endl;
            cout << "Phone number: " << arr[i].phoneNumber << endl;
            cout << "Last payment: " << arr[i].lastPayment << endl;
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Account Balance: $" << arr[i].accBalance <<"\n"<< endl;
            count++;
        }
        
    }
    
    //Will execute if no matching structures are found
    if(count == 0){
        cout << "There were no accounts that contained \"" << substring << "\" in their name." << endl;
    }
    
    
}


