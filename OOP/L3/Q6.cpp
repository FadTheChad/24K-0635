#include <iostream>
using namespace std;

class Smartphone
{
    string company;
    string model;
    string displayResolution;
    string RAM;
    string ROM;
    string storage;

public:
    void setCompany(string company)
    {
        this->company = company;
    }

    void setModel(string model)
    {
        this->model = model;
    }

    void setDisplayResolution(string displayResolution)
    {
        this->displayResolution = displayResolution;
    }

    void setRam(string RAM)
    {
        this->RAM = RAM;
    }

    void setRom(string ROM)
    {
        this->ROM = ROM;
    }

    void setStorage(string storage)
    {
        this->storage = storage;
    }

    string getCompany()
    {
        return company;
    }

    string getModel()
    {
        return model;
    }

    string getDisplayResolution()
    {
        return displayResolution;
    }

    string getRam()
    {
        return RAM;
    }

    string getRom()
    {
        return ROM;
    }

    string getStorage()
    {
        return storage;
    }

    void makePhoneCall()
    {
        cout << "Dialing a number... Call in progress!" << endl;
    }

    void sendMessage()
    {
        cout << "Message sent successfully!" << endl;
    }

    void connectToWifi()
    {
        cout << "Connected to Wi-Fi: UltraSpeed 5G Network" << endl;
    }

    void browseInternet()
    {
        cout << "Opening web browser... Loading page..." << endl;
    }
};

int main()
{
    Smartphone phone1, phone2;

    phone1.setCompany("Google");
    phone1.setModel("Pixel 8 Pro");
    phone1.setDisplayResolution("2992x1344");
    phone1.setRam("12GB");
    phone1.setRom("128GB");
    phone1.setStorage("128GB");

    phone2.setCompany("OnePlus");
    phone2.setModel("OnePlus 12");
    phone2.setDisplayResolution("3216x1440");
    phone2.setRam("16GB");
    phone2.setRom("512GB");
    phone2.setStorage("512GB");

    cout << "----- Smartphone Specifications -----" << endl;
    
    cout << "\nDevice 1:" << endl;
    cout << "Brand: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Screen Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRam() << endl;
    cout << "ROM: " << phone1.getRom() << endl;
    cout << "Internal Storage: " << phone1.getStorage() << endl;

    cout << "\nDevice 2:" << endl;
    cout << "Brand: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Screen Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRam() << endl;
    cout << "ROM: " << phone2.getRom() << endl;
    cout << "Internal Storage: " << phone2.getStorage() << endl;

    cout << "\n--- Testing Features ---" << endl;
    phone1.makePhoneCall();
    phone2.sendMessage();
    phone1.connectToWifi();
    phone2.browseInternet();

    return 0;
}
