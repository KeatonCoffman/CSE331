//
//  Hw 8 Problem 2  : program that reads in username/login pairs
//  and performs authentication of usernames until EOF is encountered.
//--------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "HashTable.cpp"

using namespace std;
//definition of your entity.
struct Password
{
    void setKey ( string newKey ) { username = newKey; }
    string getKey () const { return username; }
    static unsigned int hash(const string& str)
    {
        int val = 0;

        for (int i=0; i<str.length(); i++)
            val += str[i];
        return val;
    }
    string username,
           password;
};

int main()
{
   //few declarations ... feel free to change any of them.
    HashTable<Password, string> passwords(8);
    Password tempPass;
    string name,      // user-supplied name
           pass;      // user-supplied password
    bool userFound;   // is user in table?

    ifstream inClientFile("password.dat", ios::in);

    if (!inClientFile.is_open()) {
        cout << "Could not open file\n";
        return 0;
    }
	string input_t;
    int i=0;
    vector<string> info;
    while (inClientFile >> input_t) {
        info.push_back(input_t);
     }
     for(int i=0;i<=info.size()-1;i+=2){
		cout<<"User: "<<info[i]<<" Pass:"<<info[i+1]<<endl; 
		tempPass.username = info[i];
		tempPass.password = info[i+1];
		passwords.insert(tempPass);
	 }
	 passwords.showStructure();
	 
	 cout<<endl;
	 cout<<"Login: ";
	 
	 while(cin >> name){
		if(passwords.retrieve(name,tempPass)){
			cout<<"Password: ";
			cin>>pass;
			if(pass == tempPass.password){
				cout<<"Authentication successful"<<endl;
			}
			else{
				cout<<"Authentication failure"<<endl;
			}
		}
		else{
			cout<<"Username not found"<<endl;
		}
		cout<<"Login: ";
	 }
}
