#include "Student.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
/**
* 25/12/2020
* author: Djessa
**/
Student::Student()
{
    //ctor
}

int Student::select_mention()
{
    string first_name, last_name, numero, mention(""),  line;//variable pour stocker le   mention selectioné
    int t(0);
    cout << "\tMention : \n";
    cout << "\t1.Genie industriel" << endl;
    cout << "\t2.Genie civil" << endl;
    cout << "\t3.Numerique" << endl;
    cout << "\t>> ";
    cin >> mention;
    cin.ignore();
    ifstream file("student"); // open file
    bool not_exist = true;
    printf("+----------------------------------------------------------------------------------------+\n");
    printf("|             NOM              |            PRENOM            |          NUMERO          |\n");
    printf("+----------------------------------------------------------------------------------------+\n");
    while(getline(file, line))
    {
        first_name = line;
        getline(file, line);
        last_name = line;
        getline(file, line);
        numero = line;
        getline(file, line);
        if(line == mention){
             cout <<"|";
            show(first_name, 30);
            cout <<"|";
            show(last_name, 30);
            cout <<"|";
            show(numero, 26);
            cout <<"|";
            printf("\n+----------------------------------------------------------------------------------------+\n");
            t++;
        }
        getline(file, line);
    }
    cout << "\n Total : " << t << "\n\n";
    file.close();
}
void Student::select_all()
{
    select_all_from_file("student", "etudiant");
}
int Student::search_student()
{
    string numero;
    cout << "\nEntrer le numero de l'etudiant a rechercher : ";
    cin >> numero;
    if(!select_person_from_file("student", numero))
        cout << "\n\n<<<< ETUDIANT NOT FOUND >>>>\n\n";
}
void Student::delete_all()
{
    delete_from_file("student", "etudiant");
}
int Student::delete_student()
{
    string name, im;
    cout << "\tEntrer le nom de l'etudiant a supprimer : ";
    getline(cin, name);
    cout << "\tEntrer son numero   : ";
    getline(cin, im);
    if(delete_person_from_file("student", name, im))
        cout << "\n\t<<<< Suppression reussie >>>>\n";
    else {
        cout << "\n\t<<<< Impossible de supprimer >>>>\n";
    }
    return 0;
}
int Student::add()
{
    cout << endl;
    string data[4];
    cout << "\tEntrer le nom : ";
    getline(cin, data[0]);
    cout << "\tEntrer le prenom : ";
    getline(cin, data[1]);
    cout << "\tEntrer le numero  matricule: ";
    getline(cin, data[2]);
    // On va eviter la redondance de numero
    while(isExistPerson("student", data[2])) {
        cout << "\tCe numero est deja utilise !\n\tVeuillez saisir un autre: ";
        getline(cin, data[2]);
    }
    cout << "\n\t1: Genie industriel\n\t2: Genie civil\n\t3: Numerique\n";
    cout << "\n  >Selectionnez  le numero  du mention: ";
    getline(cin, data[3]);
    insert_in_file("student", data);
    return 0;
}
// Card manager
string Student::get_card()
{
    return m_card;
}
void Student::set_card(string const card)
{
    m_card = card;
}
Student::~Student()
{
    //dtor
}
