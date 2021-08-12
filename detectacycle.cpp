#include"graphfunctions.cpp"

int main(){
    /*addedgetograph(1,2);
    addedgetograph(2,1);
    addedgetograph(2,4);
    addedgetograph(4,2);*/
    addedgetograph(3,5);
    addedgetograph(5,3);
    addedgetograph(5,8);
    addedgetograph(8,5);
    addedgetograph(5,6);
    addedgetograph(6,5);
    addedgetograph(6,7);
    addedgetograph(7,6);
    addedgetograph(7,8);
    addedgetograph(8,7);
    addedgetograph(8,9);  
    addedgetograph(9,8);
    //bfscycle();
    dfscycle(3, -1);
}