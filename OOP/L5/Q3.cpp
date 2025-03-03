#include <iostream>

using namespace std;

class ValidateString
{
private:
    string str;

public:
    ValidateString(string s)
    {
        str = s;
    }

    // const keyword doesnt change anything in this case, however it is used so that no value is changed in this function
    void validate() const
    {
        bool valid = true;

        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];

            if (c >= 'a' && c <= 'z')
                continue;

            if (c >= 'A' && c <= 'Z')
                continue;

            valid = false;
            break;
        }

        cout << "String '" << str << "' is " << (valid ? "" : "NOT ") << "valid" << endl;
    }
};

int main()
{
    ValidateString v1("TestingStuff"), v2("Shawarma"), v3("fS0c13ty");

    v1.validate();
    v2.validate();
    v3.validate();
}