/*
 * This file is part of the QSsh Library
 *
 * Copyright (c) 2015 by Gyger Jean-Luc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301  USA.
 *
 */



#ifndef QSSHPROCESS_H
#define QSSHPROCESS_H

#include "qsshchannel.h"
#include "qssh_global.h"

class QSSHSHARED_EXPORT QSshProcess : public QSshChannel {
    Q_OBJECT
 public:    
    void startShell();
    void writeOnShell(QString shell);
    void changePtySize(int cols, int rows);
    void startCmd(const QString & cmd);
 signals:
    void started();
    void finished ( int exitCode);

public slots:
    void sendData(const char *,int)    ;

 private:
    QSshProcess(QSshClient*);
    friend class QSshClient;

};

#endif // QSSHPROCESS_H
