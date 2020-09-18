#include <iostream>
#include <pthread.h>

using namespace std;

#define SINGLETON_MULTITHREAD_2

#ifdef SINGLETON_MULTITHREAD_1
class Database {
private:
    int record;
    static Database* instance;
    Database() {
        record = 0;
        cout<<"Constructor Database class, record = "<< record <<endl;
    }

    ~Database();
public:
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;

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

void* executeThread(void* ptr) {
    for (int i = 0; i < 10; i ++)
        Database::getInstance()->printData();
    return ptr;
}

Database* Database::instance = nullptr;

int main()
{
    //init before use the singleton
    Database::getInstance();
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, *executeThread, NULL);
    pthread_create(&thread2, NULL, *executeThread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 1;
}
#endif
#ifdef SINGLETON_MULTITHREAD_2
class Database {
private:
    int record;
    static Database* instance;
    Database() {
        record = 0;
        cout<<"Constructor Database class, record = "<< record <<endl;
    }

    ~Database();

public:
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;
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

void* executeThread(void* ptr) {
    for (int i = 0; i < 10; i ++)
        Database::getInstance()->printData();
    return ptr;
}

//init in global scope
Database* Database::instance = Database::getInstance();

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, *executeThread, NULL);
    pthread_create(&thread2, NULL, *executeThread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 1;
}
#endif
#ifdef SINGLETON_MULTITHREAD_3
class Database {
private:
    int record;
    Database() {
        record = 0;
        cout<<"Constructor Database class, record = "<< record <<endl;
    }

public:
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;

    static Database* getInstance() {
        //declare static variable to use
        static Database instance;
        return &instance;
    }

    void printData() {
        cout<<"Record data = "<< ++record <<endl;
    }

    ~Database() {
        cout<<"opp, deleted"<<endl;
    }
};

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
    delete Database::getInstance();
    Database::getInstance()->printData();
    return 1;
}
#endif
#ifdef SINGLETON_MULTITHREAD_4
class Database {
private:
    int record;
    static Database* instance;
    static pthread_mutex_t mutex;
    Database() {
        record = 0;
        cout<<"Constructor Database class, record = "<< record <<endl;
    }
    ~Database();

public:
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;

    static Database* getInstance() {
        pthread_mutex_lock(&mutex);
        if (instance == nullptr)
            instance = new Database();
        pthread_mutex_unlock(&mutex);
        return instance;
    }

    void printData() {
        cout<<"Record data = "<< ++record <<endl;
    }
};

Database* Database::instance = nullptr;
pthread_mutex_t Database::mutex = PTHREAD_MUTEX_INITIALIZER;

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
#endif
