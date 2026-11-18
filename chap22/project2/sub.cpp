#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include "opencv2/opencv.hpp"
#include <memory>
#include <functional>
#include <iostream>

cv::VideoWriter writer;

void mysub_callback(rclcpp::Node::SharedPtr node, const
sensor_msgs::msg::CompressedImage::SharedPtr msg)
{
   cv::Mat frame = cv::imdecode(cv::Mat(msg->data), cv::IMREAD_COLOR);

    if (frame.empty()) {
        RCLCPP_ERROR(node->get_logger(), "Empty frame!");
        return;
    }
    if (!writer.isOpened())
        writer.open("output.mp4", cv::VideoWriter::fourcc('m','p','4','v'), 30.0, cv::Size(frame.cols, frame.rows));
    cv::imshow("Original", frame);
    cv::waitKey(1);
    writer.write(frame);
    RCLCPP_INFO(node->get_logger(),"Received Image : %s, %d, %d",msg->format.c_str(), frame.rows, frame.cols);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("imagesub");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)); //TCP //auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort(); 
    //UDP
    std::function<void(const sensor_msgs::msg::CompressedImage::SharedPtr msg)> fn;
    fn = std::bind(mysub_callback, node, std::placeholders::_1);
    auto mysub = node->create_subscription<sensor_msgs::msg::CompressedImage>(
    "image/compressed", qos_profile, fn);
    rclcpp::spin(node); 
    rclcpp::shutdown(); 
    return 0;
}
