turtlesim_node 를 실행하고 새로운 창에서 아래 명령을 실행하고 강 의 노트의 rosbag을 제외한 모든 명령어를 실습하고 결과를 캡쳐하 여 제출하라
명령과 출력 결과가 일치하는지 설명하라.
$ ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"

<img width="501" height="521" alt="image" src="https://github.com/user-attachments/assets/e7fde86a-31a9-4af2-938d-f71d69bd6881" />

/turtle1/cmd_vel 토픽에 geometry_msgs/msg/Twist 메세지를 1초에 한번씩 발행하는 명령
