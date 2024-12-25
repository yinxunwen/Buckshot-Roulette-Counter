#include <iostream>
#include <thread>
#include <queue>//队列

class GUI {
    private:
    public:
};

class main_module {
private:
    bool first_run = true;
    std::queue<int> Prophecy_notification_queue;
public:

    struct data{//数据储存
        int Bullet_Quantity_Empty_Pack_Bullets;
        int Number_of_bullets_Live_ammunition;
    }data;
    struct Mobile
    {
        int position;
        bool type;//true为实弹，false为空包弹
        bool Status_reminder = false;//状态提醒
    }Mobile;
    

    int Probability_calculation(){//计算概率 
    /* 在一组奖品中，每个奖品有自己的概率，总概率为 1.0，也就是说在库存充足的情况下，必然能抽中其中的一个。
    通过「谢谢参与」来作为无奖的奖品（也是一种奖品）需要注意的是：如果一组中所有的奖品，总概率之和不为 1.0，
    那么数值代表的概率就不是真实概率了，需要用所占比例来作为新的概率：
    新概率值=奖品概率/总概率。举个例子：只有 A 和 B 两个奖品，A 概率是 0.1，B 概率是 0.3，那么总概率就是 0.4，
    A 的真实概率就是0.1/0.4=0.25，B 的真实概率是0.3/0.4=0.75，真实的总概率依然为1。
    所以如果想要配置的奖品概率正好是抽奖时的概率值，那么就需要为这一组奖品列表的总概率配置成1.0 */
        double Probability_of_live_ammunition = 0.1 * data.Number_of_bullets_Live_ammunition/*实弹概率*/ , Probability_of_empty_ammunition = 0.1 * data.Bullet_Quantity_Empty_Pack_Bullets/*空包弹概率*/ , Total_number_of_bullets = 0.1 * (data.Number_of_bullets_Live_ammunition + data.Bullet_Quantity_Empty_Pack_Bullets)/*总概率*/;
        Probability_of_live_ammunition = 100 * (Probability_of_live_ammunition / Total_number_of_bullets);
        Probability_of_empty_ammunition = 100 * (Probability_of_empty_ammunition / Total_number_of_bullets);
        std::cout<<"实弹概率："<<Probability_of_live_ammunition<<"%"<<std::endl;
        std::cout<<"空包弹概率："<<Probability_of_empty_ammunition<<"%"<<std::endl;
        return 0;
    }
    std::pair<int, int> Input_output_processing(){//输入信息
        int A, B;
        while (true)
        {
            std::cout<<"请输入空包弹数量："<<std::endl;
            std::cin>> A;
            std::cout<<"请输入实弹数量："<<std::endl;
            std::cin>> B;
            if (A == 10)
            {
                std::cout<<"认真的？"<<std::endl;
            }
            if (A + B <= 10)
            {
                return std::make_pair(A, B);
            }
        std::cout<<"数据太离谱，重新来过！"<<std::endl;
        }
    }
    int Calculation_of_bullet_quantity(int BO){//弹药数量计算
        if (BO == 1) {
            if (data.Number_of_bullets_Live_ammunition == 0) {
                return -1;
            }
            data.Number_of_bullets_Live_ammunition--;
            std::cout<<"实弹数量减少"<<std::endl;
        } else if(BO == 2) {
            if (data.Bullet_Quantity_Empty_Pack_Bullets == 0) {
                return -1;
            }
            data.Bullet_Quantity_Empty_Pack_Bullets--;
            std::cout<<"空包弹数量减少"<<std::endl;
        }else if (BO == 3){
            return -1;
        }
        Prophecy_notification_queue.push(1);
        return 0;
    }

    int Converter_conversion_compatibility(){//转换弹药模式
        std::cout<<"转换弹药模式'3'退出"<<std::endl;
        int bo;
        std::cin>> bo;
        if (bo == 1)
        {
            Calculation_of_bullet_quantity(2);
            return 0;
        }else if (bo == 2){
            Calculation_of_bullet_quantity(1);
            return 0;
        }else if (bo == 3){
            return -1;
        }
        return 0;
    }
    int Mobile_prophecy_record(){//手机预言记录模式
        int position;
        bool type;
        while (true)
        {
            system("cls");
            std::cout<<"手机预言记录模式"<<std::endl;
            std::cout<<"请输入子弹位置'第多少发'"<<std::endl;
            std::cin>> position;
            Mobile.position = position;
            if (position > data.Number_of_bullets_Live_ammunition + data.Bullet_Quantity_Empty_Pack_Bullets)
            {
                std::cout<<"位置超出范围"<<std::endl;
                std::cout<<"你输入的比全部子弹还要多,重新来过！"<<std::endl;
            } else {
                break;
            }
        }
        std::cout<<"请输入子弹类型1为'实弹'或者2为'空包弹'输入'4'退出"<<std::endl;
        std::cin>> position;
        if (position == 1)
        {
            Mobile.type = true;
        }else if (position == 2){
            Mobile.type = false;
        }else if (position == 4){
            return -1;
        }
        std::cout<<"手机预言记录成功"<<std::endl;
        return 0;
    }

    void count_down(){//手机预言计时器
        while (true)
        {
            if (Prophecy_notification_queue.size() >= 1)
            {
                Prophecy_notification_queue.pop();
                Mobile.position--;
                if (Mobile.position == 0)
                {
                    Mobile.Status_reminder = false;
                    break;
                }
            }
        }
    }
    int Start_and_initialization(){//开始和初始化
        if (first_run)
        {
            first_run = false;
            std::cout<<"欢迎使用弹药计算器"<<std::endl;
            std::cout<<"请输入'1'或者'2'表示'实弹'和'空包弹'此消息不再提醒"<<std::endl;
            std::cout<<"回车以继续"<<std::endl;
            system("pause");
        }
        //system("cls");
        std::pair<int,int> Player_input = Input_output_processing();//初始化
        data.Bullet_Quantity_Empty_Pack_Bullets = Player_input.first;
        data.Number_of_bullets_Live_ammunition = Player_input.second;
        return 0;
    }
};

int main(){//主函数
    main_module mod;
    int input;
    mod.Start_and_initialization();//开始和初始化
    while (true)
    {
        //system("cls");
        mod.Probability_calculation();
        if (mod.Mobile.Status_reminder)//true为提醒
        {
            if (mod.Mobile.type)
            {
                std::cout<<"手机预言提醒这一发为实弹"<<std::endl;
            } else {
                std::cout<<"手机预言提醒这一发为空包弹"<<std::endl;
            }
        }
        std::cout<<"请输入'1'或者'2'输入'3'转换下一发子弹"<<std::endl<<"输入'4'进入手机预言模式"<<std::endl;
        std::cin>> input;
        if (input == 1 || input == 2)
        {
            mod.Calculation_of_bullet_quantity(input);
        }else if (input == 3){
            mod.Converter_conversion_compatibility();
        }else if (input == 4){
            mod.Mobile_prophecy_record();
            std::thread t1(&main_module::count_down,&mod);
            t1.detach();
        }
        if (mod.data.Number_of_bullets_Live_ammunition == 0 && mod.data.Bullet_Quantity_Empty_Pack_Bullets == 0)
        {
            std::cout<<"弹药用完"<<std::endl;
            mod.Start_and_initialization();
        }
        std::cout<<"实弹数量为："<<mod.data.Number_of_bullets_Live_ammunition<<"空包弹数量为："<<mod.data.Bullet_Quantity_Empty_Pack_Bullets<<std::endl;
    }
    return 0;
}