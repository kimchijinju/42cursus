# pipex

### 파이프엑스란 무슨 과제인가?
파이프 통신은 부모 자식 프로세스간의 통신만 가능하다.. 


- pipe(int[2])
	인자로 넣은 int 배열에 두 개의 파일디스크럽터를 할당한다.(데이터스트림 두 개를 생성한다)
	정상적으로 종료 되었다면 0을 반환한다. 실패시 -1

- dup(int fd)
	새로운 파일디스크립터를 할당한다. 데이터스트림은 공유되지만, 파일디스크립터 값은 open의 반환값과같게 되는것 같다..

- dup2(int fd1, int fd2)
	fd2가 가리키는 데이터스트림을 fd1로 옮긴다.

- unlink(char *pathname)
	파일의 연결 계수를 1 줄인다. 연결 계수가 0이면 파이를 삭제한다.

- waitpid(pid_t pid, int *statloc, int options)
	성공시 프로세스 아이디, 실패시 -1 반환한다. 특정한 자식 프로세스만 기다리게 할 수 있다.

- access(char *path, int mode)
	파일의 권한을 체크한다.

- strerror(int errno)
	errno 값에 대한 오류 메세지를 반환한다.

- perror(char *str)
	인자 문자열과 " : " 에 에러 메세지를 붙여서 STDERR 출력 

파이프엑스 시작하기 전 상상도...

