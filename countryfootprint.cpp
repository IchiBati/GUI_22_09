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

void CountryFootprint::setNameOfCountry(const QString &newNameOfCountry)
{
    m_nameOfCountry = newNameOfCountry;
}

void CountryFootprint::setCo2InKilograms(int newCo2InKilograms)
{
    m_co2InKilograms = newCo2InKilograms;
}
