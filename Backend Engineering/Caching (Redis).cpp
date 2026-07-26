#include <iostream>
#include <unordered_map>
using namespace std;

/*
====================================================
WITHOUT CACHING
====================================================

Problem:

Every request queries the database.

*/

class Database {

public:

    string getUser(int id) {

        cout << "Reading from Database...\n";

        return "Bhuvan";

    }

};

int main() {

    Database db;

    cout << db.getUser(1) << endl;

    cout << db.getUser(1) << endl;

    cout << db.getUser(1) << endl;

}

/*

Output:

Reading from Database...
Bhuvan

Reading from Database...
Bhuvan

Reading from Database...
Bhuvan

Problems:

- Same query executed repeatedly.
- Slow.
- High database load.

====================================================
WITH CACHING
====================================================

Solution:

Check cache first.

If data exists,
return it.

Otherwise,

read from database
and store it in cache.

*/

class Database {

public:

    string getUser(int id) {

        cout << "Reading from Database...\n";

        return "Bhuvan";

    }

};

class Cache {

private:

    unordered_map<int,string> cache;

    Database database;

public:

    string getUser(int id) {

        if(cache.count(id)) {

            cout << "Reading from Cache...\n";

            return cache[id];

        }

        string user =
            database.getUser(id);

        cache[id] = user;

        return user;

    }

};

int main() {

    Cache cache;

    cout << cache.getUser(1) << endl;

    cout << cache.getUser(1) << endl;

    cout << cache.getUser(1) << endl;

}

/*

Output:

Reading from Database...
Bhuvan

Reading from Cache...
Bhuvan

Reading from Cache...
Bhuvan

Database was queried only once.

*/