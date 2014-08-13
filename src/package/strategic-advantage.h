/********************************************************************
    Copyright (c) 2013-2014 - QSanguosha-Hegemony Team

    This file is part of QSanguosha-Hegemony.

    This game is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    See the LICENSE file for more details.

    QSanguosha-Hegemony Team
    *********************************************************************/

#ifndef _STRATEGIC_ADVANTAGE_PACKAGE_H
#define _STRATEGIC_ADVANTAGE_PACKAGE_H

#include "package.h"
#include "standard.h"
#include "skill.h"

class Blade : public Weapon{
    Q_OBJECT

public:
    Q_INVOKABLE Blade(Card::Suit suit, int number);
};

class Halberd : public Weapon{
    Q_OBJECT

public:
    Q_INVOKABLE Halberd(Card::Suit suit, int number);
};

class Breastplate : public Armor{
    Q_OBJECT

public:
    Q_INVOKABLE Breastplate(Card::Suit suit = Card::Club, int number = 2);
};

class IronArmor : public Armor{
    Q_OBJECT

public:
    Q_INVOKABLE IronArmor(Card::Suit suit = Card::Diamond, int number = 9);
};

class WoodenOxCard: public SkillCard {
    Q_OBJECT

public:
    Q_INVOKABLE WoodenOxCard();

    virtual void use(Room *room, ServerPlayer *source, QList<ServerPlayer *> &targets) const;
};

class WoodenOx: public Treasure{
    Q_OBJECT

public:
    Q_INVOKABLE WoodenOx(Card::Suit suit, int number);

    virtual void onUninstall(ServerPlayer *player) const;
};

class JadeSeal : public Treasure{
    Q_OBJECT

public:
    Q_INVOKABLE JadeSeal(Card::Suit suit, int number);
};

class Drowning: public SingleTargetTrick {
    Q_OBJECT

public:
    Q_INVOKABLE Drowning(Card::Suit suit, int number);

    virtual bool targetFilter(const QList<const Player *> &targets, const Player *to_select, const Player *Self) const;
    virtual void onEffect(const CardEffectStruct &effect) const;
    virtual bool isAvailable(const Player *player) const;

    virtual QStringList checkTargetModSkillShow(const CardUseStruct &use) const;
};

class AllianceFeast : public AOE {
    Q_OBJECT

public:
    Q_INVOKABLE AllianceFeast(Card::Suit suit = Heart, int number = 9);

    /*virtual bool targetFilter(const QList<const Player *> &targets, const Player *to_select, const Player *Self) const;
    virtual void onUse(Room *room, const CardUseStruct &card_use) const;
    virtual void use(Room *room, ServerPlayer *source, QList<ServerPlayer *> &targets) const;
    virtual void onEffect(const CardEffectStruct &effect) const;
    virtual bool isAvailable(const Player *player) const;*/
};

class StrategicAdvantagePackage : public Package{
    Q_OBJECT

public:
    StrategicAdvantagePackage();
};

#endif
