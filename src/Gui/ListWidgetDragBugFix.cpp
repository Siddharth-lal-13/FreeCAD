// SPDX-License-Identifier: LGPL-2.1-or-later

 /****************************************************************************
  *   Copyright (c) 2023 Boyer Pierre-louis <pierrelouis.boyer@gmail.com>    *
  *   Copyright (c) 2023 FreeCAD Project Association                         *
  *                                                                          *
  *   This file is part of FreeCAD.                                          *
  *                                                                          *
  *   FreeCAD is free software: you can redistribute it and/or modify it     *
  *   under the terms of the GNU Lesser General Public License as            *
  *   published by the Free Software Foundation, either version 2.1 of the   *
  *   License, or (at your option) any later version.                        *
  *                                                                          *
  *   FreeCAD is distributed in the hope that it will be useful, but         *
  *   WITHOUT ANY WARRANTY; without even the implied warranty of             *
  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU       *
  *   Lesser General Public License for more details.                        *
  *                                                                          *
  *   You should have received a copy of the GNU Lesser General Public       *
  *   License along with FreeCAD. If not, see                                *
  *   <https://www.gnu.org/licenses/>.                                       *
  *                                                                          *
  ***************************************************************************/

#include "PreCompiled.h"
#ifndef _PreComp_
# include <QDragMoveEvent>
#endif

#include "ListWidgetDragBugFix.h"


ListWidgetDragBugFix::ListWidgetDragBugFix(QWidget * parent)
  : QListWidget(parent)
{
}

ListWidgetDragBugFix::~ListWidgetDragBugFix()
{
}

void ListWidgetDragBugFix::dragMoveEvent(QDragMoveEvent *e)
{
    if ((row(itemAt(e->pos())) == currentRow() + 1)
        || (currentRow() == count() - 1 && row(itemAt(e->pos())) == -1)) {
        e->ignore();
        return;
    }
    QListWidget::dragMoveEvent(e);
}

#include "moc_ListWidgetDragBugFix.cpp"
