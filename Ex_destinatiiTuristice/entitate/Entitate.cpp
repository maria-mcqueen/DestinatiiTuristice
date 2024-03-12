//
// Created by tenni on 02/06/2023.
//

#include "Entitate.h"
#include <string.h>

Entitate::Entitate() {
    this->cod = 0;
    this->pret = 0;
    this->name = NULL;
    this->distanta = 0;
}

Entitate::Entitate(int cod, char *name, int pret,int distanta) {
    this->cod = cod;
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->pret = pret;
    this->distanta = distanta;
}

int Entitate::getCod() {
    return this->cod;
}

char *Entitate::getName() {
    return this->name;
}

int Entitate::getPret() {
    return this->pret;
}

int Entitate::getDistanta() {
    return this->distanta;
}

Entitate::Entitate(Entitate &otherEntitate) {
    this->cod = otherEntitate.getCod();
    this->pret = otherEntitate.getPret();
    this->distanta = otherEntitate.getDistanta();
    this->name = new char[strlen(otherEntitate.getName()) + 1];
    strcpy_s(this->name, strlen(otherEntitate.getName()) + 1, otherEntitate.getName());
}

bool Entitate::operator==(Entitate other) {
    if (this->cod != other.getCod())
        return false;
    if (strcmp (this->name, other.getName()) != 0)
        return false;
    if (this->pret != other.getPret())
        return false;
    return true;
}

void Entitate::setPret(int newPret) {
    this->pret = newPret;
}

void Entitate::setName(char *newName) {
    this->name = new char[strlen(newName) + 1];
    strcpy_s(this->name, strlen(newName) + 1, newName);
}

void Entitate::setDistanta(int newDistanta) {
    this->distanta = newDistanta;
}

