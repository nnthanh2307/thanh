#include <iostream>

using namespace std;

class Database {
private:
    int record;
    static Database* instance;
    Database() {
        record = 0;
        cout<<"Constructor Database class, record = "<< record <<endl;
    }

    ~Database();
#if __cplusplus < 201103L
    Database(Database const&);
    void operator=(Database const&);

public:
#else
public:
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;
#endif
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database();
        }
        return instance;
    }

    void printData() {
        cout<<"Record data = "<< ++record <<endl;
    }


};

Database* Database::instance = nullptr;
int b;
int main()
{
    Database::getInstance()->printData();
    Database::getInstance()->printData();

    Database data = *Database::getInstance();
    data.printData();

    data = *Database::getInstance();
    data.printData();

    Database::getInstance()->printData();

    Database *data2 = Database::getInstance();
    delete data2;

    Database::getInstance()->printData();

    return 1;
}
