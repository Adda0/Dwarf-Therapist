/*
Dwarf Therapist
Copyright (c) 2022 Clement Vuchener

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef DFINSTANCE_WINE_H
#define DFINSTANCE_WINE_H
#include "dfinstance.h"

class Dwarf;
class MemoryLayout;

class DFInstanceWine : public DFInstance {
    Q_OBJECT
public:
    DFInstanceWine(QObject *parent=0);
    virtual ~DFInstanceWine();

    void find_running_copy();
    bool df_running();

    USIZE read_raw(VIRTADDR addr, USIZE bytes, void *buffer);
    QString read_string(VIRTADDR addr);

    // Writing
    USIZE write_raw(VIRTADDR addr, USIZE bytes, const void *buffer);
    USIZE write_string(VIRTADDR addr, const QString &str);

    bool attach();
    bool detach();

protected:
    bool set_pid();

private:
    int wait_for_stopped();

    pid_t m_pid;
};

#endif // DFINSTANCE_WINE_H

