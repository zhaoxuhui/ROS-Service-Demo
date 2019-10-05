# include<ros/ros.h>
# include<login/user.h>

// 用于处理的回调函数，回调函数需要引用形式传入Request和Response，Response为返回数据
bool handle_function(login::user::Request &req,login::user::Response &res){
    ROS_INFO("Request from %s with password %s",req.username.c_str(),req.password.c_str());
    // 构建正确的登录信息
    std::string name = "xuhui";
    std::string passwd = "123456";
    if(name == req.username and passwd == req.password){
        res.state = "\nLogin success!\nWelcome my master " + req.username + ":)";
    }else{
        res.state = "\nLogin fail!\nYou are not my master. -_-";
    }
    return true;
}


int main(int argc, char *argv[])
{
    // 初始化节点，指定节点名称
    ros::init(argc, argv, "server_login");
    // 创建节点句柄，用于控制节点
    ros::NodeHandle nh;
    // 创建服务端，并指定服务名称
    ros::ServiceServer service = nh.advertiseService("login_info",handle_function);
    // 循环执行
    ros::spin();
    return 0;
}