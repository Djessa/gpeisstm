#include <iostream>
#include "Personal.h"
#include "Student.h"
using namespace std;

int main()
{
    int choice = 0;
    cout << "\n*************************************\n\n" <<endl;
    cout << "         Bienvenue au GPEISSTM\n" << endl;
    cout << "            Logiciel ISSTM\n\n" << endl;
    cout << "*************************************\n" <<endl;
    while(choice != 11)
    {
        cout << "Menu principale (I):\n\n" <<endl;
        cout << "1.Ajouter nouveau PAT" <<endl;
        cout << "2.Ajouter nouveau Etudiant" <<endl;
        cout << "3.Supprimer un PAT" << endl;
        cout << "4.Supprimer un Etudiant" << endl;
        cout << "5.Supprimer tous les PAT" <<endl;
        cout << "6.Supprimer tous les Etudiant" <<endl;
        cout << "7.Chercher un PAT ou un Etudiant" << endl;
        cout << "8.Afficher le nombre personnel (PAT)" << endl;
        cout << "9.Afficher les nombres de Etudiant" <<endl;
        cout << "10.Afficher les noms des etudiants par mention" << endl;
        cout << "11.Quitter\n" << endl;
        cout << ">> Entrer votre choix : ";
        cin >> choice;
        switch(choice)
        {
            case 1: Personal::add();break;
            case 2: Student::add();break;
            case 3: Personal::delete_personal();break;
            case 4: Student::delete_student();break;
            case 5: Personal::delete_all();break;
            case 6: Student::delete_all();break;
            case 7:
                cout << "\n0.Chercher un PAT";
                cout << "\n1.Chercher un etudiant";
                int prompt;
                cout << "\n>> ";
                cin >> prompt;
                if(prompt == 0)
                {
                    Personal::search_personal();
                }
                else if(prompt == 1)
                {
                    Student::search_student();
                }
                break;
            case 8:Personal::select_all();break;
            case 9:Student::select_all();break;
            case 10:Student::select_mention();break;
        }
    }
    return 0;
}
