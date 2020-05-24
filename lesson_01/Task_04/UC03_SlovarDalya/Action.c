Action()
{
	int id = 0;
	int random_letter_id = 0;
	int count;
	int word_id;
	int new_word_id;
	
	//переход на главную страницу сайта словар€ ƒал€
	lr_start_transaction("01_MainPage");
	
	web_reg_save_param_ex(
    "ParamName=letter", 
    "LB/IC=charkod\=",
    "RB/IC='>",
    "Ordinal=All",
    SEARCH_FILTERS,
        "Scope=Body",
	LAST);
	
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
	
	//letter_id random parametr из массива letter	
	lr_save_string(lr_paramarr_random("letter"), "letter_id");
	
	//печать letter_id
	//lr_output_message(lr_eval_string(""));

	lr_end_transaction("01_MainPage", LR_AUTO);

	lr_think_time(10);
	
	/* Ќажатие на букву */
	
	lr_start_transaction("02_PressLetter");

//	web_revert_auto_header("Origin");
//
//	web_add_header("Upgrade-Insecure-Requests", 
//		"1");
	
	web_reg_save_param_ex(
    "ParamName=word_id", 
    "LB/IC=wordid\=",
    "RB/IC='><strong>",
    "Ordinal=All",
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
	
	//lr_output_message(lr_eval_string("{word_id_count}"));
	
	count = atoi(lr_eval_string("{word_id_count}"));
	
	word_id = atoi(lr_eval_string("{word_id_1}"));
	
	//lr_output_message("количество слов - с этой буквой %d, первое слово %d", count, word_id);
	
	lr_save_int(count, "count_words");
	
	//lr_output_message(lr_eval_string("{count_words}"));
	
	if(count>1) {
		new_word_id = word_id + ((rand()%count)/2)*2 + 1;
	}
	else(new_word_id = word_id);
	
	lr_output_message("случайное новое слово %d", new_word_id);
	
	lr_save_int(new_word_id, "random_word");
	
	lr_output_message(lr_eval_string("{random_word}"));

	lr_end_transaction("02_PressLetter", LR_AUTO);
	
	lr_think_time(10);
	
	/* Ќажатие на случайное четное слово */
	
	lr_start_transaction("03_PressWord");

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_set_max_html_param_len("30000");
	
web_reg_save_param_ex(
    "ParamName=word", 
    "LB= словарна€ стать€, ",
    "RB=\">",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=All",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=word_znachenie", 
    "LB=</strong></p><p>",
  	"RB=</p>",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=Body",
	LAST);
	
	web_url("word.php", 
        "URL=http://slovardalja.net/word.php?wordid={random_word}",
        //"URL=http://slovardalja.net/word.php?wordid=44010",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/letter.php?charkod={letter_id}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("03_PressWord", LR_AUTO);
	
//	lr_output_message(lr_eval_string("id буквы: "));
	
	lr_output_message(lr_eval_string("слово: {word}"));
	
	lr_output_message(lr_eval_string("значение слова: {word_znachenie}"));

	/* ќстановка записи скрипта */

	return 0;
}