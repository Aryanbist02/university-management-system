class examinfo
{
private:
    char stu_deg[30], stu_name[30], stu_fname[30], stu_add[30], stu_strm[30], sd1[30], ed1[30], sm1[30], em1[30], sy1[30], ey1[30], deg[30];
    int stu_id, examform_id, hp1, hp2, hp3, hp4, hp5, hp6, hp7, hp8, s1, s2, com, gk;
    int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;
    //function to add record
    void add_to_file_schedule(char[], char[], char[], char[], char[], char[], char[]);

public:
    void exam_formentry();           //function for the form fill up
    void exam_scheduleentry(void);   //function for the entry of the schedule
    void display_list(void);         //function to display
    void display_schedulelist(void); //function to display
    void result_entry(void);         //function for the entry of the result
    void resultdisplay_list(void);   //function for the result display
    char *return_degname(int);       //function for the valid entry of degree
    int last_examformid(void);       //function to find the last id
    void clear(int, int);            //function for clearing screen
    void display(int);               //function to display
    //function to add record
    void add_to_file_form(int, int, char[], char[], char[], char[], char[]);
    //function to add record
    void add_to_filebaI(int, char[], char[], int, int, int, int, int);
    //function to add record
    void add_to_filebaII(int, char[], char[], int, int, int, int, int);
    //function to add record
    void add_to_filebaIII(int, char[], char[], int, int, int, int, int);
    //function to add record
    void add_to_filemaI(int, char[], char[], int, int, int, int, int, int, int, int);
    //function to add record
    void add_to_filemaII(int, char[], char[], int, int, int, int, int, int, int, int);
};
