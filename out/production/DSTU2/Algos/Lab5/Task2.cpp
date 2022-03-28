#include <iostream>
#include <string>

using namespace std;


struct shop{
    public:
        shop(int id,std::string number){
            shop_id = id;
            phone_number = number;
        }
        shop()=default;

    void setId(int id){
        shop_id = id;
    }

    void setNumber(std::string num){
        phone_number = num;
    }

    int getId(){
        return shop_id;
    }

    std::string getNumber(){
        return phone_number;
    }

    private:
        int shop_id;
        std::string phone_number;    
};


struct goods{

public:
    goods(double pr,double weig,std::string nm,int quant,shop sh){
        price = pr;
        weight = weig;
        name = nm;
        quantity = quant;
        shop = sh;
    }

    void setPrice(double pr){
        if(pr>0){
            price = pr;
        }
    }

    void setWeight(double weig){
        if(weig>0){
            weight = weig;
        }
    }

    void setQuantity(int quan){
        quantity = quan;
    }

    void setShop(shop sh){
        shop = sh;
    }

    void setName(std::string nm){
        name = nm;
    }

    double getPrice(){
        return price;
    }

    int getQuantity(){
        return quantity;
    }

    shop getShop(){
        return shop;
    }

    double getWeight(){
        return weight;
    }

    std::string getName(){
        return name;
    }

    private:
        double price;
        double weight;
        std::string name;
        int quantity;
        shop shop;
};


double getAveragePrice(goods *list,int size){
    double avgPrice = 0;
    for(int i = 0;i < size;i++){
        avgPrice += list[i].getPrice();
    }
    avgPrice = avgPrice/size;
    return avgPrice;
}


int getTotalQuantity(goods *list,int size){
    int totalQuantity = 0;
    for(int i = 0; i < size; i++){
        totalQuantity+=list[i].getQuantity();
    }
    return totalQuantity;
}


int main(){
    shop shop_first(1,"+79213453494");
    shop shop_second(2,"+124566653494");

    goods ball(100,0.2,"ball",10,shop_first);
    goods apple(8,0.1,"apple",100,shop_first);
    goods banana(11,0.1,"banana",200,shop_first);

    goods cucumber(5,0.1,"cucumber",800,shop_second);
    goods milk(20,1,"milk",20,shop_second);
    goods cheese(45,0.5,"cheese",130,shop_second);

    goods first_shop_list[3]={ball,apple,banana};
    goods second_shop_list[3]={cucumber,milk,cheese};

    cout<<"Average price for shop 1 : "<<getAveragePrice(first_shop_list,3)<<" Total quantity of goods : "<<getTotalQuantity(first_shop_list,3)<<endl;
    cout<<"Average price for shop 2 : "<<getAveragePrice(second_shop_list,3)<<" Total quantity of goods : "<<getTotalQuantity(second_shop_list,3)<<endl;
}
