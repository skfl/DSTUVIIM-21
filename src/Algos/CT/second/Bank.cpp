#include <iostream>

using namespace std;

struct Coins{
    public:
        
        Coins(int vl,double dmtr){
            value = vl;
            diameter = dmtr;
        }

        Coins()=default;
        void setValue(int vl){
            if(vl > 0){
                value = vl;
            }else{
                cout<<"Value can not be equal or less than zero "<<endl;
                return;
            }
        }

        void setDiameter(double dmtr){
            if(diameter > 0){
                diameter = dmtr;
            }else{
                cout<<"Diameter can not be equal or less than zero "<<endl;
                return;
            }
        }

        int getValue(){
            return value;
        }

        double getDiameter(){
            return diameter;
        }

    private:
        int value;
        double diameter;
};

class BankCC{
  
    private:
        Coins s[15];
        int top;
    public:

        BankCC(){
            top = 0;
        }

        void deposit(Coins coin){
            
            if(coin.getDiameter() > 1.25){
                cout<<"This is fake money"<<endl;
                return;
            }

            if(top>14){
                cout<<"Overflow"<<endl;
                return;
            }

            s[top] = coin;
            top++;
            return;
        }

        void depositC(Coins coin){
            if(top>14){
                cout<<"Overflow"<<endl;
                return;
            }
            s[top] = coin;
            top++;
            return;
        }

        void deposit(Coins *coin,int quantity){
            if(top+quantity>14){
                cout<<"Overflow"<<endl;
                return;
            }

            for(int i = 0;i<quantity;i++){
                if(coin[i].getDiameter() > 1.25){
                    cout<<"This is fake money"<<endl;
                    continue;
                }
                s[top] = coin[i];
                top++;
            }
            return;
        }

        int withdraw(int quantity){
            
            if(top == 0){
                cout<<"Went bankrupt"<<endl;
                return -1;
            }
            if(top - quantity < 0){
                cout<<"There is no such quantity of coins"<<endl;
                return -1;
            }
            int sum = 0;
            int cnt = top;
            for(int i = top;i>cnt-quantity;i--){
                if(top>0){
                    sum += s[top-1].getValue();
                    top--;
                }
            }
            cout<<"There were taken "<<quantity<<" coins for amount "<<sum<<endl;
            return sum;
        }    

        void putBack(int quantity){
            top+=quantity;
            return;
        }

        void showStack(){
            cout<<"Stack:"<<endl;
            for(int i = top-1;i>-1;i--){
                if(s[i].getValue()==0){
                    cout<<i+1<<") empty"<<endl;
                }else{
                    cout<<i+1<<") "<<s[i].getValue()<<endl;
                }
            }
        }
};

class Citizen{
    
    private:
        std::string name;
    protected:
        int bankroll;
    public:
        Citizen(std::string nm){
            name = nm;
            bankroll = 0;
        }
        Citizen()=default;

        void setName(std::string nm){
            if(nm != ""){
                name = nm;
            }else{
                cout<<"Name can not be empty"<<endl;
                return;
            }
        }

        std::string getName(){
            return name;
        }

        int audit(){
            return bankroll;
        }

        void pull(Coins coin,BankCC * bank){
                bank->deposit(coin);
                bankroll += coin.getValue();
        }

        void pull(Coins *coin,int quantity,BankCC * bank){
                bank->deposit(coin,quantity);
                for(int i = 0;i<quantity;i++){
                    bankroll += coin[i].getValue();
                }
        }

        void take(int quantity,BankCC * bank){
            bankroll -= bank->withdraw(quantity);
        }
};

class Counterfeiter : public Citizen{
    private:
    
    public:
        Counterfeiter(std::string nm):Citizen(nm){
        }
        
        void pull(Coins coin,BankCC * bank){
            if(coin.getDiameter() < 1.25){
                cout<<"Counterfeiters can only pull fake money"<<endl;
                return;
            }else{
                bank->depositC(coin);
                bankroll +=coin.getValue();
            }
        }

        void pull(Coins *coin,int quantity,BankCC * bank){
            for(int i = 0;i<quantity;i++){
                if(coin[i].getDiameter() < 1.25){
                    cout<<"Counterfeiters can only pull fake money"<<endl;
                    continue;
                }else{
                    bank->depositC(coin[i]);
                    bankroll +=coin[i].getValue();
                }
            }
        }

        void take(int quantity,BankCC *bank){
            int tmp = bank->withdraw(quantity);
            if(tmp<=10){
                bankroll -=tmp;
            }else{
                bank->putBack(quantity);
                cout<<"Counterfeiters can only take 10 or less money"<<endl;
                return;
            }
        }
};

class Crook : public Citizen{
    private:
        int steal = 0;
    public:
        Crook(std::string nm):Citizen(nm){
        }

        void grabAllMoney(BankCC * bank){
            if(steal == 0){
                int tmp = 1;
                while(tmp>0){
                    tmp = bank->withdraw(1);
                    bankroll+=tmp;
                }
            bankroll+=1;
            }else{
                cout<<"He already stealth money"<<endl;
                return;
            }
        }
};

void findMinMaxBankroll(Citizen **list,int count){
    int min = list[0]->audit();
    int max = list[0]->audit();
    int minIndex = 0;
    int maxIndex = 0;

    for(int i = 1;i<count;i++){
        if(list[i]->audit()<min){
            min = list[i]->audit();
            minIndex = i;
        }
        if(list[i]->audit()>max){
            max = list[i]->audit();
            maxIndex = i;
        }
    }
    cout<<"The most rich is "<<list[maxIndex]->getName()<<endl;
    cout<<"The most poor is "<<list[minIndex]->getName()<<endl;
}

int main(){
    BankCC bank;
    BankCC *bankCC = &bank;
    
    Coins coin1(1,1);
    Coins coin2(2,1);
    Coins coin5(5,1.1);
    Coins coin10(10,1.1);
    Coins fake(666,1.27);

    Coins pull[4];
    pull[0] = coin1;
    pull[1] = coin1;
    pull[2] = coin1;
    pull[3] = coin1;

    Coins fakePull[4];
    fakePull[0] = fake;
    fakePull[1] = coin1;
    fakePull[2] = fake;
    fakePull[3] = fake;

    Citizen *list[5];
    
    Citizen human1("Hoking");
    Citizen human2("Pushkin");
    Counterfeiter human3("Bender");
    Crook human4("Suvorov");
    Citizen human5("Strelcov");   

    Citizen *human11 = &human1;
    Citizen *human22 = &human2;
    Citizen *human55 = &human5;
    Crook *human44 = &human4;
    Counterfeiter *human33 = &human3;

    list[0] = human11;
    list[1] = human22;
    list[2] = human33;
    list[3] = human44;
    list[4] = human55;

    human1.pull(coin5,bankCC);
    human1.pull(coin5,bankCC);
    human2.pull(coin2,bankCC);
    human3.pull(fake,bankCC);
    human4.pull(coin10,bankCC);
    human4.grabAllMoney(bankCC);
    bankCC->showStack();
    findMinMaxBankroll(list,5);

    return 0;
}