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

    string mention("");//variable pour stocker le   mention selectioné
    int t(0);
    cout << "\tMention : \n";
    cout << "\t1.Genie industriel" << endl;
    cout << "\t2.Genie civil" << endl;
    cout << "\t3.Numerique" << endl;
    cout << "\t>> ";
    cin >> mention;
    cin.ignore();
    if(mention == "1"){
        mention = "gi";
    }
    else if(mention == "2") {
        mention = "gc";
    }
    else if(mention == "3") {
        mention = "n";
    }
    else {
        cout << "\n\tLe mention que vous avez indique n'est pas disponible\n"<<endl;
        return 0;
    }
    string fn = "" , ln, line, ima("");
    bool im(true), first(false), last(false);
    ifstream file("student"); // open file
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|          NUMERO         |           NOM           |         PRENOM          |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    while(getline(file, line))
    {
        fn = "";
        im = true;
        first = false;
        ln = "";
        ima = "";
        string ment = "";
        for(int i(0); i < line.size(); i++)
        {
            // saisir le IM dans le variable ima
            if(im) {
                if(line[i] == ','){
                    im = false;
                    first = true;
                    continue;
                } else {
                    ima += line[i];
                }

            }
            // saisir le first name  dans le variable fn
            else if(first){
                if(line[i] == ','){
                    first = false;
                    last = true;
                    continue;
                } else {
                    fn += line[i];
                }
            }
            // saisir le last name dans le variable ln
            else {
                 if(line[i] == ','){
                     ment = line.substr(i+1);
                     break;
                 }else {
                    ln += line[i];
                }
            }
        }
        // si le mention en cours sur  le fichier n'est pas le mention selectioné
        if(mention != ment )
            continue;
        t++;
        // On va bien  placé le resultat
        int len_im(0), len_fn = 0, len_ln = 0, add_im(0), add_fn = 0, add_ln = 0;
        // Affichage de IM
        len_im = 25 - ima.size();
        add_im = (len_im % 2 == 0) ? 0 : 1;
        printf("|");
        for(int i(0); i < (len_im/2); i++)
            printf(" ");
        cout << ima ;
        for(int i(0); i < (len_im/2)+add_im; i++)
            printf(" ");
        printf("|");
        // Affichage de Nom
        len_fn = 25 - fn.size();
        add_fn = (len_fn % 2 == 0) ? 0 : 1;
        for(int i(0); i < (len_fn/2); i++)
            printf(" ");
        cout << fn ;
        for(int i(0); i < (len_fn/2)+add_fn; i++)
            printf(" ");
        printf("|");
        // Affichage de Prenom
        len_ln = 25- ln.size();
        add_ln = (len_ln % 2 == 0) ? 0 : 1;
        for(int i(0); i < (len_ln/2); i++)
            printf(" ");
        cout << ln ;
        for(int i(0); i < (len_ln/2)+add_ln; i++)
            printf(" ");
        printf("|\n");
        printf("+-----------------------------------------------------------------------------+\n");
    }
    cout << "\n Total : " << t << "\n\n";
    file.close();
}
void Student::select_all()
{
    string fn = "" , ln(""), ima("");
    string  line("");
    bool im(true), first(false), last(false);
    ifstream file("student");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|        NUMERO           |           NOM           |         PRENOM          |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    while(getline(file, line))
    {
        fn = "";
        im = true;
        first = false;
        ln = "";
        ima = "";
        for(int i(0); i < line.size(); i++)
        {
            if(im) {
                if(line[i] == ','){
                    im = false;
                    first = true;
                    continue;
                } else {
                    ima += line[i];
                }

            }
            else if(first){
                if(line[i] == ','){
                    first = false;
                    last = true;
                    continue;
                } else {
                    fn += line[i];
                }
            }
            else {
                 if(line[i] == ','){
                     break;
                 }else {
                    ln += line[i];
                }
            }
        }
        int len_im(0), len_fn = 0, len_ln = 0, add_im(0), add_fn = 0, add_ln = 0;
        // Affichage de IM
        len_im = 25 - ima.size();
        add_im = (len_im % 2 == 0) ? 0 : 1;
        printf("|");
        for(int i(0); i < (len_im/2); i++)
            printf(" ");
        cout << ima ;
        for(int i(0); i < (len_im/2)+add_im; i++)
            printf(" ");
        printf("|");
        // Affichage de NOM
        len_fn = 25 - fn.size();
        add_fn = (len_fn % 2 == 0) ? 0 : 1;
        for(int i(0); i < (len_fn/2); i++)
            printf(" ");
        cout << fn ;
        for(int i(0); i < (len_fn/2)+add_fn; i++)
            printf(" ");
        printf("|");
        // Affichage de Prenom
        len_ln = 25- ln.size();
        add_ln = (len_ln % 2 == 0) ? 0 : 1;
        for(int i(0); i < (len_ln/2); i++)
            printf(" ");
        cout << ln ;
        for(int i(0); i < (len_ln/2)+add_ln; i++)
            printf(" ");
        printf("|\n");
        printf("+-----------------------------------------------------------------------------+\n");
    }
    cout << "\n Total : " << Student::total() << "\n\n";
    file.close();
}
int Student::search_student()
{
    string fn = "" , ln = ""; // Variable pour stocker le resultat
    string  line, card;
    ifstream file("student");
    string card_input;
    cout << "\nEntrer le numero de l'etudiant : ";
    cin >> card_input;
    printf("\n+-----------------------------------------+\n");
    printf("|         NOM        |       PRENOM        |\n");
    printf("+--------------------+---------------------+\n");
    while(getline(file, line))
    {
        string tmp = "";
        for(int it(0); it < line.size(); it++)
        {
            if(line[it] == ',')
                break;
            tmp += line[it];
        }
        if(tmp == card_input)
        {
            bool fist(true),  last(true);
            for(int i(tmp.size()+1); i < line.size(); i++)
            {
                if(line[i] == ',' && fist == false)
                    break;
                if(line[i] == ',') {
                    fist = false;
                    continue;
                }
                if(fist){
                    fn += line[i];
                    continue;
                }
                ln += line[i];
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
void Student::delete_all()
{
    char confirm = 'N';
    cout << "Voulez-vous vraiment supprimer tous les "<< Student::total()<<" Etudiant (O/N) :";
    cin >> confirm;
    if(confirm == 'O')
    {
        ofstream file("student");
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
int Student::total()
{
    ifstream file("student");
    int i(0);
    string data;
    while(getline(file, data))
    {
        i++;
    }
    file.close();
    return i;
}
int Student::delete_student()
{
    string first_name;
    string card;
    ifstream file("student");
    cout << "\tEntrer le numero de l'etudiant  a supprimer : ";
    cin >> card;
    cin.ignore();
    cout << "\tEntrer le nom de l'etudiant a supprimer : ";
    getline(cin, first_name);
    int i(0);
    Student students[Student::total()];
    string line;
    while(getline(file, line))
    {
        bool im = true, first = false, last;
        string ima("");
        for(int j(0); j< line.size(); j++)
        {
            if(im) {
                if(line[j] == ','){
                    im = false;
                    first = true;
                    students[i].m_card = ima;
                    continue;
                } else {
                    ima += line[j];
                }

            }
            else if(first){
                if(line[j] == ','){
                    first = false;
                    last = true;
                    continue;
                } else {
                    students[i].m_first_name += line[j];
                }
            }
            else if(last){
                if(line[j] == ','){
                    last = false;
                    continue;
                } else {
                    students[i].m_last_name += line[j];
                }
            }
            else {
                students[i].m_mention = line.substr(j);
                break;
            }
        }
        if(students[i].m_card == card && students[i].m_first_name != first_name)
        {
            cout << "\n\tImpossible de supprimer : (Le nom ne correspond pas a cette numero)\n"<<endl;
            return 0;
        }
        i++;
    }
    bool error(true);
    for(int it(0); it  < i; it++)
    {
        if(students[it].m_card == card)
            error = false;
    }
    if(error)
    {
        cout << "\n\tImpossible de supprimer : Numero n'existe pas\n" << endl;
        return 0;
    }
    file.close();
    ofstream fileSuppression("student");
    fileSuppression<"";
    fileSuppression.close();
    ofstream fileInsertion("student", ios::app);
    for(int j(0); j < i; j++)
    {
       if(students[j].m_card != card)
        {
            fileInsertion  << students[j].m_card << "," << students[j].m_first_name << "," << students[j].m_last_name<< "," << students[j].m_mention<< endl ;
        }
    }
    fileInsertion.close();
    cout << endl << "\t----------Suppression reussie----------\n" << endl;
    return 0;
}
int Student::add()
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
    cout << "\tMention : \n";
    cout << "\t1.Genie industriel" << endl;
    cout << "\t2.Genie civil" << endl;
    cout << "\t3.Numerique" << endl;
    cout << "\t>> ";
    getline(cin, mention);
    if(mention == "1"){
        mention = "gi";
    }
    else if(mention == "2") {
        mention = "gc";
    }
    else if(mention == "3") {
        mention = "n";
    }
    else {
        cout << "\n\tLe mention que vous avez indique n'est pas disponible\n"<<endl;
        return 0;
    }
    file.open("student", ios::app);
    if(file)
    {
        file  << card << "," << first_name  << "," << last_name << "," <<  mention << endl;
        cout << "\n\t----------Ajout reussie----------" << endl;
    }
    else
    {
        cout << endl << "\t----------Erreur :  Impossible d'ajouter----------" << endl;
    }
    cout << endl;
    file.close();
    return 0;
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
