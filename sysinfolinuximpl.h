#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H
#include <QtGlobal>
#include <QVector>

#include "sysinfo.h"

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();

    // SysInfo interface
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();

private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H
