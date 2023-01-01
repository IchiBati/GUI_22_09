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

}
