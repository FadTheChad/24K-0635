#include <iostream>
#include <string>
using namespace std;

class Shop
{
    string items[100];
    float prices[100];
    int counter = 0;

public:
    void add()
    {
        int n;
        cout << "Enter the number of products to add: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin.ignore();
            cout << endl
                 << "Enter product name: ";
            getline(cin, items[counter]);
            cout << "Enter the price of the product: $";
            cin >> prices[counter];
            counter++;
        }
    }

    void edit()
    {
        if (counter == 0)
        {
            cout << "No products available to edit. Please add items first." << endl;
            return;
        }

        string temp;
        cin.ignore();
        cout << "Enter the name of the product you want to update the price for: ";
        getline(cin, temp);

        int flag = 0;
        for (int i = 0; i < counter; i++)
        {
            if (items[i] == temp)
            {
                float newPrice;
                cout << "Product found! Enter the updated price: $";
                cin >> newPrice;
                prices[i] = newPrice;
                flag = 1;
                cout << "Price updated successfully!" << endl;
                break;
            }
        }

        if (!flag)
        {
            cout << "Error: Product not found in the inventory!" << endl;
        }
    }

    void display()
    {
        if (counter == 0)
        {
            cout << "No products available to display. Please add items first." << endl;
            return;
        }

        cout << endl
             << "------ Product List ------" << endl;
        for (int i = 0; i < counter; i++)
        {
            cout << "Product " << (i + 1) << ": " << items[i] << " | " << "Price: $" << prices[i] << endl;
        }
    }
};

int main()
{
    Shop store;
    int choice;
    cout << "===== Welcome to the Tech & Gadgets Store =====" << endl;
    cout << "1 - Add new products with their prices." << endl;
    cout << "2 - Update the price of an existing product." << endl;
    cout << "3 - View all available products and their prices." << endl;
    cout << "4 - Exit the system." << endl;

    while (true)
    {
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            store.add();
            break;
        case 2:
            store.edit();
            break;
        case 3:
            store.display();
            break;
        case 4:
            cout << "Thank you for using the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}
