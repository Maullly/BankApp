#include "./core/include/BankApp.h"
#include <QtWidgets/QApplication>
#include <fstream>
void checkAndCreateFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {  // Jeœli plik nie istnieje, utwórz go
        std::ofstream newFile(filename);
        newFile.close();
    }
}
int main(int argc, char *argv[])
{
    // Sprawdzenie i utworzenie plików, jeœli nie istniej¹
    checkAndCreateFile("./src/login.txt");
    checkAndCreateFile("./src/transactions.txt");
    QApplication a(argc, argv);
    BankApp w;
    w.show();
    return a.exec();
}
