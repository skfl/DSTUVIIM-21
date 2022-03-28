#include <iostream>
#include <string>

using namespace std;

struct passangerData{
    
    public:
        passangerData(std::string fName,std::string plsOfLiving,int sitNum,std::string arcrftType,std::string depTime,int ag){
            name = fName;
            placeOfLiving = plsOfLiving;
            sitNumber = sitNum;
            aircraftType = arcrftType;
            departureTime = depTime;
            age = ag;
        }

        void setName(std::string fName){
            name = fName;
        }

        void setPlaceOfLiving(std::string plsOfLiving){
            placeOfLiving = plsOfLiving;
        }

        void setSitNumber(int sitNum){
            sitNumber = sitNum;
        }

        void setAircraftType(std::string arcftType){
            aircraftType = arcftType;
        }

        void setDepartureTime(std::string depTime){
            departureTime = depTime;
        }

        void setAge(int ag){
            if(ag > 0 && ag<150){
                age = ag;
            }
        }

        std::string getName(){
            return name;
        }

        std::string getPlaceOfLiving(){
            return placeOfLiving;
        }

        int getSitNumber(){
            return sitNumber;
        }

        std::string getAircraftType(){
            return aircraftType;
        }

        std::string getDepartureType(){
            return departureTime;
        }

        int getAge(){
            return age;
        }

    private:
        std::string name;
        std::string placeOfLiving;
        int sitNumber;
        std::string aircraftType;
        std::string departureTime;
        int age;
};

double getAverageAge(passangerData *list,int size){
    double avgAge = 0;
    for(int i = 0;i < size;i++){
        avgAge +=list[i].getAge();
    }
    avgAge = avgAge / size;
    return avgAge;
}

void getPassangerByPlace(passangerData *list,int size, std::string place){
    for(int i = 0;i<size;i++){
        if(list[i].getPlaceOfLiving() == place){
            cout<<"Passanger "<<list[i].getName()<<" is from "<<place<<endl;
        }
    }
}

int main(){
    passangerData firstPassanger("Volkov Gennadiy Semenovich","Rostov-on-Don",1,"SSJ-100","10:30",33);
    passangerData secondPassanger("Zaikina Anna Andreevna","Rostov-on-Don",3,"SSJ-100","10:30",21);
    passangerData thirdPassanger("Ribalchenko Grigorii Aleksandrovich","Taganrog",31,"SSJ-100","10:30",20);

    passangerData passangersList[3]={firstPassanger,secondPassanger,thirdPassanger};

    cout<<"Average age of passangers : "<<getAverageAge(passangersList,3)<<endl;
    getPassangerByPlace(passangersList,3,"Rostov-on-Don");
}