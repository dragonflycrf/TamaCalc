#ifndef TAMADATASET_H
#define TAMADATASET_H

#include "tamaobject.h"

#include <vector>
#include <unordered_map>

#include <QSharedPointer>


class TamaDataSet : public QObject
{
    Q_OBJECT
public:
    explicit TamaDataSet(QObject *parent = nullptr);
    Q_INVOKABLE bool loadData(CQS filePath = "");
    Q_INVOKABLE std::vector<QSharedPointer<TamaObject>> getTamaData() const { return m_tamaVec; };

signals:

public slots:

private:
    QString m_filePath;
    std::vector<QSharedPointer<TamaObject>> m_tamaVec;
};

#endif // TAMADATASET_H
