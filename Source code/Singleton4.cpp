#include <iostream>
#include <pthread.h>

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

void* executeThread(void* ptr) {
    for (int i = 0; i < 10; i ++)
        Database::getInstance()->printData();
    return ptr;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, *executeThread, NULL);
    pthread_create(&thread2, NULL, *executeThread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 1;
}

