#include <iostream>
#include <stdlib.h>
using namespace std;
class Publication
{
private:
    string title;
    float price;

public:
    void getData();
    void Display();
};
void Publication::getData()
{
    cout << "Enter title" << endl;
    cin >> title;
    cout << "Enter price:" << endl;
    cin >> price;
}
void Publication::Display()
{
    cout << "Title of Book is:" << title << endl;
    cout << "Price:" << price << endl;
}
class Book : public Publication
{
private:
    int pagecount;

public:
    void insert();
    void display();
};
void Book::insert()
{
    getData();
    cout << "Enter the total page numbers" << endl;
    try
    {
        cin >> pagecount;
        if (pagecount == 0)
            throw pagecount;
    }
    catch (int)
    {
        cout << "Pagecount can't be zero";
    }
}
void Book::display()
{
    Display();
    cout << "Total page numbers is:" << pagecount << endl;
}
class Tape : public Publication
{
private:
    float minutes;

public:
    void Time();
    void Show();
};
void Tape::Time()
{
    getData();
    cout << "Enter the time of playing" << endl;
    cin >> minutes;
}
void Tape::Show()
{
    Display();
    cout << "Time of playing is:" << minutes << endl;
}
int main()
{
    Book b;
    Tape t;
    int ch;
    do
    {
        cout << "1.Book 2.CD 3.exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.insert();
            b.display();
            break;
        case 2:
            t.Time();
            t.Show();
            break;
        case 3:
            exit(0);
        }
    } while (ch != 3);
    return 0;
}
