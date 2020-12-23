//
// Created by miclefengzss on 2020/12/23.
//

#include <io_utils.h>

/*
 * struct <结构体名> {
 *  <成员类型> <成员名>;
 *  ...
 * } <结构体变量>;
 */

typedef struct Company {
  char *id;
  char *name;
  char *location;
} Company;

typedef struct Person {
  char *id;
  int age;
  char *name;
  Company *company;
  Company company2;
  struct {
    int extra;
    char *extra_str;
  } extra_value;
  struct Person *person;  // 自己指向自己
} Person;

int main() {
  // typedef 声明类型之后，可以不用加 struct
  Company company1 = {.id="456789", .name="know", .location="beijing"};
  struct Company company = {.id="123456", .name="imooc", .location="beijing"};
  struct Person person =
      {.id="001", .age=30, .name="miclefengzss", .company=&company1, .company2=company, .extra_value.extra=10, .extra_value.extra_str="111"};
  PRINT_INT(person.age);
  PRINT_HEX(&person);
  PRINT_STRING(person.company->name);

  // 如果只使用一次可以使用匿名结构体
  struct {
    char *name;
    int age;
    char *id;
  } anonymous_person;

  Person person1 = {.name = "andy", .age = 20};
  PRINT_INT(person1.age);

  return 0;
}