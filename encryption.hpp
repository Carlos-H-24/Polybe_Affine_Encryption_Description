#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <QMainWindow>
#include <QtWidgets>
#include <QSet>
#include <QtAlgorithms>

QT_BEGIN_NAMESPACE
namespace Ui { class Encryption; }
QT_END_NAMESPACE

class Encryption : public QMainWindow
{
    Q_OBJECT

public:
    Encryption(QWidget *parent = nullptr);
    static QString createSubstitutionGrid(const QString& keyword);
    static QString polybiusEncrypt(const QString& message, const QString& keyword);
    static QString polybiusDecrypt(const QString& encryptedMessage, const QString& keyword);
    static int gcd(int a, int b);
    static bool isPrimeWith26(int a);
    static QString encryptAffine(const QString& plaintext, int a, int b);
    static QString decryptAffine(const QString& ciphertext, int a, int b);
    ~Encryption();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Encryption *ui;
};
#endif // ENCRYPTION_HPP
