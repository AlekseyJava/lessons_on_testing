login()
{
   lr_start_transaction("{UC}_01_Загрузка_главной_страницы");

	web_url("login.html", 
		"URL=http://{balancedHost}/ic/dcb/login.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTTP", 
		LAST);

	web_reg_save_param_ex(
		"ParamName=csrftoken",
		"LB=csrftoken: ",
		"RB=\r\n",
		SEARCH_FILTERS,
			"Scope=headers",
		LAST);

	web_url("grib.js", 
		"URL=http://{balancedHost}/ic/dcb/rest/override-content/grib.js", 
		"Resource=1", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		LAST);

	web_add_auto_header("csrftoken", lr_eval_string("{csrftoken}"));


	web_url("settings", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/settings", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		LAST);

	web_url("globalnews", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/globalnews", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		LAST);
	web_url("view", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/banners/view", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		LAST);

	lr_end_transaction("{UC}_01_Загрузка_главной_страницы",LR_AUTO);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

    lr_start_transaction("{UC}_02_Прелогин");
	web_reg_save_param_ex("ParamName=srpB",
		"LB=srpB\":\"",
		"RB=\",\"",
		SEARCH_FILTERS,
			"Scope=Body",
		LAST);
		
	web_reg_save_param_ex("ParamName=srpS",
		"LB=srpS\":\"",
		"RB=\"",
		LAST);

	save_error();
	web_custom_request("prelogin", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/prelogin", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"user\":\"{login}\",\"changePassword\":false,\"sid\":null}", 
		LAST);
	check_error();

	lr_end_transaction("{UC}_02_Прелогин",LR_AUTO);
	
	lr_start_transaction(lr_eval_string("[Service]_{UC}_SRP_auth"));

	web_reg_save_param_ex("ParamName=valueA", 
		"LB=valueA=", 
		"RB=,", 
		"Ordinal=1", 
		"SaveLen=-1",
		SEARCH_FILTERS, 
		"IgnoreRedirections=off",
		"Scope=body", 
		LAST); 

	web_reg_save_param_ex("ParamName=valueM", 
		"LB=valueM=", 
		"RB=<", 
		"Ordinal=1", 
		"SaveLen=-1",
		SEARCH_FILTERS, 
		"IgnoreRedirections=off",
		"Scope=body", 
		LAST);

	web_submit_data("aplana_posttest", 
		"Action=http://{srp_host}:{srp_port}/sbbol_bicrypt_login/calculate_srp_data", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Mode=http", 
		ITEMDATA, 
		"Name=user_login", "Value={login}", ENDITEM, 
		"Name=user_password", "Value={password}", ENDITEM, 
		"Name=srp_salt", "Value={srpB}", ENDITEM, 
		"Name=srp_valueB", "Value={srpS}", ENDITEM, 
		LAST);

    lr_end_transaction(lr_eval_string("[Service]_{UC}_SRP_auth"), LR_AUTO);

	lr_start_transaction("{UC}_03_Логин");

	save_error();

	web_custom_request("login", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"oldPasswordSrp\":{\"srpA\":\"{valueA}\",\"srpM\":\"{valueM}\"},\"newPasswordSrp\":{\"srpV\":\"\",\"oldSrpV\":[]},\"rsaData\":{\"domElements\":\"{\\\"functions\\\":{\\\"names\\\":[\\\"$\\\",\\\"$$\\\",\\\"$a\\\",\\\"$f\\\",\\\"$h\\\",\\\"$r\\\",\\\"$w\\\",\\\"blackberrylocationcollector\\\",\\\"domdatacollection\\\",\\\"fingerprint\\\",\\\"gcd\\\",\\\"gcd_\\\",\\\"html5locationcollector\\\",\\\"hash\\\","
		"\\\"hashtable\\\",\\\"ie_fingerprint\\\",\\\"interactionelement\\\",\\\"mozilla_fingerprint\\\",\\\"objectrange\\\",\\\"opera_fingerprint\\\",\\\"p\\\",\\\"periodicalexecuter\\\",\\\"sha256\\\",\\\"srpauthresult\\\",\\\"srpclientcontext\\\",\\\"srpcontext\\\",\\\"selector\\\",\\\"spinner\\\",\\\"template\\\",\\\"timer\\\",\\\"uielementlist\\\",\\\"uievent\\\",\\\"_\\\",\\\"_addinputtoform\\\",\\\"_changepassword\\\",\\\"_login\\\",\\\"_srpchangepassword\\\",\\\"_srpmakenewpswddata\\\",\\\""
		"_srpmakepswddata\\\",\\\"_submitchangepassworddata\\\",\\\"_submitlogindata\\\",\\\"_submitlogindatabyajax\\\",\\\"_submitlogindatabyform\\\",\\\"activexdetect\\\",\\\"add\\\",\\\"addeventlistener\\\",\\\"addint\\\",\\\"addint_\\\",\\\"addshift_\\\",\\\"add_\\\",\\\"add_deviceprint\\\",\\\"alert\\\",\\\"atob\\\",\\\"ba2blks_sha1\\\",\\\"bigint2str\\\",\\\"bitsize\\\",\\\"blur\\\",\\\"btoa\\\",\\\"calch\\\",\\\"calchhex\\\",\\\"calcsha1\\\",\\\"calcsha1ba\\\",\\\"calcsha1baex\\\",\\\""
		"calcsha1blks\\\",\\\"calcsha1hex\\\"],\\\"excluded\\\":{\\\"size\\\":0,\\\"count\\\":0},\\\"truncated\\\":true},\\\"inputs\\\":[],\\\"iframes\\\":[],\\\"scripts\\\":[0,0,0,0,0,0,0,0,0,0],\\\"collection_status\\\":0}\",\"jsEvents\":\"1,1,INPUT:text,8@1,3,0;1,4,0;1,3,0;1,1,0;1,5,0;1,5,0;1,4,0@0,4521,0\",\"pageId\":\"login.html\",\"devicePrint\":\""
		"version%3D3%2E4%2E1%2E0%5F1%26pm%5Ffpua%3Dmozilla%2F5%2E0%20%28windows%20nt%206%2E1%3B%20wow64%3B%20rv%3A44%2E0%29%20gecko%2F20100101%20firefox%2F44%2E0%7C5%2E0%20%28Windows%29%7CWin32%26pm%5Ffpsc%3D16%7C1920%7C1080%7C1080%26pm%5Ffpsw%3D%26pm%5Ffptz%3D3%26pm%5Ffpln%3Dlang%3Dru%2DRU%7Csyslang%3D%7Cuserlang%3D%26pm%5Ffpjv%3D0%26pm%5Ffpco%3D1%26pm%5Ffpasw%3Dnpswf32%5F13%5F0%5F0%5F244%7Cnpctrl%26pm%5Ffpan%3DNetscape%26pm%5Ffpacn%3DMozilla%26pm%5Ffpol%3Dtrue%26pm%5Ffposp%3D%26pm%5Ffpup%3D%26pm%5Ffpsaw%"
		"3D1858%26pm%5Ffpspd%3D16%26pm%5Ffpsbd%3D%26pm%5Ffpsdx%3D%26pm%5Ffpsdy%3D%26pm%5Ffpslx%3D%26pm%5Ffpsly%3D%26pm%5Ffpsfse%3D%26pm%5Ffpsui%3D%26pm%5Fos%3DWindows%26pm%5Fbrmjv%3D44%26pm%5Fbr%3DFirefox%26pm%5Finpt%3D%26pm%5Fexpt%3D\"},\"tokenObjects\":null}", 
		LAST);

	check_error();

	lr_end_transaction("{UC}_03_Логин",LR_AUTO);

	lr_start_transaction("{UC}_04_Ввод_одноразового_пароля");

	web_reg_save_param_ex("ParamName=csrftoken",
		"LB=csrftoken: ",
		"RB=\r\n",
		SEARCH_FILTERS,
			"Scope=headers",
		LAST);

	save_error();
	web_custom_request("check-otp", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/check-otp", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"otp\":\"{oncePassword}\",\"rsaData\":{\"domElements\":\"{\\\"functions\\\":{\\\"names\\\":[\\\"$\\\",\\\"$$\\\",\\\"$a\\\",\\\"$f\\\",\\\"$h\\\",\\\"$r\\\",\\\"$w\\\",\\\"blackberrylocationcollector\\\",\\\"domdatacollection\\\",\\\"fingerprint\\\",\\\"gcd\\\",\\\"gcd_\\\",\\\"html5locationcollector\\\",\\\"hash\\\",\\\"hashtable\\\",\\\"ie_fingerprint\\\",\\\"interactionelement\\\",\\\"mozilla_fingerprint\\\",\\\"objectrange\\\",\\\"opera_fingerprint\\\",\\\"p\\\",\\\"periodicalexecuter\\\",\\\""
		"sha256\\\",\\\"srpauthresult\\\",\\\"srpclientcontext\\\",\\\"srpcontext\\\",\\\"selector\\\",\\\"spinner\\\",\\\"template\\\",\\\"timer\\\",\\\"uielementlist\\\",\\\"uievent\\\",\\\"_\\\",\\\"_addinputtoform\\\",\\\"_changepassword\\\",\\\"_login\\\",\\\"_srpchangepassword\\\",\\\"_srpmakenewpswddata\\\",\\\"_srpmakepswddata\\\",\\\"_submitchangepassworddata\\\",\\\"_submitlogindata\\\",\\\"_submitlogindatabyajax\\\",\\\"_submitlogindatabyform\\\",\\\"activexdetect\\\",\\\"add\\\",\\\""
		"addeventlistener\\\",\\\"addint\\\",\\\"addint_\\\",\\\"addshift_\\\",\\\"add_\\\",\\\"add_deviceprint\\\",\\\"alert\\\",\\\"atob\\\",\\\"ba2blks_sha1\\\",\\\"bigint2str\\\",\\\"bitsize\\\",\\\"blur\\\",\\\"btoa\\\",\\\"calch\\\",\\\"calchhex\\\",\\\"calcsha1\\\",\\\"calcsha1ba\\\",\\\"calcsha1baex\\\",\\\"calcsha1blks\\\",\\\"calcsha1hex\\\"],\\\"excluded\\\":{\\\"size\\\":0,\\\"count\\\":0},\\\"truncated\\\":true},\\\"inputs\\\":[],\\\"iframes\\\":[],\\\"scripts\\\":[0,0,0,0,0,0,0,0,0,0],\\\""
		"collection_status\\\":0}\",\"jsEvents\":\"1,1,INPUT:text,8;2,2,INPUT:text,0@1,3,0;1,4,0;1,3,0;1,1,0;1,5,0;1,5,0;1,4,0;2,3,0;2,4,0;2,3,0;2,1,0;2,1,0;2,1,0;2,1,0;2,1,0;2,4,0@0,4521,0\",\"pageId\":\"login.html\",\"devicePrint\":\""
		"version%3D3%2E4%2E1%2E0%5F1%26pm%5Ffpua%3Dmozilla%2F5%2E0%20%28windows%20nt%206%2E1%3B%20wow64%3B%20rv%3A44%2E0%29%20gecko%2F20100101%20firefox%2F44%2E0%7C5%2E0%20%28Windows%29%7CWin32%26pm%5Ffpsc%3D16%7C1920%7C1080%7C1080%26pm%5Ffpsw%3D%26pm%5Ffptz%3D3%26pm%5Ffpln%3Dlang%3Dru%2DRU%7Csyslang%3D%7Cuserlang%3D%26pm%5Ffpjv%3D0%26pm%5Ffpco%3D1%26pm%5Ffpasw%3Dnpswf32%5F13%5F0%5F0%5F244%7Cnpctrl%26pm%5Ffpan%3DNetscape%26pm%5Ffpacn%3DMozilla%26pm%5Ffpol%3Dtrue%26pm%5Ffposp%3D%26pm%5Ffpup%3D%26pm%5Ffpsaw%"
		"3D1858%26pm%5Ffpspd%3D16%26pm%5Ffpsbd%3D%26pm%5Ffpsdx%3D%26pm%5Ffpsdy%3D%26pm%5Ffpslx%3D%26pm%5Ffpsly%3D%26pm%5Ffpsfse%3D%26pm%5Ffpsui%3D%26pm%5Fos%3DWindows%26pm%5Fbrmjv%3D44%26pm%5Fbr%3DFirefox%26pm%5Finpt%3D%26pm%5Fexpt%3D\"}}", 
		LAST);
	check_error();

	web_revert_auto_header("csrftoken");        
	web_add_auto_header("csrftoken", lr_eval_string("{csrftoken}"));

	lr_end_transaction("{UC}_04_Ввод_одноразового_пароля",LR_AUTO);

	lr_start_transaction("{UC}_05_Загрузка_личного_кабинета");

	web_custom_request("update",
		"URL=http://{balancedHost}/ic/dcb/rest/accounts/update",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=http://{balancedHost}/ic/dcb/",
		"Mode=HTML",
		"EncType=",
		LAST);

	lr_continue_on_error(TRUE);

	web_reg_save_param_ex(
		"ParamName=p_signProfileId", 
		"LB=signProfiles\":[{\"id\":\"", 
		"RB=\",",
		"Notfound=error",
		LAST);

    web_reg_save_param_regexp("ParamName=userName",
		"RegExp=name\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userAccountNumber",
		"RegExp=accountNumber\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userTaxNum",
		"RegExp=taxNumber\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userKpp",
		"RegExp=kpps\":\\[\"(.+?)\"", 
		"Notfound=warning",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userBankName",
		"RegExp=bank\":{.+?name\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userBankBic",
		"RegExp=bic\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userBankCorrAcct",
		"RegExp=corrAcct\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userSType",
		"RegExp=settlementType\":\"(.+?)\"", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=userBankCity",
		"RegExp=city\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);
		
    web_reg_save_param_regexp("ParamName=accountIds",
		"RegExp={\"id\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		LAST);

	web_reg_save_param_ex("ParamName=response",
        "Notfound=warning",
 		SEARCH_FILTERS,
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
		LAST);

    web_reg_save_param_regexp(
		"ParamName=p_orgName",
		"RegExp=financialName\":\"(.+?)\",", 
		"Notfound=error",
		SEARCH_FILTERS, 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=1",
		LAST);

	asupCheck();

	web_url("index.html", 
		"URL=http://{balancedHost}/ic/dcb/index.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{balancedHost}/ic/dcb/", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=rest/override-content/grib.js", ENDITEM, 
		"Url=resources/features.json", ENDITEM, 
		"Url=resources/features.json", ENDITEM, 
		"Url=rest/configuration/settings/", ENDITEM, 
		"Url=rest/auth/settings", ENDITEM, 
		"Url=rest/configuration/settings", ENDITEM, 
		"Url=rest/user-info/permissions", ENDITEM, 
		"Url=rest/user-info/services", ENDITEM, 
		"Url=rest/user-info/sign-profiles/", ENDITEM, 
		"Url=rest/user-info/", ENDITEM, 
		"Url=rest/letters/statistics", ENDITEM, 
		"Url=rest/tokens/certificates/requests/profiles", ENDITEM, 
		"Url=rest/payments/orders/statistics/for-sign", ENDITEM, 
		"Url=rest/payments/orders/statistics/for-send", ENDITEM, 
		"Url=rest/configuration/settings", ENDITEM, 
		"Url=rest/payments/currency/personal-rate/available", ENDITEM, 
		"Url=rest/accounts", ENDITEM, 
		"Url=rest/e-invoicing/documents/statistics", ENDITEM, 
		"Url=rest/configuration/settings", ENDITEM, 
		"Url=rest/user-info/profile/settings", ENDITEM, 
		"Url=rest/user-profile/?", ENDITEM,
		"Url=rest/asup-data", ENDITEM, 
		"Url=rest/configuration/asup-settings", ENDITEM, 
		"Url=rest/asup-data/wn_plashka", ENDITEM, 
		"Url=rest/asup-data/WN_FIRST_VISIT/shown-limited", ENDITEM, 
		"Url=rest/asup-data/WN_NEXT_VISIT", ENDITEM, 
		LAST);

	if (lr_get_transaction_status("{UC}_05_Загрузка_личного_кабинета") == LR_FAIL) {
		lr_convert_string_encoding(lr_eval_string("{response}"),"utf-8",NULL,"msg");
		lr_error_message("%s", lr_eval_string("{msg}"));
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_FAIL);
	}

	lr_continue_on_error(FALSE);

	web_custom_request("exist", 
		"URL=http://{balancedHost}/ic/dcb/rest/payments/orders/exist", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[\"SIGNED\",\"CREATED\",\"PARTSIGNED\",\"IMPORTED\"]", 
		EXTRARES, 
        "Url=/ic/dcb/images/sprite-i-main-page-menu.svg",
		"Referer=http://{balancedHost}/ic/dcb/dist/app.css", ENDITEM, 
		LAST);

    web_custom_request("actual_3", 
		"URL=http://{balancedHost}/ic/dcb/rest/dictionaries/common/currency-rates/actual", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"currency\":\"EUR\",\"baseCurrency\":\"RUR\"}", 
		LAST);

	web_custom_request("actual_4", 
		"URL=http://{balancedHost}/ic/dcb/rest/dictionaries/common/currency-rates/actual", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"currency\":\"USD\",\"baseCurrency\":\"RUR\"}", 
		LAST);

	//{"docTypes":["0401060","0401061Cl"],"needAllCount":true}
	web_custom_request("view", 
		"URL=http://{balancedHost}/ic/dcb/rest/payment-templates/view", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"docTypes\":[\"0401060\",\"0401061Cl\"],\"needAllCount\":true}", 
		LAST);

    web_custom_request("userresponses", 
		"URL=http://{balancedHost}/ic/dcb/rest/asup-data/userresponses", 
		"Method=POST", 
		"Resource=0", 
		"Referer=http://{balancedHost}/ic/dcb/index.html",  
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"type\":\"LGN\"}", 
		LAST);
	lr_end_transaction("{UC}_05_Загрузка_личного_кабинета",LR_AUTO);

	asupClick();

	return 0;
}
