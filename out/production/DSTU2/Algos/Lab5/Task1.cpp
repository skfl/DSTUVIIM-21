#include <iostream>
#include <string>

using namespace std;

struct goods{

public:
    goods(double pr,double weig,std::string qual,std::string nm){
        price = pr;
        weight = weig;
        quality = qual;
        name = nm;
    }

    void setPrice(double pr){
        if(pr>0){
            price = pr;
        }
    }

    void setQuality(std::string qual){
        quality = qual;
    }

    void setWeight(double weig){
        if(weig>0){
            weight = weig;
        }
    }

    void setName(std::string nm){
        name = nm;
    }

    double getPrice(){
        return price;
    }

    std::string getQuality(){
        return quality;
    }

    double getWeight(){
        return weight;
    }

    std::string getName(){
        return name;
    }

    private:
        std::string quality;
        double price;
        double weight;
        std::string name;
};


void getMinPrice(goods *list,int size){
    
    double minPrice = list[0].getPrice();
    int minIndex = 0;

    for(int i = 1;i < size; i++){
        if(list[i].getPrice()<minPrice){
            minIndex = i;
            minPrice = list[i].getPrice();
        }
    }
    cout<<"The smallest price is "<<minPrice<<" And thats the cost of "<<list[minIndex].getName()<<endl;
}

void getMaxPrice(goods *list,int size){
    
    double maxPrice = list[0].getPrice();
    int maxIndex = 0;

    for(int i = 1;i < size; i++){
        if(list[i].getPrice()>maxPrice){
            maxIndex = i;
            maxPrice = list[i].getPrice();
        }
    }
    cout<<"The biggest price is "<<maxPrice<<" And thats the cost of "<<list[maxIndex].getName()<<endl;
}

int main(){
    
    goods ball(100,0.2,"good","ball");
    goods book(50,0.2,"factory new","book");
    goods notebook(10000,3,"factory new","notebook");
    goods chair(320,1.4,"battle scarred","chair");
    goods skirt(500,0.3,"factory new","skirt");

    goods list[5] = {ball,book,notebook,chair,skirt};

    getMinPrice(list,5);
    getMaxPrice(list,5);
}