ActionWorkWeb()
{
	web_add_header("Header", "1");
	web_add_auto_header("Auto_header", "http://ya.ru");
	web_revert_auto_header("Revert_auto_header");
	//web_add_cookie();
	return 0;
}
