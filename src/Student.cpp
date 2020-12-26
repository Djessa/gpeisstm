#include "Student.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
Student::Student()
{
    //ctor
}/*
void Personal::select_all()
{
    string fn = "" , ln, line;
    ifstream file("personal");
    printf("+------------------------------------------------------------+\n");
    printf("|   IM   |           NOM           |         PRENOM          |\n");
    printf("+------------------------------------------------------------+\n");
    while(getline(file, line))
    {
        printf("|   %c    |", line[0]);
        fn = "";
        for(int i(2); i < line.size(); i++)
        {
            if(line[i] == ',') {
                ln = line.substr(i+1);
                    break;
                }
            fn += line[i];
        }
        int len_fn = 0, len_ln = 0, add_fn = 0, add_ln = 0;
        len_fn = 25 - fn.size();
        len_ln = 25- ln.size();
        add_fn = (len_fn % 2 == 0) ? 0 : 1;
        add_ln = (len_ln % 2 == 0) ? 0 : 1;
        for(int i(0); i < (len_fn/2); i++)
            printf(" ");
        cout << fn ;
        for(int i(0); i < (len_fn/2)+add_fn; i++)
            printf(" ");
        printf("|");
        for(int i(0); i < (len_ln/2); i++)
            printf(" ");
        cout << ln ;
        for(int i(0); i < (len_ln/2)+add_ln; i++)
            printf(" ");
        printf("|\n");
        printf("+------------------------------------------------------------+\n");
    }
    cout << "\n Total : " << Personal::total() << "\n\n";
    file.close();
}
int Personal::search_personal()
{
    char im(' ');
    string fn = "" , ln, line;
    ifstream file("personal");
    char im_input;
    cout << "\nEntrer le IM du PAT : ";
    cin >> im_input;
    while(getline(file, line))
    {
        im = line[0];
        if(im == im_input)
        {
            printf("+-----------------------------------------+\n");
            printf("|         NOM        |       PRENOM        |\n");
            printf("+--------------------+---------------------+\n");
            for(int i(2); i < line.size(); i++)
            {
                if(line[i] == ',') {
                    ln = line.substr(i+1);
                    break;
                }
                fn += line[i];
            }
            int len_fn = 20 - fn.size(), len_ln = 20 - ln.size();
            int add_fn = (len_fn % 2 == 0) ? 0 : 1;
            int add_ln = (len_ln % 2 == 0) ? 0 : 1;
            printf("|");
            for(int i(0); i < (len_fn/2); i++)
                printf(" ");
            cout << fn ;
            for(int i(0); i < (len_fn/2)+add_fn; i++)
                printf(" ");
            printf("|");
            for(int i(0); i < (len_ln/2); i++)
                printf(" ");
            cout << ln ;
            for(int i(0); i < (len_ln/2)+add_ln+1; i++)
                printf(" ");
            printf("|\n");
            printf("+--------------------+---------------------+\n");
            file.close();
            return 0;
        }
    }
}
void Personal::delete_all()
{
    char confirm = 'N';
    cout << "Voulez-vous vraiment supprimer tous les "<< Personal::total()<<" PAT (O/N) :";
    cin >> confirm;
    if(confirm == 'O')
    {
        ofstream file("personal");
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
int Personal::total()
{
    ifstream file("personal");
    int i(0);
    string data;
    while(getline(file, data))
    {
        i++;
    }
    file.close();
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
    int i(0);
    Personal persons[Personal::total()];
    string line;
    while(getline(file, line))
    {
        persons[i].m_i_matricule =  line[0]-48;
        string fn = "";
        for(int j(2); j < line.size(); j++)
        {
            if(line[j] == ',') {
                persons[i].m_last_name = line.substr(j+1);
                break;
            }
            fn += line[j];
        }
        persons[i].m_first_name = fn;
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
            fileInsertion  << persons[j].m_i_matricule << "," << persons[j].m_first_name << "," << persons[j].m_last_name<< endl ;
        }
    }
    fileInsertion.close();
    cout << endl << "\t----------Suppression reussie----------\n" << endl;
    return 0;
}
*/
void Student::add()
{
    string first_name, last_name, mention;
    string card, c;
    bool card_ok = false;
    ifstream fichier;
    ofstream file;
    cout << endl;
    do
    {
        card_ok = false;
        cout << "\tNumero de carte etudiant : ";
        cin >> card;
        cin.ignore();
        fichier.open("student");
        string line;
        while(getline(fichier, line))
        {
            string i_ma("");
            for(int k(0); k < line.size(); k++)
            {
                if(line[k] == ',')
                    break;
                i_ma += line[k];
            }
            if(card ==  i_ma){
                cout << " Ce IM existe deja"<<endl;
                card_ok = true;
                break;
            }
        }
        fichier.close();
    }while(card_ok);
    cout << "\tEntrer le nom de l'etudiant : ";
    getline(cin, first_name);
    cout << "\tEntrer le prenom de l'etudiant : ";
    getline(cin, last_name);
    cout << "\tMention : ";
    getline(cin, mention);
    file.open(mention.c_str(), ios::app);
    if(file)
    {
        file  << card << "," << first_name  << "," << last_name << endl;
        cout << endl << "\t----------Ajout reussie----------" << endl;
    }
    else
    {
        cout << endl << "\t----------Erreur :  Impossible d'ajouter----------" << endl;
    }
    cout << endl;
    file.close();
}
string Student::get_first_name()
{
    return m_first_name;
}

void Student::set_first_name(string const first_name)
{
    m_first_name = first_name;
}

string Student::get_last_name()
{
    return m_last_name;
}
void Student::set_last_name(string const last_name)
{
    m_last_name = last_name;
}
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
