#ifndef CARBONFOOTPRINTDATABASE_H
#define CARBONFOOTPRINTDATABASE_H

#include <QList>
#include "countryfootprint.h"

class CarbonFootprintDatabase
{
public:
    static CarbonFootprintDatabase& instance();
    QList<CountryFootprint>& countries();

private:
    CarbonFootprintDatabase();
    QList<CountryFootprint> m_countries;
};

#endif // CARBONFOOTPRINTDATABASE_H
