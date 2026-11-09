#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <memory>
#include <iostream>

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node_pub2_3");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    auto mypub = node->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel", qos_profile);
    char key;
    while (rclcpp::ok())
    {
        std::cin >> key;
        if (key == 'q') break;
        geometry_msgs::msg::Twist message;
        if (key == 'f') message.linear.x = 2.0;
        else if (key == 'b') message.linear.x = -2.0;
        else if (key == 'l') message.angular.z = 2.0;
        else if (key == 'r') message.angular.z = -2.0;
        else{
            std::cout << "f, b, l, r 중 하나를 입력하세요." << std::endl;
            continue;
        }
        mypub->publish(message);
        RCLCPP_INFO(node->get_logger(), "Publish: linear.x = %.2f, angular.z = %.2f", message.linear.x, message.angular.z);
    }
    rclcpp::shutdown();
    return 0;
}
