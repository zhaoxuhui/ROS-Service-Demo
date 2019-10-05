# include<ros/ros.h>
# include<login/user.h>


int main(int argc, char *argv[])
{
    // 初始化节点并指定节点名称
    ros::init(argc, argv, "client_login");
    // 创建句柄
    ros::NodeHandle nh;
    // 创建客户端并指定其发送的服务端名称
    ros::ServiceClient client = nh.serviceClient<login::user>("login_info");
    
    // 获取信息
    std::string name;
    std::string passwd;
    std::cout<<"Input username:"<<std::endl;
    std::cin>>name;
    std::cout<<"Input password:"<<std::endl;
    std::cin>>passwd;

    // 新建一个消息，传入内容
    login::user info;
    info.request.username = name;
    info.request.password = passwd;
    // 注意这里call函数返回的就是在服务端定义的回调函数的返回值(true or false)
    if (client.call(info))
    {
        ROS_INFO("%s",info.response.state.c_str());
    }else{
        ROS_ERROR("Failed to call service");
    }
    return 0;
}