#include "../include/LoginWindow.h"
#include "../include/BankApp.h"
#include "../include/Osoba.h"
#include "../include/LoggedInWindow.h"
#include <QMessageBox>
#include <QDebug>

LoginWindow::LoginWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.BackButton, &QPushButton::clicked, this, &LoginWindow::on_BackButton_clicked);
	connect(ui.LogIntoButton, &QPushButton::clicked, this, &LoginWindow::on_LogIntoButton_clicked);
}

LoginWindow::~LoginWindow()
{

}

void LoginWindow::setLog(BankApp* mainApp)
{
	main = mainApp;
}

void LoginWindow::on_LogIntoButton_clicked()
{
	QString login = ui.LoginEdit->toPlainText();
	QString pin = ui.PasswordEdit->toPlainText();
	if (login.isEmpty() || pin.isEmpty()) {
		QMessageBox::warning(this, "Blad", "Wszystkie pola musza byc wypelnione!");
		return;
	}
	if (Osoba::sprawdzLogowanie("./src/login.txt", login.toStdString(), pin.toStdString())) {
		QMessageBox::information(this, "Sukces", "Zalogowano pomyslnie!");
		if (log) {
			delete log;  // Usuñ stare okno, jeœli istnia³o
			log = nullptr;
		}

		log = new LoggedInWindow();
		log->setLog(main);
		log->AccNumber(login.toStdString());
		log->show();
		close();  // Zamykamy LoginWindow
	}
	else {
		QMessageBox::warning(this, "Blad", "Niepoprawne dane logowania!");
	}
}

void LoginWindow::on_BackButton_clicked()
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
