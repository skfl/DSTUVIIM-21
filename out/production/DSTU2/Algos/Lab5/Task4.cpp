#include <iostream>
#include <string>

using namespace std;

struct pupilData{
    public:
        pupilData(std::string fullName,int ag,int schID,int clsID,int russMark,int mthMark,int phyMark){
            name = fullName;
            age = ag;
            schoolID = schID;
            classID = clsID;
            russianLanguageMark = russMark;
            mathMark = mthMark;
            physicsMark = phyMark;
        }
        
        void setName(std::string fullName){
            name = fullName;
        }

        void setAge(int ag){
            if(ag>0 && ag<150){
                age = ag;
            }
        }

        void setSchoolID(int schID){
            schoolID = schID;
        }

        void setClassID(int clsID){
            classID = clsID;
        }

        void setRussianLanguageMark(int russMark){
            if(russMark>0){
                russianLanguageMark = russMark;
            }
        }

        void setMathMark(int mthMark){
            if(mthMark>0){
                mathMark = mthMark;
            }
        }

        void setPhysicsMark(int phyMark){
            if(phyMark>0){
                physicsMark = phyMark;
            }
        }

        std::string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        int getSchoolID(){
            return schoolID;
        }

        int getClassID(){
            return classID;
        }

        int getRussianLanguageMark(){
            return russianLanguageMark;
        }

        int getMathMark(){
            return mathMark;
        }

        int getPhysicsMark(){
            return physicsMark;
        }


    private:
      std::string name;
      int age;
      int schoolID;
      int classID;
      int russianLanguageMark;
      int mathMark;
      int physicsMark;  
};

double getAverageMark(pupilData *list,int size){
    double avgMark = 0;
    for(int i = 0;i < size;i++){
        avgMark += list[i].getRussianLanguageMark();
        avgMark += list[i].getMathMark();
        avgMark += list[i].getPhysicsMark();
    }
    avgMark = avgMark / (size*3);
    return avgMark;
}

std::string getBestStudent(pupilData *list,int size){
    int maxIndex = 0;
    int maxSum = 0;
    maxSum += list[0].getRussianLanguageMark();
    maxSum += list[0].getMathMark();
    maxSum += list[0].getPhysicsMark();
    int tmpSum = 0;
    for(int i = 1;i<size;i++){
        tmpSum += list[i].getRussianLanguageMark();
        tmpSum += list[i].getMathMark();
        tmpSum += list[i].getPhysicsMark();
        if(tmpSum>maxSum){
            maxSum = tmpSum;
            maxIndex = i;
        }
        tmpSum = 0;
    }
    return list[maxIndex].getName();
}

int main(){

    pupilData firstStudent("Polevskih Vladislav Aleksandrovich",16,115,10,4,3,3);
    pupilData secondStudent("Skokov Vlade Milanovich",13,228,8,4,4,4);
    pupilData thirdStudent("Brezhnev Artem Aleksandrovich",12,1,3,4,2,2);
    pupilData fourthStudent("Solomakha Denis Anatolevich",16,5,11,5,5,5);
    pupilData fifthStudent("Kudzaev Azamat Kazbekovich",15,113,11,5,4,4);

    pupilData studentsList[5]={fifthStudent,secondStudent,thirdStudent,fourthStudent,thirdStudent};

    cout<<"Average mark is "<<getAverageMark(studentsList,5)<<endl;
    cout<<"Best student is "<<getBestStudent(studentsList,5)<<endl;
}