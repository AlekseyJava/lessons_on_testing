Action()
{
	lr_output_message("Hello. It is first work with VuGen");
	
//	method_into_method(){
//		lr_output_message("Method into method");
//	}
// ����� � ������ ����� ������ �������?
	method_3();
		
	return 0;
// ���������� ������ ����, �� ��������?
}

//���������� ���������� ������ ����� Action()?
//������� ��� ����� ������ �������� � loadrunner?


method_1() {
	lr_output_message("It is method_1");
}

method_2() {
	lr_output_message("It is method_2");
}

method_3() {
	lr_output_message("It is method_3");
}

method_work_with_transaction() {
	lr_start_transaction("tran1");
	lr_output_message("It is a transaction");
	lr_end_transaction("tran1",LR_AUTO);
	
	//lr_
}
	