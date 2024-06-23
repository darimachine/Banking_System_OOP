#include "Check.h"

#pragma warning(disable : 4996)
using std::cout;
static bool isLetterOrNumber(const char ch)
{
    
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
int Check::MAX_CODE_SIZE = 3;
bool Check::isValidCode(const MyString& code)
{
    if (code.getSize() != MAX_CODE_SIZE)
    {
        return false;
    }
    unsigned size = MAX_CODE_SIZE;
    for (int i = 0; i < size; i++)
    {
        if (!isLetterOrNumber(code[i])) {
            return false;
        }
    }
    return true;
    
}

Check::Check(const MyString& sender, const MyString& code, unsigned cashToSend, const MyString& egn) :sender(sender),cashToSend(cashToSend),egn(egn)
{
    if (!isValidCode(code))
    {
        throw std::invalid_argument("Invalid code");
    }
    uniqueCode = code;
}

unsigned Check::getCash() const
{
    return cashToSend;
}

bool Check::checkIfCodeIsRight(const MyString& code) const
{
    return code==uniqueCode;
}

const MyString& Check::getSender() const
{
    return sender;
}

const MyString& Check::getEgn() const
{
    return egn;
}

void Check::saveToFile(std::ofstream& ofs) const
{
    sender.saveToFile(ofs);
    uniqueCode.saveToFile(ofs);
    egn.saveToFile(ofs);
    ofs.write((char*)&cashToSend, sizeof(cashToSend));
}

void Check::readFromFile(std::ifstream& ifs)
{
    sender.readFromFile(ifs);
    uniqueCode.readFromFile(ifs);
    egn.readFromFile(ifs);
    ifs.read((char*)&cashToSend, sizeof(cashToSend));
}

const MyString& Check::getCode() const
{
    return uniqueCode;
}
