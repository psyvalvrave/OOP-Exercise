#ifndef CRYPTO_H
#define CRYPTO_H
#include<QVector>
#include<QString>
#include<stdlib.h>

class Crypto{
public:
    Crypto(ushort key, QString opseq,ushort charsiz){
        m_key=key;
        m_OpSequence=opseq;
        m_CharSetSize=charsiz;
    }
    Crypto(ushort key, QString opseq){
        m_key=key;
        m_OpSequence=opseq;
        m_CharSetSize=128;
    }
  QString encrypt(const QString&);
  QString decrypt(const QString&);
  int randomSize(ushort n){
      srand(m_CharSetSize);
      return rand()%n;
  }
private:
  ushort m_key;
  QString m_OpSequence;
  ushort m_CharSetSize;
  QVector<int> m_Perm;
  QString shift(const QString& text);
  QString unshift(const QString& crptext);
  QString permute(const QString& text);
  QString unpermute(const QString& scrtext);
  int myRand(int min,int max);
  QVector<int> randomPerm(int n);
};

#endif // CRYPTO_H
