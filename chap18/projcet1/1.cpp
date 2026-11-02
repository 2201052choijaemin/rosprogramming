#include "rclcpp/rclcpp.hpp"       // ROS 2 C++ 클라이언트 라이브러리
#include "std_msgs/msg/int32.hpp" // Int32 메시지 타입을 사용하기 위한 헤더
#include <memory>                 // shared_ptr 사용을 위한 헤더
#include <chrono>                 // 시간 관련 기능을 위한 헤더

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv); 
    // ROS 2 통신을 초기화하는 함수

    auto node = std::make_shared<rclcpp::Node>("node_pub1_1");
    // "node_pub1_1"이라는 이름의 ROS 2 노드 생성
    // make_shared를 사용하여 노드 객체를 동적으로 생성하고 공유 포인터로 관리

    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    // QoS(Quality of Service) 설정
    // KeepLast(10): 최근 메시지 10개까지 저장할 수 있도록 설정

    auto mypub = node->create_publisher<std_msgs::msg::Int32>(
        "topic_pub1_1", qos_profile);
    // "topic_pub1_1"이라는 토픽에 메시지를 발행하는 Publisher 생성
    // 메시지 자료형은 std_msgs::msg::Int32 사용
    // 위에서 설정한 QoS 프로파일 적용

    std_msgs::msg::Int32 message;
    // Int32 자료형의 메시지 객체 생성

    message.data = 0;
    // 메시지의 초기 데이터 값을 0으로 설정

    rclcpp::WallRate loop_rate(1.0);
    // 반복 주기를 설정하는 객체 생성
    // 1.0Hz = 1초에 한 번 반복

    while(rclcpp::ok())
    // ROS 2가 정상적으로 실행 중인 동안 반복
    {
        RCLCPP_INFO(node->get_logger(), "Publish: %d", message.data);
        // 터미널에 현재 발행할 메시지 값 출력
        // %d는 정수형 데이터를 출력하기 위한 형식 지정자

        mypub->publish(message);
        // Publisher를 통해 message를 토픽으로 발행

        ++message.data;
        // 메시지 데이터 값을 1 증가
        // 다음 반복에서는 증가된 값이 발행됨

        //rclcpp::spin_some(node);
        // 노드에서 대기 중인 콜백을 가능한 만큼 실행
        // 현재 코드는 Subscriber나 Timer 콜백이 없으므로 주석 처리

        loop_rate.sleep();
        // 설정한 반복 주기(1초)를 유지하기 위해 남은 시간만큼 대기
    }

    rclcpp::shutdown();
    // ROS 2 통신 종료 및 자원 정리

    return 0;
    // 프로그램 정상 종료
}
