//
// Created by Administrator on 2021-06-28.
//

#ifndef NDK_LOG_H
#define NDK_LOG_H
#include <android/log.h>
using namespace std;
#define NDK_LOG true
#define TAG "Sak-NDK-LOG" // 这个是自定义的LOG的标识
#if NDK_LOG
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)
#else
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#define LOGF(...)
#endif

#endif //NDK_LOG_H
