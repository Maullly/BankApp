#include "../include/Osoba.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
static std::string Plik = "../login.txt";
Osoba::Osoba(const std::string& numerKonta, const std::string& pin, const std::string& imie,
    const std::string& nazwisko, const std::string& dataUrodzenia, const std::string& email,
    const std::string& miasto, const std::string& kodPocztowy, const std::string& ulica,
    const std::string& numerDomu, double stanKonta)
    : numerKonta(numerKonta), pin(pin), imie(imie), nazwisko(nazwisko),
    dataUrodzenia(dataUrodzenia), email(email), miasto(miasto),
    kodPocztowy(kodPocztowy), ulica(ulica), numerDomu(numerDomu), stanKonta(stanKonta) {
}



std::string Osoba::getNumerKonta() const { return numerKonta; }
std::string Osoba::getPin() const { return pin; }
std::string Osoba::getImie() const { return imie; }
std::string Osoba::getNazwisko() const { return nazwisko; }
std::string Osoba::getDataUrodzenia() const { return dataUrodzenia; }
std::string Osoba::getEmail() const { return email; }
std::string Osoba::getMiasto() const { return miasto; }
std::string Osoba::getKodPocztowy() const { return kodPocztowy; }
std::string Osoba::getUlica() const { return ulica; }
std::string Osoba::getNumerDomu() const { return numerDomu; }
double Osoba::getStanKonta() const { return stanKonta; }


void Osoba::setPin(const std::string& newPin) { pin = newPin; }
void Osoba::setEmail(const std::string& newEmail) { email = newEmail; }

bool Osoba::wyplacSrodki(double kwota) {
    if (stanKonta >= kwota) {
        stanKonta -= kwota;
        return true;
    }
    return false;
}

void Osoba::zapiszDoPliku() const {
    std::ofstream plik("./src/login.txt", std::ios::app);
    if (plik.is_open()) {
        plik << numerKonta << "," << pin << "," << imie << "," << nazwisko << ","
            << dataUrodzenia << "," << email << "," << miasto << ","
            << kodPocztowy << "," << ulica << "," << numerDomu << "," << stanKonta << "\n";
        plik.close();
    }
    else {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu!\n";
    }
}
void Osoba::dodajTransakcje(const std::string& opis, double stanPrzed, double stanPo) {
    std::ofstream file("./src/transactions.txt", std::ios::app); // Otwieramy plik w trybie dopisywania
    if (!file) {
        std::cerr << "Nie mo¿na otworzyæ pliku transactions.txt do zapisu!" << std::endl;
        return;
    }

    // Pobranie aktualnej daty
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");  // Format daty: DD-MM-YYYY
    std::string currentDate = oss.str();

    // Zapisujemy dane do pliku w nowym formacie
    file << imie << "," << nazwisko << "," << currentDate << ","
        << opis << "," << stanPrzed << "," << stanPo << "," << numerKonta << "\n";

    file.close();
}

bool Osoba::sprawdzLogowanie(const std::string& Plik, const std::string& konto, const std::string& podanyPin) {
    std::ifstream plik(Plik);
    if (!plik.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku do odczytu!\n";
        return false;
    }

    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        std::string numer, pin;

        std::getline(iss, numer, ','); // Pobiera login
        std::getline(iss, pin, ',');   // Pobiera PIN

        // Usuñ ewentualne spacje z pocz¹tku numeru
        numer.erase(0, numer.find_first_not_of(" "));

        if (numer == konto && pin == podanyPin) {
            return true;
        }
    }

    return false;
}

