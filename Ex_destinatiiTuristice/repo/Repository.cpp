//
// Created by tenni on 02/06/2023.
//

#include "Repository.h"


#include "string.h"


Repository::Repository() {

}

int Repository::getCurrentSize() {
    return this->currentEntitateSize;
}

void Repository::addEntitate(Entitate &entitate) {
    Entitate *p = new Entitate(entitate);
    this->entitati.push_back(p);
    this->currentEntitateSize++;
}

vector<Entitate *> Repository::getAll() {
    return this->entitati;
}

void Repository::deleteEntitate(int cod) {
    int position = 0; // poz elem de sters

    for (const auto p: this->getAll()){
        if (p->getCod() == cod){
            this->currentEntitateSize--;

            for (int j = position; j < this->getCurrentSize(); j++)
                this->entitati.at(j) = this->entitati.at(j+1);

            this->entitati.pop_back();
            break;
        }
        position++;
    }
}

void Repository::modifyEntitate(Entitate &newEntitate) {
    int cod = newEntitate.getCod();
    int i = 0;
    for (const auto p:this->getAll()){
        if (p->getCod() == cod){
            this->entitati[i]->setPret(newEntitate.getPret());
            char* newName = new char[strlen(newEntitate.getName()) + 1];
            strcpy_s(newName, strlen(newEntitate.getName()) + 1, newEntitate.getName());
            this->entitati[i]->setName(newName);
            this->entitati[i]->setDistanta(newEntitate.getDistanta());
            break;
        }
        i++;
    }
}
