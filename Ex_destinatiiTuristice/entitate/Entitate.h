//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_ENTITATE_H
#define EXAMEN_PRA_POO_V1_ENTITATE_H


class Entitate {
private:
    int cod;
    char* name;
    int pret;
    int distanta;
public:
    Entitate();
    Entitate(int cod, char* name, int pret,int distanta);
    Entitate(Entitate &otherEntitate);


    int getCod();
    char* getName();
    int getPret();
    int getDistanta();

    void setPret(int newPret);
    void setName(char* newName);
    void setDistanta(int newDistanta);

    bool operator == (Entitate other);

};


#endif //EXAMEN_PRA_POO_V1_ENTITATE_H
