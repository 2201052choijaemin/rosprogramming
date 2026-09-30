1. CMake와 GNU Make의 차이점

CMake는 CMakeLists.txt를 바탕으로 Makefile 같은 빌드 파일을 생성하는 도구이고, GNU Make는 생성된 Makefile을 이용해 실제 컴파일과 링크를 수행하는 빌드 도구이다.

2. CMakeLists.txt의 역할

프로젝트의 이름, 소스 파일, 실행 파일, 라이브러리 등 빌드에 필요한 설정을 작성하는 파일이다. CMake는 이 파일을 읽어 빌드 환경을 구성한다.

3. CMakeCache.txt의 역할

CMake의 configure 과정에서 설정된 컴파일러, 경로, 빌드 옵션 등의 정보를 저장하는 캐시 파일이다.

4. Configure → Generate → Build 단계

Configure: CMakeLists.txt를 읽고 컴파일러와 빌드 설정을 확인한다. → CMakeCache.txt 생성

Generate: 설정된 내용을 바탕으로 Makefile 등의 빌드 파일을 생성한다.

Build: 생성된 Makefile을 이용해 소스 코드를 컴파일하고 실행 파일을 생성한다.

5. make를 이용한 빌드

Generate 단계가 끝나면 hello/build/Makefile이 생성된다. 이후 다음과 같이 실행한다.

cd hello/build
make


make 명령은 생성된 Makefile을 읽어 프로그램을 빌드한다. 따라서 cmake --build build 대신 make를 사용하여 빌드할 수 있다.
