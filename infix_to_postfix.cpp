#include <iostream>
#include <stack>
using namespace std ;

int precedence(char op ){
    if(op == '+' || op == '-')
    return 1 ;
    if(op == '*' || op == '/' || op=='%')
    return 2 ;
    if(op == '^')
    return 3 ;

    return 0 ;

}

bool isrightassociative(char op){
    return op == '^' ;
}

int main(){
    string q , p ;
    cout<<"enter infix " ;
    cin>>q ;
    stack<char> s ;

    for(int i = 0 ; i < q.length() ; i++){

        char ch = q[i] ;
        if(isalnum(ch)){
            p = p +ch ;
        }
        else if(ch == '('){
            s.push(ch) ;
        }
        else if(ch == ')'){
            while(!s.empty() && s.top()!= '('){
                p = p + (s.top()) ;
                s.pop() ;
            }
        }
        else{
            while(!s.empty() && s.top()!= '(' && 
                    (precedence(s.top()))> precedence(ch) || 
                      (precedence(s.top())) == precedence(ch) && !isrightassociative  )
                      {
                        p = p + s.top() ;
                        s.pop() ;
                      }
                      s.push(ch) ;
        }

        while(!s.empty()){
            p = p+ s.top() ;
            s.pop() ;
        }
        cout<<"postfix" <<p<<endl ;
    }
}
