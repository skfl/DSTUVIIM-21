#include <iostream>

using namespace std;

struct Cat{
    public:
        Cat(std::string nm,std::string clr,int wght,int ag){
            name = nm;
            color = clr;
            weight = wght;
            age = ag;
        }

        Cat()=default;

        void setName(std::string nm){
            name = nm;
        }

        void setColor(std::string clr){
            color = clr;
        }

        void setWeight(int wght){
            if(wght>0){
                weight = wght;
            }
        }

        void setAge(int ag){
            age = ag;
        }

        std::string getName(){
            return name;
        }

        std::string getColor(){
            return color;
        }

        int getWeight(){
            return weight;
        }

        int getAge(){
            return age;
        }
    private:
        std::string name;
        std::string color;
        int weight;
        int age;
};

class Queue{
    private:
        Cat q[10];
        int sloc,rloc,cnt;
    public:
        Queue(){
            rloc = 0;
            sloc = 0;
        };

        void qput(Cat el){
            if(sloc == 10){
                cout<<"Queue is overfill "<<endl;
                return;
            }else{
                q[sloc++]=el;
                return;
            }
        }

        Cat qget(){
            Cat null;
            if(rloc == sloc){
                cout<<"Queue is empty"<<endl;
                return null;
            }
            Cat tmp = q[rloc];
            for(int i = 1;i<10;i++){
                q[i-1] = q[i];
            }
            q[sloc-1] = null;
            sloc--;
            return tmp;
        }
        
        void showQueue(){
            cout<<"Queue "<<endl;
            for(int i = 0;i<10;i++){
                if(q[i].getName()==""){
                    cout<<i+1<<") empty"<<endl;
                    continue;
                }
                cout<<i+1<<") "<<q[i].getName()<<endl;
            }
        }

};

class Stack{
    private:
        Cat s[10];
        int top;
    public:
        Stack(){
            top = 0;
        }
        void put(Cat cat){
            if(top>=10){
                cout<<"Stack overflow"<<endl;
                return;
            }else{
                s[top] = cat;
                top++;
                return;
            }
        }

        Queue takeToQueue(){
            Queue q;
            if(top == 0 ){
                cout<<"There are no cats"<<endl;
                return q;
            }
            for(int i = top;i>0;i--){
                if(i-1>=0){
                    if(s[i-1].getColor() == "white" || s[i-1].getColor() == "red"){
                        q.qput(s[i-1]);
                    }
                }
            }
            return q;
        }

        void showStack(){
            cout<<"Stack:"<<endl;
            for(int i = 9;i>-1;i--){
                if(s[i].getName()==""){
                    cout<<i+1<<") empty"<<endl;
                }else{
                    cout<<i+1<<") "<<s[i].getName()<<endl;
                }
            }
        }

};

int main(){
    Cat barsik("barsik","white",7,2);
    Cat murzik("murzik","red",6,1);
    Cat sema("sema","black",5,2);
    Cat shanya("shanya","red",6,2);
    Cat uni("uni","multi",4,5);
    Cat maks("maks","white",6,8);
    Stack s;
    Queue q;
    s.put(barsik);
    s.put(murzik);
    s.put(sema);
    s.put(shanya);
    s.put(uni);
    s.put(maks);


    s.showStack();
    q = s.takeToQueue();
    q.showQueue();
    
}