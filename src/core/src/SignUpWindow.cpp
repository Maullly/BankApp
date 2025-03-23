#include "../include/SignUpWindow.h"
#include "../include/BankApp.h"
#include "../include/Osoba.h"
#include <QMessageBox>
#include <QDebug>
#include <fstream>
SignUpWindow::SignUpWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.BackButton, &QPushButton::clicked, this, &SignUpWindow::on_BackButton_clicked);
	connect(ui.RegistrationButton, &QPushButton::clicked, this, &SignUpWindow::on_RegistrationButton_clicked);
}

SignUpWindow::~SignUpWindow()
{
}
void SignUpWindow::setLog(BankApp* mainApp)
{
	main = mainApp;
}
void SignUpWindow::on_RegistrationButton_clicked()
{
	QString login = ui.LoginEdit->toPlainText();
	QString pin = ui.PinEdit->toPlainText();
	QString imie = ui.NameEdit->toPlainText();
	QString nazwisko = ui.SurnameEdit->toPlainText();
	QString dataUrodzenia = ui.dateEdit->text();
	QString email = ui.EmailEdit->toPlainText();
	QString miasto = ui.CityEdit->toPlainText();
	QString kodPocztowy = ui.ZipCodeEdit->toPlainText();
	QString ulica = ui.StreetEdit->toPlainText();
	QString numerDomu = ui.HouseNumberEdit->toPlainText();
	if (login.isEmpty() || pin.isEmpty() || imie.isEmpty() || nazwisko.isEmpty() || dataUrodzenia.isEmpty() || email.isEmpty() || miasto.isEmpty() || kodPocztowy.isEmpty() || ulica.isEmpty() || numerDomu.isEmpty()){
		QMessageBox::warning(this, "Blad", "Wszystkie pola musza byc wypelnione!");
		return;
	}
	QRegularExpression regex("^[0-9]{8}$");
	if (!regex.match(login).hasMatch()) {
		QMessageBox::warning(this, "Blad", "Numer konta musi sk³adaæ siê dok³adnie z 8 cyfr!");
		return;
	}
	QRegularExpression pinRegex("^[0-9]{1,4}$");
	if (!pinRegex.match(pin).hasMatch()) {
		QMessageBox::warning(this, "B³¹d", "PIN mo¿e sk³adaæ siê maksymalnie z 4 cyfr!");
		return;
	}
	Osoba nowaOsoba(login.toStdString(), pin.toStdString(), imie.toStdString(),
		nazwisko.toStdString(), dataUrodzenia.toStdString(), email.toStdString(),
		miasto.toStdString(), kodPocztowy.toStdString(), ulica.toStdString(),
		numerDomu.toStdString(), 0.0);
	nowaOsoba.zapiszDoPliku();
	QMessageBox::information(this, "Sukces", "Rejestracja zakonczona pomyslnie!");
	if (main) {
		main->show();
		close();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Main window not set");
	}
}	
void SignUpWindow::on_BackButton_clicked()
{
	if (main) {
		main->show();
		close();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Main window not set");
	}
}

