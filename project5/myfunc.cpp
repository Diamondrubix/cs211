#include "myfunc.h"

int debugmode = 0;


int eval(int v1,int v2,char op){
    if(op=='+'){
        return v1+v2;
    }else if(op=='-'){
        return v1-v2;
    }else if(op=='/'){
        return v1/v2;
    }else{
        return v1*v2;
    }

}

int popAndEval(ArrayList<int> *nums, ArrayList<char> *ops){
    int i=0;
    if(nums->length()<1){
        printf("input was not given correctly\n");
        return -999;
    }
    char op = ops->top();
    ops->pop();
    int v2 = nums->top();
    //printf("\nv1 %d \n",v1);
    nums->pop();
    int v1 = nums->top();
    //printf("v2 %d \n",v2);
    nums->pop();
    int v3 = eval(v1, v2, op);
    nums->add(v3);

}

int postfix(ArrayList<int> *nums, ArrayList<char> *ops){
    int v3 = 0;
    while(!ops->isEmpty()) {
        int i=0;
        if(nums->length()<1){
            printf("input was not given correctly\n");
            return -999;
        }
        char op = ops->top();
        ops->pop();
        int v2 = nums->top();
        //printf("\nv1 %d \n",v1);
        nums->pop();
        int v1 = nums->top();
        //printf("v2 %d \n",v2);
        nums->pop();
        v3 = eval(v1, v2, op);
        nums->add(v3);
    }
    return(v3);
}