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

public:
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

