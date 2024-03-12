//
// Created by tenni on 02/06/2023.
//

#include "Ui.h"
#include <cstring>
#include <exception>
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\exceptii\Validator.h"

Ui::Ui(Service &service){
    this->service = &service;
}

void Ui::printMenu() {
    cout<<endl;
    cout<<"1.adaugare destinatie: "<<endl;
    cout<<"2.afisare lista destinatie: "<<endl;
    cout<<"3.modif destinatie: "<<endl;
    cout<<"4.stergere destinatie: "<<endl;
    cout<<"5.sortare dupa pret: "<<endl;
    cout<<"6.Lista comenzi numerice: "<<endl;
    cout<<"7.sortare dupa distanta: "<<endl;
    cout<<"8.sortare dupa nume: "<<endl;
}

void Ui::printEntitati() {
    for (const auto p:this->service->getAll())
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<", Distanta: "<<p->getDistanta()<<endl;
}

void Ui::addEntitate() {
    try{
        int pret;
        int distanta;
        string name_str;
        string raw_cod;
        cout<<"Introduceti codul produsului: ";
        cin>>raw_cod;
        cout<<"Introduceti numele produsului: ";
        cin>>name_str;
        cout<<"Introduceti pretul produsului: ";
        cin>>pret;
        cout<<"distanta: ";
        cin>>distanta;
        char* name = new char[name_str.length() + 1];
        strcpy(name, name_str.c_str());
        int cod = Validator::isNumber(raw_cod);
        this->service->addEntitate(cod, name, pret,distanta);
    }

    catch (std::exception &e){
        cout<<e.what()<<endl;
    }
}

void Ui::deleteEntitate() {
    try{
        string raw_cod;
        cout<<"dati codul produsului: ";
        cin>>raw_cod;
        int cod = Validator::isNumber(raw_cod);
        this->service->deleteEntitate(cod);
    }
    catch (std::exception &e){
        cout<<e.what()<<endl;
    }
}

void Ui::modifyEntitate() {
    try{
        int pret;
        int distantaN;
        string name_str;
        string raw_cod;
        cout<<"dati codul de modificat: ";
        cin>>raw_cod;
        cout<<"numele nou: ";
        cin>>name_str;
        cout<<"pretul nou: ";
        cin>>pret;
        cout<<"distanta 9: ";
        cin>>distantaN;
        char* name = new char[name_str.length() + 1];
        strcpy(name, name_str.c_str());
        int cod = Validator::isNumber(raw_cod);
        this->service->modifyEntitate(cod, name, pret,distantaN);
    }

    catch(std::exception &e){
        cout<<e.what()<<endl;
        return;
    }
}

void Ui::sortEntitateByPrice() {
    vector <Entitate *> sorted = this->service->sortByPrice();
    for (const auto p: sorted){
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<", Distanta: "<<p->getDistanta()<<endl;
    }
}

void Ui::sortEntitateById(){
    vector <Entitate *> sorted = this->service->sortById();
    for (const auto p: sorted){
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<", Distanta: "<<p->getDistanta()<<endl;
    }
}

void Ui::sortEntitateByName(){
    vector <Entitate *> sorted = this->service->sortByName();
    for (const auto p: sorted){
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<", Distanta: "<<p->getDistanta()<<endl;
    }
}

void Ui::help1() {
    cout<<endl;
    cout<<"Lista comenzi numerice:"<<endl;
    cout<<"1-Adauga destinatie"<<endl;
    cout<<"2-Afiseaza destinatiile introduse pana acum"<<endl;
    cout<<"3-Modifica o destinatie"<<endl;
    cout<<"4-Sterge o destinatie"<<endl;
    cout<<"5-Sorteaza crescator destinatiile dupa pret"<<endl;
    cout<<"7-sorteaza dupa distanta"<<endl;
    cout<<"8-sorteaza dupa nume"<<endl;
    cout<<"orice alt numar-iese din program"<<endl;
}

int Ui::start() {
    //this->bancnote();
    //int opt;
    string raw_opt;
    while (true) {
        this->printMenu();
        cout << "optiunea: ";
        cin >> raw_opt;
        //int opt = Validator::isNumber(raw_opt);

        try {
            int opt = Validator::isNumber(raw_opt);
            switch (opt) {
                case 1:
                    this->addEntitate();
                    break;
                case 2:
                    this->printEntitati();
                    break;
                case 3:
                    this->modifyEntitate();
                    break;
                case 4:
                    this->deleteEntitate();
                    break;
                case 5:
                    this->sortEntitateByPrice();
                    break;
                case 6:
                    this->help1();
                    break;
                case 7:
                    this->sortEntitateById();
                    break;
                case 8:
                    this->sortEntitateByName();
                    break;
                case 0:
                    break;
                default:
                    return 0;
            }
        } catch (std::exception &e) {
            cout << e.what() << endl;
        }
    }

}