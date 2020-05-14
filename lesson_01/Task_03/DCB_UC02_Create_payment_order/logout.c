logout()
{
	lr_start_transaction(lr_eval_string("{UC}_13_Выход"));

	web_custom_request("logout", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/logout", 
		"Method=POST", 
		"Resource=0", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_url("login.html", 
		"URL=http://{balancedHost}/ic/dcb/login.html?justSignedOut", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTML", 
		LAST);

 	lr_end_transaction(lr_eval_string("{UC}_13_Выход"),LR_AUTO);

	return 0;
}
