//
// Created by miclefengzss on 2021/1/6.
//

#include <io_utils.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char string[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";

  typedef struct {
    char *name;
    int year;
  } Language;

  const char *language_break = ";";
  const char *field_break = ",";

  int language_capacity = 3;
  int language_size = 0;
  Language *languages = malloc(sizeof(Language) * language_capacity);

  if (!languages) {
    abort();
  }

  // 以指定的符号分割字符串，并返回分割后的字符串(分隔符之前的)
  char *next = strtok(string, field_break);
  while (next) {
    Language language;
    language.name = next;

    next = strtok(NULL, language_break);
    char *end;
    if (next) {
      language.year = (int) strtol(next, &end, 10);
      if (language_size + 1 >= language_capacity) {
        languages = realloc(languages, sizeof(Language) * language_capacity * 2);

        if (!languages) {
          abort();
        }
      }
      languages[language_size++] = language;
    }

    next = strtok(NULL, field_break);
  }

  PRINTLNF("languages: %d", language_size);
  PRINTLNF("languages capacity: %d", language_capacity);
  for (int k_i = 0; k_i < language_size; ++k_i) {
    PRINTLNF("Language[Name: %s, Year: %d]", languages[k_i].name, languages[k_i].year);
  }
  free(languages);
  return 0;
}
