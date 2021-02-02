#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Personal.h"
using namespace std;
/**
* 26/12/2020
* author: Djessa
**/
Personal::Personal()
{
    //ctor
}
void Personal::select_all()
{
    select_all_from_file("personal", "PAT");
}
int Personal::search_personal()
{
    string im_input;
    cout << "\nEntrer le IM du PAT a rechercher : ";
    cin >> im_input;
    if(!select_person_from_file("personal", im_input))
        cout << "\n\n<<<< PAT NOT FOUND >>>>\n\n";
}
void Personal::delete_all()
{
   delete_from_file("personal", "PAT");
}
int Personal::delete_personal()
{
    string name, im;
    cout << "\tEntrer le nom du PAT a supprimer : ";
    getline(cin, name);
    cout << "\tEntrer le IM du PAT a supprimer : ";
    getline(cin, im);
    if(delete_person_from_file("personal", name, im))
        cout << "\n\t<<<< Suppression reussie >>>>\n";
    else {
        cout << "\n\t<<<< Impossible de supprimer >>>>\n";
    }
    return 0;
}

void Personal::add()
{
    cout << endl;
    string data[3];
    cout << "\tEntrer le nom : ";
    getline(cin, data[0]);
    cout << "\tEntrer le prenom : ";
    getline(cin, data[1]);
    cout << "\tEntrer le numero  matricule: ";
    getline(cin, data[2]);
    // On va eviter la redondance de numero
    while(isExistPerson("personal", data[2])) {
        cout << "\tCe numero est deja utilise !\n\tVeuillez saisir un autre: ";
        getline(cin, data[2]);
    }
    insert_in_file("personal", data);
}

// IM manager
string Personal::get_i_matricule()
{
    return m_i_matricule;
}
void Personal::set_i_matricule(string const i_matricule)
{
    m_i_matricule = i_matricule;
}

Personal::~Personal()
{
    //dtor
}
