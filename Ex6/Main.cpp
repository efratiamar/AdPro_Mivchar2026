#include <iostream>
#include <fstream>
using namespace std;

#include "ClientData.h"
enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int enterChoice()
{
	cout << "\nEnter your choice" << endl
		<< "1 - print bank info to a text file\n"
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - delete an account" << endl
		<< "5 - end program\n? ";
	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

int initFile(int n, string fName)
{
	ofstream fout;
	fout.open(fName.c_str());

	if (!fout)
	{
		cout << "Error opening file " << fName << "for output" << endl;
		return -1;
	}

	ClientData empty;
	for (int i = 0; i < n; i++)
	{
		fout.write((char*)&empty, sizeof(ClientData));
	}
	return 0;
}

//int initFile(int n)
//{
//	ofstream fo;
//	fo.open("Clients.bin");
//
//	//fstream f;
//	//f.open("Clients.bin", ios::out);
//
//	if (!fo)
//	{
//		cout << "error" << endl;
//		return -1;
//	}
//	ClientData empty;
//	for (int i = 0; i < n; i++)
//		fo.write((char*)&empty, sizeof(ClientData));
//
//	fo.close();
//}

int getAccount()
{
	int accountNumber;
	do {
		cout << "Enter account number (1 - 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);
	return accountNumber;
}

void newClient(fstream& fInOut)
{
	ClientData newCD;
	int id = getAccount();
	newCD.setAccountNumber(id);

	char name[15];
	cout << "Enter name: ";
	cin >> name;
	newCD.setName(name);

	float b;
	cout << "Enter balance: ";
	cin >> b;
	newCD.setBalance(b);

	ClientData tmp;
	fInOut.seekg((id - 1) * sizeof(ClientData));
	fInOut.read((char*)&tmp, sizeof(ClientData));
	if (tmp.getAccountNumber() != 0)
	{ 
		cout << "Error account id already exist (" << tmp.getAccountNumber() << ")" << endl;
		return;
	}

	fInOut.seekp((id - 1) * sizeof(ClientData));
	fInOut.write((char*)&newCD, sizeof(ClientData));
}

void deleteClient(fstream& fInOut)
{
	ClientData cd;
	int id = getAccount();

	fInOut.seekg(sizeof(ClientData) * (id - 1));
	fInOut.read((char*)&cd, sizeof(ClientData));

	if (cd.getAccountNumber() == 0)
	{
		cout << "Client " << id << " not found in file" << endl;
		return;
	}
	
	ClientData empty; //XXX create empty object and write it instead of the existing object!!!!
	fInOut.seekp(sizeof(ClientData) * (id - 1));
	fInOut.write((char*)&empty, sizeof(ClientData));
}


void updateClient(fstream& fInOut)
{
	ClientData cd;
	int id = getAccount();

	fInOut.seekg(sizeof(ClientData) * (id - 1));
	fInOut.read((char*)&cd, sizeof(ClientData));

	if (cd.getAccountNumber() == 0)
	{
		cout << "Client " << id << " not found in file" << endl;
		return;
	}
		
	float b;
	cout << "Enter amount (+/-) to deposit: " << endl;
	cin >> b;
	cd.setBalance( cd.getBalance() + b);

	fInOut.seekp(sizeof(ClientData) * (id - 1));
	fInOut.write((char*)&cd, sizeof(ClientData));
}

void printAllClientsToTextFile(fstream& fInOut)
{
	ofstream fT;
	fT.open("AllClients.txt");

	if (!fT)
	{
		cout << "ERROR" << endl;
		return;
	}
	
	fInOut.seekg(0); //XXX needed!! place the reading pointer to the beginning of the binary file
	ClientData cd;
	fInOut.read((char*)&cd, sizeof(ClientData));
	while (!fInOut.eof())
	{
		if (cd.getAccountNumber() != 0)
		{
			fT << cd;
		}
		fInOut.read((char*)&cd, sizeof(ClientData));
	}

	fT.close();
}


int main()
{
	string fName = "Clients.bin";
	//only once!!!
	//initFile(100, fName);
	//return 0;
	
	fstream fInOut(fName, ios::in | ios::out);
	if (!fInOut)
	{
		cout << " could not open file.\n";
		return -1;
	}
	int choice;
	while ((choice = enterChoice()) != END)
	{
		switch (choice)
		{
		case PRINT: 	printAllClientsToTextFile(fInOut);		break;
		case UPDATE:	updateClient(fInOut);	break;
		case NEW:	newClient(fInOut);		break;
		case DELETE:	deleteClient(fInOut);	break;
		default: cout << "Incorrect choice\n";
		}
		fInOut.clear();
	}

	fInOut.close();
	return 0;
}


