#ifndef COUNTRYFOOTPRINT_H
#define COUNTRYFOOTPRINT_H

#include <QString>


class CountryFootprint
{

public:
    CountryFootprint();
    ~CountryFootprint();

    QString nameOfCountry() const;
    int co2InKilogram() const;

private:
    QString m_nameOfCountry;
    int m_co2InKilograms;

};

#endif // COUNTRYFOOTPRINT_H
