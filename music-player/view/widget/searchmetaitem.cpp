/**
 * Copyright (C) 2016 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#include "searchmetaitem.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <thememanager.h>

class SearchMetaItemPrivate
{
public:
    SearchMetaItemPrivate(SearchMetaItem *parent) : q_ptr(parent) {}

    QLabel      *metaTitle   = nullptr;
    QLabel      *metaArtist  = nullptr;
    QLabel      *metaLength  = nullptr;
    QPushButton *checkedBt   = nullptr;

    SearchMetaItem *q_ptr;
    Q_DECLARE_PUBLIC(SearchMetaItem)
};

SearchMetaItem::SearchMetaItem(QWidget *parent) : QFrame(parent), d_ptr(new SearchMetaItemPrivate(this))
{
    Q_D(SearchMetaItem);
    setObjectName("SearchMetaItem");
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 10, 0);

    auto interFrame = new QFrame();
    interFrame->setObjectName("SearchMetaItemInterFrame");
    auto interLayout = new QHBoxLayout(interFrame);
    interLayout->setMargin(0);

    auto metaInfoLayout = new QVBoxLayout;
    metaInfoLayout->setContentsMargins(10,10,10,10);
    metaInfoLayout->setSpacing(5);

    d->metaTitle = new QLabel;
    d->metaTitle->setObjectName("SearchMetaItemTitle");
    d->metaArtist = new QLabel;
    d->metaArtist->setObjectName("SearchMetaItemArtist");

    metaInfoLayout->addWidget(d->metaTitle);
    metaInfoLayout->addWidget(d->metaArtist);

    d->checkedBt = new QPushButton;
    d->checkedBt->setObjectName("SearchMetaItemCheck");
    d->checkedBt->setFixedSize(16, 16);
    d->checkedBt->setCheckable(true);

    d->metaLength = new QLabel;
    d->metaLength->setObjectName("SearchMetaItemLength");

    interLayout->addLayout(metaInfoLayout);
    interLayout->addStretch();
    interLayout->addWidget(d->checkedBt);
    interLayout->addWidget(d->metaLength);

    layout->addWidget(interFrame);
    ThemeManager::instance()->regisetrWidget(this);
}

SearchMetaItem::~SearchMetaItem()
{
}

void SearchMetaItem::initUI(const MusicMeta &meta)
{
    Q_D(SearchMetaItem);
    d->metaTitle->setText(meta.title);
    d->metaArtist->setText(meta.artist);
    d->metaLength->setText(lengthString(meta.length));
}

void SearchMetaItem::setChecked(bool check)
{
    Q_D(SearchMetaItem);
    d->checkedBt->setChecked(check);
}
