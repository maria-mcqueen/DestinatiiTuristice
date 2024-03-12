#include <iostream>
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\repo\FileRepository.h"
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\ui\Ui.h"
#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\teste\Teste.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    test_all();

    FileRepository repo = FileRepository("C:\\Users\\tenni\\CLionProjects\\examen_pra_poo_v3\\entitati.txt");
    Service service = Service(repo);
    Ui ui = Ui(service);

    ui.start();


    return 0;
}
