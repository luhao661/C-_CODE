#define _CRT_SECURE_NO_WARNINGS 1

// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_

#include <string>
using std::string;

// simple base class
class TableTennisPlayer
{
private:
    string firstname;//***ע***string����ȷʵʹ���˶�̬�ڴ���䣬
    string lastname;//�������û��ʹ�ã�����಻��Ҫ�ر��帴�ƹ��캯�������������Ⱥ���
    bool hasTable;
public:
    TableTennisPlayer(const string& fn = "none",
        const string& ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};
#endif
