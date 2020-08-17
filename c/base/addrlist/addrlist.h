#ifndef ADDRLIST_H
#define ADDRLIST_H

#endif // ADDRLIST_H

#define NAME_LENGTH 30
#define ADDR_LENGTH 100
#define PHONE_LENGTH 12

#define MAX_ADDRESSES 100 // 地址最多个数

// 根据姓名查找地址
char const *lookup_address(char const *name);

// 根据姓名查找手机号
char const *lookup_phone(char const *name);
