#include "userlistmodel.h"



UserListModel::UserListModel(QList<CountryFootprint> countries, QObject *parent)
    : QAbstractItemModel(parent), m_countries(countries)
{
}

QVariant UserListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch(section){
            case 0: return "Country";
            case 1: return "CO2 (in million tons)";
            }
        }else{
           return QString::number(section + 1);
        }

    }

    return QVariant();
}



QModelIndex UserListModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex UserListModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int UserListModel::rowCount(const QModelIndex &parent) const
{
    return m_countries.size();
}

int UserListModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole) {
        const CountryFootprint country = m_countries.at(index.row());
        switch(index.column()){
        case 0: return country.nameOfCountry();
        case 1: return country.co2InKilogram();
        }
    }

    return QVariant();
}

bool UserListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if(role == Qt::EditRole){
            CountryFootprint* country = (CountryFootprint*)value.data();
            m_countries[index.row()].setCo2InKilograms(country->co2InKilogram());
            m_countries[index.row()].setNameOfCountry(country->nameOfCountry());
            emit dataChanged(index, index, {role});
            return true;
        }

    }
    return false;
}

Qt::ItemFlags UserListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

bool UserListModel::insertRows(int row, int count, const CountryFootprint country, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    m_countries.append(country);
    endInsertRows();
    return true;
}



bool UserListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    m_countries.removeAt(row);
    endRemoveRows();
    return true;
}



QList<CountryFootprint> UserListModel::countries()
{
    return m_countries;
}
