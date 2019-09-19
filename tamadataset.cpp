#include "tamadataset.h"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

const QString ID("ID");
const QString TYPE("TYPE");
const QString LEVEL("LEVEL");
const QString POS("POS");
const QString STAR("STAR");
const QString SPD("SPD");
const QString HIT("HIT");
const QString RESIST("RESIST");
const QString ATKRATE("ATKRATE");
const QString ATK("ATK");
const QString HPRATE("HPRATE");
const QString HP("HP");
const QString DEFRATE("DEFRATE");
const QString DEF("DEF");
const QString CRITRATE("CRITRATE");
const QString CRIT("CRIT");
const QString ATTR("ATTR");

TamaDataSet::TamaDataSet(QObject *parent) : QObject(parent)
{
    m_filePath = "C:\\Users\\lchen\\Downloads\\test.json";
}

bool replaceKeyNames(QString &wholeStr) {
    wholeStr.replace("\\u5fa1\\u9b42ID", ID);
    wholeStr.replace("\\u5fa1\\u9b42\\u7c7b\\u578b", TYPE);
    wholeStr.replace("\\u5fa1\\u9b42\\u7b49\\u7ea7", LEVEL);
    wholeStr.replace("\\u4f4d\\u7f6e", POS);
    wholeStr.replace("\\u5fa1\\u9b42\\u661f\\u7ea7", STAR);
    wholeStr.replace("\\u901f\\u5ea6", SPD);
    wholeStr.replace("\\u6548\\u679c\\u547d\\u4e2d", HIT);
    wholeStr.replace("\\u6548\\u679c\\u62b5\\u6297", RESIST);
    wholeStr.replace("\\u653b\\u51fb\\u52a0\\u6210", ATKRATE);
    wholeStr.replace("\\u653b\\u51fb", ATK);
    wholeStr.replace("\\u751f\\u547d\\u52a0\\u6210", HPRATE);
    wholeStr.replace("\\u751f\\u547d", HP);
    wholeStr.replace("\\u9632\\u5fa1\\u52a0\\u6210", DEFRATE);
    wholeStr.replace("\\u9632\\u5fa1", DEF);
    wholeStr.replace("\\u66b4\\u51fb\\u4f24\\u5bb3", CRITRATE);
    wholeStr.replace("\\u66b4\\u51fb", CRIT);
    wholeStr.replace("\\u56fa\\u6709\\u5c5e\\u6027", ATTR);
    return true;
}

bool TamaDataSet::loadData(CQS filePath)
{
    //m_filePath = filePath;
    QString val;
    QFile file("C:\\Users\\lchen\\Downloads\\test_replaced.json");
    bool needReplace(false);
    if ((needReplace = !file.exists()))
        file.setFileName(m_filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        val = file.readAll();
        file.close();
    }

    if (needReplace) {
        replaceKeyNames(val);
        QFile file("C:\\Users\\lchen\\Downloads\\test_replaced.json");
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            file.write(val.toUtf8(), val.size());
            file.close();
        }
    }
    auto d = QJsonDocument::fromJson(val.toUtf8().data());
    auto array = d.array();
    for (short i(1); i < array.size(); ++i) {
        auto obj = array[i].toObject();
        auto tama = QSharedPointer<TamaObject>(new TamaObject(obj[ID].toString()));
        //TamaObject tama(obj[ID].toString());
        if (tama->setType(obj[TYPE].toString())) {
            tama->setPos(obj[POS].toInt());
            tama->setLvl(obj[LEVEL].toInt());
            tama->setPos(obj[STAR].toInt());
            QStringList ignoreList = {ID, TYPE, POS, LEVEL, STAR};
            for (short j(0); j < obj.size(); ++j) {
                QString key = obj.keys()[j];
                if (ignoreList.contains(key))
                    continue;
                double val = obj[key].toDouble();
                if (key == SPD)
                    tama->setSpd(val);
                else if (key == HIT)
                    tama->setHit(val);
                else if (key == RESIST)
                    tama->setResist(val);
                else if (key == ATK)
                    tama->setAtk(val);
                else if (key == ATKRATE)
                    tama->setAtkRate(val);
                else if (key == HP)
                    tama->setHp(val);
                else if (key == HPRATE)
                    tama->setHpRate(val);
                else if (key == DEF)
                    tama->setDef(val);
                else if (key == DEFRATE)
                    tama->setDefRate(val);
                else if (key == CRIT)
                    tama->setCrit(val);
                else if (key == CRITRATE)
                    tama->setCritRate(val);
                else if (key == ATTR)
                    tama->setAttr(obj[key].toString());
            }
            m_tamaVec.push_back(tama);
        }
        else {
            qDebug() << obj[ID].toString();
        }
    }
    return true;
}
