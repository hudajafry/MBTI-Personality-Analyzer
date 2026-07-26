#include <iostream>
#include <fstream>
#include "uz.h"

using namespace std;

User::User() : username(""), password(""){}

User::User(const string& uname, const string& pwd)
    : username(uname), password(pwd){}

void User::signUp() {
    cout << "Sign Up\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    saveToFile();
}
void User::saveToFile() const {
    ofstream outfile("userdata.txt", ios::app); // Append mode

    if (!outfile) {
        cerr << "Error opening file for writing\n";
        return;
    }

    // Save in a simple format: username password statistics (space separated)
    outfile << username <<" "<< password << " "<<endl;

    outfile.close();
}