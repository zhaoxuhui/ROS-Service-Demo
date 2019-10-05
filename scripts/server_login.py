# coding=utf-8
# 注意service模块的加载方式，from 包名.srv import *
# 其中srv指的是在包根目录下的srv文件夹，也即srv模块
import rospy
from login.srv import *


def handle_function(req):
    # 回调函数传入的是user类型的请求，它的返回值直接就是userResponse类型的结果
    rospy.loginfo("Request from %s with password %s",
                  req.username, req.password)
    if req.username == "xuhui" and req.password == "123456":
        return userResponse("\nLogin success!\nWelcome my master "+req.username+":)")
    else:
        return userResponse("\nLogin fail!\nYou are not my master. -_-")


def server_login():
    # 初始化节点
    rospy.init_node("server_login")
    # 构造服务，指定服务名称，消息类型以及回调函数
    ser = rospy.Service("login_info", user, handle_function)
    rospy.loginfo("Ready to handle the request:")
    # 循环执行
    rospy.spin()


if __name__ == "__main__":
    server_login()
