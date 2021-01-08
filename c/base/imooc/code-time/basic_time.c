//
// Created by miclefengzss on 2021/1/7.
//

#include <io_utils.h>
#include <time.h>
#include <time_utils.h>
#include <sys/timeb.h>

#if defined(__unix__) || defined(__APPLE__)
#  include <sys/time.h>
#endif

int main() {

  clock_t; // 进程所消耗CPU的时间
  struct tm time_value;

#if defined(__unix__) || defined(__APPLE__)
  struct timeval timeval_value;
  gettimeofday(&timeval_value, NULL);
  PRINT_LONG(timeval_value.tv_sec * 1000000L + timeval_value.tv_usec);
#endif

  time_t current_time; // 时间戳
  time(&current_time);
  PRINT_LONG(current_time);

  current_time = time(NULL);
  PRINT_LONG(current_time);

  struct timespec timespec_value; // C11; MSVC
  timespec_get(&timespec_value, TIME_UTC);
  PRINT_LONG(timespec_value.tv_sec * 1000000000L + timespec_value.tv_nsec);
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  timespec_get(&timespec_value, TIME_UTC);
  PRINT_LONG(timespec_value.tv_sec * 1000000000L + timespec_value.tv_nsec);
  PRINT_LONG(timespec_value.tv_sec);
  PRINT_LONG(timespec_value.tv_nsec);

  struct timeb timeb_value;
  ftime(&timeb_value);
  PRINT_LONG(timeb_value.time * 1000L + timeb_value.millitm);
  return 0;
}