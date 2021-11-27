#ifndef QUESTION1_H
#define QUESTION1_H
#include<cstring>
class CMystring
{
private:
    char* m_pData;
public:
    CMystring(char* pData = nullptr);
    CMystring(const CMystring& str);
    ~CMystring(void);

    CMystring& operator =(const CMystring& str)
    {
        //basic
        /*if(this == &str)
        {
            return *this;
        }

        delete []m_pData;
        m_pData = nullptr;

        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(m_pData,str.m_pData);*/
        //advance
        if(this != &str)
        {
            CMystring strTemp(str);

            char* pTemp = strTemp.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }
    }
};

#endif // QUESTION1_H
