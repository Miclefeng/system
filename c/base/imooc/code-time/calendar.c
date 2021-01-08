#include <ntsid.h>
//
// Created by miclefengzss on 2021/1/7.
//
#define _XOPEN_SOURCE

#include <io_utils.h>
#include <time.h>
#include <time_utils.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1415926

void ParseTime(char const *time_string, struct tm *parse_time);

void DoHardWork() {
  double sum = 0;
  for (int i = 0; i < 10000000; ++i) {
    sum += i * i / PI;
  }
  PRINT_DOUBLE(sum);
}

int main() {
  time_t current_time;
  time(&current_time);
  PRINT_LONG(current_time);
  // 格式化日期
  struct tm *calendar_time = localtime(&current_time);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);
  PRINTLNF("==================================");
//  calendar_time->tm_sec = 70;
  // 日历格式转换为时间戳, 完成转换
  current_time = mktime(calendar_time);
  PRINT_LONG(current_time);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);
  PRINTLNF("==================================");

  puts(asctime(calendar_time));
  puts(ctime(&current_time));

  char current_time_s[20] = {0};
  size_t size = strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
  PRINT_LONG(size);
  puts(current_time_s);
  strftime(current_time_s, 20, "%F %T", calendar_time);
  puts(current_time_s);
  PRINTLNF("==================================");

// 解析时间  需要定义 _XOPEN_SOURCE 宏
  char *times = "2021-01-08 19:24:31.456";
  struct tm parse_time;
  char *unparsed_string = strptime(times, "%F %T", &parse_time);
  PRINT_INT(parse_time.tm_year);
  PRINT_INT(parse_time.tm_mon);
  PRINT_INT(parse_time.tm_mday);
  PRINT_INT(parse_time.tm_hour);
  PRINT_INT(parse_time.tm_min);
  PRINT_INT(parse_time.tm_sec);
  puts(unparsed_string);
  int millisecond;
  sscanf(unparsed_string, ".%3d", &millisecond);
  char *end;
  const long kI = strtol(unparsed_string + 1, &end, 10);
  PRINT_LONG(kI);
  PRINT_INT(millisecond);
  PRINTLNF("==================================");

  long_time_t current_time_in_millisecond = TimeInMillisecond();
  int current_time_millisecond = current_time_in_millisecond % 1000;
  strftime(current_time_s, 20, "%Y%m%d%H%M%S", calendar_time);
  sprintf(current_time_s + 14, "%03d", current_time_millisecond);
  puts(current_time_s);
  PRINTLNF("==================================");

  ParseTime("2021-01-08 19:46:22", &parse_time);
  PRINT_INT(parse_time.tm_year);
  PRINT_INT(parse_time.tm_mon);
  PRINT_INT(parse_time.tm_mday);
  PRINT_INT(parse_time.tm_hour);
  PRINT_INT(parse_time.tm_min);
  PRINT_INT(parse_time.tm_sec);

  PRINTLNF("==================================");

//  clock(); // 返回处理器消耗的时间，更能反映程序运行时的耗时
//  time(NULL); // 返回的是系统时间，更能描述真实世界的时间变化
  long long start_time_ms = TimeInMillisecond();
  clock_t start_time_c = clock();
  DoHardWork();
  clock_t end_time_c = clock();
  long long end_time_ms = TimeInMillisecond();
  PRINT_LLONG(end_time_ms - start_time_ms);
  PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);
  return 0;
}

void ParseTime(char const *time_string, struct tm *parse_time) {
  sscanf(time_string, "%4d-%2d-%2d %2d:%2d:%2d",
         &parse_time->tm_year,
         &parse_time->tm_mon,
         &parse_time->tm_mday,
         &parse_time->tm_hour,
         &parse_time->tm_min,
         &parse_time->tm_sec
  );
  parse_time->tm_year -= 1900;
  parse_time->tm_mon -= 1;
  mktime(parse_time);
}

__unused void ParseTime2(char const *time_string, struct tm *parse_time) {
  char const *start = time_string;
  char *end;
  while (1) {
    const long kI = strtol(start, &end, 10);
    PRINTLNF("%s", start);
    PRINTLNF("%s", end);
    if (start == end) {
      break;
    }
    printf("'%.*s'\t===> %ld", (int) (end - start), start, kI);
    puts("\n");
    start = end;
  }
}