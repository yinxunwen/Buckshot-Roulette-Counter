#include <iostream>
#include <thread>

class main_module {
private:
    bool first_run = true;
public:

    struct data{//数据储存
        int Bullet_Quantity_Empty_Pack_Bullets;
        int Number_of_bullets_Live_ammunition;
    }data;
    struct Mobile
    {
        int position;
        bool type;//true为实弹，false为空包弹
    }Mobile;
    

    void Probability_calculation(){//计算概率
        int A = data.Number_of_bullets_Live_ammunition;
        int B = data.Bullet_Quantity_Empty_Pack_Bullets;
        std::cout<<"当前实弹概率为："<< A * 10 << "%" <<std::endl;
        std::cout<<"当前空包弹概率为："<< B * 10 << "%" <<std::endl;
    }
    std::pair<int, int> Input_output_processing(){//输入信息
        int A, B;
        while (true)
        {
            std::cout<<"请输入空包弹数量："<<std::endl;
            std::cin>> A;
            std::cout<<"请输入实弹数量："<<std::endl;
            std::cin>> B;
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
    for (int A = Mobile.position - 1;;)
    {
        if (Mobile.position == 0)
        {
            if (Mobile.type)
            {
                std::cout<<"手机预言提醒这一发为实弹"<<std::endl;
            } else {
                std::cout<<"手机预言提醒这一发为空包弹"<<std::endl;
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
            std::cout<<"手机预言尚未完成，不要使用，概率计算存在问题，不要相信"<<std::endl;
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
        //mod.Probability_calculation();
        std::cout<<"请输入'1'或者'2'输入'3'转换下一发子弹"<<std::endl;/*<<"输入'4'进入手机预言模式"<<std::endl*/;
        std::cin>> input;
        if (input == 1 || input == 2)
        {
            mod.Calculation_of_bullet_quantity(input);
        }else if (input == 3){
            mod.Converter_conversion_compatibility();
        /*}else if (input == 4){
            mod.Mobile_prophecy_record();
            std::thread t1(&main_module::count_down,&mod);
            t1.detach();*/
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