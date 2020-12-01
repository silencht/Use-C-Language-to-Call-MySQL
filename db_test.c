#include "db_base.h"

//Test
int main()
{
	const char* host = "192.168.1.105";
	const char* user = "schtest";
	const char* passwd = "sunchanghe";
	const char* db_name = "schbase";

	char* prep_ins_query = "INSERT INTO runoob_tbl(%s,%s,%s) VALUES (%s,%s,%s)";
	char insert_query[512] = { 0 };

	char* prep_sel_query = "SELECT * from %s";
	char select_query[256] = { 0 };

	MYSQL* mysql = db_connect(host, user, passwd, db_name);						//连接
	if (mysql == NULL)
	{
		printf("db_connect failed \n");
		syslog(LOG_ERR, "db_connect failed\n");
		return 0;
	}
//	else	(printf("************success connect!************\n"));

	sprintf(insert_query, prep_ins_query, "runoob_title", "runoob_author","submission_date","'Study Perl'","'runoob teach'","NOW()");	//拼接插入语句

	sprintf(select_query, prep_sel_query, "runoob_tbl");		//拼接查询语句

	db_change_query(mysql, insert_query);									//增加行

	db_select_query(mysql, select_query);									//查询

	db_change_query(mysql, "UPDATE runoob_tbl SET runoob_title = 'Study Java', runoob_author = 'sunchanghe' WHERE runoob_id = 1");			//修改行

	db_select_query(mysql, select_query);									//查询

	//db_change_query(mysql, "DELETE FROM runoob_tbl WHERE runoob_id > 1");			//删除行

	//db_select_query(mysql, select_query);									//查询

	db_disconnect(mysql);											                         //断开连接

	return 0;
}
