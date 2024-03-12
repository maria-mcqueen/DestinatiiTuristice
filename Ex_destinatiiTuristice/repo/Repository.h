//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_REPOSITORY_H
#define EXAMEN_PRA_POO_V1_REPOSITORY_H


#include <iostream>
#include <vector>
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\entitate\Entitate.h"

using namespace std;

class Repository {
private:
    int currentEntitateSize = 0;

protected:
    vector <Entitate *> entitati;

public:
    Repository();
    virtual int getCurrentSize();
    virtual void addEntitate(Entitate &entitate);
    virtual void deleteEntitate(int cod);
    virtual void modifyEntitate(Entitate &newEntitate);
    virtual vector<Entitate *> getAll();
};


#endif //EXAMEN_PRA_POO_V1_REPOSITORY_H
