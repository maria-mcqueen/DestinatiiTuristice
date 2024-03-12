////
//// Created by tenni on 02/06/2023.
////
//
//#include "Teste.h"
//
//#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\entitate\Entitate.h"
//#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\repo\Repository.h"
//#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\service\Service.h"
//#include "C:\Users\tenni\CLionProjects\examen_pra_poo_v3\repo\FileRepository.h"
//#include <string.h>
//#include <cassert>
//
//void testProduct(){
//    /// test constructor implicit
//    Entitate p;
//    assert (p.getName() == NULL);
//    assert (p.getCod() == 0);
//    assert (p.getPret() == 0);
//
//    /// test constructor cu parametri
//    Entitate pr(1, "croisant", 5);
//    assert (strcmp(pr.getName(), "croisant") == 0);
//    assert (pr.getCod() == 1);
//    assert (pr.getPret() == 5);
//
//    /// test copy constructor
//    Entitate pr1 = Entitate(pr);
//    assert (pr1.getCod() == 1);
//    assert (pr1.getPret() == 5);
//    assert (strcmp(pr1.getName(), "croisant") == 0);
//}
//
//void testRepo(){
//    /// test constructor
//    Repository repo;
//    assert (repo.getCurrentSize() == 0);
//
//    /// test adaugare
//    Entitate pr1(1, "croisant", 5);
//    Entitate pr2(2, "suc", 4);
//    repo.addEntitate(pr1);
//    repo.addEntitate(pr2);
//    assert (repo.getCurrentSize() == 2);
//
//    /// test getAll
//    vector <Entitate *> products = repo.getAll();
//    assert (pr1 == Entitate(*products[0]));
//    assert (pr2 == Entitate(*products[1]));
//}
//
//void test_delete_repo(){
//    Repository repo;
//    Entitate product1 = Entitate(1, "carne", 5);
//    Entitate product2 = Entitate(2, "cascaval", 4);
//    Entitate product3 = Entitate(3, "sunca", 12);
//    repo.addEntitate(product1), repo.addEntitate(product2), repo.addEntitate(product3);
//
//    repo.deleteEntitate(2);
//    assert (repo.getCurrentSize() == 2);
//    vector <Entitate *> products = repo.getAll();
//    assert (Entitate(*products[0]) == product1);
//    assert (Entitate(*products[1]) == product3);
//}
//
//void testService(){
//    Repository repo;
//    Entitate product(1, "croisant", 5);
//    repo.addEntitate(product);
//
//    /// test constructor
//    Service service = Service(repo);
//    assert (service.getCurrentSize() == 1);
//
//    /// test add
//    service.addEntitate(2, "suc", 4);
//    assert (service.getCurrentSize() == 2);
//
//    /// test getAll
//    vector <Entitate *> products = service.getAll();
//    assert (product == Entitate(*products[0]));
//    assert (products[1]->getCod() == 2);
//    assert (products[1]->getPret() == 4);
//    assert (strcmp(products[1]->getName(), "suc") == 0);
//}
//
//
//void test_sort_by_price(){
//    Repository repo;
//    Entitate product1 = Entitate(1, "carne", 5);
//    Entitate product2 = Entitate(2, "cascaval", 4);
//    Entitate product3 = Entitate(3, "sunca", 12);
//    repo.addEntitate(product1), repo.addEntitate(product2), repo.addEntitate(product3);
//    Service service = Service(repo);
//
//    vector <Entitate *> sorted = service.sortByPrice();
//    assert (product2 == Entitate(*sorted[0]));
//    assert (product1 == Entitate(*sorted[1]));
//    assert (product3 == Entitate(*sorted[2]));
//
//}
//
//
//
//void test_file_repo(){
//    FileRepository repo = FileRepository("C:\\Users\\tenni\\CLionProjects\\examen_pra_poo_v1\\entitati.txt");
//
//    /// test citire din fisier
//    vector <Entitate *> products = repo.getAll();
//    assert (products.size() == 7);
//
//    /// test adaugare in fisier
//    Entitate product1 = Entitate(8, "carne", 11);
//    repo.addEntitate(product1);
//    products = repo.getAll();
//    assert (products.size() == 8);
//    //assert (product1 == Product(*products[7]));
//
//    /// test modificare in fisier
//    Entitate product2 = Entitate(9, "carne", 10);
//    repo.modifyEntitate(product2);
//    products = repo.getAll();
//    //assert (product2 == Product(*products[7]));
//
//    /// test stergere in fisier
//    repo.deleteEntitate(8);
//    products = repo.getAll();
//    assert (products.size() == 7);
//}
//
//void test_all() {
//    testProduct();
//    testRepo();
//    testService();
//    test_delete_repo();
//    test_sort_by_price();
//    test_file_repo();
//
//}
//
