#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTimeEdit>
#include <QDateTime>
#include <QLineEdit>
#include <QString>
#include <vector>
#include "pamietnikwpis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDateTimeEdit* obiekt_czas = findChild<QDateTimeEdit*>();
    QDateTime czas = obiekt_czas->dateTime();
    QLineEdit* obiekt_wartosc = findChild<QLineEdit*>();
    QString wartosc = obiekt_wartosc->text();
    PamietnikWpis nowy_wpis = PamietnikWpis(czas, wartosc);
    dodaj_wpis(nowy_wpis);
}

void MainWindow::dodaj_wpis(PamietnikWpis nowy_wpis) {
    if (m_wszystkie_wpisy.empty()) m_wszystkie_wpisy.push_back(nowy_wpis);
    else
    {
        if (m_wszystkie_wpisy.size() == 1)
        {
            if (nowy_wpis < m_wszystkie_wpisy[0])
            {
                PamietnikWpis temp = m_wszystkie_wpisy[0];
                m_wszystkie_wpisy[0] = nowy_wpis;
                m_wszystkie_wpisy.push_back(temp);
            }
            else if (m_wszystkie_wpisy[0] == nowy_wpis)
            {
                m_wszystkie_wpisy[0] = nowy_wpis;
            }
            else
            {
                m_wszystkie_wpisy.push_back(nowy_wpis);
            }
        }
        else
        {
            bool wpisano = false;
            for (size_t i = 0; i < m_wszystkie_wpisy.size(); i++)
            {
                if (nowy_wpis < m_wszystkie_wpisy[i])
                {
                    std::vector<PamietnikWpis> nowy_wektor = {};  // Tak, nie wiem jak to inaczej zaimplementować..
                    if(i != 0) for(size_t j = 0; j < i; j++) nowy_wektor.push_back(m_wszystkie_wpisy[j]);
                    nowy_wektor.push_back(nowy_wpis);
                    if(i != m_wszystkie_wpisy.size() - 1)
                    {
                        for(size_t j = i; j < m_wszystkie_wpisy.size(); j++) nowy_wektor.push_back(m_wszystkie_wpisy[j]);
                    }
                    wpisano = true;
                    break;
                }
                if (nowy_wpis == m_wszystkie_wpisy[i])
                {
                    m_wszystkie_wpisy[i] = nowy_wpis;
                    wpisano = true;
                    break;
                }
            }
            if (!wpisano) m_wszystkie_wpisy.push_back(nowy_wpis);
        }
    }
}
