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
//		"RB=\}",
		"RB=\"",
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
		lr_save_string(lr_eval_string("{host_bal}"),"balancedHost");
	}else{
		//lr_output_message("Balancer OK");
	}

	lr_end_transaction(lr_eval_string("[Service]_DCB_Получение_хоста_от_балансировщика"),LR_AUTO);
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
		"URL=http://{balancedHost}/ic/dcb/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=css/common.css", ENDITEM, 
		"Url=css/vendors.css", ENDITEM, 
		"Url=css/login.css", ENDITEM, 
		"Url=fonts/roboto-regular.eot", ENDITEM, 
		"Url=fonts/roboto-medium.eot", ENDITEM, 
		"Url=fonts/pt_sans-regular.eot", ENDITEM, 
		"Url=fonts/Roboto-Light-webfont.eot", ENDITEM, 
		"Url=fonts/pt_sans-bold.eot", ENDITEM, 
		"Url=fonts/pt_sans-regular.woff", ENDITEM, 
		"Url=fonts/pt_sans-bold.woff", ENDITEM, 
		"Url=i18n.bundle.json", ENDITEM, 
		"Url=js/chunks/21.SVGIcons--LogoSBBOLRu_8a4499ec5da97462da95.js", ENDITEM, 
		"Url=images/btnWindowsStore.svg", ENDITEM, 
		"Url=js/chunks/36.SVGIcons--DigitalSummit_6657d3afc43bdc7a1b69.js", ENDITEM, 
		"Url=images/btnGooglePlay.svg", ENDITEM, 
		"Url=fonts/sbbol-icons.eot", ENDITEM, 
		"Url=images/btnAppStore.svg", ENDITEM, 
		"Url=js/chunks/11.SVGIcons--RedDotIcon_0828b6417c1b587af05d.js", ENDITEM, 
		"Url=js/chunks/38.SVGIcons--CxForumIcon_f0654f30001b97db71de.js", ENDITEM, 
		"Url=js/chunks/1.Chat-Chat_6f32f8672326d2af062e.js", ENDITEM, 
		"Url=images/login/bg-5.jpg", ENDITEM, 
		"Url=images/login/icon-login-5.svg", ENDITEM, 
		"Url=images/login/bg-1.jpg", ENDITEM, 
		"Url=images/login/icon-login-1.svg", ENDITEM, 
		"Url=images/login/bg-6.jpg", ENDITEM, 
		"Url=images/login/bg-3.jpg", ENDITEM, 
		"Url=images/login/icon-login-3.svg", ENDITEM, 
		"Url=images/login/icon-login-6.svg", ENDITEM, 
		"Url=images/spinner.png", ENDITEM, 
		"Url=images/mini-logo.svg", ENDITEM, 
		"Url=js/chunks/411.Login-CheckOtpPage_9920f77ae8f685009a1f.js", ENDITEM, 
		LAST);
		lr_end_transaction("[Service]_DownloadStaticContent", LR_AUTO);
	}    
    
}

void asupCheck(){
	web_reg_save_param_regexp(
		"ParamName=p_ASUPId",
		"RegExp=id\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);

		
	web_reg_save_param_regexp(
		"ParamName=p_ASUPOfferId",
		"RegExp=EXTERNAL_ID\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=p_ASUPcarouselId",
		"RegExp=id\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data/WN_FIRST_VISIT/shown-limited",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=p_ASUPcarouselOfferId",
		"RegExp=EXTERNAL_ID\":\"(.+?)\",", 
		"Notfound=warning",
		SEARCH_FILTERS, 
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/asup-data/WN_FIRST_VISIT/shown-limited",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=All",
		LAST);
	
	 web_reg_save_param_regexp(
		"ParamName=WebAnalyticsAgreeModal",
		"RegExp=WEB_ANALYTICS_AGREE\",(.*)", 
		"Notfound=warning",
		SEARCH_FILTERS, 
			"Ordinal=All",
		LAST);
			
}

 void asupClick(){
 	int i;
 	//Обычный АСУП
 	if(lr_paramarr_len("p_ASUPId") > 0){

		lr_start_transaction("DCB_АСУП_отклики_по_всем_предложениям");

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

        if(lr_paramarr_len("p_ASUPOfferId") > 0){

			lr_save_string("","p_ASUPIds");

			for(i=1; i <= lr_paramarr_len("p_ASUPId"); i++){
				lr_save_string(lr_paramarr_idx("p_ASUPId", i),"p_Id");
				lr_save_string(lr_paramarr_idx("p_ASUPOfferId", i),"p_OfferId");

				//Узнать больше
				web_custom_request(
					"ASUPSHM",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"SHM\"}",
					LAST);

	                        //Заказ звонка
				web_custom_request(
					"ASUPOC",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"OC\"}",
					LAST);

        	                //перешел в магазин
				web_custom_request(
					"ASUPOGS",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"OGS\"}",
					LAST);

                	        //Оформить
				web_custom_request(
					"ASUPORC",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"ORC\"}",
					LAST);

                	        //Перешел в модальное окно
				web_custom_request(
					"ASUPSHF",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"SHF\"}",
					LAST);

                	        //Логин в магазин
				web_custom_request(
					"ASUPSHP",
					"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_Id}/responses/",
					"Method=POST",
					"Resource=0",
					"Referer=http://{balancedHost}/ic/dcb/index.html",
					"Mode=HTTP",
					"EncType=application/json",
					"Body={\"externalOfferId\":\"{p_OfferId}\", \"type\":\"SHP\"}",
					LAST);

				lr_save_int(i, "i");

				lr_save_string(lr_eval_string("{p_ASUPIds}\"{p_Id}\""),"p_ASUPIds");
			    if(i != lr_paramarr_len("p_ASUPId"))
			         lr_save_string(lr_eval_string("{p_ASUPIds},"),"p_ASUPIds");
				
			}

		}

		lr_end_transaction("DCB_АСУП_отклики_по_всем_предложениям", LR_AUTO);
 	}

 	//Крутим карусель, отправляем отклики от 1 до n
 	if(lr_paramarr_len("p_ASUPcarouselId") > 0){

		lr_start_transaction("DCB_Карусель_отклики_по_предложениям");
		lr_save_string("","p_ASUPcarouselIds");

		for(i=1; i <= lr_paramarr_len("p_ASUPcarouselId"); i++){
			lr_save_string(lr_paramarr_idx("p_ASUPcarouselId", i),"p_carouselId");
			lr_save_string(lr_paramarr_idx("p_ASUPcarouselOfferId", i),"p_carouselOfferId");

			web_custom_request(
				"ASUPcarouselVOF",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_carouselOfferId}\", \"type\":\"VOF\"}",
				LAST);

			web_custom_request(
				"ASUPcarouselSFL",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_carouselOfferId}\", \"type\":\"SFL\"}",
				LAST);

			web_custom_request(
				"ASUPcarouselSHM",
				"URL=http://{balancedHost}/ic/dcb/rest/asup-data/{p_carouselId}/responses/",
				"Method=POST",
				"Resource=0",
				"Referer=http://{balancedHost}/ic/dcb/index.html",
				"Mode=HTTP",
				"EncType=application/json",
				"Body={\"externalOfferId\":\"{p_carouselOfferId}\", \"type\":\"SHM\"}",
				LAST);

			lr_save_int(i, "i");
			lr_save_string(lr_eval_string("{p_ASUPcarouselIds}\"{p_carouselId}\""),"p_ASUPcarouselIds");
			if(i != lr_paramarr_len("p_ASUPcarouselId"))
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

	//соглашаемся на отправку данных в гугл-аналитику
	 if(lr_paramarr_len("WebAnalyticsAgreeModal") > 0){

		lr_start_transaction("DCB_Гугл-аналитика_согласие");

		web_url("modal",
				"Url=http://{balancedHost}/ic/dcb/nls/ru/WebAnalyticsAgreeModal.json",
				LAST);

		web_custom_request("save",
			"URL=http://{balancedHost}/ic/dcb/rest/user-info/google-analytics-agree/save",
			"Method=POST",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=http://{balancedHost}/ic/dcb/index.html",
			"Mode=HTML",
			"EncType=application/json",
			"Body={\"agree\":true}",
			LAST);

		lr_end_transaction("DCB_Гугл-аналитика_согласие", LR_AUTO);
	}
 }
