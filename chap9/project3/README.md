1. 패키지를 구성하는 가장 중요한 필수 파일 2가지
ROS 2의 ament_cmake 기반 패키지를 구성할 때 가장 중요한 파일은 다음 두 가지이다.

package.xml

패키지의 이름, 버전, 설명, 제작자, 라이선스 및 의존성 등의 정보를 저장한다.

ROS 2가 해당 패키지의 기본 정보를 파악하는 데 사용된다.

CMakeLists.txt

패키지를 빌드하는 방법을 정의하는 파일이다.

소스 파일, 라이브러리, 실행 파일 등을 어떻게 빌드하고 설치할지 설정한다.

ament_cmake를 사용하는 ROS 2 패키지에서는 find_package(ament_cmake REQUIRED) 등을 이용하여 빌드 환경을 설정한다.

따라서 package.xml은 패키지의 정보와 의존성을 정의하고, CMakeLists.txt는 패키지를 빌드하는 방법을 정의한다.

2. XML 파일 형식
XML(Extensible Markup Language)은 데이터를 저장하고 전달하기 위해 사용하는 마크업 언어이다.

XML은 <태그>를 사용하여 데이터의 구조와 의미를 표현한다. 사용자가 필요한 태그를 직접 정의할 수 있다는 특징이 있다.

예시는 다음과 같다.

<package>
    <name>my_package</name>
    <version>1.0.0</version>
    <description>ROS 2 package</description>
</package>

XML의 주요 특징은 다음과 같다.

사람이 읽고 이해하기 쉽다.

데이터의 구조를 표현하기 쉽다.

운영체제나 프로그램에 관계없이 사용할 수 있다.

태그를 이용하여 데이터의 의미를 표현할 수 있다.

ROS 2에서는 package.xml이 XML 형식으로 작성되며, 패키지의 이름이나 의존성 등의 정보를 저장하는 데 사용된다.

3. ament_cmake와 CMake의 차이
CMake
CMake는 프로그램을 빌드하기 위한 설정 및 빌드 시스템 생성 도구이다.
CMakeLists.txt 파일에 빌드에 필요한 설정을 작성하면 운영체제와 컴파일러에 맞는 빌드 환경을 구성할 수 있다.

즉, CMake는 일반적인 C/C++ 프로젝트에서 사용할 수 있는 범용 빌드 시스템이다.

ament_cmake
ament_cmake는 ROS 2에서 CMake를 사용하여 패키지를 쉽게 빌드할 수 있도록 만들어진 ROS 2용 빌드 시스템이다.

기본적으로 CMake를 사용하지만, ROS 2 패키지에 필요한 기능을 추가로 제공한다. 예를 들어 ROS 2 패키지의 의존성을 찾거나, 패키지를 빌드하고 설치하는 과정 등을 ROS 2 환경에 맞게 처리할 수 있다.

차이점 정리
구분	CMake	ament_cmake
목적	일반적인 소프트웨어 빌드	ROS 2 패키지 빌드
기반	CMake 자체	CMake 기반
사용 분야	C/C++ 등 다양한 프로젝트	ROS 2
ROS 2 기능	기본 제공하지 않음	ROS 2 패키지 및 의존성 관리 지원
주요 설정 파일	CMakeLists.txt	CMakeLists.txt + package.xml
