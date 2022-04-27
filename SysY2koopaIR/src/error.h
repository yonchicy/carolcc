//
// Created by yonchicy on 2022/3/16.
//

#ifndef EASYCC_ERROR_H
#define EASYCC_ERROR_H




#define __DEBUG 
#define __WARN
#define __TRACE
#define __INFO

#ifdef __DEBUG
#define ERROR(format, ...) \
        printf("\x1b[32m" format "\x1b[0m",##__VA_ARGS__); 
#else 
#define ERROR(format, ...) 
#endif

#ifdef __WARN
#define WARNNING(format, ...) \
            printf("\x1b[93m" format "\x1b[0m",##__VA_ARGS__); 
#else 
#define WARNNING(format, ...) 
#endif


#ifdef __INFO
#define INFO(format, ...) \
            printf("\x1b[34m" format "\x1b[0m",##__VA_ARGS__); 
#else 
#define INFO(format, ...) 
#endif

#ifdef __TRACE
#define TRACE(format, ...) \
            printf("\x1b[90m" format "\x1b[0m",##__VA_ARGS__); 
#else 
#define TRACE(format, ...) 
#endif

#endif // EASYCC_ERROR_H
