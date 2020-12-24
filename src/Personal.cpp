#include "Personal.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Personal::Personal()
{
    //ctor
}
void Personal::delete_all()
{
    char confirm = 'N';
    cout << "Voulez-vous vraiment supprimer tous les "<< Personal::total()<<" PAT (O/N) :";
    cin >> confirm;
    if(confirm == 'O')
    {
        ofstream file("personal");
        file<<"";
        file.close();
        cout << "\n\t----------Suppression reussie----------\n"<<endl;
    }
}
int Personal::total()
{
    ifstream file("personal");
    int i(0);
    string data;
    while(!file.eof())
    {
        getline(file, data);
        i++;
    }
    return i;
}
int Personal::delete_personal()
{
    string first_name;
    int i_matricule;
    ifstream file("personal");
    cout << "\tEntrer le IM du PAT a supprimer : ";
    cin >> i_matricule;
    cin.ignore();
    cout << "\tEntrer le nom du PAT a supprimer : ";
    cin >> first_name;
    string fistName;
    int iMatricule;
    string lastName;
    int i(0);
    Personal persons[Personal::total()-1];
    while(file>>iMatricule>>fistName>>lastName)
    {
        persons[i].m_first_name = fistName;
        persons[i].m_last_name =  lastName;
        persons[i].m_i_matricule = iMatricule;
        if(persons[i].m_i_matricule == i_matricule && persons[i].m_first_name != first_name)
        {
            cout << "\n\tImpossible de supprimer : (Le nom ne correspond pas a cette IM)\n"<<endl;
            return 0;
        }
        i++;
    }
    file.close();
    ofstream fileSuppression("personal");
    fileSuppression<"";
    fileSuppression.close();
    ofstream fileInsertion("personal", ios::app);
    for(int j(0); j < i; j++)
    {
       if(persons[j].m_i_matricule != i_matricule)
        {
            fileInsertion  << persons[j].m_i_matricule << "\t" << persons[j].m_first_name << "\t" << persons[j].m_last_name<< endl ;
        }
    }
    fileInsertion.close();
    cout << endl << "\t----------Suppression reussie----------\n" << endl;
    return 0;
}

void Personal::add()
{
    string first_name, last_name;
    int i_matricule, i_m;bool i_matricule_ok = false;
    ifstream fichier;
    ofstream file ("personal", ios::app);
    cout << endl;
    do
    {
        i_matricule_ok = false;
        cout << "\tEntrer le IM du PAT : ";
        cin >> i_matricule;
        cin.ignore();
        fichier.open("personal");
        while(fichier>>i_m>>first_name>>last_name)
        {
            if(i_matricule == i_m){
                cout << " Ce IM existe deja"<<endl;
                i_matricule_ok = true;
                break;
            }
        }
        fichier.close();
    }while(i_matricule_ok);
    cout << "\tEntrer le nom du PAT : ";
    getline(cin, first_name);
    cout << "\tEntrer le prenom du PAT : ";
    getline(cin, last_name);
    if(file)
    {
        file  << i_matricule << "\t" << first_name  << "\t" << last_name << endl;
        cout << endl << "\t----------Ajout reussie----------" << endl;
    }
    else
    {
        cout << endl << "\t----------Erreur :  Impossible d'ajouter----------" << endl;
    }
    cout << endl;
}
string Personal::get_first_name()
{
    return m_first_name;
}

void Personal::set_first_name(string const first_name)
{
    m_first_name = first_name;
}

string Personal::get_last_name()
{
    return m_last_name;
}
void Personal::set_last_name(string const last_name)
{
    m_last_name = last_name;
}
int Personal::get_i_matricule()
{
    return m_i_matricule;
}
void Personal::set_i_matricule(int const i_matricule)
{
    m_i_matricule = i_matricule;
}

Personal::~Personal()
{
    //dtor
}
