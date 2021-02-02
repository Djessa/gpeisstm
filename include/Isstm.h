#ifndef ISSTM_H
#define ISSTM_H
#include <string>
// classe de base
class Isstm
{
    public:
        Isstm();
        virtual ~Isstm();
        // Getters
        std::string get_first_name();
        std::string get_last_name();
        // Setters
        void set_first_name(std::string const first_name);
        void set_last_name(std::string const last_name);
    protected:
        std::string m_first_name;
        std::string m_last_name;
};
// Fonctions
void insert_in_file(std::string filename, std::string data[]);
bool isExistPerson(std::string filename, std::string number);
void delete_from_file(std::string filename, std::string entity);
int total(std::string filename);
bool delete_person_from_file(std::string filename, std::string name, std::string number);
bool select_person_from_file(std::string filename, std::string number);
void select_all_from_file(std::string filename, std::string entity);
void show(std::string chaine, int lenColumn);
#endif // ISSTM_H
