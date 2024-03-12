//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_FILEREPOSITORY_H
#define EXAMEN_PRA_POO_V1_FILEREPOSITORY_H

#pragma once
#include "Repository.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

class FileRepository : public Repository {
private:
    string fileName;

public:
    FileRepository(const string& fileName);
    void loadFromFile();
    void saveToFile();

    void addEntitate(Entitate &product) override;
    void modifyEntitate(Entitate &product) override;
    void deleteEntitate(int cod) override;
    vector<Entitate *> getAll() override;
    int getCurrentSize() override;

};


#endif //EXAMEN_PRA_POO_V1_FILEREPOSITORY_H
