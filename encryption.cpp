#include "encryption.hpp"
#include "ui_form.h"

Encryption::Encryption(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Encryption)
{
    ui->setupUi(this);
}

Encryption::~Encryption()
{
    delete ui;
}

QString Encryption::createSubstitutionGrid(const QString& keyword) {
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString grid = keyword;

    for (QChar letter : keyword) {
        alphabet.remove(letter.toUpper());
    }
    grid += alphabet;
    return grid;
}

QString Encryption::polybiusEncrypt(const QString& message, const QString& keyword) {
    QString table = createSubstitutionGrid(keyword.toUpper());
    QString encryptedMessage = "";

    for (QChar letter : message) {
        // Vérifie si la lettre est alphabétique
        if (letter.isLetter()) {
            letter = letter.toUpper();

            // Trouve les coordonnées de la lettre dans la table
            int index = table.indexOf(letter);
            int row = (index / 5) + 1;
            int col = (index % 5) + 1;

            // Ajoute les coordonnées chiffrées au message
            encryptedMessage += QString::number(row) + QString::number(col  ) + " ";
        } else if (letter == ' ') {
            // Ajoute un caractère spécial pour représenter l'espace
            encryptedMessage += "00 ";
        }
    }

    return encryptedMessage.trimmed();
}

QString Encryption::polybiusDecrypt(const QString& encryptedMessage, const QString& keyword) {
    QString table = createSubstitutionGrid(keyword.toUpper());
    QString decryptedMessage = "";

    // Divise le message chiffré en paires de coordonnées
    QStringList coordinates = encryptedMessage.split(' ');

    // Parcourt chaque paire de coordonnées
    for (const QString& coord : coordinates) {
        if (coord.length() >= 2) {
            int row = coord[0].digitValue();
            int col = coord[1].digitValue();

            // Vérifie si les coordonnées représentent un espace spécial
            if (row == 0 && col == 0) {
                decryptedMessage += ' ';
            } else {
                // Calcule l'index dans la table et ajoute la lettre déchiffrée
                int index = (row - 1) * 5 + (col - 1);
                if (index >= 0 && index < table.length()) {
                    decryptedMessage += table[index];
                }
            }
        }
    }

    return decryptedMessage;
}

// ...



void Encryption::on_pushButton_clicked()
{
    QString type = "";
    QString type2 = "";
    QString keyword = "";
    QString message = "";
    QString result = "";
    keyword = ui->lineEdit->text();
    message = ui->plainTextEdit->toPlainText();



    if(ui->radioButton->isChecked()){
        type = "Message chiffré";
        type2 = "chiffrer";
    }else if(ui->radioButton_2->isChecked()){
        type = "Message déchiffré";
        type2 = "déchiffrer";
    }


    if(message.isEmpty()){
        QMessageBox::critical(this,"Erreur","Le message à "+type2+" ne peut être vide.");
        return;
    }


    ui->display_type->setText(type);

    if(ui->radioButton->isChecked()){
        result = polybiusEncrypt(message,keyword);
    }else if(ui->radioButton_2->isChecked()){
        result = polybiusDecrypt(message,keyword);
    }

    ui->display_result->setText(result);
}



int Encryption::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool Encryption::isPrimeWith26(int a){
    return gcd(a, 26) == 1;
}


QString Encryption::encryptAffine(const QString &plaintext, int a, int b){
    QString ciphertext = "";

    for (QChar ch : plaintext) {
        if (ch.isLetter()) {
            QChar base = (ch.isUpper()) ? 'A' : 'a';
            int x = ch.toLatin1() - base.toLatin1();
            int y = (a * x + b) % 26;
            ciphertext.append(QChar(y + base.toLatin1()));
        } else {
            ciphertext.append(ch);
        }
    }

    return ciphertext;
}


QString Encryption::decryptAffine(const QString &ciphertext, int a, int b){
    int aInverse = 1;
    while ((a * aInverse) % 26 != 1) {
        aInverse++;
    }

    QString decryptedText = "";

    for (QChar ch : ciphertext) {
        if (ch.isLetter()) {
            QChar base = (ch.isUpper()) ? 'A' : 'a';
            int y = ch.toLatin1() - base.toLatin1();
            int x = (aInverse * (y - b + 26)) % 26;
            decryptedText.append(QChar(x + base.toLatin1()));
        } else {
            decryptedText.append(ch);
        }
    }

    return decryptedText;
}


void Encryption::on_pushButton_2_clicked()
{
    QString type = "";
    QString type2 = "";
    int a = 0;
    int b = 0;
    QString message = "";
    QString result = "";
    a = ui->spinBox->value();
    b = ui->spinBox_2->value();
    message = ui->plainTextEdit_2->toPlainText();



    if(ui->radioButton_3->isChecked()){
        type = "Message chiffré";
        type2 = "chiffrer";
    }else if(ui->radioButton_4->isChecked()){
        type = "Message déchiffré";
        type2 = "déchiffrer";
    }


    if(message.isEmpty()){
        QMessageBox::critical(this,"Erreur","Le message à "+type2+" ne peut être vide.");
        return;
    }


    ui->label_8->setText(type);

    if (!isPrimeWith26(a)) {
        QMessageBox::critical(this,"Erreur","La valeur de a doit être premier avec 26");
        return;
    }

    if(ui->radioButton_3->isChecked()){
        result = encryptAffine(message,a,b);
    }else if(ui->radioButton_4->isChecked()){
        result = decryptAffine(message,a,b);
    }

    ui->textEdit->setText(result);
}

