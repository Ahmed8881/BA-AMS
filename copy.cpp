#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <thread>
#include <chrono>
float total = 0; /// added

using namespace std;
string setcolor(unsigned short color);

int input(int number);
void topHeader();
void sign_page();
void exit();
void page_of_admin();
void loadingAnimation();
// void page_of_user();
void login(string &name, string &password, string &role_check, string namearray[], string passwordarray[], string rolearray[], int &indexCount);
void sign_up(string &name, string &password, string &role);
int searchArray(string arr[], string object, int &indexCount);
bool log(string name, string password, string namearray[], string passwordarray[], int &indexCount);
void sign_string(string name, string password, string role, string namearray[], string passwordarray[], string rolearray[], int &indexCount);
bool signUp(string name, string password, string role, string namearray[], string passwordarray[], string rolearray[], int sized, int &indexcount);

// bool check_flight(string ticket_route[], string ticket_time[], string time, string route, int idx_ticket);
void displayAllPlanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], string Plane_status[], int planeCount);
void delete_flight(int ticket_price[], string ticket_route[], int ticket_seat_Num[], string ticket_time[], int idx_ticket);
void employee_add(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee);
void delete_employee(string employee_name[], string employee_age[], string employee_num[], int idx_employee);
void addPlaneInfo(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount, int planeSize);
void add_flight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket, int &op); // validated

bool addPlane(string plane_id, string planeType, string planecapacity, string planeRange, string fuelcapacity, string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount, int planeSize);

void view_customer_complains(string customer_name[], string customer_number[], string complain[], int idx_complian);
void changeTicketPrice(int ticket_price[], int idx_ticket, string ticket_route[], string ticket_time[], int ticket_seat_Num[]);

void totalAmountEarned(int ticket_price[], int idx_ticket);
void changeUserPassword(string username[], string userPassword[], string userRole[], int size, int &usercount);
void customer_page();
void add_complains(string customer_name[], string customer_number[], string complain[], int &idx_complian);
void view_flights(int ticket_price[], string ticket_route[], int ticket_seat_Num[], string ticket_time[], int idx_ticket);
void search_flight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket, int size);
void reserves_seat(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[]);
void view_reserved_flights(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[]);
void available_seats(string flight_names[], int seatsused[], int idx_ticket);
void change_pass(string namearray[], string passwordarray[], int pass);
void confirm_payment(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[], int &idx_ticket1);
void cancelflight(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[], int &idx_ticket1);
string getData(string data, int index);
int choiceCheck(int op);             // choice validation
string contactCheck(string contact); // contact validation
string isNum(string input);          // age validation
string isAlpha(string input);        // name and city validation
string isNum1(string input);         // price validation
string passwordlength(string anypass);
int INTVALIDATION(string command);
string timevalidation(string input);
string checkNumber(string input);
string passwordlength1(string anypass);
bool checkComma(string s);
/// file storeings allllllllll
void storelogin(string namearray[], string passwordarray[], string rolearray[], int indexCount);
void storeflight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int idx_ticket);
void store_employee(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee);
void storeplanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount);
void store_customercomplain(string customer_name[], string customer_number[], string complain[], int &idx_complian);
///////load file handling
void loadlogin(string namearray[], string passwordarray[], string rolearray[], int &indexCount);
void loadflight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket);
void load_employee(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee);
void loadplanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount);
void load_customercomplain(string customer_name[], string customer_number[], string complain[], int &idx_complian);

/////                                                                               /Main start/////
int main()
{
    system("cls");
    /// data for login in///
    string name;
    // int op = 0;
    int sized = 100;
    int user_controller = 0;
    string password;
    string role;
    string role_check;
    int indexCount = 0;
    int pass = 100;
    string namearray[100];
    string passwordarray[100];
    string rolearray[100];

    /////data to add flight///
    int idx_ticket = 0;
    string ticket_route[100];
    string ticket_time[100];
    int ticket_seat_Num[100];
    int ticket_price[100];
    bool reserve_seat[100];
    int seatsused[100];
    int customer = 0;

    ///////data for employee/
    int idx_employee = 0;
    string employee_name[100];
    string employee_age[100];
    string employee_num[100];
    string employee_salary[100];
    ///// data add to complains ///
    int lenght = 100;
    int idx_complian = 0;
    string customer_name[lenght];
    string complain[lenght];
    string customer_number[lenght];
    //////plane information data////
    int planeCount = 0;
    int planeSize = 100;
    string Plane_id[planeSize];
    string Plane_Type[planeSize];
    string Plane_Capacity[planeSize];
    string fuel_Capacity[planeSize];
    string Plane_Range[planeSize];
    string Plane_status[planeSize];
    /// loading data of login from file ///
    loadlogin(namearray, passwordarray, rolearray, indexCount);
    loadflight(ticket_route, ticket_price, ticket_seat_Num, ticket_time, idx_ticket);
    load_employee(employee_name, employee_age, employee_num, employee_salary, idx_employee);
    loadplanes(Plane_id, Plane_Type, Plane_Capacity, fuel_Capacity, Plane_Range, planeCount);
    load_customercomplain(customer_name, customer_number, complain, idx_complian);
    // int number = 0;
    int op = 0;
    while (op != 3)
    {
        // loadingAnimation();
        if (op == 0)
        {
            system("cls");
            topHeader();
            sign_page();
            op = choiceCheck(op);
        }
        else if (op == 1)
        {
            sign_up(name, password, role);
            bool check = signUp(name, password, role, namearray, passwordarray, rolearray, sized, indexCount);
            if (check)
            {
                sign_string(name, password, role, namearray, passwordarray, rolearray, indexCount);
                setcolor(11);
                cout << endl;
                cout << "\t\tYou Have Successfully SignedUp" << endl;
                cout << endl;
                // getch();
                setcolor(15);
                cout << "Press any key to continue....";
                getch();
            }
            else
            {
                setcolor(12);
                cout << endl;
                cout << "\t\tSignUp failed." << endl;
                cout << endl;
                // getch();
                setcolor(15);
                cout << "Press any key to continue....";
                getch();
            }
            op = 0;
        }
        else if (op == 2)
        {
            cout << "\t\t\tEnter your name: ";
            cin >> name;
            cout << "\t\t\tEnter your password: ";
            cin >> password;

            login(name, password, role_check, namearray, passwordarray, rolearray, indexCount);
            Sleep(1000);
            op = 0;
            if (role_check == "admin")
            {
                system("cls");
                topHeader();

                while (op != 10)
                {
                    int op = 0;
                    if (op == 0)
                    {
                        system("cls");
                        topHeader();
                        page_of_admin();
                        op = choiceCheck(op);
                    }

                    if (op == 1)
                    {

                        system("cls");
                        add_flight(ticket_route, ticket_price, ticket_seat_Num, ticket_time, idx_ticket, op);
                    }
                    if (op == 2)
                    {

                        system("cls");
                        delete_flight(ticket_price, ticket_route, ticket_seat_Num, ticket_time, idx_ticket);
                    }
                    if (op == 3)
                    {
                        system("cls");
                        employee_add(employee_name, employee_age, employee_num, employee_salary, idx_employee);
                    }
                    if (op == 4)
                    {
                        system("cls");
                        delete_employee(employee_name, employee_age, employee_num, idx_employee);
                    }
                    if (op == 5)
                    {
                        system("cls");
                        addPlaneInfo(Plane_id, Plane_Type, Plane_Capacity, fuel_Capacity, Plane_Range, planeCount, planeSize);
                    }
                    if (op == 6)
                    {
                        system("cls");
                        view_customer_complains(customer_name, customer_number, complain, idx_complian);
                    }
                    if (op == 7)
                    {
                        system("cls");
                        totalAmountEarned(ticket_price, idx_ticket);
                    }
                    if (op == 8)
                    {
                        system("cls");
                        view_flights(ticket_price, ticket_route, ticket_seat_Num, ticket_time, idx_ticket);
                    }
                    if (op == 9)
                    {
                        system("cls");
                        changeTicketPrice(ticket_price, idx_ticket, ticket_route, ticket_time, ticket_seat_Num);
                    }
                    if (op == 11)
                    {
                        op = 10;
                        role_check = "";
                        break;
                    }
                }
                op = 0;
            }
            /////////////////////////////////////////////////////////////////////////customeer///////////////////////////////////////////////////
            if (role_check == "customer")
            {
                while (true)
                {

                    //////////////////////////////////////////////////////add functions for customer///////////////////////////////////////////////////////////////////////
                    int op = 0;
                    if (op == 0)
                    {
                        system("cls");
                        topHeader();
                        customer_page();
                        op = choiceCheck(op);
                    }
                    if (op == 1)
                    {
                        system("cls");
                        view_flights(ticket_price, ticket_route, ticket_seat_Num, ticket_time, idx_ticket);
                        getch();
                    }
                    else if (op == 2)
                    {
                        system("cls");
                        reserves_seat(ticket_route, ticket_seat_Num, idx_ticket, reserve_seat, seatsused, ticket_price);
                    }
                    else if (op == 3)
                    {
                        system("cls");
                        search_flight(ticket_route, ticket_price, ticket_seat_Num, ticket_time, idx_ticket, planeSize);
                    }
                    else if (op == 4)
                    {
                        system("cls");
                        view_reserved_flights(ticket_route, ticket_seat_Num, idx_ticket, reserve_seat, seatsused);
                        getch();
                    }

                    else if (op == 5)
                    {
                        system("cls");
                        add_complains(customer_name, customer_number, complain, idx_complian);
                    }
                    else if (op == 6)
                    {
                        int idx_ticket1 = 0;
                        cancelflight(ticket_route, ticket_seat_Num, idx_ticket, reserve_seat, seatsused, ticket_price, idx_ticket1);
                    }
                    else if (op == 7)
                    {
                        system("cls");
                        confirm_payment(ticket_route, ticket_seat_Num, idx_ticket, reserve_seat, seatsused, ticket_price, idx_ticket);
                    }
                    else if (op == 8)
                    {
                        displayAllPlanes(Plane_id, Plane_Type, Plane_Capacity, fuel_Capacity, Plane_Range, Plane_status, planeCount);
                        getch();
                    }
                    else if (op == 9)
                    {
                        system("cls");
                        changeUserPassword(namearray, passwordarray, rolearray, indexCount, pass);
                    }
                    else if (op == 10)
                    {
                        op = 0;
                        role_check = "";
                        break;
                    }
                }
                op = 0;
            }
        }
        else
        {
            cout << "Invalid option" << endl;
            op = 0;
            Sleep(700);
        }
    }
    storelogin(namearray, passwordarray, rolearray, indexCount);
    storeflight(ticket_route, ticket_price, ticket_seat_Num, ticket_time, idx_ticket);
    store_employee(employee_name, employee_age, employee_num, employee_salary, idx_employee);
    storeplanes(Plane_id, Plane_Type, Plane_Capacity, fuel_Capacity, Plane_Range, planeCount);
    store_customercomplain(customer_name, customer_number, complain, idx_complian);

    system("cls");
    return 0;
}
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}
bool signUp(string name, string password, string role, string namearray[], string passwordarray[], string rolearray[], int sized, int &indexcount)
{
    bool check = true;
    for (int i = 0; i < indexcount; i++)
    {
        if (namearray[i] == name && passwordarray[i] == password)
        {
            check = false;
        }
    }
    if ((role != "admin") && (role != "customer"))
    {
        check = false;
    }

    if (check)
    {
        if (indexcount <= sized)
        {
            namearray[indexcount] = name;
            passwordarray[indexcount] = password;
            rolearray[indexcount] = role;
            indexcount++;
        }
    }
    return check;
}
int INTVALIDATION(string command)
{
AGAIN:
    int temp = 0;
    string input;
    cout << command;
    cin >> input;
    try
    {
        temp = stoi(input);
    }
    catch (invalid_argument)
    {
        cout << "Invalid input" << endl;
        Sleep(700);
        goto AGAIN;
    }
    return temp;
}
//                                                                change user name password
void changeUserPassword(string username[], string userPassword[], string userRole[], int size, int &usercount)
{
    string name;
    string password;
    cout << "   Enter Current Name:  ";
    name = isAlpha(name);
    cout << "   Enter Current Password:  ";
    password = passwordlength(password);

    bool check = true;
    for (int i = 0; i < usercount; i++)
    {
        if (username[i] == name && userPassword[i] == password)
        {
            cout << endl;
            cout << "Choose what to change:\n";
            cout << "1. Change Username\n";
            cout << "2. Change Password\n";
            cout << "3. Exit\n";
            cout << "Enter your choice (1 or 2 or 3): ";
            string op;
            cin >> op;
            string newName, newPassword;
            if (op == "1")
            {
                cout << "   Enter name:  ";
                username[i] = isAlpha(newName);
                setcolor(11);
                cout << "Username changed successfully.\n";
                setcolor(15);
            }
            else if (op == "2")
            {
                cout << "   Enter new Password:  ";
                userPassword[i] = passwordlength(newPassword);
                setcolor(11);
                cout << "Password changed successfully.\n";
                setcolor(15);
            }
            else if (op == "3")
            {
                // cout << "Press any key to exit....";
                // getch();
                // return; g
                goto last;
            }
            else
            {
                cout << "Invalid choice. No changes made.\n";
            }
            check = false;
        }
    }
    if (check)
    {
        setcolor(12);
        cout << endl;
        cout << "   User not found. No changes made" << endl;
        setcolor(15);
    }
last:
    cout << endl;
    cout << "   Press any key to Exit:   ";
    getch();
    return;
}
void login(string &name, string &password, string &role_check, string namearray[], string passwordarray[], string rolearray[], int &indexCount)
{
    if (log(name, password, namearray, passwordarray, indexCount))
    {
        system("cls");
        topHeader();
        cout << "Login successful!" << endl;
        int data_index = searchArray(namearray, name, indexCount);
        cout << "Welcome, " << namearray[data_index] << "!" << endl;
        cout << "Your role: " << rolearray[data_index] << endl;
        role_check = rolearray[data_index];
    }
    else
    {
        cout << "Login failed. User not found or incorrect password." << endl;
    }
}
string getData(string data, int index)
{
    string temp = "";
    int count = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == ',')
        {
            count++;
            continue;
        }
        else if (count == index)
        {
            temp += data[i];
        }
    }
    return temp;
}
//                                                                          login ends//
void topHeader()
{
    setcolor(3);
    cout << R"(             _    ___ ____  _     ___ _   _ _____           __  __    _    _   _    _    ____ __  __ _____ _   _ _____  )" << endl;
    cout << R"(            / \  |_ _|  _ \| |   |_ _| \ | | ____|         |  \/  |  / \  | \ | |  / \  / ___|  \/  | ____| \ | |_   _| )" << endl;
    cout << R"(           / _ \  | || |_) | |    | ||  \| |  _|           | |\/| | / _ \ |  \| | / _ \| |  _| |\/| |  _| |  \| | | |   )" << endl;
    cout << R"(          / ___ \ | ||  _ <| |___ | || |\  | |___          | |  | |/ ___ \| |\  |/ ___ \ |_| | |  | | |___| |\  | | |   )" << endl;
    cout << R"(         /_/   \_\___|_| \_\_____|___|_| \_|_____          |_|  |_/_/   \_\_| \_/_/   \_\____|_|  |_|_____|_| \_| |_|   )" << endl;
    cout << R"(                                ______   ______ _____ _____ __  __                                                      )" << endl;
    cout << R"(                               / ___\ \ / / ___|_   _| ____|  \/  |                                                     )" << endl;
    cout << R"(                               \___ \\ V /\___ \ | | |  _| | |\/| |                                                     )" << endl;
    cout << R"(                                ___) || |  ___) || | | |___| |  | |                                                     )" << endl;
    cout << R"(                               |____/ |_| |____/ |_| |_____|_|  |_|                                                     )" << endl;
}
//                                                                         top header ends/
void sign_page()
{

    setcolor(10);
    cout << "#########################################################################################################" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                       ##   ##  ### ###  ####      ## ##    ## ##   ##   ##  ### ###                   #" << endl;
    cout << "#                       ##   ##   ##       ##      ##       ##   ##  # ### #   ##                       #" << endl;
    cout << "#                       ##   ##   ##  ##   ##      ##   ##  ##   ##   ## ##    ##  ##                   #" << endl;
    cout << "#                       ## # ##   ## ##    ##      ##       ##   ##  ## # ##   ## ##                    #" << endl;
    cout << "#                       # ### #   ##       ##      ##       ##   ##  ##   ##   ##                       #" << endl;
    cout << "#                        ## ##    ##  ##   ##  ##  ##   ##  ##   ##  ##   ##   ##  ##                   #" << endl;
    cout << "#                       ##   ##  ### ###  ### ###   ## ##    ## ##   ##   ##  ### ###                   #" << endl;
    cout << "#########################################################################################################" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#              ##              ## ##     ####    ## ##   ###  ##  ##  ###  ### ##                       #" << endl;
    cout << "#             ###             ##   ##     ##    ##   ##    ## ##  ##   ##   ##  ##                      #" << endl;
    cout << "#              ##             ####        ##    ##        # ## #  ##   ##   ##  ##                      #" << endl;
    cout << "#              ##              #####      ##    ##  ###   ## ##   ##   ##   ##  ##                      #" << endl;
    cout << "#              ##                 ###     ##    ##   ##   ##  ##  ##   ##   ## ##                       #" << endl;
    cout << "#              ##             ##   ##     ##    ##   ##   ##  ##  ##   ##   ##                          #" << endl;
    cout << "#             ####             ## ##     ####    ## ##   ###  ##   ## ##   ####                         #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#               ##            ####       ## ##    ## ##  ####   ###   ##                                #" << endl;
    cout << "#             ## ##            ##       ##   ##  ##   ##   ##    ##   ##                                #" << endl;
    cout << "#            ##  ##            ##       ##   ##  ##   ##   ##     ##  ##                                #" << endl;
    cout << "#                ##            ##       ##   ##  ##        ##    # ##  #                                #" << endl;
    cout << "#              ##              ##       ##   ##  ##  ###   ##    ##  ###                                #" << endl;
    cout << "#            #   ##            ##   ##  ##   ##  ##   ##   ##    ##   ##                                #" << endl;
    cout << "#            ######            ### ###   ## ##    ## ##  ####   ###   ##                                #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#########################################################################################################" << endl;
}

//                                                                        sign in header ends
int choiceCheck(int op) // choice validation
{
    cout << "Enter your choice: ";
    cin >> op;
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong Option..." << endl;
            cout << "Enter Option: ";
            cin >> op;
        }
        if (!cin.fail())
        {
            break;
        }
    }
    return op;
}
// int input(int number)
//{
//
//     cout << "Enter your choice:";
//     cout << "or enter 3 to exit.....";
//     cin >> number;
//     return number;
// }

///                                                      functions that take choice to login as admin or cus ends/
void exit()
{
    system("cls");
    topHeader();
    setcolor(14);

    cout << R"(        ___________  __    __       __      _____  ___   __   ___   ________      )" << endl;
    cout << R"(        ("     _   ")/" |  | "\     /""\    (\"   \|"  \ |/"| /  ") /"       )    )" << endl;
    cout << R"(         )__/  \\__/(:  (__)  :)   /    \   |.\\   \    |(: |/   / (:   \___/     )" << endl;
    cout << R"(            \\_ /    \/      \/   /' /\  \  |: \.   \\  ||    /   \_  \       )" << endl;
    cout << R"(            |.  |    //  __  \\  //  __'  \ |.  \    \. |(// _  \    __/  \\      )" << endl;
    cout << R"(            \:  |   (:  (  )  :)/   /  \\  \|    \    \ ||: | \  \  /" \   :)     )" << endl;
    cout << R"(             \__|    \__|  |__/(___/    \___)\___|\____\)(__|  \__)(_______/      )" << endl;
}
/// evits page ends//
void sign_up(string &name, string &password, string &role)
{

    cout << "\t\tENTER YOUR USER NAME: ";
    name = isAlpha(name);

    cout << "\t\tENTER YOUR PASSWORD: ";
    password = passwordlength1(password);

    cout << "\t\tENTER ROLE(admin or customer): ";
    cin >> role;
    // if (role == "admin" || role == "customer")
    // {
    //     cout << "You have successfully signed up" << endl;
    // }
    // else
    // {
    //     cout << "\t\tYou have entered wrong role" << endl;
    //     cout << "\t\tEnter role again" << endl;
    //     cin >> role;
    // }
    // cout << "\t\tPRESS ANY KEY TO CONTINUE ";
    // getch();
}
///                                                                 function taking input for sin up ends/
int searchArray(string arr[], string object, int &indexCount)
{ // arr-->names and object---->username
    for (int i = 0; i <= indexCount; i++)
    {
        if (arr[i] == object)
        {
            return i;
        }
    }
    return -1;
}
//                                                                  this search the array gor login  ends here/
bool log(string name, string password, string namearray[], string passwordarray[], int &indexCount)
{

    int data_index = searchArray(namearray, name, indexCount);
    if (data_index == -1)
    {
        return false;
    }
    if (name == namearray[data_index] && password == passwordarray[data_index])
    {
        return true;
    }
    return false;
}
///                                                                         bool log ends here//

void sign_string(string name, string password, string role, string namearray[], string passwordarray[], string rolearray[], int &indexCount)
{
    namearray[indexCount] = name;
    passwordarray[indexCount] = password;
    rolearray[indexCount] = role;
    // cout << namearray[indexCount];
    indexCount++;
}
void page_of_admin()
{
    system("cls");
    topHeader();
    setcolor(2);
    // name_app();
    cout << "                                                                                           " << endl;
    cout << "                                                                                           " << endl;
    cout << "...................................ADMIN LOGIN PAGE........................................." << endl;
    cout << "|                                                                                          |" << endl;
    cout << "|         1--To add ticket ENTER 1:                                                        |" << endl; // ok
    cout << "|         2--To delete ticket ENTER 2:                                                     |" << endl; // ok
    cout << "|         3--To add new employ  ENTER 3                                                    |" << endl; // ok
    cout << "|         4--To delete new employ  ENTER 4                                                 |" << endl; // ok
    cout << "|         5--To add info of new plane  ENTER 5                                             |" << endl; // add
    cout << "|         6--To Check Complains  ENTER 6                                                   |" << endl; // ok
    cout << "|         7--To view total amount earned ENTER 7                                           |" << endl; // check
    cout << "|         8--To View flight details  ENTER 8                                               |" << endl;
    cout << "|         9--To Change price of ticket  ENTER 9                                            |" << endl; // check
    cout << "|         10-To                                                                            |" << endl;
    cout << "|         11-To Logout  ENTER 11                                                           |" << endl; // ok
    cout << "|         Enter your option here...                                                        |" << endl;
    cout << "|                                                                                          |" << endl;
    cout << "|__________________________________________________________________________________________|" << endl;

    // try to take it in main and pass by regerenvce to this function
}

void displayAllPlanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], string Plane_status[], int planeCount)
{
    system("cls");
    cout << "All Planes Details:" << endl;
    cout << "<-------------------------->" << endl;

    for (int i = 0; i < planeCount; i++)
    {
        cout << "Plane ID: " << Plane_id[i] << endl;
        cout << "Plane Type: " << Plane_Type[i] << endl;
        cout << "Plane Range: " << Plane_Range[i] << " miles" << endl;
        cout << "Plane Status: " << Plane_status[i] << endl;
        cout << "<-------------------------->" << endl;
    }
    cout << "Press any key to continue....";
    getch();
}
void add_flight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket, int &op) // validated
{
again:
    system("cls");
    topHeader();

    setcolor(1);
    cout << R"(                                                                                     )" << endl;
    cout << R"(                                                                                     )" << endl;
    cout << R"(    _    ____  ____    _____ _     ___ ____ _   _ _____   _   _ _____ ____  _____    )" << endl;
    cout << R"(   / \  |  _ \|  _ \  |  ___| |   |_ _/ ___| | | |_   _| | | | | ____|  _ \| ____|   )" << endl;
    cout << R"(  / _ \ | | | | | | | | |_  | |    | | |  _| |_| | | |   | |_| |  _| | |_) |  _|     )" << endl;
    cout << R"( / ___ \| |_| | |_| | |  _| | |___ | | |_| |  _  | | |   |  _  | |___|  _ <| |___    )" << endl;
    cout << R"(/_/   \_\____/|____/  |_|   |_____|___\____|_| |_| |_|   |_| |_|_____|_| \_\_____|   )" << endl;

    setcolor(2);

    cout << "Enter the route for the ticket: ";
    string route;
    route = isAlpha(route);

    cout << "Enter the time for the ticket in (24 hours format):  ";
    string time;
time:
    cin.clear();
    cin.sync();
    time = checkNumber(time);
    int temp = stoi(time);
    if (temp > 24)
    {
        cout << "Invalid time" << endl;
        cout << "Enter a valid time: ";
        goto time;
    }

    int seats;
    seats = INTVALIDATION("Enter the total number of seats: ");

    int price;
    price = INTVALIDATION("Enter the price of the ticket: RS");

    ticket_route[idx_ticket] = route;
    ticket_time[idx_ticket] = time;
    ticket_seat_Num[idx_ticket] = seats;
    ticket_price[idx_ticket] = price;
    idx_ticket++;

    string check_flight;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
again1:
    cout << "                                         " << endl;
    cout << "Enter 1 to add another ticket\n";
    cout << "Enter 2 to go back\n";

    cin >> check_flight;

    if (check_flight == "1")
    {
        system("cls");
        goto again;
    }
    else if (check_flight == "2")
    {

        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option..\n";
        goto again1;
        return;
    }
    getch();
}
// bool check_flight(string ticket_route[],string ticket_time[],string time,string route,int idx_ticket){
// for(int i=0;i<idx_ticket;i++){
//     if(ticket_route[i]==route && ticket_time[i]==time){
// return true;
//     }
//     else
//     return false;
// }
// }
void delete_flight(int ticket_price[], string ticket_route[], int ticket_seat_Num[], string ticket_time[], int idx_ticket)
{
again:
    setcolor(1);

    cout << R"(    ____  _____ _     _____ _____ _____   _____ _     ___ ____ _   _ _____   _   _ _____ ____  _____   )" << endl;
    cout << R"(   |  _ \| ____| |   | ____|_   _| ____| |  ___| |   |_ _/ ___| | | |_   _| | | | | ____|  _ \| ____   )" << endl;
    cout << R"(   | | | |  _| | |   |  _|   | | |  _|   | |_  | |    | | |  _| |_| | | |   | |_| |  _| | |_) |  _|    )" << endl;
    cout << R"(   | |_| | |___| |___| |___  | | | |___  |  _| | |___ | | |_| |  _  | | |   |  _  | |___|  _ <| |___   )" << endl;
    cout << R"(   |____/|_____|_____|_____| |_| |_____| |_|   |_____|___\____|_| |_| |_|   |_| |_|_____|_| \_\_____  )" << endl;
    cout << "                                                                                                           " << endl;
    cout << "                                                                                                           " << endl;
    cout << "                                                                                                           " << endl;
    cout << "                                                                                                           " << endl;
    setcolor(2);
    cout << setw(20) << setcolor(4) << "Flight Number" << setw(19) << setcolor(4) << "Route"
         << setw(21) << setcolor(4) << "Price" << setw(19) << setcolor(4) << "Price" << setw(20) << setcolor(4) << "Total seats" << endl;
    cout << "                                                                                                         " << endl;
    for (int i = 0; i < idx_ticket; i++)
    {
        if (ticket_route[i] != "")
        {

            cout << setw(25) << i + 1 << setw(30) << ticket_route[i]
                 << setw(25) << "$" + to_string(ticket_price[i]) << setw(30) << ticket_time[i]
                 << setw(25) << ticket_seat_Num[i] << endl;
            cout << "                                                                                                          " << endl;
        }
    }
    cout << "Enter the flight number you want to delete: ";
    cout << " " << endl;
    cout << "press 0 to return.....";
    int flight_num;
    cin >> flight_num;
    // Idhar say change start howay
    flight_num--;
    // ticket_route[flight_num] = "";
    for (int i = flight_num; i < idx_ticket; i++)
    {
        ticket_route[i] = ticket_route[i + 1];
        ticket_time[i] = ticket_time[i + 1];
        ticket_seat_Num[i] = ticket_seat_Num[i + 1];
        ticket_price[i] = ticket_price[i + 1];
    }

    for (int i = 0; i < idx_ticket; i++)
    {
        if (ticket_route[i] != "")
        {
            cout << " flight Number " << i + 1 << endl;
            cout << ticket_route[i] << endl;
            cout << ticket_price[i] << endl;
            cout << ticket_time[i] << endl;
            cout << ticket_seat_Num[i] << endl;
        }
    }
    cout << endl;
    string addMore_employee;
again2:
    cout << "                                         " << endl;
    cout << "Enter 1 to delete another employee: \n";
    cout << "Enter 2 to go back: \n";
    cin >> addMore_employee;
    if (addMore_employee == "1")
    {
        goto again;
    }
    else if (addMore_employee == "2")
    {
        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option. \n";
        goto again2;
        return;
    }
    getch();
}
void employee_add(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee) // validated
{
again:
    system("cls");
    setcolor(1);

    cout << R"(      _    ____  ____         _____ __  __ ____  _     _____   _______ _____  )" << endl;
    cout << R"(     / \  |  _ \|  _ \       | ____|  \/  |  _ \| |   / _ \ \ / / ____| ____| )" << endl;
    cout << R"(    / _ \ | | | | | | |      |  _| | |\/| | |_) | |  | | | \ V /|  _| |  _|   )" << endl;
    cout << R"(   / ___ \| |_| | |_| |      | |___| |  | |  __/| |__| |_| || | | |___| |___  )" << endl;
    cout << R"(  /_/   \_\____/|____/       |_____|_|  |_|_|   |_____\___/ |_| |_____|_____  )" << endl;

    setcolor(2);

    string name, age, contact;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Enter the name of employee: ";
    cin.ignore();
    name = isAlpha(name); // name and city validation

    cout << "Enter the age of employee: ";
ageC:
    age = checkNumber(age); // age validation
    int ageCheck = stoi(age);
    if (ageCheck < 18 || ageCheck > 60)
    {
        cout << endl;
        cout << "Wrong Input...." << endl;
        cout << "Enter age again....";
        goto ageC;
    }

    cout << "Enter the contact number of employee: ";
    contact = contactCheck(contact); // contact validation

    cout << "Enter the salary of employee: "
         << "Rs ";
    string salary;
    salary = checkNumber(salary); // price

    employee_name[idx_employee] = name;
    employee_age[idx_employee] = age;
    employee_num[idx_employee] = contact;
    employee_salary[idx_employee] = salary;
    idx_employee++;

    string addMore_employee;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
again2:
    cout << "                                         " << endl;
    cout << "Enter 1 to add another employee\n";
    cout << "Enter 2 to go back\n";
    cin >> addMore_employee;
    if (addMore_employee == "1")
    {
        goto again;
    }
    else if (addMore_employee == "2")
    {
        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option. \n";
        goto again2;
        return;
    }
    getch();
}

void delete_employee(string employee_name[], string employee_age[], string employee_num[], int idx_employee)
{
again:
    setcolor(1);

    cout << R"(   ____  _____ _     _____ _____ _____   _____ __  __ ____  _     _____   _______ _____   )" << endl;
    cout << R"(  |  _ \| ____| |   | ____|_   _| ____| | ____|  \/  |  _ \| |   / _ \ \ / / ____| ____|  )" << endl;
    cout << R"(  | | | |  _| | |   |  _|   | | |  _|   |  _| | |\/| | |_) | |  | | | \ V /|  _| |  _|    )" << endl;
    cout << R"(  | |_| | |___| |___| |___  | | | |___  | |___| |  | |  __/| |__| |_| || | | |___| |___   )" << endl;
    cout << R"(  |____/|_____|_____|_____| |_| |_____| |_____|_|  |_|_|   |_____\___/ |_| |_____|_____|  )" << endl;
    setcolor(2);

    for (int i = 0; i < idx_employee; i++)
    {
        if (employee_name[i] != "")
        {
            cout << " Employee Number " << i + 1 << endl;
            cout << employee_name[i] << endl;
            cout << employee_age[i] << endl;
            cout << employee_num[i] << endl;
        }
    }

    cout << "Enter the Employee number you want to delete: ";
    cout << "" << endl;
    cout << "press 0 to return.....";
    int employee_num1;
    cin >> employee_num1;
    employee_num1--;
    // employee_name[employee_num1 - 1] = "";
    for (int i = 0; i < idx_employee; i++)
    {
        employee_name[i] = employee_name[i + 1];
        employee_age[i] = employee_age[i + 1];
        employee_num[i] = employee_num[i + 1];
    }
    for (int i = 0; i < idx_employee; i++)
    {
        if (employee_name[i] != "")
        {
            cout << " Employee Number " << i + 1 << endl;
            cout << employee_name[i] << endl;
            cout << employee_age[i] << endl;
            cout << employee_num[i] << endl;
        }
    }
    cout << "" << endl;
    string delMore_employee;
again2:
    cout << "                                         " << endl;
    cout << "Enter 1 to delete another employee: \n";
    cout << "Enter 2 to go back: \n";
    cin >> delMore_employee;
    if (delMore_employee == "1")
    {
        goto again;
    }
    else if (delMore_employee == "2")
    {
        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option. \n";
        goto again2;
        return;
    }
    getch();
}

void view_customer_complains(string customer_name[], string customer_number[], string complain[], int idx_complian)
{

    setcolor(1);
    cout << R"(     ____ _   _ ____ _____ ___  __  __ _____ ____        ____ ___  __  __ ____  _        _    ___ _   _ ____      )" << endl;
    cout << R"(    / ___| | | / ___|_   _/ _ \|  \/  | ____|  _ \      / ___/ _ \|  \/  |  _ \| |      / \  |_ _| \ | / ___|     )" << endl;
    cout << R"(   | |   | | | \___ \ | || | | | |\/| |  _| | |_) |    | |  | | | | |\/| | |_) | |     / _ \  | ||  \| \___ \     )" << endl;
    cout << R"(   | |___| |_| |___) || || |_| | |  | | |___|  _ <     | |__| |_| | |  | |  __/| |___ / ___ \ | || |\  |___) |    )" << endl;
    cout << R"(    \____|\___/|____/ |_| \___/|_|  |_|_____|_| \_\     \____\___/|_|  |_|_|   |_____/_/   \_\___|_| \_|____/     )" << endl;

    setcolor(2);

    for (int i = 0; i < idx_complian; i++)
    {
        if (customer_name[i] != "")
        {
            cout << "..............................Complain number :" << i + 1 << endl;
            cout << ".Name of customer :" << customer_name[i] << endl; ///////////////not imolemented yet///////////////////////
            cout << ".Customer mobile number: " << customer_number[i] << endl;
            cout << "..............................Complian for customer is given as.......................\n";
            cout << complain[i];
            cout << "";
        }
    }
    getch();
}
void totalAmountEarned(int ticket_price[], int idx_ticket)
{
    int total = 0;
    for (int i = 0; i < idx_ticket; i++)
    {
        total = total + ticket_price[i];
    }
    cout << "Total amount earned is: " << total << endl;
    getch();
}
void changeTicketPrice(int ticket_price[], int idx_ticket, string ticket_route[], string ticket_time[], int ticket_seat_Num[])
{
    view_flights(ticket_price, ticket_route, ticket_seat_Num, ticket_time, idx_ticket);

    int flight_num;
    cout << "Enter the flight number you want to change the price of: ";
    cin >> flight_num;
    cout << "Enter the new price: ";
    int new_price;
    new_price = INTVALIDATION("Enter the new price: ");
    ticket_price[flight_num - 1] = new_price;
    cout << "Price changed successfully!" << endl;
}
void addPlaneInfo(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount, int planeSize)
{
again:
    setcolor(1);
    cout << "Enter Plane Details:- " << endl;
    cout << "<-------------------------->" << endl;
    setcolor(15);
    cout << "Plane ID in numbers only:   ";
    string plane_id;
    plane_id = checkNumber(plane_id);

    cout << "Plane Number:    ";
    string planeType;
    planeType = checkNumber(planeType);

    cout << "Plane Capacity:   ";
    string planeCapacity;
    planeCapacity = checkNumber(planeCapacity);

    cout << "Fuel Capacity (in litres) :    ";
    string fuelcapacity;
    fuelcapacity = checkNumber(fuelcapacity);
    cout << "Palne Range (in miles):  ";
    string planeRange;
    planeRange = checkNumber(planeRange);

    bool check = addPlane(plane_id, planeType, planeCapacity, planeRange, fuelcapacity, Plane_id, Plane_Type, Plane_Capacity, fuel_Capacity, Plane_Range, planeCount, planeSize);
    if (check)
    {
        setcolor(3);
        cout << "Plane added Successfully " << endl;
        setcolor(15);
    }

    if (!check)
    {
        setcolor(4);
        cout << "Error! Plane not added." << endl;
        setcolor(15);
    }

    string check_flight;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
again1:
    cout << "                                         " << endl;
    cout << "Enter 1 to add another ticket\n";
    cout << "Enter 2 to go back\n";

    cin >> check_flight;

    if (check_flight == "1")
    {
        system("cls");
        goto again;
    }
    else if (check_flight == "2")
    {

        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option..\n";
        goto again1;
        return;
    }
    getch();
}
bool addPlane(string plane_id, string planeType, string planecapacity, string planeRange, string fuelcapacity, string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount, int planeSize)
{
    bool check = true;
    for (int i = 0; i < planeCount; i++)
    {
        if (plane_id == Plane_id[i] && planeType == Plane_Type[i])
        {
            check = false;
        }
    }
    if (check == true)
    {
        if (planeCount < planeSize)
        {
            Plane_id[planeCount] = plane_id;
            Plane_Type[planeCount] = planeType;
            Plane_Capacity[planeCount] = planecapacity;
            fuel_Capacity[planeCount] = fuelcapacity;
            Plane_Range[planeCount] = planeRange;

            planeCount++;
        }
    }
    return check;
}
void customer_page()
{
    setcolor(2);
    cout << endl;
    cout << endl;
    cout << " __________________________________________________________________________________" << endl;
    cout << "|                                                                                  |" << endl;
    cout << R"(|    _____ _   _ _____ _____ ________  ___ ___________  ______  ___  _____  _____  |)" << endl;
    cout << R"(|  /  __ \ | | /  ___|_   _|  _  |  \/  ||  ___| ___ \ | ___ \/ _ \|  __ \|  ___|  |)" << endl;
    cout << R"(|  | /  \/ | | \ `--.  | | | | | | .  . || |__ | |_/ / | |_/ / /_\ \ |  \/| |__    |)" << endl;
    cout << R"(|  | |   | | | |`--. \ | | | | | | |\/| ||  __||    /  |  __/|  _  | | __ |  __|   |)" << endl;
    cout << R"(|  | \__/\ |_| /\__/ / | | \ \_/ / |  | || |___| |\ \  | |   | | | | |_\ \| |___   |)" << endl;
    cout << R"(|   \____/\___/\____/  \_/  \___/\_|  |_/\____/\_| \_| \_|   \_| |_/\____/\____/   |)" << endl;
    cout << "|__________________________________________________________________________________|" << endl;
    cout << "|                                                                                  |" << endl;
    cout << "|            Enter option 1 to view flights..                                      |" << endl; // ok
    cout << "|            Enter option 2 to buy ticket                                          |" << endl; // ok
    cout << "|            Enter option 3 to search flight..                                     |" << endl; // ok
    cout << "|            Enter option 4 to view your tickets                                   |" << endl; // ok
    cout << "|            Enter option 5 to add complains..                                     |" << endl; // ok
    cout << "|            Enter option 6 to cancel flight                                       |" << endl;
    cout << "|            Enter option 7 to..Confirm Payment                                    |" << endl; // check
    cout << "|            Enter option 8 to view airplanes                                      |" << endl;
    cout << "|            Enter option 9 to chang password                                      |" << endl;
    cout << "|            Enter option 10 to logout                                             |" << endl; // ok
    cout << "|                                                                                  |" << endl;
    cout << "|__________________________________________________________________________________|" << endl;
}
void view_flights(int ticket_price[], string ticket_route[], int ticket_seat_Num[], string ticket_time[], int idx_ticket)
{
    setcolor(1);
    cout << R"(   _____ _     ___ ____ _   _ _____ ____    ____  _____ _____  _    ___ _     ____    )" << endl;
    cout << R"(  |  ___| |   |_ _/ ___| | | |_   _/ ___|  |  _ \| ____|_   _|/ \  |_ _| |   / ___|   )" << endl;
    cout << R"(  | |_  | |    | | |  _| |_| | | | \___ \  | | | |  _|   | | / _ \  | || |   \___ \   )" << endl;
    cout << R"(  |  _| | |___ | | |_| |  _  | | |  ___) | | |_| | |___  | |/ ___ \ | || |___ ___) |  )" << endl;
    cout << R"(  |_|   |_____|___\____|_| |_| |_| |____/  |____/|_____| |_/_/   \_\___|_____|____/   )" << endl;
    cout << "                                                                                             " << endl;
    cout << "                                                                                             " << endl;
    cout << "                                                                                             " << endl;
    cout << "                                                                                             " << endl;
    cout << "                                                                                             " << endl;
    cout << "                                                                                             " << endl;
    setcolor(2);

    cout << setw(20) << setcolor(4) << "Flight Number" << setw(20) << setcolor(4) << "Route"
         << setw(21) << setcolor(4) << "Price" << setw(19) << setcolor(4) << "Time" << setw(20) << setcolor(4) << "Seat Number" << endl;
    cout << "                                                                                                         " << endl;
    for (int i = 0; i < idx_ticket; i++)
    {
        if (ticket_route[i] != "")
        {
            cout << setw(25) << i + 1 << setw(30) << ticket_route[i]
                 << setw(25) << "$" + to_string(ticket_price[i]) << setw(30) << ticket_time[i]
                 << setw(25) << ticket_seat_Num[i] << endl;
            cout << "                                                                                                         " << endl;
        }
    }
    cout << "Press any key to continue:  ";
    getch();
}
void add_complains(string customer_name[], string customer_number[], string complain[], int &idx_complian)
{
again:

    setcolor(1);
    cout << R"(       _    ____  ____                ____ ___  __  __ ____  _        _    ___ _   _ ____  )" << endl;
    cout << R"(      / \  |  _ \|  _ \              / ___/ _ \|  \/  |  _ \| |      / \  |_ _| \ | / ___| )" << endl;
    cout << R"(     / _ \ | | | | | | |            | |  | | | | |\/| | |_) | |     / _ \  | ||  \| \___ \ )" << endl;
    cout << R"(    / ___ \| |_| | |_| |            | |__| |_| | |  | |  __/| |___ / ___ \ | || |\  |___) |)" << endl;
    cout << R"(   /_/   \_\____/|____/              \____\___/|_|  |_|_|   |_____/_/   \_\___|_| \_|____/ )" << endl;

    setcolor(2);

    cout << "Enter your name : ";
    string name;
    name = isAlpha(name);
    cout << "Enter you contact number:";
    string number; ///////////////////////////////not implemented yet///////////////////////////
    number = contactCheck(number);

    cout << "Enter your complain here: ";
    string complian;
    cin.ignore();
    getline(cin, complian);

    customer_name[idx_complian] = name;
    customer_number[idx_complian] = number;
    complain[idx_complian] = complian;
    idx_complian++;

    string check_com;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
again1:
    cout << "                                         " << endl;
    cout << "Enter 1 to add another complain\n";
    cout << "Enter 2 to go back\n";
    cin >> check_com;

    if (check_com == "1")
    {
        goto again;
    }
    else if (check_com == "2")
    {
        return;
    }
    else
    {
        system("cls");
        topHeader();
        cout << "Invalid option. .\n";
        goto again1;

        return;
    }
    getch();
}

void search_flight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket, int size)
{
    setcolor(1);

    cout << R"(           ____  _____    _    ____   ____ _   _             _____ _     ___ ____ _   _ _____     )" << endl;
    cout << R"(          / ___|| ____|  / \  |  _ \ / ___| | | |           |  ___| |   |_ _/ ___| | | |_   _|    )" << endl;
    cout << R"(          \___ \|  _|   / _ \ | |_) | |   | |_| |           | |_  | |    | | |  _| |_| | | |      )" << endl;
    cout << R"(           ___) | |___ / ___ \|  _ <| |___|  _  |           |  _| | |___ | | |_| |  _  | | |      )" << endl;
    cout << R"(          |____/|_____/_/   \_\_| \_\\____|_| |_|           |_|   |_____|___\____|_| |_| |_|      )" << endl;

    setcolor(2);

    cout << "\tEnter the route of flight you want to search.......: ";
    string route;
    cin >> route;
    for (int i = 0; i < size; ++i)
    {
        if (ticket_route[i] == route)
        {
            // Display the flight information
            cout << endl;
            cout << "\t\tFlight Details:" << endl;
            cout << "\t\tRoute: " << ticket_route[i] << endl;
            cout << "\t\tTime: " << ticket_time[i] << endl;
            cout << "\t\tSeat Number: " << ticket_seat_Num[i] << endl;
            cout << "\t\tPrice: $" << ticket_price[i] << endl;
        }
    }
    cout << "Press any key to continue:  ";
    getch();
}
void reserves_seat(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[])
{
    view_flights(ticket_price, flight_names, ticket_seat_Num, flight_names, idx_ticket);
    cout << "" << endl;
    cout << "" << endl;
    cout << "Enter the Flight Route you want to reserve a seat for: ";
    string flightName;
    flightName = isAlpha(flightName);

    int seatNum;
    seatNum = INTVALIDATION("Enter the seat number you want to reserve: ");

    bool flightFound = false;
    bool seatAvailable = false;

    for (int i = 0; i < idx_ticket; i++)
    {
        if (flight_names[i] == flightName && ticket_seat_Num[i] > 0 && ticket_seat_Num[i] - seatNum >= 0)
        {
            flightFound = true;
            seatAvailable = true;
            ticket_seat_Num[i] -= seatNum;
            seatsused[i] = seatNum;
            reserve_seat[i] = true;
            total += seatNum * ticket_price[i]; /// added
            break;
        }
    }

    if (flightFound)
    {
        if (seatAvailable)
        {
            setcolor(100);
            cout << "Seat " << seatNum << " on flight " << flightName << " reserved successfully!" << endl;
        }
        else
        {
            cout << "Seat " << seatNum << " on flight " << flightName << " is not available." << endl;
        }
    }
    else
    {
        cout << "Flight " << flightName << " not found." << endl;
    }
    cout << "Press any key to continue:  ";
    getch();
}
void view_reserved_flights(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[])
{
    cout << "Reserved Flights:" << endl;
    for (int i = 0; i < idx_ticket; i++)
    {
        if (reserve_seat[i])
        {
            cout << "Flight: " << flight_names[i] << ", Reserved Seats: " << seatsused[i] << endl;
        }
        else
        {
            cout << "No flights have been reserved." << endl;
        }
    }
    cout << "Press any key to continue:  ";
    getch();
}
void available_seats(string flight_names[], int seatsused[], int idx_ticket)
{
    cout << "Enter the route for which you want to check: ";
    string route;
    route = isAlpha(route);
    for (int i = 0; i < idx_ticket; i++)
    {
        if (flight_names[i] == route)
        {
            cout << seatsused[i];
        }
    }
}
void change_pass(string namearray[], string passwordarray[], int pass)
{

    cout << "Enter your existing password: ";
    string oldpass;
    oldpass = passwordlength1(oldpass);
    cout << "                                ";
    cout << "Enter your new password: ";
    string newpass;
    newpass = passwordlength1(newpass);
    for (int i = 0; i < pass; i++)
    {
        if (passwordarray[i] == oldpass)
        {
            passwordarray[i] = newpass;
        }
        else
            cout << "Incorect password  ";
    }
}
void confirm_payment(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[], int &idx_ticket1)
{
    view_flights(ticket_price, flight_names, ticket_seat_Num, flight_names, idx_ticket);
    cout << "" << endl;
    cout << "Enter the route name  for which you want to confirm payment: ";
    string route;
    route = isAlpha(route);
    for (int i = 0; i < idx_ticket; i++)
    {
        if (flight_names[i] == route)
        {

            int amount;
            amount = INTVALIDATION("Enter the amount you want to pay: ");
            if (amount == ticket_price[i])
            {
                cout << "Payment confirmed";
                ticket_seat_Num[i] -= seatsused[i];
                reserve_seat[i] = false;
                seatsused[i] = 0;
                idx_ticket1++;
            }
            else
                cout << "Payment not confirmed";
        }
    }
    cout << "Press any key to continue:  ";
    getch();
}
void cancelflight(string flight_names[], int ticket_seat_Num[], int idx_ticket, bool reserve_seat[], int seatsused[], int ticket_price[], int &idx_ticket1)
{
    view_flights(ticket_price, flight_names, ticket_seat_Num, flight_names, idx_ticket);
    cout << "" << endl;
    cout << "Enter the route for which you want to cancel flight: ";
    string route;
    route = isAlpha(route);
    for (int i = 0; i < idx_ticket; i++)
    {
        if (flight_names[i] == route)
        {

            int amount;
            amount = INTVALIDATION("Enter the amount you want to pay: ");

            if (amount == ticket_price[i])
            {
                cout << "Flight cancelled";
                ticket_seat_Num[i] += seatsused[i];
                reserve_seat[i] = false;
                seatsused[i] = 0;
                idx_ticket1--;
            }
            else
                cout << "Flight not cancelled";
        }
    }
    cout << "Press any key to continue:  ";
    getch();
}
string contactCheck(string contact) // contact validation
{
    cin >> contact;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = contact.length();
        for (int i = 0; i < size; i++)
        {
            if (contact[i] != ' ')
            {
                check = int(contact[i]);
                if ((check >= 48 && check <= 57) && (size == 11))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            return contact;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Wrong Contact info..." << endl;
            cout << "Enter Contact No (11 numbers): ";
            cin >> contact;
        }
    }
}
string isNum(string input) // age validation
{

    cin >> input;
    int x;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            if (input[i] != ' ')
            {
                check = int(input[i]);
                if ((check >= 48 && check <= 57))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            x = stoi(input);
            if (x >= 18 && x <= 60)
            {
                return input;
            }
            else
            {
                cin.clear();
                cin.sync();
                cout << "Wrong Age..." << endl;
                cout << "Enter age: ";
                cin >> input;
            }
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Wrong Age..." << endl;
            cout << "Enter age: ";
            cin >> input;
        }
    }
    return 0;
}
string isAlpha(string input) // name and city validation
{

    cin.clear();
    cin.sync();
    getline(cin >> ws, input);
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            check = int(input[i]);
            if ((check >= 65 && check <= 90) || (check >= 97 && check <= 122) || input[i] == ' ')
            {
                flap = true;
            }
            else
            {
                flap = false;
                break;
            }
        }
        if (flap == true)
        {
            return input;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input..." << endl;
            cout << "Enter Again: ";
            getline(cin >> ws, input);
        }
    }
}
string passwordlength(string anypass)
{
    cin >> anypass;
    int size;
    while (true)
    {
        size = anypass.length();
        if (size <= 8 && size >= 4)
        {

            return anypass;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Password must not be greater than 8 characters long" << endl;
            cout << "Enter password again: ";
            cin >> anypass;
        }
    }
    return 0;
}
string isNum1(string input) // price
{

    cin >> input;
    int x;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            if (input[i] != ' ')
            {
                check = int(input[i]);
                if ((check >= 48 && check <= 57))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            x = stoi(input);
            if (x >= 1 && x <= 5000000)
            {
                return input;
            }
            else
            {
                cin.clear();
                cin.sync();
                cout << "Wrong input..." << endl;
                cout << "Enter salary: ";
                cin >> input;
            }
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input..." << endl;
            cout << "Enter salary: ";
            cin >> input;
        }
    }
    return 0;
}
// void view_account_info(string customer_name[], string customer_number[], string complain[], int &idx_complian){
//             cout<<"Enter your name: ";
//             string name;
//             cin>>name;
//             cout<<"Enter your number: ";
//             string number;
//             cin>>number;
//             for(int i=0;i<idx_complian;i++){
//                 if(customer_name[i]==name && customer_number[i]==number){
//                     cout<<"Name: "<<customer_name[i]<<endl;
//                     cout<<"Number: "<<customer_number[i]<<endl;
//                     cout<<"Complain: "<<complain[i]<<endl;
//                 }
//             }
//         }
// void ratingofapp(){
//     cout<<"Enter your rating of app in stars: ";
//     int stars;
//     cin>>stars;
//     if(stars==5){
//         cout<<"Thank you for your rating";
//     }
//     else if(stars==4){
//         cout<<"Thank you for your rating";
//     }
//     else if(stars==3){
//         cout<<"Thank you for your rating";
//     }
//     else if(stars==2){
//         cout<<"Thank you for your rating";
//     }
//     else if(stars==1){
//         cout<<"Thank you for your rating";
//     }
//     else
//     cout<<"Invalid rating";
// }
// string pilot_name[];
// string pilot_age[];
// string pilot_number[];
// string pilot_salary[];
// int idx_pilot;
// void pilots_details(string pilot_name[],string pilot_age[],string pilot_number[],string pilot_salary[],int &idx_pilot){
//     cout<<"Enter the name of pilot: ";
//     string name;
//     cin>>name;
//     cout<<"Enter the age of pilot: ";
//     string age;
//     cin>>age;
//     cout<<"Enter the number of pilot: ";
//     string number;
//     cin>>number;
//     cout<<"Enter the salary of pilot: ";
//     string salary;
//     cin>>salary;
//     pilot_name[idx_pilot]=name;
//     pilot_age[idx_pilot]=age;
//     pilot_number[idx_pilot]=number;
//     pilot_salary[idx_pilot]=salary;
//     idx_pilot++;
// }
// int bagcharges[100];
// int idx_bag;
//    void baggagehandlinginfo(){
//        cout<<"Enter the weight of baggage: ";
//        int weight;
//        cin>>weight;
//        if(weight<=20){
//            cout<<"No extra charges";
//        }
//        else if(weight>20 && weight<=30){
//            cout<<"Extra charges are 10$";
//        }
//        else if(weight>30 && weight<=40){
//            cout<<"Extra charges are 20$";
//        }
//        else if(weight>40 && weight<=50){
//            cout<<"Extra charges are 30$";
//        }
//        else if(weight>50 && weight<=60){
//            cout<<"Extra charges are 40$";
//        }
//        else if(weight>60 && weight<=70){
//            cout<<"Extra charges are 50$";
//        }
//        else if(weight>70 && weight<=80){
//            cout<<"Extra charges are 60$";
//        }
//        else if(weight>80 && weight<=90){
//            cout<<"Extra charges are 70$";
//        }
//        else if(weight>90 && weight<=100){
//            cout<<"Extra charges are 80$";
//        }
//        else if(weight>100 && weight<=110){
//            cout<<"Extra charges are 90$";
//        }
//        else if(weight>110 && weight<=120){
//            cout<<"Extra charges are 100$";
//        }
//        else if(weight>120 && weight<=130){
//            cout<<"Extra charges are 110$";
//        }
//        else if(weight>130 && weight<=140){
//            cout<<"Extra charges are 120$";
//        }
//        else if(weight>140 && weight<=150){
//            cout<<"Extra charges are 130$";
//        }
//        else if(weight>150 && weight<=160){
//            cout<<"Extra charges are 140$";
//        }
//        else if(weight>160 && weight<=170){
//            cout<<"Extra charges are 150$";
//        }
//        else if(weight>170 && weight<=180){
//            cout<<"Extra charges are 160$";
//        }
//        else if(weight>180 && weight<=190){
//            cout<<"Extra charges are 170$";
//        }
//        else if(weight>190 && weight<=200){
//            cout<<"Extra charges are 180$";
//        }
//        else if(weight>200 && weight<=210){
//            cout<<"Extra charges are 190$";
//        }
//        else if(weight>210 && weight<=220){
//            cout<<"Extra charges are 200$";
//        }
//        else if(weight>220){
//            cout<<"Invalid weight";
//        }
//        cout<<"Enter your charges if you want to pay : ";
//          int charges;
//             cin>>charges;
//             if(weight<=20 && charges==0){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>20 && weight<=30 && charges==10){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>30 && weight<=40 && charges==20){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>40 && weight<=50 && charges==30){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>50 && weight<=60 && charges==40){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>60 && weight<=70 && charges==50){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>70 && weight<=80 && charges==60){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>80 && weight<=90 && charges==70){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>90 && weight<=100 && charges==80){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>100 && weight<=110 && charges==90){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>110 && weight<=120 && charges==100){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>120 && weight<=130 && charges==110){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>130 && weight<=140 && charges==120){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>140 && weight<=150 && charges==130){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>150 && weight<=160 && charges==140){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>160 && weight<=170 && charges==150){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>170 && weight<=180 && charges==160){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>180 && weight<=190 && charges==170){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>190 && weight<=200 && charges==180){
//                 cout<<"Thank you for your cooperation";
//             }
//             else if(weight>200 && weight<=210 && charges==190){
//                 cout<<"Thanks you for your cooperation";
//                 }
//                 if(weight>210 && weight<=220 && charges==200){
//                 cout<<"Thanks you for your cooperation";
//                 }
//                 else if (weight>220){
//                     cout<<"Invalid weight";
//                 }
//                 else{
//                     cout<<"Invalid charges";
//                 }
//             bagcharges[idx_bag]=charges;
//             idx_bag++;
void loadingAnimation()
{
    cout << "Loading ";
    for (int i = 0; i < 20; ++i)
    {
        switch (i % 4)
        {
        case 0:
            cout << "|||";
            break; // Left arrow
        case 1:
            cout << "|||";
            break; // Down arrow
        case 2:
            cout << "|||";
            break; // Right arrow
        case 3:
            cout << "|||";
            break; // Up arrow
        case 4:
            cout << "|||";
            break;
        case 5:
            cout << "|||";
            break;
        case 6:
            cout << "|||";
            break;
        case 7:
            cout << "|||";
            break;
        case 8:
            cout << "|||";
            break;
        case 9:
            cout << "|||";
            break;
        }

        cout.flush(); // Flush the output buffer to immediately show the character
        Sleep(100);
        cout << "\b \b"; // Move the cursor back and overwrite the previous character
    }
    cout << " Done!" << endl;
}
string timevalidation(string input)
{
again:
    cin >> input;
    bool am_pm_found = false;
    int i = input.length();
    if ((input[i - 2] == 'A' || input[i - 2] == 'a' || input[i - 2] == 'P' || input[i - 2] == 'p') && input[i - 1] == 'M' || input[i - 1] == 'm')
    {
        am_pm_found = true;
    }
    if (am_pm_found == true)
    {
        return input;
    }
    else
    {
        cin.clear();
        cin.sync();
        cout << "Wrong input..." << endl;
        cout << "Enter Again: ";
        goto again;
    }
}
string checkNumber(string input)

{
    cin >> input;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            if (input[i] != ' ')
            {
                check = int(input[i]);
                if (check >= 48 && check <= 57)
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            return input;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Wrong  info..." << endl;
            cout << "Enter Again (only numbers): ";
            cin >> input;
        }
    }
}
string passwordlength1(string anypass)
{
    cin >> anypass;
    int size;
    while (true)
    {
        size = anypass.length();
        if (size <= 8 && size >= 4 && anypass.find(',') == string::npos)
        {
            return anypass;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Password must not be greater than 8 characters long and should not contain a comma" << endl;
            cout << "Enter password again: ";
            cin >> anypass;
        }
    }
    return "";
}
bool checkComma(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ',')
        {
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void storelogin(string namearray[], string passwordarray[], string rolearray[], int indexCount)
{
    fstream file;
    file.open("login.txt", ios::out);
    for (int i = 0; i < indexCount; i++)
    {
        if (i == indexCount - 1)
            file << namearray[i] << "," << passwordarray[i] << "," << rolearray[i];
        else
            file << namearray[i] << "," << passwordarray[i] << "," << rolearray[i] << "\n";
    }
    file.close();
}
void storeflight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int idx_ticket)
{
    fstream file;
    file.open("flight.txt", ios::out);
    for (int i = 0; i < idx_ticket; i++)
    {
        if (i == idx_ticket - 1)
            file << ticket_route[i] << "," << ticket_price[i] << "," << ticket_time[i] << "," << ticket_seat_Num[i];
        else
            file << ticket_route[i] << "," << ticket_price[i] << "," << ticket_time[i] << "," << ticket_seat_Num[i] << "\n";
    }
    file.close();
}
void store_employee(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee)
{
    fstream file;
    file.open("employee.txt", ios::out);
    for (int i = 0; i < idx_employee; i++)
    {
        if (i == idx_employee - 1)
            file << employee_name[i] << "," << employee_age[i] << "," << employee_num[i] << "," << employee_salary[i];
        else
            file << employee_name[i] << "," << employee_age[i] << "," << employee_num[i] << "," << employee_salary[i] << "\n";
    }
    file.close();
}
void storeplanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount)
{
    fstream file;
    file.open("planes.txt", ios::out);
    for (int i = 0; i < planeCount; i++)
    {
        if (i == planeCount - 1)
            file << Plane_id[i] << "," << Plane_Type[i] << "," << Plane_Capacity[i] << "," << fuel_Capacity[i] << "," << Plane_Range[i];
        else
            file << Plane_id[i] << "," << Plane_Type[i] << "," << Plane_Capacity[i] << "," << fuel_Capacity[i] << "," << Plane_Range[i] << "\n";
    }
    file.close();
}
void store_customercomplain(string customer_name[], string customer_number[], string complain[], int &idx_complian)
{
    fstream file;
    file.open("complain.txt", ios::out);
    for (int i = 0; i < idx_complian; i++)
    {
        if (i == idx_complian - 1)
            file << customer_name[i] << "," << customer_number[i] << "," << complain[i];
        else
            file << customer_name[i] << "," << customer_number[i] << "," << complain[i] << "\n";
    }
    file.close();
}
void storeprice(string price[], int idx_price)
{
    fstream file;
    file.open("price.txt", ios::out);
    for (int i = 0; i < idx_price; i++)
    {
        if (i == idx_price - 1)
            file << price[i];
        else
            file << price[i] << "\n";
    }
    file.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadlogin(string namearray[], string passwordarray[], string rolearray[], int &indexCount)
{
    fstream file;
    string data = "";
    file.open("login.txt", ios::in);
    if (file.fail())
        return;
    while (!file.eof())
    {
        getline(file, data);
        namearray[indexCount] = getData(data, 0);
        passwordarray[indexCount] = getData(data, 1);
        rolearray[indexCount] = getData(data, 2);
        indexCount++;
    }
    file.close();
}
void loadflight(string ticket_route[], int ticket_price[], int ticket_seat_Num[], string ticket_time[], int &idx_ticket)
{
    fstream file;
    string data = "";
    file.open("flight.txt", ios::in);
    if (file.fail())
        return;
    while (!file.eof())
    {
        getline(file, data);
        ticket_route[idx_ticket] = getData(data, 0);
        ticket_price[idx_ticket] = stoi(getData(data, 1));
        ticket_seat_Num[idx_ticket] = stoi(getData(data, 2));
        ticket_time[idx_ticket] = getData(data, 3);
        idx_ticket++;
    }
    file.close();
}
void load_employee(string employee_name[], string employee_age[], string employee_num[], string employee_salary[], int &idx_employee)
{
    fstream file;
    string data = "";
    file.open("employee.txt", ios::in);
    if (file.fail())
        return;
    while (!file.eof())
    {
        getline(file, data);
        employee_name[idx_employee] = getData(data, 0);
        employee_age[idx_employee] = getData(data, 1);
        employee_num[idx_employee] = getData(data, 2);

        idx_employee++;
    }
    file.close();
}
void loadplanes(string Plane_id[], string Plane_Type[], string Plane_Capacity[], string fuel_Capacity[], string Plane_Range[], int &planeCount)
{
    fstream file;
    string data = "";
    file.open("planes.txt", ios::in);
    if (file.fail())
        return;
    while (!file.eof())
    {
        getline(file, data);
        Plane_id[planeCount] = getData(data, 0);
        Plane_Type[planeCount] = getData(data, 1);
        Plane_Capacity[planeCount] = getData(data, 2);
        fuel_Capacity[planeCount] = getData(data, 3);
        Plane_Range[planeCount] = getData(data, 4);
        planeCount++;
    }
    file.close();
}
void load_customercomplain(string customer_name[], string customer_number[], string complain[], int &idx_complian)
{
    fstream file;
    string data = "";
    file.open("complain.txt", ios::in);
    if (file.fail())
        return;
    while (!file.eof())
    {
        getline(file, data);
        customer_name[idx_complian] = getData(data, 0);
        customer_number[idx_complian] = getData(data, 1);
        complain[idx_complian] = getData(data, 2);
        idx_complian++;
    }
    file.close();
}
void loadprice(string price[], int idx_price)
{
    fstream file;
    string data = "";
    file.open("price.txt", ios::in);
    while (!file.eof())
    {
        getline(file, data);
        price[idx_price] = getData(data, 0);
        idx_price++;
    }
    file.close();
}
