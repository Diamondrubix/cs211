
#include "dynamicList.h"

int main() {

    dynamicList sets[5];

    sets[0]= dynamicList();
    sets[1]= dynamicList();
    sets[2]= dynamicList();
    sets[3]= dynamicList();
    sets[4]= dynamicList();
    printf("welcome to my final exam program!\n");


    int command;
    int val1;
    int val2;
    int val3;
    scanf("%d",&command);
    bool gameOver = false;

    while(!gameOver) {
        if(command ==6){
            gameOver = true;
            break;
        }else{
            scanf("%d",&val1);
        }

        if (command == 1) {
            scanf("%d", &val2);
            if(!sets[val1-1].doesValueExist(val2)) {
                sets[val1 - 1].add(val2);
            }else{
                printf("%d is already in set %d\n",val2,val1);
            }
        }else if(command ==2){
            sets[val1-1].showList();
            printf("\n");
        }else if(command ==3){
            sets[val1-1].removeAll();
        }else if(command ==4){
            scanf("%d", &val2);
            scanf("%d", &val3);

            int i;
            int j;
            sets[val1-1].removeAll();
            for(i = 0; i<=sets[val2-1].length();i++){
                if(!sets[val1-1].doesValueExist(sets[val2-1].get(i))){
                    sets[val1-1].add(sets[val2-1].get(i));
                }
            }
            for(i = 0; i<=sets[val3-1].length();i++){
                if(!sets[val1-1].doesValueExist(sets[val3-1].get(i))){
                    sets[val1-1].add(sets[val3-1].get(i));
                }
            }

        }else if(command ==5){
            scanf("%d", &val2);
            scanf("%d", &val3);

            int i;
            int j;

            sets[val1-1].removeAll();

            for(i=0;i<=sets[val2-1].length();i++){
                if(sets[val3-1].doesValueExist(sets[val2-1].get(i))){
                    if(!sets[val1-1].doesValueExist(sets[val2-1].get(i))){
                        sets[val1-1].add(sets[val2-1].get(i));
                    }
                }
            }

            for(i=0;i<=sets[val2-1].length();i++){
                for(j=0;j<=sets[val3-1].length();j++){
                    if(sets[val2-1].get(i)==sets[val3-1].get(j)){
                        if(!sets[val1-1].doesValueExist(sets[val2-1].get(i))) {
                            sets[val1 - 1].add(sets[val2-1].get(i));
                        }
                    }
                }
            }


        }else{
            printf("the input you provided in not a valid command\n");
        }

        scanf("%d",&command);
        //scanf("%d",&val1);

    }

    //printf("command %d, val %d",command,val1);


    return 0;
}