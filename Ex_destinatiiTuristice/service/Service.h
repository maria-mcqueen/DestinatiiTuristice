//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_SERVICE_H
#define EXAMEN_PRA_POO_V1_SERVICE_H

#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\repo\Repository.h"

class Service {
private:
    Repository *repo;

public:
    Service() = default;
    Service(Repository &repo);
    int getCurrentSize();
    vector <Entitate *> getAll();
    Entitate getByCode(int cod);
    void addEntitate(int cod, char* name, int pret,int distanta);
    void deleteEntitate(int cod);
    void modifyEntitate(int cod, char* newName, int newPret,int newDistanta);
    vector<Entitate *> sortByPrice();
    vector<Entitate *> sortById();
    vector<Entitate *> sortByName();
//    vector<Entitate *> filterPriceHigherThan(int limit);

//    void addBancnota(int valoare);
//    vector<int> getAllBancnote();
//    void deleteBancnota(int valoare);
//
//    static int changeOccurrenceToBanknote(int i);
//    vector<int> buyProduct(int rest);

};


#endif //EXAMEN_PRA_POO_V1_SERVICE_H
