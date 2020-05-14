ActionWorkWithValue()
{
	int i = 10;
	lr_output_message("%d",i/5);
	
	lr_save_string("some value","parametr");
	
	lr_output_message(lr_eval_string("{parametr}"));
	//lr_output_message(lr_ev);
	return 0;
}
