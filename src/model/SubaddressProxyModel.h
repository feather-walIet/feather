// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2020-2023 The Monero Project

#ifndef FEATHER_SUBADDRESSPROXYMODEL_H
#define FEATHER_SUBADDRESSPROXYMODEL_H

#include "libwalletqt/Subaddress.h"

#include <QSortFilterProxyModel>

class SubaddressProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit SubaddressProxyModel(QObject* parent, Subaddress *subaddress, bool hidePrimary = false);
    bool filterAcceptsRow(int sourceRow,
                          const QModelIndex &sourceParent) const;

public slots:
    void setSearchFilter(const QString& searchString){
        m_searchRegExp.setPattern(searchString);
        m_searchCaseSensitiveRegExp.setPattern(searchString);
        invalidateFilter();
    }

    void setShowUsed(const bool showUsed){
        m_showUsed = showUsed;
        invalidateFilter();
    }

    void setShowHidden(const bool showHidden){
        m_showHidden = showHidden;
        invalidateFilter();
    }

    void setHiddenAddresses(const QStringList& hiddenAddresses) {
        m_hiddenAddresses = hiddenAddresses;
        invalidateFilter();
    }

    void setShowChangeAddresses(const bool showChange) {
        m_showChange = showChange;
        invalidateFilter();
    }

private:
    Subaddress *m_subaddress;

    QStringList m_hiddenAddresses;
    QRegularExpression m_searchRegExp;
    QRegularExpression m_searchCaseSensitiveRegExp;
    bool m_showUsed = false;
    bool m_showHidden = false;
    bool m_showChange = false;
};

#endif //FEATHER_SUBADDRESSPROXYMODEL_H
