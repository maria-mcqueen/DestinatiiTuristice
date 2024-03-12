//
// Created by tenni on 02/06/2023.
//

#include <algorithm>
#include "Service.h"
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\entitate\Entitate.h"

Service::Service(Repository &repo) {
    this->repo = &repo;

}

int Service::getCurrentSize() {
    return this->repo->getCurrentSize();
}

vector <Entitate *> Service::getAll(){
    return this->repo->getAll();
}

void Service::addEntitate(int cod, char *name, int pret,int distanta) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (exists)
        throw invalid_argument("Exista un alt produs in tonomat cu acest cod");
    if (pret < 0 || pret > 1000)
        throw invalid_argument("Pretul introdus nu este valid!");
    if (cod < 0 || cod > 1000)
        throw invalid_argument("Codul introdus nu este valid!");

    Entitate newProduct = Entitate(cod, name, pret,distanta);
    this->repo->addEntitate(newProduct);
}

void Service::deleteEntitate(int cod) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (exists == 0)
        throw invalid_argument("Produsul nu exista");
    else
        this->repo->deleteEntitate(cod);
}



void Service::modifyEntitate(int cod, char *newName, int newPret,int newDistanta) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (!exists)
        throw invalid_argument("Nu exista niciun produs cu acest cod");
    if (newPret < 0 || newPret > 1000)
        throw invalid_argument("Pretul introdus nu este valid!");
    if (cod < 0 || cod > 1000)
        throw invalid_argument("Codul introdus nu este valid!");

    Entitate newProduct = Entitate(cod, newName, newPret,newDistanta);
    this->repo->modifyEntitate(newProduct);
}

vector<Entitate *> Service::sortByPrice() {
    vector <Entitate *> entitati = this->getAll();
    sort(entitati.begin(), entitati.end(), [](Entitate *a, Entitate *b){ return (a->getPret() < b->getPret());});
    return entitati;
}

vector<Entitate *> Service::sortById() {
    vector <Entitate *> entitati = this->getAll();
    sort(entitati.begin(), entitati.end(), [](Entitate *a, Entitate *b){ return (a->getDistanta() < b->getDistanta());});
    return entitati;
}

vector<Entitate *> Service::sortByName() {
    vector <Entitate *> entitati = this->getAll();
    sort(entitati.begin(), entitati.end(), [](Entitate *a, Entitate *b){ return (a->getName()[0] < b->getName()[0]);});
    return entitati;
}

//vector<Product *> Service::filterPriceHigherThan(int limit) {
//    vector <Product *> products = this->getAll();
//    vector <Product *> filtered;
//
//    if (limit < 0 || limit > 1000)
//        throw invalid_argument("Nu e bine");
//
//    for (const auto p: products){
//        if (p->getPret() > limit)
//            filtered.push_back(p);
//    }
//
//    return filtered;
//}

Entitate Service::getByCode(int cod) {
    for (const auto p:this->getAll()){
        if (p->getCod() == cod){
            return *p;
        }
    }
    throw invalid_argument("Codul nu este valid uwu"); // daca nu am returnat nimic
}



