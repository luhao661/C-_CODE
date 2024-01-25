#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_4_H
#define BCLX_15_8_4_H
// sales.h  -- exceptions and inheritance
#include <stdexcept>//������logic_error�쳣��ϵ�к�runtime_error�쳣��ϵ��
#include <string>

class Sales
{
public:
    enum { MONTHS = 12 };   // could be a static const
    //Ҳ�ɷ���private��
private:
    int year;
    double gross[MONTHS];

public:
    //Ƕ����
    /**************************************************************************/
    class bad_index : public std::logic_error//�߼������е�����ֵ����
    {
    private:
        int bi;  // bad index value

    public:
        explicit bad_index(int ix,//***ע***������ʽ��ʼ����Ŀ���Ƿ�ֹ������ʽ����ת��
            const std::string& s = "Index error in Sales object\n");
        int bi_val() const
        {
            return bi;
        }
        //virtual ~bad_index() throw() {} //C++98�Ĺ��ܣ��쳣�淶
        //��дΪ��(C++11�Ѳ�ʹ���쳣�淶)
        virtual ~bad_index()
        {}
    };
    /**************************************************************************/

    explicit Sales(int yy = 0);//���캯����Ĭ�Ϲ��캯��
    Sales(int yy, const double* gr, int n);

    int Year() const
    {
        return year;
    }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
    virtual ~Sales()
    {}
};

class LabeledSales : public Sales
{
private:
    std::string label;
public:
    /**************************************************************************/
    class nbad_index : public Sales::bad_index//��Ƕ������м̳�
    {
    private:
        std::string lbl;
    public:
        nbad_index(const std::string& lb, int ix,
            const std::string& s = "Index error in LabeledSales object\n");
        const std::string& label_val() const
        {
            return lbl;
        }
        virtual ~nbad_index()
        {}
    };
    /**************************************************************************/

    explicit LabeledSales(const std::string& lb = "none", int yy = 0);
    LabeledSales(const std::string& lb, int yy, const double* gr, int n);

    const std::string& Label() const
    {
        return label;
    }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
    virtual ~LabeledSales()
    {}
};

#endif 
