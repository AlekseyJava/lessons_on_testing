Action()
{

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("slovardalja.net", 
		"URL=http://slovardalja.net/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t94.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	lr_think_time(66);

	/* Нажимаю на букву К */

	web_add_cookie("__utma=196215790.657020300.1589556729.1589556729.1589556729.1; DOMAIN=slovardalja.net");

	web_add_cookie("__utmc=196215790; DOMAIN=slovardalja.net");

	web_add_cookie("__utmz=196215790.1589556729.1.1.utmccn=(direct)|utmcsr=(direct)|utmcmd=(none); DOMAIN=slovardalja.net");

	web_add_cookie("__gads=ID=e00f22fd17b91716:T=1589556730:S=ALNI_MaKKiQsabpquzlTWZDvT2Pmduuo2w; DOMAIN=slovardalja.net");

	web_add_cookie("fid=6c551876-6878-4776-9b41-aba7bf111072; DOMAIN=slovardalja.net");

		web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(1541);

	web_url("letter.php", 
		"URL=http://slovardalja.net/letter.php?charkod=202", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t112.inf", 
		"Mode=HTML", 
		LAST);


	lr_think_time(134);

	/* Переходим на КАВЫГЛАЗ(12 слово) */
	
	web_add_cookie("__utma=196215790.657020300.1589556729.1589556729.1589558553.2; DOMAIN=slovardalja.net");

	web_add_cookie("__utmb=196215790; DOMAIN=slovardalja.net");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("word.php", 
		"URL=http://slovardalja.net/word.php?wordid=12475", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/letter.php?charkod=202", 
		"Snapshot=t135.inf", 
		"Mode=HTML", 
		LAST);

	/* Exit */
	return 0;
}