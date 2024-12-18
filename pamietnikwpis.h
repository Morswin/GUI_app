#ifndef PAMIETNIKWPIS_H
#define PAMIETNIKWPIS_H

#include <QDateTime>
#include <QString>

class PamietnikWpis
{
private:
    QDateTime m_czas;
    QString m_wartosc;
public:
    PamietnikWpis(QDateTime, QString);
    bool operator==(PamietnikWpis&);
    bool operator!=(PamietnikWpis&);
    bool operator<(PamietnikWpis&);
};

#endif // PAMIETNIKWPIS_H
