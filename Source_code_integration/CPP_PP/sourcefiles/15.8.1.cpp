#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
#include "15.8.1.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;

    cout << "TV is " << (state == Off ? "Off" : "On") << endl;

    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV ? "TV" : "DVD") << endl;
    }
}

bool Tv::switch_moshi(Remote& r)const
{
    if (ison())
    {
        r.normal_or_interaction ^= 1;//***ע***��Tv������ΪRemote�����Ԫ
                                                          //��Tv�෽���в��ܷ���Remote���е�˽�г�Ա
        return true;
    }
    else
        return false;
}

void Remote::show_moshi(void)const
{
    using std::cout;
    using std::endl;
    cout << "��ǰģʽΪ��"<<((normal_or_interaction==Tv::Normal)?"����":"����");
    cout << endl;                   //***ע***�˴�Ҫ�����������������������������漰����������ȼ�
}

#endif