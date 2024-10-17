#ifndef DATABASE_H
#define DATABASE_H

#include "../sqlite3.h"

#include <string>

class Database {
public:
    Database(const std::string& dbName);
    ~Database();

    bool createTables();
    bool insertUser(const std::string& username, const std::string& password, const std::string& role);

private:
    sqlite3* db;
};

#endif // DATABASE_H
