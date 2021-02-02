#ifndef PERSONAL_H
#define PERSONAL_H
#include "Isstm.h"
#include <string>
/**
* 26/12/2020
* author: Djessa
**/
class Personal : public Isstm
{
    public:
        Personal();
        std::string get_i_matricule();
        void set_i_matricule(std::string const i_matricule);
        virtual ~Personal();


    static void add();
    static int delete_personal();
    static void delete_all();
    static int search_personal();
    static void select_all();


    private:
        std::string m_i_matricule;
};

#endif // PERSONAL_H
