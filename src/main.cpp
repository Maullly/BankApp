#include "./core/include/BankApp.h"
#include <QtWidgets/QApplication>
#include <fstream>
void checkAndCreateFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {  // Je�li plik nie istnieje, utw�rz go
        std::ofstream newFile(filename);
        newFile.close();
    }
}
int main(int argc, char *argv[])
{
    // Sprawdzenie i utworzenie plik�w, je�li nie istniej�
    checkAndCreateFile("./src/login.txt");
    checkAndCreateFile("./src/transactions.txt");
    QApplication a(argc, argv);
    BankApp w;
    w.show();
    return a.exec();
}
