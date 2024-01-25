#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_1_H
#define BCLX_15_8_1_H

//class Remote;   //�˴����Բ�����ǰ����������Ϊfriend class Remote;�Ѿ��൱��ǰ������

class Tv
{
    friend class Remote;   // Remote can access Tv private parts
                                          //***ע***����Ԫ��������λ���κ�λ��
private:
    int state;                // on or off
    int volume;            // assumed to be digitized
    int maxchannel;    // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;               // TV or DVD

public:
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
    enum {Normal, Interaction};

    Tv(int s = Off, int mc = 125)
        : state(s), volume(5), maxchannel(mc), channel(2),
        mode(Cable), input(TV)
    {}
    void onoff()
    {
        //state = (state == On) ? Off : On; 
        //д������
        state ^= 1;
    }
    bool ison() const
    {
        return state == On;
    }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode()
    {
        mode = (mode == Antenna) ? Cable : Antenna;
    }
    void set_input()
    {
        input = (input == TV) ? DVD : TV;
    }
    void settings() const; // display all settings

    bool switch_moshi(Remote& r)const;
};

class Remote
{
    friend class Tv;

private:
    int mode;              // controls TV or DVD
    int normal_or_interaction;//����򻥶�ģʽ

public:
    Remote(int m = Tv::TV,int m1= Tv::Normal)//��Ԫ�������������ڣ�Ҫʹ�����е���ʾ�����Ļ�Ҫ����������������������P329
        : mode(m),normal_or_interaction(m1)
    {}
    bool volup(Tv& t)
    {
        return t.volup();
    }
    bool voldown(Tv& t)
    {
        return t.voldown();
    }
    void onoff(Tv& t)
    {
        t.onoff();
    }
    void chanup(Tv& t)
    {
        t.chanup();
    }
    void chandown(Tv& t)
    {
        t.chandown();
    }
    void set_chan(Tv& t, int c)
    {
        t.channel = c; //***ע***��Ԫ�෽�����Է���ԭʼ���˽�г�Ա�ͱ�����Ա
    }
    void set_mode(Tv& t)
    {
        t.set_mode();
    }
    void set_input(Tv& t)
    {
        t.set_input();
    }
    void show_moshi(void)const;
};
#endif
