# MINITALK

프로세스끼리 통신을 해야함.. 

signal
sigemptyset
sigaddset
sigaction
kill
getpid
함수를 공부하자.

공부 시작 전 미니톡에 대한 상상도..

- 서버
main()
{
	pid = getpid();
	print self pid..
	send value to client pid..

}

- 클라이언트
main (argv)
{
	int server_pid = argv[1];
	kill(server_pid, sig..);
	문자열은 어떻게 보내지..?
}

일단은 구현할게 이정도밖에 없어보임 
클라이언트는 서버의 pid를 받아서 문자열을 보내야함 
kill 함수로 신호를 보낼 수 있음.. 문자열은 어떻게 보내야할까

https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%8B%9C%EA%B7%B8%EB%84%90-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-sigaction
