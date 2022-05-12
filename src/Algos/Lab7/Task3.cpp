#include <iostream>

using namespace std;

struct Coin{
    public:
        Coin(int vl,std::string nm){
            value = vl;
            name = nm;
        }
        Coin()=default;

        void setValue(int vl){
            value = vl;
        }

        void setName(std::string nm){
            name = nm;
        }

        int getValue(){
            return value;
        }

        std::string getName(){
            return name;
        }

    private:
        int value;
        std::string name;
};

class stack{
    private:
        Coin s[10];
        int top;
    public:
        stack(){
            top = 0;
        }

        void put(Coin coin){
            if(top>=10){
                cout<<"Stack overflow"<<endl;
                return;
            }else{
                s[top] = coin;
                top++;
                return;
            }
        }
        int getBankroll(){
            int sum = 0;
            for(int i = top;i>0;i--){
                sum+=s[i-1].getValue();
            }
            return sum;
        }
        int takeByVolume(int volume){
            if(top == 0){
                cout<<"Stack is empty"<<endl;
                return -1;
            }

            if(getBankroll()<volume){
                cout<<"There is no such money "<<endl;
                return -1;
            }
            int sum = 0;
            int cnt = 0;
            Coin null;
            while(sum<volume && top-1 >= 0){
              sum += s[top-1].getValue();
              s[top-1] = null;
              top--;
              cnt++;
            }
            
            cout<<"There were taken "<<cnt<<" coins for amount "<<sum<<endl;
            return sum;
        }

        int takeByQuantity(int quantity){
            if(top == 0){
                cout<<"Stack is empty"<<endl;
                return -1;
            }

            if(top - quantity < 0){
                cout<<"There is no such quantity of coins"<<endl;
                return -1;
            }
            
            int sum = 0;
            Coin null;
            int cnt = top;
            for(int i = top;i>cnt-quantity;i--){
                
                if(top>0){
                    sum += s[top-1].getValue();
                    s[top-1] = null;
                    top--;
                }
            }
            cout<<"There were taken "<<quantity<<" coins for amount "<<sum<<endl;
            return sum;
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
    stack a;
    Coin coin10(10,"10");
    Coin coin5(5,"5");
    Coin coin2(2,"2");
    Coin coin1(1,"1");
    
    
    a.put(coin2);
    a.put(coin1);
    a.put(coin2);
    a.put(coin1);
    a.put(coin10);
    a.put(coin1);
    a.put(coin10);
    a.put(coin5);
    a.put(coin5);
    a.put(coin5);
    cout<<a.getBankroll()<<" - bank"<<endl;
    a.showStack();
    a.takeByQuantity(4);
    a.showStack();
    
    
}