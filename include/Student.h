#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
    public:
        Student();
        std::string get_first_name();
        void set_first_name(std::string const first_name);
        std::string get_last_name();
        void set_last_name(std::string const last_name);
        std::string get_card();
        void set_card(std::string const card);
        virtual ~Student();
    static void add();
    static int delete_student();
    static void delete_all();
    static int  total();
    static int search_student();
    static void select_all();

    private:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_card;
};

#endif // STUDENT_H
