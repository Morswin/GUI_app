#include "pamietnikwpis.h"

#include<QDateTime>
#include<QString>

PamietnikWpis::PamietnikWpis(QDateTime czas, QString wartosc)
{
    m_czas = czas;
    m_wartosc = wartosc;
}

bool PamietnikWpis::operator==(PamietnikWpis& innyWpis)
{
    if (m_czas == innyWpis.m_czas) return true;
    return false;
}

bool PamietnikWpis::operator!=(PamietnikWpis& innyWpis)
{
    if (m_czas != innyWpis.m_czas) return true;
    return false;
}

bool PamietnikWpis::operator<(PamietnikWpis& innyWpis)
{
    if (m_czas < innyWpis.m_czas) return true;
    return false;
}
