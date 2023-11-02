#include <pthread.h>
#include "error.h"

int main(int argc, char *argv[])
{
	pthread_mutex_t mtx;
	pthread_mutexattr_t mtxAttr;
	int s;

	s = pthread_mutexattr_init(&mtxAttr);
	if (s != 0)
	{
		pth_err_exit(s, "pthread_mutexattr_init error");
	}
	PTH_DBG("HELLO, world");
	s = pthread_mutexattr_settype(&mtxAttr, PTHREAD_MUTEX_ERRORCHECK);
	if (s != 0)
	{
		pth_err_exit(s, "pthread_mutexattr_settype error");
	}
	s = pthread_mutex_init(&mtx, &mtxAttr);
	if (s != 0)
	{
		pth_err_exit(s, "pthread_mutex_init error");
	}

	s = pthread_mutexattr_destroy(&mtxAttr);
	if (s != 0)
	{
		pth_err_exit(s, "pthread_mutexattr_destroy error");
	}

	PTH_DBG("GoodBye world");

	return 0;
}
