#include <iostream>

using namespace std;

class Stack{
    private:
        std::string s[10];
        int top;
        int bot;
        int len;
    
    public:
        Stack(){
            top = 9;
            bot = 0;

        }

        void putFromString(std::string str){;
            if(str.length()>10){
                cout<<"doesnt fit"<<endl;
                return;
            }
            len = str.length();
            top = len-1;
            for(int i = 0;i<str.length();i++){
                s[i] = str[i];
            }
        }

        bool check(){
            bool v = false;
            if(s[0] == ""){
                cout<<"Stack is empty"<<endl;
                return v;
            }

            if(len%2!=0){
                cout<<"Uneven quantity"<<endl;
                return v;
            }

            while(top-bot>0){
                if((s[top]==")" && s[bot]=="(") || (s[top]=="]" && s[bot]=="[")){
                    top--;
                    bot++;
                }else{
                    cout<<"There is mismatch"<<endl;
                    return v;
                }
            }
            v = true;
            cout<<"Everything is fine"<<endl;
            return v;
        }

        void showStack(){
            cout<<"Stack :"<<endl;
            for(int i = 9;i>-1;i--){
                cout<<i+1<<") "<<s[i]<<endl;
            }
        }
};

int main(){
    Stack s;
    std::string str = "(([(())])))))"; // (([(]))) (([(())]))
    s.putFromString(str);
    s.check();
}