#include<crypto.h>
#include<QString>
#include<QChar>
#include<QByteArray>
#include<QVector>
#include<stdlib.h>

QString Crypto::shift(const QString& text){
    QString result="";
    int r = randomSize(m_CharSetSize);
    for(int i=0;i<text.length();i++){
        result += QChar((int(text[i].toLatin1())+r)%128);
    }
    return result;
}
QString Crypto::unshift(const QString& crptext){
    QString result="";
    int r = randomSize(m_CharSetSize);
    for(int i=0;i<crptext.length();i++){
        int k= int(crptext[i].toLatin1())-r;
        if(k<0){
            k= k+128;
        }
        result += QChar(k);
    }
    return result;
}

QString Crypto::permute(const QString& text){
    srand(m_key);
    m_Perm.resize(text.length());
    m_Perm = randomPerm(text.length());
    QChar temp;
    QString result=text;
    for(int i=0;i<m_Perm.length();i++){
        temp = result[i];
        result[i] = result[m_Perm.at(i)];
        result[m_Perm.at(i)] = temp;
    }
    return result;
}
QString Crypto::unpermute(const QString& scrtext){
    srand(m_key);
    m_Perm.resize(scrtext.length());
    m_Perm = randomPerm(scrtext.length());
    QChar temp;
    QString result=scrtext;
    for(int i=0;i<m_Perm.length();i++){
        temp = result[i];
        result[i] = result[m_Perm.at(i)];
        result[m_Perm.at(i)] = temp;
    }
    return result;
}

int Crypto::myRand(int min, int max){
    return rand()%max+min;
}

QVector<int> Crypto::randomPerm(int n){
    m_Perm.resize(n);
    for(int i=0;i<n;i++){
        m_Perm[i]=i;
    }
    for(int i=0;i<n;i++){
        int r = myRand(1,n-1);
        int temp;
        temp = m_Perm[r-1];
        m_Perm[r-1] = m_Perm[r+1];
        m_Perm[r+1] = temp;
    }
    return m_Perm;
}
QString Crypto::encrypt(const QString& text){
    QString result = text;
    for(int i=0;i<m_OpSequence.length();i++){
        if(m_OpSequence[i]=='p'){
            result = permute(result);
        }
        if(m_OpSequence[i]=='s'){
            result = shift(result);
        }
    }
    return result;
}
QString Crypto::decrypt(const QString& text){
    QString result = text;
    for(int i=m_OpSequence.length();i>=0;i--){
        if(m_OpSequence[i]=='p'){
            result = unpermute(result);
        }
        if(m_OpSequence[i]=='s'){
            result = unshift(result);
        }
    }
    return result;
}

