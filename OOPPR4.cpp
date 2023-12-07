
// Practical 4  FIle Handling oop
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Student
{
public:
    char name[20];
    string phone;

public:
    void accept();
    void display();
};
void Student::accept()
{
    cin >> name;
    cin >> phone;
}
void Student::display()
{
    cout << name << " " << phone << endl;
}
int main()
{
    int ch;
    int limit;
    cout << "Enter the number of people whose information is to be stored" << endl;
    cin >> limit;
    Student *a = new Student[limit];
    fstream file;
    file.open("ry_4.txt", ios::in | ios::out);
    do
    {
        cout << "1.Store 2.Display 3.Search 4.Modify 5.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the name and phone number" << endl;
            for (int i = 0; i < limit; i++)
            {
                a[i].accept();

                file.write((char *)&a[i], sizeof(a[i]));
            }
            break;
        case 2:
            cout << "Stored information are" << endl;
            for (int i = 0; i < limit; i++)
            {
                a[i].display();
                file.read((char *)&a[i], sizeof(a[i]));
            }
            break;
        case 3:
            int ch1;
            cout << "1.By name 2.By phone" << endl;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                char name1[20];
                cout << "Enter the name" << endl;
                cin >> name1;
                for (int i = 0; i < limit; i++)
                {
                    if (a[i].name == name1)
                    {
                        file.read((char *)&a[i], sizeof(a[i]));
                        cout << a[i].phone << endl;
                    }
                }
                break;
            case 2:
                string phone1;
                cout << "Enter the phone number of the person" << endl;
                cin >> phone1;
                for (int i = 0; i < limit; i++)
                {
                    if (a[i].phone == phone1)
                    {

                        file.read((char *)&a[i], sizeof(a[i]));
                        cout << a[i].name << endl;
                    }
                }
                break;
            }
            break;
        case 4:
            string phone2, phone3;

            cout << "Enter the old telephone number which u want to modify" << endl;
            cin >> phone2;
            for (int i = 0; i < limit; i++)
            {
                if (a[i].phone == phone2)
                {
                    file.read((char *)&a[i], sizeof(a[i]));
                    cout << "Enter new phone number" << endl;
                    cin >> phone3;
                    a[i].phone == phone3;
                    file.write((char *)&a[i], sizeof(a[i]));
                }
            }
            break;
        }
    } while (ch != 5);
    return 0;
}
