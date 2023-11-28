#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class item
{
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    bool operator==(const item &i1)
    {
        if (code == i1.code)
            return 1;
        return 0;
    }
};
vector<item> o1;
void print(item &i1);
void display();
void insert();
void search();
void dlt();

bool compare(const item &i1, const item &i2)
{
    return i1.cost < i2.cost;
}

int main()
{
    int ch;
    do
    {
        cout << "\n\n****Menu***";
        cout << "\n 1.Insert";
        cout << "\n 2.Display";
        cout << "\n 3.Search";
        cout << "\n 4.Sort";
        cout << "\n 5 Delete";
        cout << "\n 6.Exit";
        cout << "\n Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(o1.begin(), o1.end(), compare);
            cout << "\nSorted on cost ";
            display();
            break;
        case 5:
            dlt();
            break;
        case 6:
            exit(0);
        }
    } while (ch != 7);
    return 0;
}
void insert()
{
    item i1;

    cout << "\n Enter the item name : " << endl;
    cin >> i1.name;
    cout << "\n Enter item quantity : " << endl;
    cin >> i1.quantity;
    cout << "\n Enter item cost : " << endl;
    cin >> i1.cost;
    cout << "\n Enter item code : " << endl;
    cin >> i1.code;
    o1.push_back(i1);
}
void display()
{
    for_each(o1.begin(), o1.end(), print);
}

void print(item &i1)
{
    cout << "\n Item Name : " << i1.name << endl;
    cout << "\n Item Quantity : " << i1.quantity << endl;
    cout << "\n Item Cost : " << i1.cost << endl;
    cout << "\n Item Code : " << i1.code << endl;
}

void search()
{
    vector<item>::iterator p;
    item i1;
    cout << "\n Enter Code to search item : " << endl;
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "\n Not found ";
    }
    else
    {
        cout << "\n Found" << endl;
        cout << "\n Item Name : " << p->name << endl;
        cout << "\n Item Quantity : " << p->quantity << endl;
        cout << "\n Item Cost : " << p->cost << endl;
        cout << "\n Item Code : " << p->code << endl;
    }
}

void dlt()
{
    vector<item>::iterator p;
    item i1;
    cout << "\n Enter item code to delete : " << endl;
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "\n Not found ";
    }
    else
    {
        o1.erase(p);
        cout << "\n Deleted ";
    }
}
