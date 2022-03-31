#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>


using namespace std;


struct studentData{
    public:
        studentData(std::string sName,int gNum,int chemMark,int phyMark,int progMark){
            surname = sName;
            groupNumber = gNum;
            chemestryMark = chemMark;
            physicsMark = phyMark;
            programmingMark = progMark;
        }
        studentData() = default;

        std::string getSurname(){
            return surname;
        }

        int getGroupNumber(){
            return groupNumber;
        }

        int getChemesty(){
            return chemestryMark;
        }

        int getPhysics(){
            return physicsMark;
        }

        int getProgramming(){
            return programmingMark;
        }

        void setSurname(std::string sName){
            surname = sName;
        }

        void setGroupNumber(int gNum){
            groupNumber = gNum;
        }

        void setChemestryMark(int chemMark){
            chemestryMark = chemMark;
        }

        void setPhysicsMark(int phyMark){
            physicsMark = phyMark;
        }

        void setProgrammingMark(int progMark){
            programmingMark = progMark;
        }


    private:
        std::string surname;
        int groupNumber;
        int chemestryMark;
        int physicsMark;
        int programmingMark;

};


void printLoser(studentData *list,int size){
    for(int i = 0;i<size;i++){
        if(list[i].getChemesty() != 0 && list[i].getPhysics() != 0 && list[i].getProgramming() != 0){
            cout<<"Student "<<list[i].getSurname()<<" isn't a loser!"<<endl;
        }
    }
}


int main(){

    studentData studentList[50];
    
    // set group number
    for(int i = 0;i<50;i++){
        studentList[i].setGroupNumber(rand() % 10);  
    }

    // set physics mark
    for(int i = 0;i<50;i++){
        studentList[i].setPhysicsMark(rand() % 6);
    }

    // set chemestry mark
    for(int i = 0;i<50;i++){
        studentList[i].setChemestryMark(rand() % 6);
    }

    // set programming mark
    for(int i = 0;i<50;i++){
        studentList[i].setProgrammingMark(rand() % 6);
    }

    // set surnames
    std::string line;
 
    std::ifstream in("SurnameList.txt");
    int j = 0;
    if (in.is_open()){
        while (getline(in, line)){
            studentList[j].setSurname(line);
            j++;
        }
    }
    in.close();
    
    printLoser(studentList,50);

}