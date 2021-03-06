#include "loginhelper.h"
#include <sstream>
#include <QRegExp>

LoginHelper::LoginHelper(DatabaseHandler *dbh)
{
    databaseHandler = dbh;
}

bool LoginHelper::userOK(std::string user, std::string pass)
{    
    std::hash<std::string> str_hash;

    std::string passwordHashFromDb = databaseHandler->getHashFromDbForUser(user);

    std::stringstream ss;
    ss << str_hash(pass);

//    qDebug() << "Hash for user: " << QString::fromStdString(passwordHashFromDb);
    qDebug() << "Hash generated with password supplied: " << str_hash(pass);

    return ss.str() == passwordHashFromDb;
}
