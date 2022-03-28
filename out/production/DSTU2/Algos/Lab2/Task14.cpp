#include <iostream>

const int size=4;
int A[size] ={2,2,2,4};
int B[size] ={4,1,2,1};

int* sortArray(int *arr,int size){
    int tmp;
    for(int i = 0;i<size-1;i++){
        for(int j = 0;j < size - i - 1;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = tmp; 
            }
        }
    }
    return arr;
}

int getCSize(int *A,int *B,int size){
    int *srtdA = new int[size];
    srtdA = sortArray(A,size);

    int cSize = 0;
     
    for(int i = 0;i < size;i++){
        int j = i+1;
        if(srtdA[i] == srtdA[j]){
            while(srtdA[i] == srtdA[j]){
                j++;
            }
        }
        j -= 1;
        for(int k = 0;k < size;k++){
            
            if(B[k]==srtdA[j]){
                cSize += 1;
                break;
            }
        }
        i = j;
    }
    if(cSize<1){
        return -1;
    }
    return cSize;
}

int* getArrayOfCommons(int *A,int *B,int size,int cSize){
    if(cSize<1){
        std::cout<<"There is no common numbers"<<std::endl;
        return NULL;
    }
    int *srtdA = new int[size];
    srtdA = sortArray(A,size);

    int *C = new int[cSize];
    int z = 0;

    for(int i = 0;i<size;i++){
                                                            // 2 2 2 4    
        int j = i+1;
        if(srtdA[i] == srtdA[j]){
            while(srtdA[i] == srtdA[j]){
                j++;
            }
        }
        j -= 1;
        
        for(int k = 0;k < size;k++){
            
            if(B[k]==srtdA[j]){
                C[z]=srtdA[j];
                z+=1;
                break;
            }
        }
        i = j;
    }
    return C;
}

int arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"A array : "<<std::endl;
    arrayOutput(A,size);
    std::cout<<"B array : "<<std::endl;
    arrayOutput(B,size);
    std::cout<<"C array : "<<std::endl;
    arrayOutput(getArrayOfCommons(A,B,size,getCSize(A,B,size)),getCSize(A,B,size));
    
}