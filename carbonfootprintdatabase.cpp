#include "carbonfootprintdatabase.h"

CarbonFootprintDatabase& CarbonFootprintDatabase::instance()
{
    static CarbonFootprintDatabase databaseInstance;

    return databaseInstance;
}

CarbonFootprintDatabase::CarbonFootprintDatabase()
{

}
