#ifndef SYNONYMDICTIONARY_H
#define SYNONYMDICTIONARY_H

#endif // SYNONYMDICTIONARY_H

#include <QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QRandomGenerator>

typedef QMap<QString, QList<QString>> SynonymTable;

QString replaceWithRandomSynonym(QString& word, SynonymTable& table);
