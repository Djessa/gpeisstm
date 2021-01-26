#ifndef PERSONAL_H
#define PERSONAL_H
#include <string>
/**
* 26/12/2020
* author: Djessa
**/
class Personal
{
    public:
        Personal();
        std::string get_first_name();
        void set_first_name(std::string const first_name);
        std::string get_last_name();
        void set_last_name(std::string const last_name);
        int get_i_matricule();
        void set_i_matricule(int const i_matricule);
        virtual ~Personal();
    static void add();
    static int delete_personal();
    static void delete_all();
    static int  total();
    static int search_personal();
    static void select_all();
    private:
        std::string m_first_name;
        std::string m_last_name;
        int m_i_matricule;
};

#endif // PERSONAL_H
