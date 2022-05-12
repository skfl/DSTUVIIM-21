#include <iostream>

using namespace std;

struct elements{
    public:
        elements(std::string elName,int elPriority){
            name = elName;
            priority = elPriority;
        }
        elements()=default;

        std::string getName(){
            return name;
        }

        int getPriority(){
            return priority;
        }

        void setName(std::string elName){
            name = elName;
        }

        void setPriority(int elPriority){
            if(elPriority>=0){
                priority = elPriority;
            }else{
                priority = 0;
            }
        }

    private:
        std::string name;
        int priority;
};

class queue{
    private:
        elements q[10];
        int sloc,rloc,cnt;
    public:
        queue(){
            rloc = 0;
            sloc = 0;
        };

        void qput(elements el){
            if(sloc == 10){
                cout<<"Queue is overfill "<<endl;
                return;
            }else{
                q[sloc++]=el;
                return;
            }
        }

        void putWithPriorityEnd(elements el){
            if(sloc == 10){
                cout<<"Queue is overfill "<<endl;
                return;
            }else{
                if(q[rloc].getPriority()>el.getPriority()){
                    qput(el);
                    //showQueue();
                    return;
                }else{
                    for(int i = sloc;i>0;i--){
                        q[i] = q[i-1];
                    }
                    sloc++;
                    q[rloc] = el;
                    //showQueue();
                    return;
                }
            }
        }

        void putByPriority(elements el){
            if(sloc == 10){
                cout<<"Queue is overfill"<<endl;
                return;
            }else{
                for(int i = 0;i<10;i++){
                    if(q[i].getName() == ""){
                        q[i] = el;
                        sloc++;
                        return;
                    }
                    if(q[i].getPriority()>el.getPriority()){
                        continue;
                    }else{
                        for(int j = sloc;j>i;j--){
                            q[j] = q[j-1];
                        }
                        q[i] = el;
                        sloc++;
                        return; 
                    }
                }
            }
        }

        elements qget(){
            elements null;
            if(rloc == sloc){
                cout<<"Queue is empty"<<endl;
                return null;
            }
            elements tmp = q[rloc];
            for(int i = 1;i<10;i++){
                q[i-1] = q[i];
            }
            q[sloc-1] = null;
            sloc--;
            return tmp;
        }
        
        void killEach(int num){
            elements null;
            int cnt;
            for(int i = num-1;i<10;i+=num){
                q[i] = null;
            }
            for(int i = 0;i<10;i++){
                if(q[i].getName()!=""){
                    continue;
                }else{
                    cnt = i+1;
                    if(cnt<10){
                        while (q[cnt].getName() == "" && cnt+1<10){
                            cnt++;
                        }
                        q[i] = q[cnt];
                        q[cnt] = null;
                    }
                }
            }
            for(int i = 10;i>0;i--){
                if(q[i].getName()!=""){
                    sloc = i+1;
                    return;
                }
            }

        } 

        void showQueue(){
            cout<<"Queue "<<endl;
            for(int i = 0;i<10;i++){
                if(q[i].getName()==""){
                    cout<<i+1<<") empty"<<endl;
                    continue;
                }
                cout<<i+1<<") "<<q[i].getName()<<" with priority "<<q[i].getPriority()<<endl;
            }
        }

};
int main(){
    elements el[11];
    el[0].setName("A");
    el[1].setName("B");
    el[2].setName("C");
    el[3].setName("D");
    el[4].setName("E");
    el[5].setName("F");
    el[6].setName("G");
    el[7].setName("H");
    el[8].setName("I");
    el[9].setName("J");
    el[10].setName("K");
    
    for(int i = 0;i<11;i++){
        el[i].setPriority(rand() % 5);
        //cout<<el[i].getName()<<" "<<el[i].getPriority()<<endl;
    }
    
    queue a;
    for(int i = 0;i<10;i++){
        a.putByPriority(el[i]);
    }
    a.showQueue();
    a.killEach(2);
    a.showQueue();
}