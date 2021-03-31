#include "examinfo.hh"
/*This is a important function.This function asks for the student id for the
form entry and after entering the student id it matches the id in "STUDENT.dat"
if id is found it extract information related to that id and displays in the
screen and the writes it in to "FORM.dat" data file*/
void examinfo::exam_formentry()
{
    clrscr();
    int t, valid, i, t_stuid;
    student stu;
    examinfo einfo;
    shape s;
    s.box(2, 1, 79, 25, 218);
    s.box(25, 2, 54, 4, 219);
    gotoxy(5, 5);
    cout << "ENTER THE STUDENT ID:-";
    cin >> t_stuid;
    if (t_stuid == 0)
        return;
    if (!stu.found_student(t_stuid))
    {
        gotoxy(5, 5);
        cout << "\7 STUDENT NOT FOUND";
        getch();
        return;
    }
    gotoxy(65, 2);
    cout << "<0>=EXIT";
    gotoxy(3, 3);
    for (i = 1; i <= 76; i++)
        cprintf(" ");
    textbackground(BLACK);
    textcolor(BLACK + BLINK);
    textbackground(WHITE);
    gotoxy(30, 3);
    cout << "EXAM ENTRY FORM";
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    int d1, m1, y1;
    struct date d;
    getdate(&d);
    d1 = d.da_day;
    m1 = d.da_mon;
    y1 = d.da_year;
    int examform_id;
    char ch;
    examform_id = einfo.last_examformid();
    examform_id++;
    gotoxy(5, 6);
    cout << "DATE:-" << d1 << "/" << m1 << "/" << y1;
    gotoxy(5, 8);
    cout << "EXAM FORM ID:-" << examform_id;
    gotoxy(5, 9);
    cout << "NAME:-";
    gotoxy(5, 10);
    cout << "FATHER NAME:-";
    gotoxy(5, 11);
    cout << "ADDRESS:-";
    gotoxy(5, 12);
    cout << "STREAM:-";
    gotoxy(5, 13);
    cout << "DEGREE:-";
    stu.examdisplay(t_stuid, examform_id);
}
/* supporting function for add to file for student*/
void examinfo::add_to_file_form(int t_stuid, int t_examformid, char t_name[30], char t_fname[30], char t_add[30], char t_strm[30], char t_deg[30])
{
    fstream file;
    stu_id = t_stuid;
    examform_id = t_examformid;
    strcpy(stu_name, t_name);
    strcpy(stu_fname, t_fname);
    strcpy(stu_add, t_add);
    strcpy(stu_strm, t_strm);
    strcpy(stu_deg, t_deg);
    //append newm record into STUDENT.dat data file.
    file.open("FORM.dat", ios::out | ios::app);
    file.write((char *)this, sizeof(examinfo));
    file.close();
}
/*supporting function for creating last student id*/
int examinfo::last_examformid(void)
{
    fstream file;
    file.open("FORM.dat", ios::in);
    file.seekg(0, ios::beg);
    int count = 0;
    //find the last id number
    while (file.read((char *)this, sizeof(examinfo)))
        count = examform_id;
    file.close();
    return count;
}
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void examinfo::clear(int col, int row)
{
    for (int j = col; j <= 79; j++)
    {
        gotoxy(j, row);
        cout << "";
    }
}