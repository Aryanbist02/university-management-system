#include "main-menu.hh"

void main_menu::welcome_screen()
{
    int i, col = 100, maxCol = 100;

    setfillstyle(1, BLACK);
    bar(0, 0, 639, 479);

    setcolor(BLUE);

    for (i = 0; i < 400; ++i, ++col, ++maxCol)
    {
        line(col, 150, maxCol, 350);
        delay(6);
    }
    setfillstyle(7, 1);
    bar(100, 150, 500, 350);

    setcolor(WHITE);

    outtextxy(180, 200, "University Management System");

    setcolor(GREEN);

    outtextxy(216, 230, "Jitender Bhardwaj");
    outtextxy(220, 250, "DOEACC 'A' Level");

    setcolor(WHITE);
    outtextxy(150, 270, "T r i n e t r a   D a t a   L i n k s");

    setcolor(GREEN);
    outtextxy(225, 290, "Reg. No. 411966");

    setcolor(WHITE);

    outtextxy(180, 370, "Press any key to continue . . .");

    getch();
}

/*Function to display all the menu prompt message from the pointer array
of option a[]*/
void main_menu::normal(int x, int y, char *str)
{
    gotoxy(x, y);
    cprintf("%s", str);
}
//Function to move the cursor in the menu prompt with reverse video color
void main_menu::reverse(int x, int y, char *str)
{
    textcolor(5 + 143);
    textbackground(WHITE);
    gotoxy(x, y);
    cprintf("%s", str);
    textcolor(GREEN);
    textbackground(BLACK);
}
void main_menu::box(int x1, int y1, int x2, int y2)
{
    for (int col = x1; col < x2; col++)
    {
        gotoxy(col, y1);
        cprintf("%c", 196);
        gotoxy(col, y2);
        cprintf("%c", 196);
    }
    for (int row = y1; row < y2; row++)
    {
        gotoxy(x1, row);
        cprintf("%c", 179);
        gotoxy(x2, row);
        cprintf("%c", 179);
    }
    gotoxy(x1, y1);
    cprintf("%c", 218);
    gotoxy(x1, y2);
    cprintf("%c", 192);
    gotoxy(x2, y1);
    cprintf("%c", 191);
    gotoxy(x2, y2);
    cprintf("%c", 217);
}
char main_menu::menu()
{
    clrscr();
    textcolor(22);
    box(20, 6, 65, 20);
    box(18, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(28, 5);
    textbackground(WHITE);
    cprintf("University Management System");
    textbackground(BLACK);
    textcolor(22);
    for (int i = 1; i < 6; i++)
        normal(32, i + 10, a[i]);
    reverse(32, 10, a[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR); //change the cursor type
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, a[i]);
            i--;
            if (i == -1)
                i = 5;
            reverse(32, i + 10, a[i]);
            break;

        case 80:
            normal(32, i + 10, a[i]);
            i++;
            if (i == 6)
                i = 0;
            reverse(32, i + 10, a[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*The function main_menu() is used to display the main menu of university managment system.
This function uses 6 main options and each has its specific purposes for maintaining
the university.In this menu,the user can avail the facilities by pressing any number
from 1 to 5 and in case he presses any other key the prompt will come back from menu to the
source promgram or it is better to press '0' to exit from the menu.other than 0 and 1...5
if you press any other key the university managment system do not response till you press a valid number
*/
void main_menu::control_menu()
{
    char choice;
    do
    {
        choice = menu();

        clrscr();

        switch (choice)
        {
        case '1':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            gotoxy(7, 4);
            entry_menu(); //sub menu of main menu
            break;

        case '2':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            gotoxy(7, 5);
            display_menu(); //sub menu of main menu
            break;

        case '3':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            gotoxy(7, 6);
            enquiry_menu(); //sub menu of main menu
            break;

        case '4':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            gotoxy(7, 8);
            modification_menu(); //sub menu of main menu
            break;

        case '5':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            gotoxy(7, 9);
            performance_menu(); //sub menu of main menu
            break;

        case '6':
            exit(0);
        }
    } while (choice != 5);
}
/*design of entry menu:- This function is used to return the cursor position to the entry menu function where the menu prompt is valid(design function)*/
char main_menu::e_menu()
{
    clrscr();

    textcolor(22);
    box(25, 6, 65, 20);
    box(23, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(34, 5);
    textbackground(GREEN);
    cprintf("Entry Menu");
    textcolor(22);
    textbackground(BLACK);
    for (int i = 1; i < 6; i++)
        normal(32, i + 10, b[i]);
    reverse(32, 10, b[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR); //change the cursor
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, b[i]);
            i--;
            if (i == -1)
                i = 5;
            reverse(32, i + 10, b[i]);
            break;

        case 80:
            normal(32, i + 10, b[i]);
            i++;
            if (i == 6)
                i = 0;
            reverse(32, i + 10, b[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*Function for entry menu with open college, student, examform, schedule and result sub-menu.This is one of the submenu which manages
five basic operations such as:
	-New College
	-New Student
	-Exam Form
	-Exam Schedule
	-Result
while entering new college information college name, address, streem, degree are asked to enter
student menu provides information to add that are nessary.*/
void main_menu::entry_menu()
{
    char choice;
    student stu;
    college coll;
    examinfo einfo;
    do
    {
        choice = e_menu();
        clrscr();
        switch (choice)
        {
        case '1':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            gotoxy(7, 4);
            coll.new_college(); //sub menu of entry menu
            break;

        case '2':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            gotoxy(7, 5);
            stu.new_student(); //sub menu of entry menu
            break;

        case '3':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            gotoxy(7, 6);
            einfo.exam_formentry(); //sub menu of entry menu
            break;

        case '4':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            gotoxy(7, 7);
            einfo.exam_scheduleentry(); //sub menu of entry menu
            break;

        case '5':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            gotoxy(7, 8);
            einfo.result_entry(); //sub menu of entry menu
            break;

        case '6':
            return;
        }
    } while (choice != 5);
}
/*design of display menu:-This function is used to return the cursor poisition to the display menu function where the menu prompt is valid(design part)*/
char main_menu::d_menu()
{
    clrscr();
    textcolor(22);
    box(25, 6, 65, 20);
    box(23, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(34, 5);
    textbackground(GREEN);
    cprintf("Display Menu");
    textcolor(22);
    textbackground(BLACK);
    for (int i = 1; i < 6; i++)
        normal(32, i + 10, c[i]);
    reverse(32, 10, c[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR); //change the cursor type
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, c[i]);
            i--;
            if (i == -1)
                i = 5;
            reverse(32, i + 10, c[i]);
            break;

        case 80:
            normal(32, i + 10, c[i]);
            i++;
            if (i == 6)
                i = 0;
            reverse(32, i + 10, c[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*Function for display menu with college,  student,  exam form,  exam schedule,  and result.This is one of the sub menu which manages
five operations such as:
	-College
	-Student
	-Exam Form
	-Exam Schedule
	-Result
while displaying records it displays all the records that were enterd in the entry section and
extract this information from their particulat database files*/
void main_menu::display_menu()
{
    char choice;
    college coll;
    student stu;
    examinfo einfo;
    do
    {
        choice = d_menu();
        clrscr();
        switch (choice)
        {
        case '1':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            coll.display_list(); //sub menu of display menu
            getch();
            break;

        case '2':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            stu.display_list(); //sub menu of display menu
            getch();
            break;

        case '3':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            einfo.display_list(); //submenu of display menu
            getch();
            break;

        case '4':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            einfo.display_schedulelist(); //sub menu of dispalay menu
            getch();
            break;

        case '5':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            einfo.resultdisplay_list(); //sub menu of display menu
            getch();
            break;

        case '6':
            return;
        }
    } while (choice != 5);
}
/*design of enquiry menu:-This function is used to return the cursor position to the enquiry menu function where the menu prompt is valid(design function)*/
char main_menu::enqu_menu()
{
    clrscr();
    textcolor(22);
    box(25, 6, 65, 20);
    box(23, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(34, 5);
    textbackground(GREEN);
    cprintf("Enquiry Menu");
    textcolor(22);
    textbackground(BLACK);
    for (int i = 1; i < 3; i++)
        normal(32, i + 10, d[i]);
    reverse(32, 10, d[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR); //change the cursor type
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, d[i]);
            i--;
            if (i == -1)
                i = 2;
            reverse(32, i + 10, d[i]);
            break;

        case 80:
            normal(32, i + 10, d[i]);
            i++;
            if (i == 3)
                i = 0;
            reverse(32, i + 10, d[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*This function is used for the enwuiry of aparticular college or student
This function asks the user to enter id of the college or student for which
they want to enquir about*/
void main_menu::enquiry_menu()
{
    char choice;
    college coll;
    student stu;
    examinfo einfo;
    do
    {
        choice = enqu_menu();
        clrscr();
        switch (choice)
        {
        case '1':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            coll.college_enquiry(); //Sub menu of Enquiry
            getch();
            break;

        case '2':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            stu.enquiry_student(); //sub menu of Enquiry
            getch();
            break;

        case '3':
            return;
        }
    } while (choice != 5);
}
/*design of modify menu:-This function is used to return the cursor position to the modify menu function where the menu prompt is valid(design function)*/
char main_menu::mod_menu()
{
    clrscr();
    textcolor(22);
    box(25, 6, 65, 20);
    box(23, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(34, 5);
    textbackground(GREEN);
    cprintf("Modification Menu");
    textcolor(22);
    textbackground(BLACK);
    for (int i = 1; i < 3; i++)
        normal(32, i + 10, e[i]);
    reverse(32, 10, e[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR);
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, e[i]);
            i--;
            if (i == -1)
                i = 2;
            reverse(32, i + 10, e[i]);
            break;

        case 80:
            normal(32, i + 10, e[i]);
            i++;
            if (i == 3)
                i = 0;
            reverse(32, i + 10, e[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*This function is used to modify the information of the college or student.
This function asks for the college or student id for modification.First it
shows the old record and then asks the user "Do You Want To Modify(Y/N).If
the user press yes it ask the user to enter the new information and then
saves it in their particular data files*/
void main_menu::modification_menu()
{
    char choice;
    college coll;
    student stu;
    examinfo einfo;
    do
    {
        choice = mod_menu();
        clrscr();
        switch (choice)
        {
        case '1':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            coll.college_modification(); //sub menu of modification
            break;

        case '2':
            box(3, 1, 75, 24);
            box(5, 2, 73, 23);
            _setcursortype(_NORMALCURSOR);
            stu.student_modification(); //sub menu ofmodification
            break;

        case '3':
            return;
        }
    } while (choice != 3);
}
/*design of perform menu:-This function is used to return the cursor position to the performance menu function where the menu prompt is valid(design function)*/
char main_menu::perform_menu()
{
    clrscr();
    textcolor(22);
    box(25, 6, 65, 20);
    box(23, 4, 67, 22);
    textcolor(5 + 143);
    gotoxy(34, 5);
    textbackground(GREEN);
    cprintf("Performance Menu");
    textcolor(22);
    textbackground(BLACK);
    for (int i = 1; i < 2; i++)
        normal(32, i + 10, f[i]);
    reverse(32, 10, f[0]);
    i = done = 0;
    _setcursortype(_NOCURSOR);
    do
    {
        int key = getch();
        switch (key)
        {
        case 72:
            normal(32, i + 10, f[i]);
            i--;
            if (i == -1)
                i = 1;
            reverse(32, i + 10, f[i]);
            break;

        case 80:
            normal(32, i + 10, f[i]);
            i++;
            if (i == 2)
                i = 0;
            reverse(32, i + 10, f[i]);
            break;

        case 13:
            done = 1;
        }
    } while (!done);
    _setcursortype(_NOCURSOR);
    return (i + 49);
}
/*This function dispalys the performance of the university such as
	- Foundation
	-Annual Report
*/
void main_menu::performance_menu()
{
    char choice;
    performance perf;
    do
    {
        choice = perform_menu();
        clrscr();
        switch (choice)
        {
        case '1':
            box(2, 1, 77, 24);
            box(3, 2, 75, 23);
            _setcursortype(_NORMALCURSOR);
            perf.foundation();
            getch();
            break;

        case '2':
            return;
        }
    } while (choice != 2);
}