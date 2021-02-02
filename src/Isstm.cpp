#include "Isstm.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
Isstm::Isstm()
{
    //ctor
}
// Inserer un tableau de données dans un fichier
void insert_in_file(string filename, string data[])
{
    ofstream file;
    string line("");
    // On va mettre les donnees dans un string
    line = data[0] + "\n" + data[1] + "\n" + data[2];
    if(filename == "student") {
        line+= "\n" + data[3]; // un etudiant doit avoir  le  mention
        file.open("student", ios::app);
    } else {
        file.open("personal", ios::app);
    }
    line += "\n\n";
    if(file)
    {
        file  << line;
        cout << endl << "\t----------Ajout reussie----------" << endl;
    }
    else
    {
        cout << endl << "\t----------Erreur :  Impossible d'ajouter----------" << endl;
    }
    cout << endl;
    file.close();
}
// permet de verifier si le personne  existe dans un fichier
bool isExistPerson(string filename, string number)
{
    ifstream file;
    string line;
    if(filename == "personal") {
        file.open("personal");
        while(getline(file, line))
        {
            getline(file, line);
            getline(file, line);
            if(number == line)
                return true;
            getline(file, line);
        }
    }
    else {
        file.open("student");
        while(getline(file, line))
        {
            getline(file, line);
            getline(file, line);
            if(number == line) {
                file.close();
                return true;
            }
            getline(file, line);
            getline(file, line);
        }
    }
    file.close();
    return false;
}
int total(string filename) {
    ifstream file;
    string line;
    int total(0);
    if(filename == "personal") {
        file.open("personal");
        if(file) {
            while(getline(file, line))
            {
                getline(file, line);
                getline(file, line);
                getline(file, line);
                total++;
            }
        }
    }
    else {
        file.open("student");
        if(file) {
            while(getline(file, line))
            {
                getline(file, line);
                getline(file, line);
                getline(file, line);
                getline(file, line);
                total++;
            }
        }
    }
    file.close();
    return total;
}
void delete_from_file(string filename, string entity)
{
    char confirm = 'N';
    ofstream file;
    cout << "Voulez-vous vraiment supprimer  "<< total(filename) << " " << entity << "  qui reste dans la base (O/N) : ";
    cin >> confirm;
    if(confirm == 'O')
    {    if(filename == "personal")
            file.open("personal");
        else
            file.open("student");
        if(file)
        {
            file<<"";
            file.close();
            cout << "\n\t----------Suppression reussie----------\n"<<endl;
        }
        else
        {
            cout << "\n\t----------Impossible de supprimer----------\n" << endl;
            file.close();
        }
    }
}
bool delete_person_from_file(string filename, string name, string number)
{
    ifstream file;
    ofstream file_write("write", ios::app);
    string data[4];
    string line;
    bool success(false);
    if(filename == "personal") {
        file.open("personal");
        if(file)
        {
            while(getline(file, line))
            {
                if(name == line) {
                    data[0] = line;
                    getline(file, line);
                    data[1] = line;
                    getline(file, line);
                    data[2] = line;
                    getline(file, line);
                    if(number != data[2])
                        file_write<<data[0]<<endl<<data[1]<<endl<<data[2]<<endl<<endl;
                    else
                        success = true;
                } else {
                    file_write<<line<<endl;
                    getline(file, line);
                    file_write<<line<<endl;
                    getline(file, line);
                    file_write<<line<<endl<<endl;
                    getline(file, line);
                }
            }
            file_write.close();
            file.close();
            remove("personal");
            rename("write",  "personal");
            if(success)
                return true;
        }
    }
    else {
        file.open("student");
        while(getline(file, line))
        {
            if(name == line) {
                data[0] = line;
                getline(file, line);
                data[1] = line;
                getline(file, line);
                data[2] = line;
                getline(file, line);
                data[3] = line;
                getline(file, line);
                if(number != data[2])
                    file_write<<data[0]<<endl<<data[1]<<endl<<data[2]<<endl<< data[3] << endl << endl;
                else
                    success = true;
            } else {
                file_write<<line<<endl;
                getline(file, line);
                file_write<<line<<endl;
                getline(file, line);
                file_write<<line<<endl;
                getline(file, line);
                file_write<<line<<endl<<endl;
                getline(file, line);
            }
        }
        file_write.close();
        file.close();
        remove("student");
        rename("write",  "student");
        if(success)
            return true;
    }
    file.close();
    return false;
}
bool select_person_from_file(string filename, string number)
{
    ifstream file;
    string line;
    string first_name;
    string last_name;
    if(filename == "personal") {
        file.open("personal");
        if(file) {
            while(getline(file, line))
            {
                first_name = line;
                getline(file, line);
                last_name = line;
                getline(file, line);
                if(line == number){
                    cout<<"\nPAT FOUND : "<< first_name <<" "<< last_name << endl << endl;
                    return true;
                }
                getline(file, line);

            }
        }
    } else {
        file.open("student");
        if(file) {
            while(getline(file, line))
            {
                first_name = line;
                getline(file, line);
                last_name = line;
                getline(file, line);
                if(line == number){
                    cout<<"\nETUDIANT FOUND : "<< first_name <<" "<< last_name << endl << endl;
                    return true;
                }
                getline(file, line);
                getline(file, line);
            }
        }
    }
    return false;
}
void select_all_from_file(string filename, string entity)
{
    if(total(filename) == 0)
    {
        cout << "\n\t<<<< Il n'y a aucun " << entity <<  " dans la base >>>>\n";
    }
    else
    {
        ifstream file;
        string line;
        if(filename == "personal") {
            file.open("personal");
            if(file)
            {
                cout <<"Liste  des PAT:\n";
                printf("+------------------------------------------------------------------------------------+\n");
                printf("|             NOM              |            PRENOM            |          IM          |\n");
                printf("+------------------------------------------------------------------------------------+\n");
                while(getline(file, line))
                {
                   cout <<"|";
                   show(line, 30);
                   cout <<"|";
                   getline(file, line);
                   show(line, 30);
                   cout <<"|";
                   getline(file, line);
                   show(line, 22);
                   cout <<"|";
                   getline(file, line);
                   printf("\n+------------------------------------------------------------------------------------+\n");
                }
                cout << "Total : " << total("personal") << endl;
            }
        }
        else
        {
                file.open("student");
                if(file)
                {
                    cout <<"Liste  des etudiants:\n";
                    printf("+----------------------------------------------------------------------------------------+\n");
                    printf("|             NOM              |            PRENOM            |          NUMERO          |\n");
                    printf("+----------------------------------------------------------------------------------------+\n");
                    while(getline(file, line))
                    {
                       cout <<"|";
                       show(line, 30);
                       cout <<"|";
                       getline(file, line);
                       show(line, 30);
                       cout <<"|";
                       getline(file, line);
                       show(line, 26);
                       cout <<"|";
                       getline(file, line);
                        printf("\n+----------------------------------------------------------------------------------------+\n");
                       getline(file, line);
                    }
                    cout << "Total : " << total("student") << endl;
                }
            }
    }
}
// First name manager
string Isstm::get_first_name()
{
    return m_first_name;
}

void Isstm::set_first_name(string const first_name)
{
    m_first_name = first_name;
}
// Last name manager
string Isstm::get_last_name()
{
    return m_last_name;
}
void Isstm::set_last_name(string const last_name)
{
    m_last_name = last_name;
}
void show(string chaine, int lenColumn)
{
    int addSpace(0);
    int lenSpace = lenColumn - chaine.size();
    if(lenSpace % 2 != 0)
        addSpace = 1;
    for(int i(0); i < (lenSpace/2); i++)
        printf(" ");
    cout << chaine ;
    for(int i(0); i < (lenSpace/2)+addSpace; i++)
        printf(" ");
}
Isstm::~Isstm()
{
    //dtor
}
