cmake_minimum_required(VERSION 3.24)
project(examen_pra_poo_v1)

set(CMAKE_CXX_STANDARD 17)

add_executable(examen_pra_poo_v1 main.cpp entitate/Entitate.h entitate/Entitate.cpp repo/Repository.h repo/Repository.cpp repo/FileRepository.h repo/FileRepository.cpp service/Service.h service/Service.cpp ui/Ui.h ui/Ui.cpp teste/Teste.h teste/Teste.cpp exceptii/Validator.h exceptii/Validator.cpp exceptii/ExceptieGenerala.cpp exceptii/ExceptieCustomNumber.cpp)
