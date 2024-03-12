//
// Created by tenni on 02/06/2023.
//

#include "FileRepository.h"

#include <fstream>
#include <sstream>

FileRepository::FileRepository(const string& fileName) : fileName(fileName) {
    this->fileName = fileName;
    loadFromFile();
}

void FileRepository::loadFromFile() {
    ifstream f(this->fileName);

    if (!f.is_open()){
        cout<<"Fisierul nu a putut fi deschis!";
        return;
    }

    entitati.clear();

    while (!f.eof()){
        int cod, pret, distanta;
        string name_str;
        string sa;
        while( f >> cod >> name_str >> pret >> distanta){
            //getline(f,sa,',');
            char* name = new char[name_str.length() + 1];
            strcpy(name, name_str.c_str());
            Entitate product = Entitate(cod, name, pret,distanta);
            Entitate *p = new Entitate(product);
            this->entitati.push_back(p);
        }
    }
    f.close();
}

void FileRepository::saveToFile() {

    ofstream file(fileName);

    if (!file.is_open()){
        cout<<"Fisierul nu a putut fi deschis!";
        return;
    }

    for (const auto &p: Repository :: getAll()){
        file<<p->getCod()<<" "<<p->getName()<<" "<<p->getPret()<<" "<<p->getDistanta()<<endl;
    }
    file.close();
}

void FileRepository::addEntitate(Entitate &product) {
    Repository::addEntitate(product);
    saveToFile();
}

void FileRepository::modifyEntitate(Entitate &product) {
    Repository::modifyEntitate(product);
    saveToFile();
}

void FileRepository::deleteEntitate(int cod) {
    Repository::deleteEntitate(cod);
    saveToFile();
}

vector<Entitate *> FileRepository::getAll() {
    loadFromFile();
    return entitati;
}

int FileRepository::getCurrentSize() {
    loadFromFile();
    return Repository::getCurrentSize();
}
