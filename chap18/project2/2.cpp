#include "rclcpp/rclcpp.hpp"             // ROS 2 C++ 클라이언트 라이브러리
#include "geometry_msgs/msg/vector3.hpp" // Vector3 메시지 타입을 사용하기 위한 헤더
#include <memory>                        // shared_ptr 사용을 위한 헤더
#include <iostream>                      // 키보드 입력(cin)과 화면 출력(cout)을 위한 헤더

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // ROS 2 통신 초기화

  auto node = std::make_shared<rclcpp::Node>("node_pub1_2");
  // "node_pub1_2"라는 이름의 ROS 2 노드 생성

  auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
  // QoS(Quality of Service) 설정
  // KeepLast(10): 최근 메시지 10개까지 저장하도록 설정

  auto mypub = node->create_publisher<geometry_msgs::msg::Vector3>(
    "topic_pub1_2", qos_profile);
  // "topic_pub1_2"라는 토픽에 메시지를 발행하는 Publisher 생성
  // 메시지 자료형은 geometry_msgs::msg::Vector3 사용
  // 설정한 QoS 프로파일 적용

  geometry_msgs::msg::Vector3 message;
  // Vector3 자료형의 메시지 객체 생성
  // x, y, z 세 가지 실수형 데이터를 저장할 수 있음

  while (rclcpp::ok())
  // ROS 2가 정상적으로 실행 중인 동안 반복
  {
    std::cout << "실수 3개를 입력하세요 (x y z): " << std::flush;
    // 사용자에게 x, y, z 세 개의 실수 입력 요청
    // flush는 출력 버퍼를 비워 입력 안내 문구가 바로 화면에 표시되도록 함

    if (!(std::cin >> message.x >> message.y >> message.z))
    // 키보드로 입력한 세 값을 각각 x, y, z에 저장
    // 입력에 실패하면 조건문 내부 실행
    {
      std::cout << "\n입력이 종료되었거나 잘못된 값이 입력되었습니다."
                << std::endl;
      // 입력이 종료되었거나 잘못된 값이 입력되었음을 화면에 출력
      break;
      // while 반복문 종료
    }

    if (!rclcpp::ok())
    {
      break;
      // ROS 2가 종료된 상태라면 반복문 종료
    }

    RCLCPP_INFO(
      node->get_logger(),
      "Publish: x = %.3f, y = %.3f, z = %.3f",
      message.x, message.y, message.z);
    // 입력한 x, y, z 값을 터미널에 출력
    // %.3f는 실수를 소수점 셋째 자리까지 출력하는 형식 지정자

    mypub->publish(message);
    // 입력받은 x, y, z 데이터를 Vector3 메시지로 토픽에 발행
  }

  rclcpp::shutdown();
  // ROS 2 통신 종료 및 자원 정리

  return 0;
  // 프로그램 정상 종료
}
