#include "tamaobject.h"

#include <QMetaEnum>

#include <unordered_map>

static std::unordered_map<std::string, QString> nameMap = {
    {"火灵", "HUOLING"}, {"蚌精", "BANGJING"}, {"飞缘魔", "FEIYUANMO"}, // HIT
    {"返魂香", "FANHUNXIANG"}, {"魍魉之匣", "WANGLIANG"}, {"幽谷响", "YOUGUXIANG"}, {"骰子鬼", "TOUZIGUI"}, //RISIST
    {"心眼", "XINYAN"}, {"狰", "ZHENG"}, {"轮入道", "LUNRUDAO"}, {"狂骨", "KUANGGU"}, {"鸣屋", "MINGWU"}, {"蝠翼", "FUYI"}, {"阴摩罗", "YINMOLUO"}, {"兵主部", "BINGZHUBU"}, // ATKRATE
    {"地藏像", "DIZHANG"}, {"薙魂", "TIHUN"}, {"钟灵", "ZHONGLING"}, {"镜姬", "JINGJI"}, {"树妖", "SHUYAO"}, {"被服", "BEIFU"}, {"涅槃之火", "NIEPAN"}, {"涂佛", "TUFO"}, // HPRATE
    {"招财猫", "ZHAOCAI"}, {"木魅", "MUMEI"}, {"珍珠", "ZHENZHU"}, {"魅妖", "MEIYAO"}, {"雪幽魂", "XUEYOUHUN"}, {"反枕", "FANZHEN"}, {"日女巳时", "RINV"}, // DEFRATE
    {"破势", "POSHI"}, {"针女", "ZHENNV"}, {"网切", "WANGQIE"}, {"三味", "SANWEI"}, {"伤魂鸟", "SHANGHUNNIAO"}, {"镇墓兽", "ZHENGMUSHOU"}, {"青女房", "QINGNVFANG"}, // CRIT
    {"荒骷髅", "HUANGKULOU"}, {"蜃气楼", "SHENQILOU"}, {"土蜘蛛", "TUZHIZHU"}, {"地震鲶", "DIZHENNIAN"}, {"胧车", "LONGCHE"}, {"鬼灵歌伎", "GUILING"} // BOSS
};

TamaObject::TamaObject(CQS &id, QObject *parent)
    : QObject(parent)
    , m_id(id)
    , m_type(TamaType::NOTYPE)
    , m_subType(TamaSubType::NOSUBTYPE)
    , m_attr(TamaAttribute::NOATTR)
    , m_pos(1), m_lvl(15), m_star(6)
    , m_spd(0.0)
    , m_hit(0.0), m_resist(0.0)
    , m_atk(0.0), m_atkRate(0.0)
    , m_hp(0.0), m_hpRate(0.0)
    , m_def(0.0), m_defRate(0.0)
    , m_crit(0.0), m_critRate(0.0)
{
}

bool TamaObject::setType(CQS &name)
{
    int idx = getEnumIdx(name, "TamaSubType");
    if (idx == -1) return false;
    m_typeName = name;
    m_subType = TamaSubType(idx);
    m_type = TamaType(idx / 10);
    return true;
}

bool TamaObject::setAttr(CQS &attr)
{
    int idx = getEnumIdx("ATTR_" + attr, "TamaAttribute");
    if (idx == -1) return false;
    m_attr = TamaAttribute(idx);
    return true;
}

int TamaObject::getEnumIdx(CQS &key, CQS &enumName)
{
    if (key.isEmpty()) return -1;
    QMetaEnum metaEnum = this->staticMetaObject.enumerator(this->staticMetaObject.indexOfEnumerator(enumName.toLatin1()));
    return metaEnum.keyToValue(nameMap[key.toStdString()].toLatin1());
}
