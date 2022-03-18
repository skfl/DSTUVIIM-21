#include <iostream>

const int n = 3;
int *index[n];

const int size = 7;
int arr[size] = {10,8,3,4,5,6,31};
int a = 3;
int b = 8;

double getProduct(int *arr,int size){
    double product = 1;
    for(int i = 0;i<size;i++){
        product*=arr[i];
    }
    return product;
}

int getSumEven(int *arr,int size){
    int sum=0;
    for(int i=1;i<size;i+=2){
        sum+=arr[i];
    }
    return sum;
}

double getEvenDivOdd(int *arr,int size){
    double sumEven = 0;
    double sumOdd = 0;
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){
            sumEven+=arr[i];
        }else{
            sumOdd+=arr[i];
        }
    }
    if(sumOdd!=0){
        return sumEven/sumOdd;
    }
}

int* getIndexOfPositive(int *arr,int size){
    int *positiveIndex[5];
}

int isIndexEqElem(int *arr,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==i+1){
            std::cout<<"Yes, there is.Index = "<<i+1<<std::endl;
        }
    }
}

int arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int countGap(int *arr,int size,int a,int b){
    int cnt = 0;
    for(int i=0;i<size;i++){
        if(arr[i]>=a && arr[i]<=b){
            cnt+=1;
        }
    }
    return cnt;
}

int* getPositiveIndex(int *arr,int size){
    int cntPos = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] > 0 ){
            cntPos+=1;
        }
    }
    
    int *positiveIndex = new int[cntPos];
    int j = 0;

    for(int i = 0;i < size;i++){
        if(arr[i] > 0){
            positiveIndex[j] = i;
            j++;
        }
    }
    return positiveIndex;
}

int* firstThreeInOrder(int *arr,int size){
    
    int *index = new int[3];
    int cnt = 1;
    int f = 0;

    for(int i = 0;i < size;i++){
        if(arr[i+1] > arr[i]){
            cnt +=1 ;
        }else{
            cnt = 1;
        }
        f = i+1;
        if(cnt == 3){
            for(int j = cnt-1;j >= 0;j--){                             // 1 2 4 1 2 3
                index[j] = f+1;
                f--;
            }
            return index;
        }
    }
    
}

int main(){
    std::cout<<"Array : "<<std::endl;
    arrayOutput(arr,size);
    std::cout<<"a) Product equals : "<<std::endl;
    std::cout<<getProduct(arr,size)<<std::endl;
    std::cout<<"b) Even sum equals : "<<std::endl;
    std::cout<<getSumEven(arr,size)<<std::endl;
    std::cout<<"c) sumEven/sumOdd equals : "<<std::endl;
    std::cout<<getEvenDivOdd(arr,size)<<std::endl;
    std::cout<<"d) Positive nums are on index : "<<std::endl;
    arrayOutput(getPositiveIndex(arr,size),size);
    std::cout<<"e) Is there element equals index : "<<std::endl;
    isIndexEqElem(arr,size);
    std::cout<<"f) There is "<<countGap(arr,size,a,b)<<" numbers for the gap "<<a<<" "<<b<<std::endl;
    std::cout<<"g) First three nums in order are on index :"<<std::endl;
    arrayOutput(firstThreeInOrder(arr,size),3);
    




}