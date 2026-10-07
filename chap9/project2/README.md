사용자 홈디렉터리 아래에 작업폴더 ros2_ws를 생성하고 강의노트의 패키지 생성 및 빌드 명령어를 실습하고 결과를 제출하시오.
<img width="1103" height="569" alt="image" src="https://github.com/user-attachments/assets/5736dc13-868a-46a9-b2df-34f4d14a9eb7" />

<img width="523" height="126" alt="image" src="https://github.com/user-attachments/assets/75fafa07-3aab-4f38-9171-7497e8696244" />

<img width="936" height="500" alt="image" src="https://github.com/user-attachments/assets/97967411-5de8-4e53-a24a-ecaf33e5add1" />

<img width="1092" height="432" alt="image" src="https://github.com/user-attachments/assets/2393b79a-8257-4fa1-a6f4-09bea225adf4" />

<img width="902" height="121" alt="image" src="https://github.com/user-attachments/assets/dd794da1-330a-4102-bc7a-72fb79eccd8f" />

<img width="393" height="151" alt="image" src="https://github.com/user-attachments/assets/794629e7-25e5-49f2-b86d-66bbd0083265" />

자동으로 생성되는 파일과 디렉터리를 출력하고 각각 설명하시오.

ros2_ws/
├── build/
├── install/
├── log/
└── src/
    └── first_pkg/
        ├── CMakeLists.txt
        ├── include/
        ├── package.xml
        └── src/

build/: 빌드 과정에서 생성되는 파일 저장

install/: 빌드된 패키지 설치 파일 저장

log/: 빌드 과정의 로그 저장

src/: ROS 2 패키지가 저장되는 디렉터리

first_pkg/: 생성한 패키지 디렉터리

CMakeLists.txt: 패키지 빌드 설정 파일

package.xml: 패키지 정보 및 의존성 관리 파일

include/: 헤더 파일 저장 디렉터리

src/: 소스 코드 저장 디렉터리
