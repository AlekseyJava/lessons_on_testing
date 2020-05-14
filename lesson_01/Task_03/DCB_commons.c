char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    if (!orig)
        return NULL;
    if (!rep)
        rep = "";
    len_rep = strlen(rep);
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = (char*)strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    tmp = result = (char*)malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = (char*)strstr(orig, rep);
        len_front = ins - orig;
        tmp = (char*)strncpy(tmp, orig, len_front) + len_front;
        tmp = (char*)strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

save_error(){

	web_reg_save_param_ex("ParamName=errorText", 
		"LB=errorMsg\":\"", 
		"RB=\"",
        "Notfound=warning",
		"Ordinal=ALL",
		LAST);

	web_reg_save_param_ex("ParamName=errorMsg", 
		"LB=message\":\"", 
		"RB=\}",
        "Notfound=warning",
		"Ordinal=ALL",
		LAST);
}

check_error(){
	int k;
	int k1;
	if (atoi(lr_eval_string("{errorText_count}"))!=0) {
		for(k = 1; k<=atoi(lr_eval_string("{errorText_count}")); k++){
			lr_save_int(k,"k");
			lr_convert_string_encoding(lr_eval_string(lr_eval_string("{errorText_{k}}")),"utf-8",NULL,"msg");
			lr_error_message("login: %s", lr_eval_string("{login}"));
			lr_error_message("%s", lr_eval_string("{msg}"));

			for(k1 = 1; k1<=atoi(lr_eval_string("{errorMsg_count}")); k1++){
				lr_save_int(k1,"k1");
				lr_convert_string_encoding(lr_eval_string(lr_eval_string("{errorMsg_{k1}}")),"utf-8",NULL,"msg");
				lr_error_message("%s", lr_eval_string("{msg}"));
			}
		}

		lr_save_string("FAIL","ScriptResult");

		logout();

        lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_FAIL);
	}
}

int resolve_wm(char *login){
	int substring = 10;
	substring = strstr(login, "us_"); //проверяем на принадлежность 1му плечу, иначе второе
	if(substring != 0){ //если 1е плечо
		return 1;
	}else{ //если 2е плечо
		return 2;
	}
}

void resolve_host(){
	int code = 0;
	
	lr_start_transaction(lr_eval_string("[Service]_DCB_Получение_хоста_от_балансировщика"));
	
	if(resolve_wm(lr_eval_string("{login}")) == 1){ //если 1е плечо
		lr_save_string("1","branch");
	}else{ //если 2е плечо
		lr_save_string("2","branch");
	}
	
	web_reg_save_param("code", "LB=code\":", "RB=,", "notFound=Warning", LAST);
	web_reg_save_param("message", "LB=message\":\"", "RB=\"", "notFound=Warning", LAST);
	web_reg_save_param("balancedHost", "LB=host\":\"", "RB=\"", "notFound=Warning", LAST);
	web_custom_request(
		"balancehost", 
		"URL=http://{balancerHost}/HTTPBalancer/balancehost", 
        "Method=POST", 
        "EncType=application/json", 
		"Body={\"name\":\"DCB\"}",
		"LAST");

	code = atoi(lr_eval_string("{code}")); //проверка получения адреса
	if(code != 0){
		lr_output_message(lr_eval_string("Balancer BAD code {code}"));
        lr_end_transaction(lr_eval_string("[Service]_DCB_Получение_хоста_от_балансировщика"),LR_FAIL);
	}else{
        lr_end_transaction(lr_eval_string("[Service]_DCB_Получение_хоста_от_балансировщика"),LR_PASS);
	}
}

void resolve_host_SBBOL(){
	int substring = 10;
	int code = 0;
	lr_start_transaction(lr_eval_string("SBBOL_Service00_Получение_хоста_от_балансировщика"));

	substring = strstr(lr_eval_string("{login}"), "us_"); //проверяем на принадлежность 1му плечу, иначе второе

	if(substring != 0){ //если 1е плечо
		lr_save_string("ic/wm1","hostGroup");
		lr_save_string("1","branch");
	}else{ //если 2е плечо
		lr_save_string("ic/wm2","hostGroup");
		lr_save_string("2","branch");
	}

	web_reg_save_param("code", "LB=code\":", "RB=,", "notFound=Warning", LAST);
	web_reg_save_param("message", "LB=message\":\"", "RB=\"", "notFound=Warning", LAST);
	web_reg_save_param("balancedHost", "LB=host\":\"", "RB=\"", "notFound=Warning", LAST);
	web_custom_request(
		"balancehost", 
		"URL=http://{balancerHost}/HTTPBalancer/balancehost", 
        "Method=POST", 
        "EncType=application/json", 
		"Body={"
		"\"name\":\"{hostGroup}\"" //выбираем группу хостов
		"}",
		"LAST");

	code = atoi(lr_eval_string("{code}")); //проверка получения адреса
	if(code != 0){
		lr_output_message(lr_eval_string("Balancer BAD code {code}"));
		lr_save_string(lr_eval_string("{host_bal}"),"balancedHost");
	}else{
		lr_save_string(lr_eval_string("{balancedHost}"),"balancedHost");
		//lr_output_message("Balancer OK");
	}
	lr_end_transaction(lr_eval_string("SBBOL_Service00_Получение_хоста_от_балансировщика"),LR_AUTO);

}

void cacheDownload(){
	int casherProbably; //0-100
	int randValue;
	srand(time(NULL));
	randValue = 0 + (rand() % 100);
	casherProbably = 15;
	if(randValue <= casherProbably){
		lr_start_transaction("[Service]_DownloadStaticContent");
		web_url("dcb", 
			"URL=http://{balancedHost}/ic/dcb", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=dcb/login.css", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/vendors/vendors_27d257b56af4f7441428.css", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/favicons/favicon-32.png", "Referer=", ENDITEM, 
			"Url=dcb/i18n.bundle.json", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/mini-logo.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/fonts/roboto-regular.woff2", "Referer=http://{balancedHost}/ic/dcb/login.css", ENDITEM, 
			"Url=dcb/images/spinner.png", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/rest/auth/settings", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/logo.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/bg-5.jpg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/icon-login-5.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/bg-2.jpg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/icon-login-2.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/rest/auth/globalnews", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/bg-1.jpg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/icon-login-1.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/bg-3.jpg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/btnGooglePlay.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/btnAppStore.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/images/login/icon-login-3.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/fonts/sbbol-icons.ttf", "Referer=http://{balancedHost}/ic/dcb/common.css", ENDITEM, 
			"Url=dcb/images/btnWindowsStore.svg", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/Login-CheckOtpPage_469d658e03ad1bdf11ff.js", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			"Url=dcb/rest/auth/globalnews", "Referer=http://{balancedHost}/ic/dcb/", ENDITEM, 
			LAST);
		lr_end_transaction("[Service]_DownloadStaticContent", LR_AUTO);
	}    
    
}

void asupCheck(){
	web_reg_save_param_regexp(
		"ParamName=ASUP",
		"RegExp=id\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=ASUPcarouselId",
		"RegExp=id\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data/WN_FIRST_VISIT/shown-limited",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=ASUPcarouselOfferId",
		"RegExp=EXTERNAL_ID\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data/WN_FIRST_VISIT/shown-limited",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);
}

void asupClick(){
	int i;
	//Обычный АСУП
	if(lr_paramarr_len("ASUP") > 0){
		lr_start_transaction("DCB_АСУП_отклики_по_предложениям");
		save_error();
		web_custom_request(
			"userresponses",
			"URL=http://{balancedHost}/ic/dcb/rest/asup-data/userresponses",
			"Method=POST",
			"Resource=0",
			"Referer=http://{balancedHost}/ic/dcb/index.html",
			"Mode=HTTP",
			"EncType=application/json",
			"Body={\"type\":\"LGN\"}",
			LAST);
		check_error();
		lr_end_transaction("DCB_АСУП_отклики_по_предложениям", LR_AUTO);
	}
	
	//Крутим карусель, отправляем отклики от 1 до n
	if(lr_paramarr_len("ASUPcarouselId") > 0){
		lr_start_transaction("DCB_Карусель_отклики_по_предложениям");
		lr_save_string("","p_ASUPcarouselIds");
		for(i=1; i <= lr_paramarr_len("ASUPcarouselId"); i++){
			lr_save_string(lr_paramarr_idx("ASUPcarouselId", i),"p_carouselId");
			lr_save_string(lr_paramarr_idx("ASUPcarouselOfferId", i),"p_ASUPcarouselOfferId");
			
			web_custom_request(
				"ASUPcarouselVOF",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_ASUPcarouselOfferId}\", \"type\":\"VOF\"}",
				LAST);

			web_custom_request(
				"ASUPcarouselSFL",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_ASUPcarouselOfferId}\", \"type\":\"SFL\"}",
				LAST);

			web_custom_request(
				"ASUPcarouselSHM",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_ASUPcarouselOfferId}\", \"type\":\"SHM\"}",
				LAST);

			lr_save_int(i, "i");
			lr_save_string(lr_eval_string("{p_ASUPcarouselIds}\"{p_carouselId}\""),"p_ASUPcarouselIds");
			if(i != lr_paramarr_len("ASUPcarouselId"))
			   lr_save_string(lr_eval_string("{p_ASUPcarouselIds},"),"p_ASUPcarouselIds");
		}
	
		web_custom_request(
			"ASUPcarouselCPO",
			"URL=http://{balancedHost}/ic/dcb/rest/asup-data/userresponses",
			"Method=POST",
			"Resource=0",
			"Referer=http://{balancedHost}/ic/dcb/index.html",
			"Mode=HTTP",
			"EncType=application/json",
			"Body={\"type\":\"CPO\"}",
			LAST);
	
		save_error();
		web_custom_request(
			"ASUPcarousel_increment",
			"URL=http://{balancedHost}/ic/dcb/rest/asup-data/increment-shown-count",
			"Method=POST",
			"Resource=0",
			"Referer=http://{balancedHost}/ic/dcb/index.html",
			"Mode=HTTP",
			"EncType=application/json",
			"Body=[{p_ASUPcarouselIds}]",
			LAST);
		check_error();
		
		lr_end_transaction("DCB_Карусель_отклики_по_предложениям", LR_AUTO);
	}
}