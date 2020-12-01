### 测试系统：

- Linux ：Ubuntu18.04

### 编译命令：
- gcc db_base.c db_test.c -o test `mysql_config --cflags --libs`

### 运行：
- ./test

### 注意事项：

- 工程项目加载MySQL的C语言接口函数时，要载入这个数据库的静态链接库。安装好MySQL数据库服务后，按如下方法操作：

1. Add the following statement in your makefile:

```makefile
LDFLAGS+=...... 
OBJ=.... db_base.o
```

​	this statement is found from the bash shell ，and you can query through this command : 

```bash
$ mysql_config  --libs
```

​	In my makefile ,for example：

```makefile
#add Mysql

LDFLAGS+= -L/usr/lib/aarch64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -latomic -ldl

OBJ=.... db_base.o
```

2. And if you want to use it in your   *.cpp file , Please be careful of the following:

```c++
/* for data_base：MySQL */
extern "C"{
#include <stdlib.h> 
#include "db_base.h"
}
```

​	this  "extern "C"{……}" statement is very important.
​	if don't have this statement, maybe meet the error :"undefined reference to" .

### 原工程仓库下载链接：

​	https://github.com/CorKay/database_mysql