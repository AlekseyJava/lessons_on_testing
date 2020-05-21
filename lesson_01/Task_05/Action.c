Action()
{

	lr_start_transaction("01_MainPage");

	
	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("slovardalja.net", 
		"URL=http://slovardalja.net/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://an.yandex.ru/system/context.js", ENDITEM, 
		"Url=http://ssp-rtb.sape.ru/data/?callback=sapeRTBreadRtStatResponse_53471&srtbid=95403&scids=93390459&sx=1280&sy=913&ref=&allimps=0&fl=0&tz=%2B04%3A00&u=http%3A%2F%2Fslovardalja.net%2F", ENDITEM, 
		"Url=http://counter.yadro.ru/hit?q;t44.1;r;s1280*1024*24;uhttp%3A//slovardalja.net/;h%u0422%u043E%u043B%u043A%u043E%u0432%u044B%u0439%20%u0441%u043B%u043E%u0432%u0430%u0440%u044C%20%u0414%u0430%u043B%u044F%20%u043E%u043D%u043B%u0430%u0439%u043D;0.14184255798015322", ENDITEM, 
		"Url=http://avatars.mds.yandex.net/get-direct/478025/bA5QHtMpdQb7YLz3Dp-AXA/x450", ENDITEM, 
		"Url=http://avatars.mds.yandex.net/get-direct/2799451/F9d5XfgXTMDm-XIasVhqTA/y300", ENDITEM, 
		"Url=http://tpc.googlesyndication.com/sodar/sodar2.js", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"http://slovardalja.net");

	web_custom_request("ip2w.json", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"start\",\"ts\":8405}],\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	web_custom_request("ip2w.json_2", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"blocksId\":[\"9050\",\"16494\"],\"isAdBlock\":false,\"referrer\":\"http://no.domain/\",\"sessionReferrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-~~SHA~VERSION~STRING~~\",\"r\":\"ug97rprcgy\",\"city\":null,\"region\":null,\"countryCode\":null,\"width\":1280,\"skip\":[]}", 
		LAST);

	web_custom_request("ip2w.json_3", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"loaded\",\"ts\":9816},{\"t\":\"fetch\",\"bId\":9050,\"ts\":9910},{\"t\":\"fetch\",\"bId\":16494,\"ts\":9910}],\"referrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	web_custom_request("ip2w.json_4", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"injected\",\"bId\":9050,\"aId\":30300,\"ts\":12439},{\"t\":\"injected\",\"bId\":16494,\"aId\":50542,\"ts\":12452}],\"referrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	lr_think_time(7);

	web_custom_request("ip2w.json_5", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"thick\",\"bId\":9050,\"aId\":30300,\"ts\":23969}],\"referrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	web_custom_request("ip2w.json_6", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"thick\",\"bId\":16494,\"aId\":50542,\"ts\":159908}],\"referrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	web_custom_request("ip2w.json_7", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"dom\",\"ts\":176020}],\"referrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"ug97rprcgy\"}", 
		LAST);

	lr_end_transaction("01_MainPage", LR_AUTO);

	/* Переход на букву З */
	
	lr_start_transaction("02_LetterPage");


	web_add_cookie("__utma=196215790.1108334625.1590051561.1590051561.1590051561.1; DOMAIN=slovardalja.net");

	web_add_cookie("__utmb=196215790; DOMAIN=slovardalja.net");

	web_add_cookie("__utmc=196215790; DOMAIN=slovardalja.net");

	web_add_cookie("__utmz=196215790.1590051561.1.1.utmccn=(direct)|utmcsr=(direct)|utmcmd=(none); DOMAIN=slovardalja.net");

	web_add_cookie("__gads=ID=ee91d3edd5a58f0b:T=1590051562:S=ALNI_MaKzNz_R7D-2qc3I0ubePqIVvKFPw; DOMAIN=slovardalja.net");

	web_add_cookie("fid=c5bb0c20-ef57-427e-93e7-f0c70c2a6912; DOMAIN=slovardalja.net");

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	//lr_think_time(10);

	web_url("letter.php", 
		"URL=http://slovardalja.net/letter.php?charkod=199", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://slovardalja.net");

	web_custom_request("ip2w.json_8", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"start\",\"ts\":1666}],\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		LAST);

	web_custom_request("ip2w.json_9", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"blocksId\":[\"9050\"],\"isAdBlock\":false,\"referrer\":\"http://slovardalja.net/\",\"sessionReferrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-~~SHA~VERSION~STRING~~\",\"r\":\"2n4ydvohl0\",\"city\":null,\"region\":null,\"countryCode\":null,\"width\":1280,\"skip\":[]}", 
		LAST);

	web_custom_request("ip2w.json_10", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"blocksId\":[\"16494\"],\"isAdBlock\":false,\"referrer\":\"http://slovardalja.net/\",\"sessionReferrer\":\"http://no.domain/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-~~SHA~VERSION~STRING~~\",\"r\":\"2n4ydvohl0\",\"city\":null,\"region\":null,\"countryCode\":null,\"width\":1280,\"skip\":[]}", 
		LAST);

	web_custom_request("ip2w.json_11", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"loaded\",\"ts\":4368},{\"t\":\"fetch\",\"bId\":9050,\"ts\":4372},{\"t\":\"fetch\",\"bId\":16494,\"ts\":6791}],\"referrer\":\"http://slovardalja.net/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		LAST);

	web_custom_request("ip2w.json_12", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"injected\",\"bId\":9050,\"aId\":30300,\"ts\":7013},{\"t\":\"injected\",\"bId\":16494,\"aId\":50542,\"ts\":7237}],\"referrer\":\"http://slovardalja.net/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		EXTRARES, 
		"Url=http://ssp-rtb.sape.ru/data/?callback=sapeRTBreadRtStatResponse_53471&srtbid=95403&scids=93390459&sx=1280&sy=913&ref=http%3A%2F%2Fslovardalja.net%2F&allimps=0&fl=0&tz=%2B04%3A00&u=http%3A%2F%2Fslovardalja.net%2Fletter.php%3Fcharkod%3D199", "Referer=http://slovardalja.net/letter.php?charkod=199", ENDITEM, 
		"Url=http://counter.yadro.ru/hit?q;t44.1;rhttp%3A//slovardalja.net/;s1280*1024*24;uhttp%3A//slovardalja.net/letter.php%3Fcharkod%3D199;h%u0422%u043E%u043B%u043A%u043E%u0432%u044B%u0439%20%u0441%u043B%u043E%u0432%u0430%u0440%u044C%20%u0414%u0430%u043B%u044F%20%u043E%u043D%u043B%u0430%u0439%u043D;0.06727346773787524", "Referer=http://slovardalja.net/letter.php?charkod=199", ENDITEM, 
		LAST);

	web_custom_request("ip2w.json_13", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"thick\",\"bId\":9050,\"aId\":30300,\"ts\":36173}],\"referrer\":\"http://slovardalja.net/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		LAST);

	web_custom_request("ip2w.json_14", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"thick\",\"bId\":16494,\"aId\":50542,\"ts\":39024}],\"referrer\":\"http://slovardalja.net/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		LAST);

	lr_think_time(4);

	web_custom_request("ip2w.json_15", 
		"URL=http://any.realbig.media/ip2w.json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://slovardalja.net/letter.php?charkod=199", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"stat\":[{\"t\":\"dom\",\"ts\":42567}],\"referrer\":\"http://slovardalja.net/\",\"url\":\"http://slovardalja.net/letter.php?charkod=199\",\"v\":\"2.2.1-f9e3db2\",\"r\":\"2n4ydvohl0\"}", 
		LAST);

	lr_end_transaction("02_LetterPage", LR_AUTO);

	/* стоп */

	return 0;
}