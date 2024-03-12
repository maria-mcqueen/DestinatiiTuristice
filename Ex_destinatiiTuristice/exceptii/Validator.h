//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_VALIDATOR_H
#define EXAMEN_PRA_POO_V1_VALIDATOR_H

#include <iostream>
#include <string>
#include "ExceptieCustomNumber.h"
#include "ExceptieGenerala.h"

class Validator {
public:
    static int isNumber(std::string possible_number) {
        try {
            return std::stoi(possible_number);
        } catch (std::exception e) { // <- bad practice
            throw ExceptieCustomNumber("Received parameter " + possible_number + " is not a number");
        }
    }

    static int isName(std::string option) {
        try {
            if(isdigit(option[1])==0)
                return 0;
        } catch (std::exception e) { // <- bad practice
            throw ExceptieCustomNumber("Received parameter " + option + " is not a string");
        }
    }

};


#endif //EXAMEN_PRA_POO_V1_VALIDATOR_H
