#include "countryfootprint.h"

CountryFootprint::CountryFootprint()
{

}

QString CountryFootprint::nameOfCountry() const{
    return m_nameOfCountry;
}


int CountryFootprint::co2InKilogram() const{
    return m_co2InKilograms;
}
