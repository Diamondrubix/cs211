/*
#include "arrayListMine.h"



template <class t>
ArrayList<t>::ArrayList(){
    arr = (t *) malloc (size * sizeof(t));
    init();
}
*/
/*
template <class t>
ArrayList<t>::init(){
    int size = 2;
    int leng = 2;
    int end = 0;
    int growth = 2;
    t* arr;
}
 */
/*
template <class t>
t ArrayList<t>::add(t a){
    if(leng==size){
        int *temp;
        size = size + growth;
        temp = (t *) malloc ( size * sizeof(t) );
        //temp[size];
        int i;
        for ( i = 0 ; i < leng ; i++)
            temp[i] = arr[i];
        leng = i++;
        free (arr);
        arr = temp;
    }
    arr[leng]=a;
    leng++;
}
*/
//will return the amount of elements in the array
/*
template <class t>
ArrayList<t>::length(){
    return leng;
}
 */
/*
template <class t>
ArrayList<t>::get(int i){
    return arr[i];
}
 */


//change by how much the array grows. idk if explicit is a good idea
/* ArrayList::ArrayList(int g){
    growth = g;
    arr = (t *) malloc (size * sizeof(t));
}
 */