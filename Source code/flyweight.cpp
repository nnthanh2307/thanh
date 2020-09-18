#include <iostream>
#include <pthread.h>
#include <map>

using namespace std;
class GraphichRender {
public:
    void draw(void* data) {
        //draw to screen

        cout<<"drawed data"<<endl;
    }
};

class Soldier {
public:
    virtual void moveSoldier(int previousLocationX,
                             int previousLocationY , int newLocationX ,int newLocationY) = 0;
};

class SoldierImp: public Soldier{
private:
    GraphichRender render;
public:
    void moveSoldier(int previousLocationX, int previousLocationY,
                int newLocationX, int newLocationY) override{

            // delete soldier representation from previous location
            // then render soldier representation in new location
            cout<<"moved the soldier from x:" <<previousLocationX<<",y: "<<previousLocationY<<"to X:"<<newLocationX<<", Y:"<<newLocationY<<endl;
            render.draw(this);
        }
};

enum SoldierE{
    MinSolider,
    GermanySolider,
    KoreanSolider,
    VietNamSolider,
    ThaiLandSolider,
    CambodiaSolider,
    MaxSolider
};

class SoldierFactory {
private:
    map<SoldierE, Soldier*> soldiers;
    static SoldierFactory* instance;
public:
    SoldierFactory() {
        soldiers.insert(pair<SoldierE,Soldier*>(GermanySolider, nullptr));
        soldiers.insert(pair<SoldierE,Soldier*>(KoreanSolider, nullptr));
        soldiers.insert(pair<SoldierE,Soldier*>(VietNamSolider, nullptr));
        soldiers.insert(pair<SoldierE,Soldier*>(ThaiLandSolider, nullptr));
        soldiers.insert(pair<SoldierE,Soldier*>(CambodiaSolider, nullptr));
    }

    static Soldier* getSoldier(SoldierE key) {
        if (instance == nullptr) {
            instance = new SoldierFactory();
        }
        if (key > MinSolider && key < MaxSolider) {
            map<SoldierE, Soldier*>::iterator it = instance->soldiers.find(key);
            if (it->second == nullptr) {
                it->second = new SoldierImp();
            }
            return it->second;
        }
        return nullptr;
    }
};

SoldierFactory* SoldierFactory::instance = nullptr;

class SoldierClient {
private:
    Soldier* sold;
    int currentLocationX = 0;
    int currentLocationY=0;
    SoldierE type;
public:
    SoldierClient(SoldierE type) {
        this->type = type;
        sold = SoldierFactory::getSoldier(type);
    }

    void moveSoldier(int newLocationX, int newLocationY){

            // here the actual rendering is handled by the flyweight object
            sold->moveSoldier(currentLocationX,
                currentLocationY, newLocationX, newLocationY);

            // this object is responsible for maintaining the state
            // that is extrinsic to the flyweight
            currentLocationX = newLocationX;

            currentLocationY = newLocationY;
        }
};

int main()
{
    SoldierClient* soldiers[10]= {
        new SoldierClient(GermanySolider),
        new SoldierClient(VietNamSolider),
        new SoldierClient(KoreanSolider),
        new SoldierClient(ThaiLandSolider),
        new SoldierClient(CambodiaSolider),
        new SoldierClient(CambodiaSolider),
        new SoldierClient(CambodiaSolider),
        new SoldierClient(CambodiaSolider),
        new SoldierClient(CambodiaSolider),
        new SoldierClient(CambodiaSolider)
    };

    soldiers[0]->moveSoldier(2,3);
    soldiers[1]->moveSoldier(5,6);
    soldiers[2]->moveSoldier(2,3);
    soldiers[3]->moveSoldier(5,3);
    soldiers[4]->moveSoldier(8,1);
    soldiers[5]->moveSoldier(2,3);
    soldiers[6]->moveSoldier(7,5);
    soldiers[7]->moveSoldier(4,3);
    soldiers[8]->moveSoldier(9,8);
    soldiers[9]->moveSoldier(0,3);


    return 1;
}

