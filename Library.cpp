#include <iostream>
#include<stack>
using namespace std;
class main_worker
{
    string Full_name;
    int age;
    int  Mysalary = 900 ,Mypension = 800 ;
public:

    void set_full_name(string Full_name) {
        this->Full_name = Full_name;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    string get_full_name()
    {
        return Full_name;
    }

    int get_age() {
        return age;
    }

    int  salary()
    {
        if (get_age() > 60)
        {
            return  Mypension+Mysalary;
        }
        else {
            return   Mysalary;

        }
    }

    void opreation() {
        cout << "Select one of the following choices : " << endl;
        cout << "1- buy" << endl;
        cout << "2- purchase " << endl;
        cout << "3- Borrow a book" << endl;
    }

};
class nonmain_worker
{
    string Full_name;
    int salary_of_day=70 ,days;

public:

    void set_full_name(string Full_name)
    {
        this->Full_name = Full_name;
    }

    string get_full_name()
    {
        return Full_name;
    }
    void set_days(int days){
        this->days =days;
    }

    int mysalary()
    {
        return  salary_of_day * days;
    }

    void opreation() {
        cout << "Select one of the following choices : " << endl;
        cout << "1- you can only Borrow a book" << endl;
    }

};

class books
{

private:

    int price_buy = 10, Price_borrow = 5, stock = 9;
    int min_stock = 3;
    stack<string>book1;

public:

    void buy_book(int copy) {
        if ((book1.size() - copy) >= min_stock) {
            for (int i = 0; i < copy; i++) {
                book1.pop();
            }
            int cost = copy * price_buy;
            cout << "The "<< copy<<" Book You Buy Will Cost : " << cost << " $\n";
        }
        else {
            cout << "you can't buy\n";
        }

    }

    void  purchas_book(int copy) {
        if (copy + book1.size() <= stock) {
            for (int i = 0; i < copy; i++) {
                book1.push("book");
            }
            cout << "you add " << copy << " to the store\n";
        }
        else {
            cout << "U can't added\n";
        }
    }



    void  borrow_book(int copy, int days) {
        if (days==0){
            cout<<"The number of days can't be ZERO\n";
        }
        else if (copy <= book1.size()) {
            for (int i = 0; i < copy; i++) {
                book1.pop();
            }
            int cost = days * (copy * Price_borrow);
            cout << "Now you can borrow " << copy << " Books  for " << days << "days\n";
            cout << "The Books You borrow Will Cost : " << cost << " $\n";

        }
        else {
            cout << "you can't borrow Books\n";
        }
    }

    void Add_books() {
        for (int i = 0; i < stock; i++) {
            book1.push("book");

        }
    }

    int info() {
        return  book1.size();

    }

};

class Magazine_story {
    int price_buy = 20, price_borrow = 10;
    stack<string>rack;

public:

    void buying(int copy) {
        if (copy <= rack.size()) {
            int cost = copy * price_buy;
            for (int i = 0; i < copy; i++) {
                rack.pop();
            }
            cout << "you buy " << copy << " & The cost is "<<cost <<" $ \n";
        }
        else {
            cout << "you don't have enough copy!!!\n";
        }

    }
    void borrowing(int copy, int day) {
        if (day==0){
            cout<<"The number of days can't be ZERO\n";
        }
        else if (copy <= rack.size()) {
            int cost = copy * price_borrow * day;
            for (int i = 0; i < copy; i++) {
                rack.pop();
            }
            cout << "you borrowed " << copy <<" & The cost is "<<cost <<" $" ;
        }
        else {
            cout << "you don't have enough copies!!!\n";
        }
    }
    void  purchas(int copy) {

        for (int i = 0; i < copy; i++) {
            rack.push("book");
        }
        cout << "you add " << copy << " to the store\n";

    }

    int info() {
        return rack.size();
    }

    void add_items() {
        for (int i = 0; i < 9; i++) {
            rack.push("item");
        }
    }

};

void main_menu() {
    cout << "Select one of the following choices : " << endl;
    cout << "1- main worker" << endl;
    cout << "2-nonmain worker " << endl;
    cout << "3-All Data about library\n";
    cout << "4- Exit " << endl;

}
void types() {
    cout << "Select one of the following choices : " << endl;
    cout << "1- Book ." << endl;
    cout << "2- Story . " << endl;
    cout << "3- Magazine ." << endl;
}

void Book_types() {
    cout << "Select one of the following choices : " << endl;
    cout << "1- religious_book" << endl;
    cout << "2- geometric_book " << endl;
    cout << "3- medical__book " << endl;
}

int main()
{

    const int Main_num = 10;
    const int Nonmain_num = 6;

    main_worker w1[Main_num]; 
    nonmain_worker w2[Nonmain_num];

    w1[0].set_full_name("nafisa abdelaziz elkady");
    w1[1].set_full_name("eman fathy mansour");
    w1[2].set_full_name("mohamed elarabie aborayia");
    w1[3].set_full_name("ahmed ali saad");
    w1[4].set_full_name("mohamed mohamed ali");
    w1[5].set_full_name("merna hany ramzy");
    w1[6].set_full_name("mai ahmed ali");
    w1[7].set_full_name("hassan saad mohamed");
    w1[8].set_full_name("noha mohamed ramzy");
    w1[9].set_full_name("larissa akram ramzy");

    w2[0].set_full_name("mohamed adel emam");
    w2[1].set_full_name("karem hessen ali");
    w2[2].set_full_name("shahd mohamed abdallah");
    w2[3].set_full_name("ramy mohamed emam");
    w2[4].set_full_name("ahmed khaled saleh");
    w2[5].set_full_name("sara mohamed nour");


    ///////////////////////////////////////////////////////////////////// 

    books religious;
    books geometric;
    books medical;

    religious.Add_books();
    geometric.Add_books();
    medical.Add_books();

    Magazine_story magazine;
    Magazine_story story;

    magazine.add_items();
    story.add_items();

    int choose, opreation, type, booktype, copy, days;
    bool p1 = 1;
    string name, fname, sname, lname , check1;

    while (true) {
        cout << "\n*--------------Welcome to the Book Store---------------*" << endl << endl;

        main_menu();

        cin >> choose;

        if (choose== 1) {
            cout << "Enter your Full Name\n";
            cin >> fname >> sname >> lname;
            name = fname + " " + sname + " " + lname;
            for (int i = 0; i < Main_num; i++)
            {
                if (w1[i].get_full_name() == name)
                {
                    p1 = 0;
                    cout << "correct\n";
                    // All the operations the main worker can do 
                    while (true) {
                        w1[i].opreation();
                        cin >> opreation;
                        if (opreation== 1) { //which type of book or story or magazine  want to buy
                            types();
                            cin >> type;
                            if (type == 1) { // which book types
                                Book_types();
                                cin >> booktype;
                                cout << "how many copies";
                                cin >> copy;
                                if (booktype == 1) {
                                    religious.buy_book(copy);
                                }
                                else if (booktype == 2) {
                                    geometric.buy_book(copy);
                                }
                                else if (booktype == 3) {
                                    medical.buy_book(copy);
                                }
                                else {
                                    cout << "Try again .\n";
                                }
                            }
                            else if (type == 2) { // Buy story 
                                cout << "how many copies\n";
                                cin >> copy;
                                story.buying(copy);
                            }
                            else if (type == 3) { 
                                cout << "how many copies\n";
                                cin >> copy;
                                magazine.buying(copy);
                            }
                            else {
                                cout << "Try again .\n";
                            }
                        }
                        else if (opreation== 2) { //Purchas 
                            types();
                            cin >> type;
                            if (type == 1) { //book or story or magazine 
                                Book_types();
                                cin >> booktype;
                                cout << "how many copies\n";
                                cin >> copy;
                                if (booktype == 1) {
                                    religious.purchas_book(copy);
                                }
                                else if (booktype == 2) {
                                    geometric.purchas_book(copy);
                                }
                                else if (booktype == 3) {
                                    medical.purchas_book(copy);
                                }
                                else {
                                    cout << "Try again .\n";
                                }
                            }
                            else if (type == 2) {
                                cout << "how many copies\n";
                                cin >> copy;
                                story.purchas(copy);
                            }
                            else if (type == 3) {
                                cout << "how many copies\n";
                                cin >> copy;
                                magazine.purchas(copy);
                            }
                            else {
                                cout << "Try again .\n";
                            }
                        }
                        else if (opreation == 3) {
                            types();
                            cin >> type;
                            if (type == 1) { //book types
                                Book_types();
                                cin >> booktype;
                                cout << "how many copies & days";
                                cin >> copy >> days;
                                if (booktype == 1) {
                                    religious.borrow_book(copy, days);
                                }
                                else if (booktype == 2) {
                                    geometric.borrow_book(copy, days);
                                }
                                else if (booktype == 3) {
                                    medical.borrow_book(copy, days);
                                }
                                else {
                                    cout << "Try again .\n";
                                }
                            }
                            else if (type == 2) {
                                cout << "how many copies & days\n";
                                cin >> copy >> days;
                                story.borrowing(copy, days);
                                cout << "stories  for " << days << "days .\n";
                            }
                            else if (type == 3) {
                                cout << "how many copies & days\n";
                                cin >> copy >> days;
                                magazine.borrowing(copy, days);
                                cout << "Magazine   for " << days << "days .\n";
                            }
                            else {
                                cout << "Try again .\n";
                            }
                        }

                        else { // don't chose any of the operations 
                            cout << " see you later \n----------------------\n";
                            break;
                     
                        }
                        cout << "If You  want to buy or borrow or sell again plz enter ( yes ) or ( no ) to finish \n";
                        cin >> check1;
                        if (check1 != "yes")
                        {
                            break; //breaking the operations while ture 
                        }

                    }
                    break; // breaking the main worker while ture 
                }

            }
            if (p1) { // can't find the main worker 
                cout << "not main worker\n";
            }
        }

        else if (choose == 2) {  //  not main worker 
            cout << "Enter your Full Name\n";
            cin >> fname >> sname >> lname;
            name = fname + " " + sname + " "+lname;
            for (int i = 0; i < Nonmain_num; i++) {
                if (w2[i].get_full_name() == name) {
                    p1 = 0;
                    cout << "correct\n";

                    while (true)
                    {
                        w2[i].opreation();
                        cin >> opreation;
                        if (opreation == 1) {
                            types();   //book or story
                            cin >> type;
                            if (type == 1) { //book types
                                Book_types();
                                cin >> booktype;
                                cout << "how many copies & days";
                                cin >> copy >> days;
                                if (booktype == 1) {
                                    religious.borrow_book(copy, days);
                                }
                                else if (booktype == 2) {
                                    geometric.borrow_book(copy, days);
                                }
                                else if (booktype == 3) {
                                    medical.borrow_book(copy, days);
                                }
                                else {
                                    cout << "Try again .\n";
                                }
                            }
                            else if (type == 2) {
                                cout << "how many copies & days\n";
                                cin >> copy >> days;
                                story.borrowing(copy, days);
                            }
                            else if (type == 3) {
                                cout << "how many copies & days\n";
                                cin >> copy >> days;
                                magazine.borrowing(copy, days);
                            }
                            else {
                                cout << "Try again .\n";
                            }
                        }
                        else { // don't chose any of the operations
                            cout << " see you later \n----------------------\n";
                            break;
                        }
                        cout << "U are want to buy or borrow or sell again plz enter enter ( yes ) or ( no ) to finish \n";
                        cin >> check1;
                        if (check1 != "yes")
                        {
                            break;
                        }
                    }
                }
            }
            if (p1) { // can't find the non main worker
                cout << "not Nonmain worker\n";
            }
        }

        else if (choose== 3) { 
            cout << "----------------------------------------------------------------------\n";
            cout << "the num of Main worker is " << Main_num << endl;
            cout << "the num of NonMain worker is " << Nonmain_num << endl;
            cout << "The total Num of Books is : " << religious.info() + geometric.info() + medical.info() << endl;
            cout << "religious : " << religious.info();
            cout << "\tgeometric : " << geometric.info();
            cout << "\tmedical : " << medical.info() << endl;
            cout << "The total Num of storys is : " << story.info() << endl;
            cout << "The total Num of Magazine is : " << magazine.info() << endl;
            cout << "----------------------------------------------------------------------\n";
        }

        else { 
            break;//break the All program
        }
    }
    cout << "Bye Bye .";
    return 0;

}
