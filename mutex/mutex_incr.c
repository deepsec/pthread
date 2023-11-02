#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "error.h"

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *threadFunc(void *arg)
{
    int loops = *(int *)arg;
    int loc, j, s;

    for (j = 0; j < loops; j++) {
        s = pthread_mutex_lock(&mtx);
        if (s != 0) {
            pth_err_exit(s, "pthread_mutex_lock() error");
        }
        loc = glob;
        loc++;
        glob = loc;
        s = pthread_mutex_unlock(&mtx);
        if (s != 0) {
            pth_err_exit(s, "pthread_mutex_unlock() error");
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t   t1, t2;
    int loops, s;

    if (argc != 2) {
        err_quit("USAGE: %s loops", argv[0]);
    }
    loops = strtod(argv[1], NULL);

    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if (s != 0) {
        pth_err_exit(s, "pthread_create() error");
    }
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if (s != 0) {
        pth_err_exit(s, "pthread_create() error");
    }

    s = pthread_join(t1, NULL);
    if (s != 0) {
        pth_err_exit(s, "pthread_join() error");
    }
    s = pthread_join(t2, NULL);
    if (s != 0) {
        pth_err_exit(s, "pthread_join() error");
    }

    printf("glob = %d\n", glob);
    return 0;
}