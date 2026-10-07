1. 빌드 시스템과 빌드 툴의 차이를 설명하라.

빌드 시스템: 프로그램을 빌드하는 방법과 과정을 관리한다. (예: CMake)
빌드 툴: 실제 빌드를 실행한다. (예: colcon)

2. 패키지 생성 명령어를 실행하는 위치는 어디이고 그곳으로 이동하 는 명령어를 쓰시오.

위치: ~/ros2_ws/src

이동 명령어: cd ~/ros2_ws/src

3. 패키지 생성 명령어의 사용법을 설명하라.

ros2 pkg create <패키지이름>

4. 패키지 빌드 명령어를 실행하는 위치는 어디이고 그곳으로 이동하 는 명령어를 쓰시오

cd ~/ros2_ws

5. 패키지 빌드 명령어의 사용법을 설명하라.

colcon build --symlink-install --packages-select <pkgname>

colcon build : 패키지를 빌드한다.

--symlink-install : 파일을 복사하지 않고 심볼릭 링크로 설치하여 수정 사항을 빠르게 반영한다.

--packages-select <패키지이름> : 지정한 패키지만 빌드한다.
