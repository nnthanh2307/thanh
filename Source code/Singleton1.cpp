//#include <iostream>
//
//using namespace std;
//
//class Database {
//private:
//    int record;
//    static Database* instance;
//    Database() {
//        record = 0;
//        cout<<"Constructor Database class, record = "<< record <<endl;
//    }
//
//public:
//    static Database* getInstance() {
//        if (instance == nullptr) {
//            instance = new Database();
//        }
//        return instance;
//    }
//
//    void printData() {
//        cout<<"Record data = "<< ++record <<endl;
//    }
//};
//
//Database* Database::instance = nullptr;
//
//int main()
//{
//    Database::getInstance()->printData();
//    Database::getInstance()->printData();
//    return 1;
//}
#include <iostream>
#include <thread>
using namespace std;
class Database{
	private:
		int record;
		static Database* instance;
		Database(){
			record = 0;
			cout << "Constructor Database class, record = " << record << endl;
		}
	public:
		Database(Database const&) = delete; //Neu ta khong hide copy constructor va oprator assignment
		void operator = (Database const&) = delete; //thi khong the han che viec tao duoc object thong qua 
		static Database* getInstance(){     //copy contructor va toan tu gan.
			if(instance == nullptr){
				instance = new Database();
			}
			return instance;
		}
		void print(){
			cout << "Record data = " << ++record << endl;
		}
};

void *executeThread(void * ptr){
	for(int i = 0; i < 10 ; i++)
		Database::getInstance()->print();
	return ptr;
}

Database* Database :: instance = nullptr;

int main()
{
//	Database::getInstance()->print();
//	Database::getInstance()->print();
//	Database data = *Database::getInstance();
//	data.print();
//	data = *Database::getInstance();
//	data.print();
//	Database::getInstance()->print();
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, *executeThread, NULL);
	pthread_create(&thread2, NULL, *executeThread, NULL);	
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	return 0;	
}
