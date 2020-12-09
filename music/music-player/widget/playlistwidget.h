/*
 * Copyright (C) 2016 ~ 2018 Wuhan Deepin Technology Co., Ltd.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <DWidget>
#include <DLabel>

DWIDGET_USE_NAMESPACE

class PlayListView;
class InotifyFiles;
class PlayListWidget : public DWidget
{
    Q_OBJECT
public:
    explicit PlayListWidget(QWidget *parent = Q_NULLPTR);
    ~PlayListWidget() override;

    void initConntion();
//    void showEmptyHits(bool empty);
public slots:
    void slotPlayListChanged();

    void slotTheme(int type);
    void changePicture(QPixmap pixmap, QPixmap sidebarPixmap, QPixmap albumPixmap);

signals:
    void requestCustomContextMenu(const QPoint &pos, char type);
    void musicFileMiss();
    void btPlayList();

private slots:
    void slotClearAllClicked();
    //刷新歌曲数量
    void slotUpdateItemCount();
protected:
    bool eventFilter(QObject *o, QEvent *e) Q_DECL_OVERRIDE;

protected:
    virtual void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
    virtual void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
//    virtual void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
//    virtual void dragLeaveEvent(QDragLeaveEvent *event) Q_DECL_OVERRIDE;
    virtual void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    DLabel              *m_titleLabel     = nullptr;
    DLabel              *m_infoLabel      = nullptr;
    DLabel              *m_emptyHits      = nullptr;
    DWidget             *m_actionBar      = nullptr;
    DPushButton         *m_btClearAll     = nullptr;
    PlayListView        *m_playListView   = nullptr;
    QAction             *m_customAction   = nullptr;
//    InotifyFiles        inotifyFiles;
};
