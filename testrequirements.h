#ifndef TESTREQUIREMENTS_H
#define TESTREQUIREMENTS_H
#include<stdlib.h>
#include<QVector>

class TestRequirement{
public:
    TestRequirement();
    ~TestRequirement();
    int myRand(int min,int max);
    QVector<QString> randomPerm(int n, unsigned key);
};

#endif // TESTREQUIREMENTS_H
