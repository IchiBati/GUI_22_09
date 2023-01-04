#include "carbonfootprintdatabase.h"

CarbonFootprintDatabase& CarbonFootprintDatabase::instance()
{
    static CarbonFootprintDatabase databaseInstance;

    return databaseInstance;
}

QList<CountryFootprint> &CarbonFootprintDatabase::countries()
{
    return m_countries;
}

CarbonFootprintDatabase::CarbonFootprintDatabase()
{
    CarbonFootprintDatabase::m_countries.append(CountryFootprint("Deutschland", 1001));
    CarbonFootprintDatabase::m_countries.append(CountryFootprint("Spanien", 2004));
    CarbonFootprintDatabase::m_countries.append(CountryFootprint("England", 1001));
}
