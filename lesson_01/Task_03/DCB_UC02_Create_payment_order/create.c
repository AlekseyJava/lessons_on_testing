create()
{
	//расчет НДС 18%
	int amount = atoi("{amount}");
	double nds = ((double)amount/118)*18;
	char strNds[100];
	lr_save_int(nds,"nds");
	//создание строки назначения платежа
    lr_start_transaction("{UC}_06_Вкладка_платежи_и_переводы");

	web_url("statistics_3", 
		"URL=http://{balancedHost}/ic/dcb/rest/letters/statistics", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		LAST);

	save_error();
	web_custom_request("view_3", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/view", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"accountNumber\":null,\"bic\":null,\"number\":null,\"orderBy\":null,\"counterpartyName\":null,\"counterpartyTaxNumber\":null,\"counterpartyAccountNumber\":null,\"statusCodes\":[],\"pagination\":{\"offset\":0,\"count\":10}}", 
		LAST);
	check_error();

	web_custom_request("view_4", 
		"URL=http://{balancedHost}/ic/dcb/rest/letters/view", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html",
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"currentPage\":1,\"perPage\":10,\"typeCodes\":[],\"isRead\":false,\"mustRead\":true,\"pagination\":{\"count\":10,\"offset\":0},\"statusCode\":\"INBOX\",\"letterTypes\":[]}", 
		LAST);

	lr_end_transaction(lr_eval_string("{UC}_06_Вкладка_платежи_и_переводы"),LR_AUTO);

	lr_start_transaction(lr_eval_string("{UC}_07_Меню_Новый_платеж_контрагенту"));

	web_reg_save_param_ex("ParamName=number",
		"LB=number\":\"",
		"RB=\",\"",
        "Notfound=error",
 		SEARCH_FILTERS,
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/payments/orders/prefilled-forms?type=RUB_COMM",
		LAST);

    web_custom_request("view", 
		"URL=http://{balancedHost}/ic/dcb/rest/payment-templates/view", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={}", 
		EXTRARES, 
		"Url=../payments/orders/prefilled-forms?type=RUB_COMM", ENDITEM, 
 		"Url=../dictionaries/common/small", "Referer=http://{balancedHost}/ic/dcb/index.html", ENDITEM,
 		"Url=../dictionaries/common/vat", "Referer=http://{balancedHost}/ic/dcb/index.html", ENDITEM,
		LAST);

	lr_end_transaction(lr_eval_string("{UC}_07_Меню_Новый_платеж_контрагенту"),LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

	lr_start_transaction(lr_eval_string("{UC}_08_Кнопка_Создать"));

	web_reg_save_param_ex("ParamName=docID", 
		"LB={\"id\":\"", 
		"RB=\",\"version",
		"Notfound=error",
		LAST);
	
	save_error();

	web_custom_request("payments", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/?target=NEW", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"BodyBinary={"
			"\"docType\":\"RUB_ORDER\","
			"\"type\":\"RUB_COMM\","
			"\"number\":\"{number}\","
			"\"docDate\":\"{date}\","
			"\"statusCode\":\"CREATED\","
			"\"amount\":"
			"{"
				"\"currencyCode\":\"810\","
				"\"currencyName\":\"RUR\","
				"\"amount\":\"{amount}\""
			"},"
			"\"payer\":"
			"{"
				"\"accountRequisites\":"
				"{"
					"\"accountNumber\":\"{userAccountNumber}\","
					"\"accountAlias\":\"{userName}\","
					"\"bank\":"
					"{"
						"\"bic\":\"{userBankBic}\","
						"\"name\":\"{userBankName}\","
						"\"corrAcct\":\"{userBankCorrAcct}\","
						"\"city\":\"{userBankCity}\","
						"\"settlementType\":\"{userSType}\""
					"}"
				"},"
				"\"name\":\"{userName}\","
				"\"taxNumber\":\"{userTaxNum}\","
				"\"kpp\":\"{userKpp}\""
			"},"
			"\"payee\":"
			"{"
				"\"id\":{payeeId},"
				"\"kpp\":\"{payeeKpp}\","
				"\"taxNumber\":\"{payeeTaxNum}\","
				"\"name\":\"{payeeName}\","
				"\"accountRequisites\":"
				"{"
					"\"accountNumber\":\"{payeeAccNum}\","
					"\"bank\":"
					"{"
						"\"bic\":\"{payeeBankBic}\","
						"\"name\":\"{payeeBankName}\","
						"\"city\":\"{payeeBankCity}\","
						"\"settlementType\":\"{payeeSType}\","
						"\"corrAcct\":\"{payeeBankCorrAcct}\""
					"}"
				"}"
			"},"
			"\"urgencyCode\":\"NORMAL\","
			"\"vat\":"
			"{"
				"\"code\":\"INCLUDED\","
				"\"amount\":"
				"{"
					"\"currencyCode\":\"810\","
					"\"currencyName\":\"RUR\","
					"\"amount\":\"{nds}\""
				"},"
				"\"rate\":\"18\""
			"},"
			"\"rankCode\":\"5\","
			"\"deliveryType\":\"СЌР»РµРєС‚СЂРѕРЅРЅРѕ\","
			"\"operationCode\":\"01\","
			"\"codeVO\":null,"
			"\"purpose\":\"Р’ С‚РѕРј С‡РёСЃР»Рµ РќР”РЎ 18 % - {nds} СЂСѓР±Р»РµР№.\""
		"}",
		LAST);

	check_error();

 	web_custom_request("exist_2", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/exist", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[\"SIGNED\",\"CREATED\",\"PARTSIGNED\",\"IMPORTED\"]", 
		EXTRARES, 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", ENDITEM, 
		LAST);

	lr_end_transaction(lr_eval_string("{UC}_08_Кнопка_Создать"),LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

	lr_start_transaction(lr_eval_string("{UC}_09_Кнопка_Получить_SMS_код"));

    save_error();

	web_custom_request("request", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/{docID}/sign/otp/request", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"signProfileId\":\"{p_signProfileId}\"}", 
		LAST);

	check_error();

	lr_end_transaction(lr_eval_string("{UC}_09_Кнопка_Получить_SMS_код"),LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

	lr_start_transaction(lr_eval_string("{UC}_10_Ввод_и_отправка_SMS_пароля"));

    save_error();

	web_custom_request("check", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/{docID}/sign/otp/check", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"signProfileId\":\"{p_signProfileId}\",\"otp\":\"{oncePassword}\"}", 
		LAST);

	check_error();

	web_custom_request("exist_3", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/exist", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[\"SIGNED\",\"CREATED\",\"PARTSIGNED\",\"IMPORTED\"]", 
		EXTRARES, 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", ENDITEM, 
		LAST);

	lr_end_transaction(lr_eval_string("{UC}_10_Ввод_и_отправка_SMS_пароля"),LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

	lr_start_transaction(lr_eval_string("{UC}_11_Кнопка_Отправить_в_банк"));

    save_error();

	web_custom_request("send", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/{docID}/send", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"domElements\":\"{\\\"functions\\\":{\\\"names\\\":[\\\"blackberrylocationcollector\\\",\\\"datetimepicker\\\",\\\"domdatacollection\\\",\\\"editablename\\\",\\\"ellipsis\\\",\\\"fingerprint\\\",\\\"html5locationcollector\\\",\\\"hashtable\\\",\\\"ie_fingerprint\\\",\\\"input\\\",\\\"inputnumber\\\",\\\"interactionelement\\\",\\\"link\\\",\\\"loadingcontentoverlay\\\",\\\"maskeddatepicker\\\",\\\"maskedinput\\\",\\\"modal\\\",\\\"moment\\\",\\\"mozilla_fingerprint\\\",\\\""
		"opera_fingerprint\\\",\\\"p\\\",\\\"pagination\\\",\\\"query\\\",\\\"routehandler\\\",\\\"slider\\\",\\\"starfavorite\\\",\\\"tableview\\\",\\\"tableviewrow\\\",\\\"tabs\\\",\\\"textarea\\\",\\\"timer\\\",\\\"uielementlist\\\",\\\"uievent\\\",\\\"_\\\",\\\"activexdetect\\\",\\\"addeventlistener\\\",\\\"add_deviceprint\\\",\\\"alert\\\",\\\"atob\\\",\\\"blur\\\",\\\"btoa\\\",\\\"cancelanimationframe\\\",\\\"captureevents\\\",\\\"clearinterval\\\",\\\"cleartimeout\\\",\\\"close\\\",\\\"confirm\\\","
		"\\\"converttimestamptogmt\\\",\\\"createimagebitmap\\\",\\\"debug\\\",\\\"decode_deviceprint\\\",\\\"detectdevicecollectionapimode\\\",\\\"detectfields\\\",\\\"dispatchevent\\\",\\\"dump\\\",\\\"encode_deviceprint\\\",\\\"fetch\\\",\\\"find\\\",\\\"focus\\\",\\\"forceie89synchronicity\\\",\\\"form_add_data\\\"],\\\"excluded\\\":{\\\"size\\\":0,\\\"count\\\":0},\\\"truncated\\\":true},\\\"inputs\\\":[],\\\"iframes\\\":[],\\\"scripts\\\":[0,0,0],\\\"collection_status\\\":0}\",\"jsEvents\":\"1,1,"
		"INPUT:text,0;2,2,INPUT:text,0@1,3,0;1,1,0;1,4,0;2,3,0;2,1,0;2,1,0;2,1,0;2,1,0;2,1,0;2,4,0@0,908,0\",\"pageId\":\"index.html\",\"devicePrint\":\""
		"version%3D3%2E4%2E1%2E0%5F1%26pm%5Ffpua%3Dmozilla%2F5%2E0%20%28windows%20nt%206%2E1%3B%20wow64%3B%20rv%3A44%2E0%29%20gecko%2F20100101%20firefox%2F44%2E0%7C5%2E0%20%28Windows%29%7CWin32%26pm%5Ffpsc%3D16%7C1600%7C900%7C856%26pm%5Ffpsw%3D%26pm%5Ffptz%3D3%26pm%5Ffpln%3Dlang%3Dru%2DRU%7Csyslang%3D%7Cuserlang%3D%26pm%5Ffpjv%3D0%26pm%5Ffpco%3D1%26pm%5Ffpasw%3Dnpdeployjava1%7Cnpswf32%5F13%5F0%5F0%5F244%7Cnpctrl%26pm%5Ffpan%3DNetscape%26pm%5Ffpacn%3DMozilla%26pm%5Ffpol%3Dtrue%26pm%5Ffposp%3D%26pm%5Ffpup%3D"
		"%26pm%5Ffpsaw%3D1600%26pm%5Ffpspd%3D16%26pm%5Ffpsbd%3D%26pm%5Ffpsdx%3D%26pm%5Ffpsdy%3D%26pm%5Ffpslx%3D%26pm%5Ffpsly%3D%26pm%5Ffpsfse%3D%26pm%5Ffpsui%3D%26pm%5Fos%3DWindows%26pm%5Fbrmjv%3D44%26pm%5Fbr%3DFirefox%26pm%5Finpt%3D%26pm%5Fexpt%3D\"}", 
		LAST);

	check_error();

	web_custom_request("exist_4", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/exist", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[\"SIGNED\",\"CREATED\",\"PARTSIGNED\",\"IMPORTED\"]", 
		EXTRARES, 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", ENDITEM, 
		LAST);

	lr_end_transaction(lr_eval_string("{UC}_11_Кнопка_Отправить_в_банк"),LR_AUTO);

	return 0;
}
