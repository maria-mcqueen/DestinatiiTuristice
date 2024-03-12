//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_UI_H
#define EXAMEN_PRA_POO_V1_UI_H

#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\service\Service.h"


class Ui {
private:
    Service *service;
    static void printMenu();
    void printEntitati();
    void addEntitate();
    void deleteEntitate();
    void modifyEntitate();
    void sortEntitateByPrice();
    void help1();
    void sortEntitateById();
    void sortEntitateByName();
//    void filterProductsHigherThan();
//
//    void addBancnota();
//    void printBancnote();
//    void deleteBancnota();
//
//    void buyProduct();

public:
    Ui() = default;
    Ui(Service &service);
    int start();

    //void bancnote();

};


#endif //EXAMEN_PRA_POO_V1_UI_H
