#ifndef COUNTRYFOOTPRINT_H
#define COUNTRYFOOTPRINT_H

#include <QString>


class CountryFootprint
{

public:
    CountryFootprint(QString name, int co2);
    ~CountryFootprint();

    QString nameOfCountry() const;
    int co2InKilogram() const;



    void setNameOfCountry(const QString &newNameOfCountry);
    void setCo2InKilograms(int newCo2InKilograms);

private:
    QString m_nameOfCountry;
    int m_co2InKilograms;

};

#endif // COUNTRYFOOTPRINT_H
