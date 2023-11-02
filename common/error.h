#ifndef __ERROR_H__
#define __ERROR_H__

void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_exit(int error, const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

void pth_err_exit(int error, const char *fmt, ...);
void pth_err_msg(const char *fmt, ...);
void pth_err_quit(const char *fmt, ...);

#define ERR_RET(fmt, args...)		err_ret("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define ERR_SYS(fmt, args...)		err_sys("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define ERR_EXIT(error, fmt, args...)	err_exit(error, "*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define ERR_DUMP(fmt, args...)		err_dump("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define ERR_MSG(fmt, args...)		err_msg("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define ERR_QUIT(fmt, args...)		err_quit("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)

#define PTH_ERR_EXIT(error, fmt, args...)	pth_err_exit(error, "*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define PTH_ERR_MSG(fmt, args...)		pth_err_msg("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)
#define PTH_ERR_QUIT(fmt, args...)		pth_err_quit("*ERR* %s[%d]: " fmt, __FILE__, __LINE__, ## args)

#ifdef __DEEPDBG__
#define DBG(fmt, args...)		err_msg("*DBG* %s[%d] -> " fmt, __FILE__, __LINE__, ## args)
#define PTH_DBG(fmt, args...)		pth_err_msg("*PTH_DBG* %s[%d] -> " fmt, __FILE__, __LINE__, ## args)
#else
#define DBG(fmt, args...)
#define PTH_DBG(fmt, args...)
#endif

#endif
