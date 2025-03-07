#include <iostream>
#include <string>

using namespace std;

class MenuItem
{
public:
    string foodName;
    double foodPrice;

    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}
};

class Menu
{
private:
    MenuItem **items;
    int itemCount;

public:
    Menu() : itemCount(0), items(nullptr) {}

    ~Menu()
    {
        for (int i = 0; i < itemCount; ++i)
        {
            delete items[i];
        }
        delete[] items;
    }

    void addItem(MenuItem *item)
    {
        MenuItem **newItems = new MenuItem *[itemCount + 1];
        for (int i = 0; i < itemCount; ++i)
        {
            newItems[i] = items[i];
        }
        newItems[itemCount] = item;
        delete[] items;
        items = newItems;
        itemCount++;
    }

    void removeItem(string foodName)
    {
        int indexToRemove = -1;
        for (int i = 0; i < itemCount; ++i)
        {
            if (items[i]->foodName == foodName)
            {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1)
        {
            MenuItem **newItems = new MenuItem *[itemCount - 1];
            for (int i = 0, j = 0; i < itemCount; ++i)
            {
                if (i != indexToRemove)
                {
                    newItems[j++] = items[i];
                }
                else
                {
                    delete items[i];
                }
            }
            delete[] items;
            items = newItems;
            itemCount--;
        }
    }

    void displayMenu() const
    {
        for (int i = 0; i < itemCount; ++i)
        {
            cout << items[i]->foodName << " - $" << items[i]->foodPrice << endl;
        }
    }
};

class Payment
{
public:
    double amount;

    Payment(double amt) : amount(amt) {}

    void displayPayment() const
    {
        cout << "Total amount to be paid: $" << amount << endl;
    }
};

class Order
{
private:
    MenuItem **orderedItems;
    int orderItemCount;
    Payment payment;

public:
    Order(MenuItem **items, int itemCount, Payment pay)
        : orderedItems(items), orderItemCount(itemCount), payment(pay) {}

    ~Order()
    {
        for (int i = 0; i < orderItemCount; ++i)
        {
            delete orderedItems[i];
        }
        delete[] orderedItems;
    }

    void displayOrder() const
    {
        cout << "Order details:" << endl;
        for (int i = 0; i < orderItemCount; ++i)
        {
            cout << orderedItems[i]->foodName << " - $" << orderedItems[i]->foodPrice << endl;
        }
        payment.displayPayment();
    }
};

class RestaurantOrderingSystem
{
private:
    Menu menu;

public:
    void setMenu(Menu newMenu)
    {
        menu = newMenu;
    }

    void placeOrder(MenuItem **items, int itemCount, Payment payment)
    {
        Order order(items, itemCount, payment);
        order.displayOrder();
    }

    void displayMenu() const
    {
        menu.displayMenu();
    }
};

int main()
{
    Menu menu;
    menu.addItem(new MenuItem("Shawarma", 119.99));
    menu.addItem(new MenuItem("Pizza", 199.99));
    menu.addItem(new MenuItem("Pasta", 149.49));

    RestaurantOrderingSystem system;
    system.setMenu(menu);

    system.displayMenu();

    MenuItem **orderItems = new MenuItem *[2];
    orderItems[0] = new MenuItem("Shawarma", 119.99);
    orderItems[1] = new MenuItem("Pizza", 199.99);

    Payment payment(14.98);
    system.placeOrder(orderItems, 2, payment);

    for (int i = 0; i < 2; ++i)
    {
        delete orderItems[i];
    }
    delete[] orderItems;

    return 0;
}
