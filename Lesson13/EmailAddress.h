#pragma once
#include <string>
#include <fstream>
using namespace std;

fstream EmailAddress::file;	 //איתחול ב- EmailAddress.cpp

class EmailAddress {
private:
    string address;
    void setAddress(string e);	
    static fstream file;		//in EmailAddress.h

public:
    friend istream& operator>>(istream&, EmailAddress&);
    bool uniqueAddress(string e);
};

istream& operator>>(istream& is, EmailAddress& adrs) {
    string e;
    is >> e;
    adrs.setAddress(e);
    return is;
}

void EmailAddress::setAddress(string e)
{
    int pos = e.find('@');
    if (pos == -1)
        throw "email address must include '@'";
    if (pos == 0)
        throw "email address cannot begin with '@'";
    string domain = e.substr(pos + 1, e.length());
    pos = domain.find('@');
    if (pos != -1)
        throw "'@' can appear only once";
    pos = domain.find('.');
    if (pos == -1) throw "domain must include at least one '.'";
    if (pos == 0)throw "domain cannot begin with '.'";
    if (domain[domain.length() - 1] == '.')throw "domain cannot end with '.'";
    address = e;
}

bool EmailAddress::uniqueAddress(string e)
{
    bool found = false;

    file.open("addressBook", ios::in);

    if (!file)
        return false;
    string address;
    while (file >> address)
    {
        if (address == e && found)
        {
            file.close();
            return false;
        }
        if (address == e && !found)
            found = true;
    }
    file.close();
    return true;

}
