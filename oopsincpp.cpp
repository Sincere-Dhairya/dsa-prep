#include<iostream>
#include<string.h>
//#include<conio.h>

using namespace std;

class parent{
    private:
    int age;
    void set_age(){
        this->age = 26;
    }

    public:
    int score;
    string name;
    parent(int num){ score = num;}
    parent(int n, string s) {
        score = n, name = s;
    }
    int get_score(){ return score;}
    int get_age(){
        set_age();
        return age;
    }
};

int main(){
    parent a(5, "sameer");
    cout<<sizeof(a);
    //getche();
    //getch();
    return 0;
}