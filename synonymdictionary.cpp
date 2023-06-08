#include "synonymdictionary.h"

QString replaceWithRandomSynonym(QString& word, SynonymTable& table){
    if (!table.contains(word))
        return word;

    const QList<QString>& synonyms = table.value(word);

    int index = QRandomGenerator::global()->bounded(synonyms.size());

    return synonyms.at(index);
}
