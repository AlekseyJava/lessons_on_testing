Action()
{

	resolve_host();

	lr_save_string("DCB_UC02","UC");

	cacheDownload(); 

	login();


	lr_think_time(atoi("{thinktime}"));

		lr_start_transaction("_{UC}_Создание_ПП");

        create();

		lr_end_transaction("_{UC}_Создание_ПП",LR_AUTO);

		lr_think_time(atoi("{thinktime}"));


	logout();

    return 0;
}