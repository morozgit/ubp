//#include"mainwindow.h"

#include<QFile>
class Data
{
private:
    // QString m_filename;

    QByteArray data_array;
public:

    QFile file;
     Data(QString filename): file(filename)
     {
        file.open(QIODevice::ReadOnly); // открытие файла архива
        data_array = file.read(3480).toHex();
     }
    const QByteArray &gettmp() const
     {
         return data_array;
     }
//     const QFile &getFile() const
//     {
//         return  file;
//     }
};

