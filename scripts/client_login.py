# coding=utf-8
import rospy
from login.srv import *


def client_login():
    # 初始化节点，指定名称
    rospy.init_node("client_login")
    # 等待指定的可用服务(阻塞)
    rospy.wait_for_service("login_info")

    # 输入信息
    name = raw_input("Input username:\n")
    passwd = raw_input("Input password:\n")

    try:
        # 构造客户端，指定服务端名称和传输的消息类型
        client = rospy.ServiceProxy("login_info", user)
        # 客户端发送消息，并返回结果
        resp = client.call(name, passwd)
        rospy.loginfo("%s", resp.state)
    except rospy.ServiceException, e:
        rospy.logwarn("Service call failed:%s" % e)


if __name__ == "__main__":
    client_login()
