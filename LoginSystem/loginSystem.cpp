//Roan Morgan
//Design Project: Login System
//4.3.23
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;

bool isNameDup(map<string, string>, string);
bool isName(map<string, string>, string);
bool isValidLogin(map<string, string>, string, string);

int main(void) {

	char logout = 'n';
	char exit = 'n';
	map<string, string> userList;
	char userin;
	string tempUserName;
	string tempPass;
	string tempDeleteName;
	char endLoop = 'n';
	string leave = "n";

	//main loop
	while (exit == 'n') { 

		logout = 'n';


		system("CLS");

		//project description
		cout << "Design Project: Login System" << endl;
		cout << "input 'n' to navigate the menu:\n\n";

		//ask for register
		cout << "Register New User? (y/n): "; 
		cin >> userin;
		cin.ignore();

		//if yes register
		if (userin == 'y') {

			//clear the ui
			system("CLS");

			//replaced project description to new page
			cout << "Design Project: Login System" << endl;

			cout << "Registering A New Account:\n" << endl;

			//enter a unique username make sure to check for copies
			cout << "Enter your new username: ";
			getline(cin, tempUserName);

			try { //check if the name is a duplicate
				if (!isNameDup(userList, tempUserName)) {
					cout << "Enter your new password: ";
					getline(cin, tempPass);
				}

				userList[tempUserName] = tempPass;

				cout << "success!" << endl;
			}
			catch (exception(err)) {
				cout << "Error: " << err.what();
			}

			Sleep(500);

		} 
		//if no register
		else {
			//ask for login
			cout << "Login? (y/n): ";
			cin >> userin;
			cin.ignore();

			//yes login
			if (userin == 'y') { 
				//clear the ui
				system("CLS");

				//replaced project description to new page
				cout << "Design Project: Login System" << endl;

				cout << "Login to an Existing Account:\n" << endl;

				//enter a unique username make sure to check for copies
				cout << "Enter your username: ";
				getline(cin, tempUserName);

				//check the database
				
				try {
					//check to see if the inputted username exists
					if (isName(userList, tempUserName)) {
						cout << "Enter your password: ";
						getline(cin, tempPass);
					}
				}
				catch (exception(err)) {
					cout << "Error: " << err.what();
					userin = 'n';
					Sleep(500);
				}

				//check to see if username and pass lineup
				try {
					if (isValidLogin(userList, tempUserName, tempPass)) {
						cout << "Logged in successfully!!!" << endl;
						Sleep(500);
					}
				}
				catch (exception err) {
					cout << "Error: " << err.what();
				}

				while (logout != 'y' && userin != 'n') {

					system("CLS");

					//replaced project description to new page
					cout << "Design Project: Login System" << endl;

					cout << "Welcome " << tempUserName << "...\n" << endl;

					cout << "Change Password? (y/n): ";
					cin >> userin;
					cin.ignore();

					//yes change password
					if (userin == 'y') {
						//add change password functionality
						system("CLS");

						//replaced project description to new page
						cout << "Design Project: Login System" << endl;

						cout << "Change password:\n\n";

						cout << "Enter your new password: ";
						getline(cin, tempPass);

						userList[tempUserName] = tempPass;

						cout << "Password Changed Successfully!" << endl;

						Sleep(500);
					}
					//no change password
					else {
						leave = 'n';

						cout << "List users? (y/n): ";
						cin >> userin;
						cin.ignore();

						//yes list users
						if (userin == 'y') {

							//add change password functionality
							system("CLS");

							//replaced project description to new page
							cout << "Design Project: Login System" << endl;

							cout << "Complete List of Users:\n\n";
							for (auto cur = userList.begin(); cur != userList.end(); cur++) {
								cout << cur->first << endl;
							}

							while (leave != "") {
								cout << "\nenter to exit...";
								getline(cin, leave);
							}

						}
						//no list users
						else {
							cout << "Delete A User? (y/n): ";
							cin >> userin;
							cin.ignore();

							//yes delete users
							if (userin == 'y') {
								//delete a user of choice

								//add change password functionality
								system("CLS");

								//replaced project description to new page
								cout << "Design Project: Login System" << endl;

								cout << "Delete Users:\n\n";

								cout << "Username to Delete: ";
								getline(cin, tempDeleteName);

								try {
									if (isName) {
										userList.erase(tempDeleteName);
									}
								}
								catch (exception(err)) {
									cout << "Error: " << err.what();
									Sleep(500);
								}
							}
							//no delete users
							else {
								cout << "Logout? (y/n): ";
								cin >> logout;
							}
						}

					}

				}

				

			}
			//no login
			else {
				cout << "\nTerminate program? (y/n): ";
				cin >> exit;
			}
		}


	}

	return(0);
}

bool isNameDup(map<string, string> ulist, string username) {

	for (map<string, string>::iterator cur = ulist.begin(); cur != ulist.end(); cur++) {
		string uname = cur->first;
		if (uname == username) {
			throw exception("Username Taken!");
		}
	}
	return false;
}

bool isName(map<string, string> ulist, string username) {

	for (map<string, string>::iterator cur = ulist.begin(); cur != ulist.end(); cur++) {
		string uname = cur->first;
		if (uname == username) {
			return true;
		}
	}
	
	throw exception("Username Not Recognized");

}

bool isValidLogin(map<string, string> ulist, string username, string password) {

	for (map<string, string>::iterator cur = ulist.begin(); cur != ulist.end(); cur++) {
		string uname = cur->first;
		string pass = cur->second;
		if (uname == username && pass == password) {
			return true;
		}
	}

	throw exception("Login Not Recognized");

}