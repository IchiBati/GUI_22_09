#ifndef CARBONFOOTPRINTDATABASE_H
#define CARBONFOOTPRINTDATABASE_H

#include <QList>
#include "countryfootprint.h"

class CarbonFootprintDatabase
{
public:
    QList<CountryFootprint> m_countries;
    static CarbonFootprintDatabase& instance();

private:
    CarbonFootprintDatabase();

};

#endif // CARBONFOOTPRINTDATABASE_H
