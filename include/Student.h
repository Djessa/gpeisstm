#ifndef STUDENT_H
#define STUDENT_H
#include "Isstm.h"
#include <string>

class Student:public Isstm
{
    public:
        Student();
        std::string get_card();
        void set_card(std::string const card);
        virtual ~Student();
    static int add();
    static int delete_student();
    static void delete_all();
    static int search_student();
    static void select_all();
    static int select_mention();

    private:
        std::string m_card;
        std::string m_mention;
};

#endif // STUDENT_H
