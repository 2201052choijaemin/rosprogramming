#include "rclcpp/rclcpp.hpp"          // ROS 2 C++ 클라이언트 라이브러리
#include "geometry_msgs/msg/twist.hpp" // Twist 메시지 타입을 사용하기 위한 헤더
#include <memory>                     // shared_ptr 사용을 위한 헤더
#include <iostream>                   // 키보드 입력(cin) 및 화면 출력(cout)을 위한 헤더

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // ROS 2 통신 초기화

  auto node = std::make_shared<rclcpp::Node>("node_pub1_3");
  // "node_pub1_3"이라는 이름의 ROS 2 노드 생성

  auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
  // QoS(Quality of Service) 설정
  // KeepLast(10): 최근 메시지 10개까지 저장하도록 설정

  auto mypub = node->create_publisher<geometry_msgs::msg::Twist>(
    "/turtle1/cmd_vel", qos_profile);
  // "/turtle1/cmd_vel" 토픽에 메시지를 발행하는 Publisher 생성
  // 메시지 자료형은 geometry_msgs::msg::Twist 사용
  // turtlesim의 거북이 이동 및 회전 속도를 제어하는 토픽

  char key;
  // 사용자가 입력하는 키보드 문자를 저장할 변수 선언

  while (rclcpp::ok())
  // ROS 2가 정상적으로 실행 중인 동안 반복
  {
    std::cout
      << "명령 입력 (f: 전진, b: 후진, l: 좌회전, r: 우회전, q: 종료): "
      << std::flush;
    // 사용자에게 이동 명령 입력 요청
    // flush를 사용하여 안내 문구가 즉시 화면에 표시되도록 함

    if (!(std::cin >> key))
    // 키보드 입력에 실패하면 조건문 실행
    {
      break;
      // while 반복문 종료
    }

    if (!rclcpp::ok())
    {
      break;
      // ROS 2가 종료된 상태라면 반복문 종료
    }

    if (key == 'q')
    {
      break;
      // q를 입력하면 프로그램 반복문 종료
    }

    geometry_msgs::msg::Twist message;
    // Twist 자료형의 메시지 객체 생성
    // 선속도(linear)와 각속도(angular)를 저장할 수 있음
    // 기본적으로 모든 속도 값은 0으로 초기화됨

    switch (key)
    // 사용자가 입력한 키에 따라 실행할 명령 선택
    {
      case 'f':
        message.linear.x = 2.0;
        // f 입력 시 x축 방향 선속도를 2.0으로 설정
        // 거북이가 전진하도록 설정
        break;

      case 'b':
        message.linear.x = -2.0;
        // b 입력 시 x축 방향 선속도를 -2.0으로 설정
        // 거북이가 후진하도록 설정
        break;

      case 'l':
        message.angular.z = 2.0;
        // l 입력 시 z축 방향 각속도를 2.0으로 설정
        // 거북이가 좌회전하도록 설정
        break;

      case 'r':
        message.angular.z = -2.0;
        // r 입력 시 z축 방향 각속도를 -2.0으로 설정
        // 거북이가 우회전하도록 설정
        break;

      default:
        std::cout << "f, b, l, r 중 하나를 입력하세요." << std::endl;
        // f, b, l, r 이외의 문자를 입력하면 오류 안내 출력

        continue;
        // 현재 반복을 건너뛰고 while문의 처음으로 돌아감
    }

    mypub->publish(message);
    // 설정된 선속도와 각속도 메시지를 토픽으로 발행
    // turtlesim은 이 메시지를 받아 거북이 이동을 수행

    RCLCPP_INFO(
      node->get_logger(),
      "Publish: linear.x = %.2f, angular.z = %.2f",
      message.linear.x,
      message.angular.z);
    // 발행한 선속도(linear.x)와 각속도(angular.z)를 터미널에 출력
    // %.2f는 실수를 소수점 둘째 자리까지 출력하는 형식 지정자
  }

  rclcpp::shutdown();
  // ROS 2 통신 종료 및 자원 정리

  return 0;
  // 프로그램 정상 종료
}
