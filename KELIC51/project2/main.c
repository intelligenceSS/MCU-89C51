#include <REG51.H>
sbit led0 = P1 ^ 0;
sbit led1 = P1 ^ 1;
sbit led2 = P1 ^ 2;
sbit led3 = P1 ^ 3;
sbit s0 = P1 ^ 7;
sbit s1 = P1 ^ 6;

void main()
{
    while (1)
    {   
        // 面判断是s0和s1两开关者关状态(高电压为1，不等于0即全为1)
        // 当s0和s1都关闭状态让led0亮
        if ((s0 != 0) && (s1 != 0))
        {
            led0 = 0;  // 让led0为开状态(亮灯)
            led1 = led2 = led3 = 1;  //其于的灯为关状态(熄灭)
        }
        // 当s0单独按下s1为关闭状态让led1为高
        else if ((s0 != 1) && (s1 != 0))
        {
            led1 = 0;
            led0 = led2 = led3 = 1;
        }
        // 当s1单独按下，s0为关闭状态让led2亮
        else if ((s0 != 0) && (s1 != 1))
        {
            led2 = 0;
            led0 = led1 = led3 = 1;
        }
        // 当s0和s1同时按下，让led3亮
        else if ((s0 != 1) && (s1 != 1))
        {
            led3 = 0;
            led0 = led2 = led1 = 1;
        }
    }
}