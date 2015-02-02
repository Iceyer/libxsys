#pragma once

#include <QObject>
#include <QString>

#include "../Common/Result.h"

namespace XSys {

namespace DiskUtil {
    enum PartionFormat {
        PF_FAT32,
        PF_NTFS,
        PF_RAW,
    };

    bool UmountDisk(const QString &targetDev);
    bool EjectDisk(const QString &targetDev);

    QString MountPoint(const QString& targetDev) ;
    PartionFormat GetPartitionFormat(const QString &targetDev);
    QString GetPartitionDisk(const QString &targetDev);
}

namespace Bootloader {

    Result InstallBootloader(const QString &diskDev);

    namespace Syslinux {
        Result InstallSyslinux(const QString &diskDev);
        Result ConfigSyslinx(const QString &targetDev);
    }

    }
}
