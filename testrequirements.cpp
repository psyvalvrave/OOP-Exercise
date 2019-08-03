#include<testrequirements.h>
#include<QChar>
#include<QString>
using namespace std;
int TestRequirement::myRand(int min, int max){
    return rand()%max+min;
}

friend QVector<QString> TestRequirement::randomPerm(int n, unsigned key){
    srand(key);
    QVector<QString> vector(n);
    for(int i=0;i<vector.length();i++){
        vector[i]=i;
    }
    for(int i=0;i<vector.length();i++){
        int r = myRand(1,n-1);
        QString temp;
        temp = vector[r-1];
        vector[r-1] = vector[r+1];
        vector[r+1] = temp;
    }
    return vector;
}


