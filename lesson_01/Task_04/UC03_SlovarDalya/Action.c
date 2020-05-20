Action()
{
	int id = 0;

	lr_start_transaction("01_MainPage");
	
	web_add_header("Upgrade-Insecure-Requests", 
		"1");

//	web_add_cookie("__utma=196215790.633335759.1589944572.1589944572.1589944572.1; DOMAIN=slovardalja.net");
//
//	web_add_cookie("__utmb=196215790; DOMAIN=slovardalja.net");
//
//	web_add_cookie("__utmc=196215790; DOMAIN=slovardalja.net");
//
//	web_add_cookie("__utmz=196215790.1589944572.1.1.utmccn=(direct)|utmcsr=(direct)|utmcmd=(none); DOMAIN=slovardalja.net");
//
//	web_add_cookie("__gads=ID=fe15cf4a3b9a8992:T=1589944572:S=ALNI_MYSuNkr_YSJGY0TxpiWnntFB-vrBA; DOMAIN=slovardalja.net");
//
//	web_add_cookie("fid=2897f844-3a02-4b6a-89c9-107ec0cb217b; DOMAIN=slovardalja.net");

	web_url("slovardalja.net", 
		"URL=http://slovardalja.net/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
//		EXTRARES, 
//		"Url=http://an.yandex.ru/system/context.js", ENDITEM, 
//		"Url=http://ssp-rtb.sape.ru/data/?callback=sapeRTBreadRtStatResponse_53471&srtbid=95403&scids=93390459&sx=1280&sy=913&ref=&allimps=0&fl=0&tz=%2B04%3A00&u=http%3A%2F%2Fslovardalja.net%2F", ENDITEM, 
//		"Url=http://counter.yadro.ru/hit?q;t44.1;r;s1280*1024*24;uhttp%3A//slovardalja.net/;h%u0422%u043E%u043B%u043A%u043E%u0432%u044B%u0439%20%u0441%u043B%u043E%u0432%u0430%u0440%u044C%20%u0414%u0430%u043B%u044F%20%u043E%u043D%u043B%u0430%u0439%u043D;0.8188255457706335", ENDITEM, 
//		"Url=http://avatars.mds.yandex.net/get-direct/1663802/7KEqQpfJCRBUCb1FEH5H7A/y450", ENDITEM, 
//		"Url=http://tpc.googlesyndication.com/sodar/sodar2.js", ENDITEM, 
//		"Url=/favicon.ico", ENDITEM, 
		LAST);

	lr_end_transaction("01_MainPage", LR_AUTO);

	lr_think_time(10);
	
	/* Нажатие на букву */
	
	lr_start_transaction("02_PressLetter");

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	//letter_id random 192-223(от А до Я)
	
	web_reg_save_param_ex(
    "ParamName=word_id", 
    "LB/IC=wordid\=",
    "RB/IC='><strong>",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=Body",
	LAST);
		
	web_url("letter.php", 
		"URL=http://slovardalja.net/letter.php?charkod={letter_id}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_output_message(lr_eval_string("{word_id}"));
	//id = word_id;
	
	//как взять массив из snapshot??
	//lr_output_message("%d", id);
	
	//	функция преобразования строку в число??

	lr_end_transaction("02_PressLetter", LR_AUTO);
	
	lr_think_time(10);
	
	/* Нажатие на 12 слово (КАВЫГЛАЗ) */
	
	lr_start_transaction("03_PressWord");

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
web_reg_save_param_ex(
    "ParamName=word", 
    "LB/IC= словарная статья, ",
    "RB/IC=\">",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=All",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=word_znachenie", 
    "LB/IC=</p><p>",
    "RB/IC=</p>",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=Body",
	LAST);
	
	web_url("word.php", 
        "URL=http://slovardalja.net/word.php?wordid={word_id}",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/letter.php?charkod={letter_id}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("03_PressWord", LR_AUTO);
	
	lr_output_message(lr_eval_string("id буквы: {letter_id}"));

	lr_output_message(lr_eval_string("id слова: {word_id}"));
	
	lr_output_message(lr_eval_string("слово: {word}"));
	
	lr_output_message(lr_eval_string("значение слова: {word_znachenie}"));
	
	
	/* Остановка записи скрипта */

	return 0;
}