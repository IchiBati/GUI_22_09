#include "countryfootprint.h"

CountryFootprint::CountryFootprint(QString name, int co2)
{
    m_nameOfCountry = name;
    m_co2InKilograms = co2;
}

CountryFootprint::~CountryFootprint()
{

}

QString CountryFootprint::nameOfCountry() const{
    return m_nameOfCountry;
}


int CountryFootprint::co2InKilogram() const{
    return m_co2InKilograms;
}
