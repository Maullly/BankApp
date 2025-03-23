#ifndef OSOBA_H
#define OSOBA_H

#include <string>
#include <vector>

class Osoba {
private:
    std::string numerKonta;
    std::string pin;
    std::string imie;
    std::string nazwisko;
    std::string dataUrodzenia;
    std::string email;
    std::string miasto;
    std::string kodPocztowy;
    std::string ulica;
    std::string numerDomu;
    std::string Plik;
    double stanKonta;
    std::vector<std::string> historiaTransakcji;


public:
    Osoba(const std::string& numerKonta, const std::string& pin, const std::string& imie,
        const std::string& nazwisko, const std::string& dataUrodzenia, const std::string& email,
        const std::string& miasto, const std::string& kodPocztowy, const std::string& ulica,
        const std::string& numerDomu, double stanKonta = 0.0);
    // Zapisz dane do pliku
    void zapiszDoPliku() const;
    // Dodanie transakcji do historii
    void dodajTransakcje(const std::string& opis, double stanPrzed, double stanPo);
    static bool sprawdzLogowanie(const std::string& Plik, const std::string& numerKonta, const std::string& pin);

    // Gettery
    std::string getNumerKonta() const;
    std::string getPin() const;
    std::string getImie() const;
    std::string getNazwisko() const;
    std::string getDataUrodzenia() const;
    std::string getEmail() const;
    std::string getMiasto() const;
    std::string getKodPocztowy() const;
    std::string getUlica() const;
    std::string getNumerDomu() const;
    double getStanKonta() const;

    // Settery
    void setPin(const std::string& newPin);
    void setEmail(const std::string& newEmail);
    bool wyplacSrodki(double kwota);
};

#endif // OSOBA_H
