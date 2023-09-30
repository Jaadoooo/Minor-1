#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "SillyPassword";

int main() 
{	
	
	string us = "chitrak";
	string pa = "aseri123";
	string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username != us || password != pa)
    {
        cout << "Authentication failed. Exiting..." << endl;
        return 1; // Exit the program
    }
    
	
	MYSQL* obj;
	
	char Name[30];
	int Age;
	char Address[30]; 

	bool ProgramIsOpened = true;
	int answer;
	
	char* consult;
	char* sentence;
	string sentence_aux;
	
//---------------------------------------------------------------------------
// Connection 

	if (!(obj = mysql_init(0)))
	{
		cout << "ERROR: MySQL object could not be created." << endl;
	}
	else
	{
		if(!mysql_real_connect(obj, "localhost", "root", "chitttu", "software", 3306, NULL, 0))
		{
			cout << "ERROR: Some database info is wrong or do not exist." << endl;
			cout << mysql_error(obj) << endl;
	    }
	    else
	    {	
	    	cout << "LogIn Successful." << endl << endl;

	    	while(ProgramIsOpened)
	    	{
	    		cout << "Name - ";
				cin >> Name;
				
				cout << "Age - ";
				cin >> Age;
				cin.ignore(); 
				
				cout << "Address - ";
				cin.ignore(); 
				cin.getline(Address, 30, '\n');
				cout << endl;

	    		// Setting update 
	    		
	    		sentence_aux = "INSERT INTO software(Name, Age, Address) VALUES ('%s', '%d', '%s')";
	    		sentence = new char [sentence_aux.length() + 1];
	    		strcpy(sentence, sentence_aux.c_str());
	    		
	    		consult = new char[strlen(sentence) + strlen(Name) + sizeof(Age) + strlen(Address)];
	    		sprintf(consult,sentence,Name,Age,Address);
	    		
	    		// Make our attempt 
	    		if(mysql_ping(obj))
				{
					cout << "ERROR: Imposible to connect." << endl;
					cout << mysql_error(obj) << endl;
				}
				if(mysql_query(obj, consult))
				{
					cout << "ERROR: " << mysql_error(obj) << endl;
					rewind(stdin);
					getchar();
				}
				else
				{
					cout << "Info added correctly." << endl;
				}
				mysql_store_result(obj);

				cout << endl << "Another?" << endl;
				cout << "[1]: Yes" << endl;
				cout << "[0]: N0" << endl;
				cout << "Answer: ";
				cin >> answer;
				cin.ignore(100, '\n');
				if (answer == 0)	
				{
					ProgramIsOpened = false;	
				}
				cout << endl;	    		
			}
		}
	}
	
	cout << "BYE!" << endl;
	return 0;
}

