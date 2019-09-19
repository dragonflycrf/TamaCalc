#ifndef TAMAOBJECT_H
#define TAMAOBJECT_H

#include <QObject>

typedef const QString CQS;
enum TamaAttribute
{
    NOATTR = -1, ATTR_SPD, ATTR_HIT, ATTR_RESIST, ATTR_ATKRATE, ATTR_HPRATE, ATTR_DEFRATE, ATTR_CRIT
};

class TamaObject : public QObject
{
    Q_OBJECT
    Q_ENUMS(TamaType)
    Q_ENUMS(TamaSubType)
public:
    explicit TamaObject(CQS &id, QObject *parent = nullptr);
    enum TamaType {
        NOTYPE = -1,
        HIT, RESIST, ATKRATE, HPRATE, DEFRATE, CRIT, BOSS
    };
    enum TamaSubType {
        NOSUBTYPE = -1,
        HUOLING, // HIT
        BANGJING, FEIYUANMO,
        FANHUNXIANG = HUOLING + 10, //RISIST
        WANGLIANG, YOUGUXIANG, SAIZIGUI,
        XINYAN = FANHUNXIANG + 10, // ATKRATE
        ZHENG, LUNRUDAO, KUANGGU, MINGWU, FUYI, YINMOLUO, BINGZHUBU,
        DIZHANG = XINYAN + 10, // HPRATE
        TIHUN, ZHONGLING, JINGJI, SHUYAO, BEIFU, NIEPAN, TUFO,
        ZHAOCAI = DIZHANG + 10, // DEFRATE
        MUMEI, ZHENZHU, MEIYAO, XUEYOUHUN, FANZHEN, RINV,
        POSHI = ZHAOCAI + 10, // CRIT
        ZHENNV, WANGQIE, SANWEI, SHANGHUNNIAO, ZHENGMUSHOU, QINGNVFANG,
        HUANGKULOU = POSHI + 10, // BOSS
        SHENQILOU, TUZHIZHU, DIZHENNIAN, LONGCHE, GUILING
    };

    bool setType(CQS &name);
    TamaType getType() const { return m_type; }
    TamaSubType getSubType() const { return m_subType; }
    QString getTypeName() const { return m_typeName; }
    bool setAttr(CQS &attr);
    TamaAttribute getAttr() const { return m_attr; }

    void setPos(int pos) { m_pos = pos; }
    int getPos() const { return m_pos; }
    void setLvl(int lvl) { m_lvl = lvl; }
    int getLvl() const { return m_lvl; }
    void setStar(int star) { m_star = star; }
    int getStar() const { return m_star; }
    void setSpd(double spd) { m_spd = spd; }
    double getSpd() const { return m_spd; }
    void setHit(double hit) { m_hit = hit; }
    double getHit() const { return m_hit; }
    void setResist(double resist) { m_resist = resist; }
    double getResist() const { return m_resist; }
    void setAtk(double atk) { m_atk = atk; }
    double getAtk() const { return m_atk; }
    void setAtkRate(double atkRate) { m_atkRate = atkRate; }
    double getAtkRate() const { return m_atkRate; }
    void setHp(double hp) { m_hp = hp; }
    double getHp() const { return m_hp; }
    void setHpRate(double hpRate) { m_hpRate = hpRate; }
    double getHpRate() const { return m_hpRate; }
    void setDef(double def) { m_def = def; }
    double getDef() const { return m_def; }
    void setDefRate(double defRate) { m_defRate = defRate; }
    double getDefRate() const { return m_defRate; }
    void setCrit(double crit) { m_crit = crit; }
    double getCrit() const { return m_crit; }
    void setCritRate(double critRate) { m_critRate = critRate; }
    double getCritRate() const { return m_critRate; }

signals:

public slots:


private:
    int getEnumIdx(CQS &key, CQS &enumName);

    QString m_id;
    TamaType m_type;
    TamaSubType m_subType;
    TamaAttribute m_attr;
    QString m_typeName;
    int m_pos, m_lvl, m_star;
    double m_spd;
    double m_hit, m_resist;
    double m_atk, m_atkRate;
    double m_hp, m_hpRate;
    double m_def, m_defRate;
    double m_crit, m_critRate;
};

#endif // TAMAOBJECT_H
