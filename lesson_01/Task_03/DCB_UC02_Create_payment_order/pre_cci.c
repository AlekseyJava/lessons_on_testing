# 1 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c"
# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrw_custom_body.h" 1
 





# 8 "globals.h" 2

# 1 "login.c" 1
login()
{
   lr_start_transaction("{UC}_01_Загрузка_главной_страницы");

	web_url("login.html", 
		"URL=http://{balancedHost}/ic/dcb/login.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTTP", 
		"LAST");

	web_reg_save_param_ex(
		"ParamName=csrftoken",
		"LB=csrftoken: ",
		"RB=\r\n",
		"SEARCH_FILTERS",
			"Scope=headers",
		"LAST");

	web_url("grib.js", 
		"URL=http://{balancedHost}/ic/dcb/rest/override-content/grib.js", 
		"Resource=1", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"LAST");

	web_add_auto_header("csrftoken", lr_eval_string("{csrftoken}"));


	web_url("settings", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/settings", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"LAST");

	web_url("globalnews", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/globalnews", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"LAST");
	web_url("view", 
		"URL=http://{balancedHost}/ic/dcb/rest/auth/banners/view", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/login.html", 
		"LAST");

	lr_end_transaction("{UC}_01_Загрузка_главной_страницы",2);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

    lr_start_transaction("{UC}_02_Прелогин");
	web_reg_save_param_ex("ParamName=srpB",
		"LB=srpB\":\"",
		"RB=\",\"",
		"SEARCH_FILTERS",
			"Scope=Body",
		"LAST");
		
	web_reg_save_param_ex("ParamName=srpS",
		"LB=srpS\":\"",
		"RB=\"",
		"LAST");

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
		"LAST");
	check_error();

	lr_end_transaction("{UC}_02_Прелогин",2);
	
	lr_start_transaction(lr_eval_string("[Service]_{UC}_SRP_auth"));

	web_reg_save_param_ex("ParamName=valueA", 
		"LB=valueA=", 
		"RB=,", 
		"Ordinal=1", 
		"SaveLen=-1",
		"SEARCH_FILTERS", 
		"IgnoreRedirections=off",
		"Scope=body", 
		"LAST"); 

	web_reg_save_param_ex("ParamName=valueM", 
		"LB=valueM=", 
		"RB=<", 
		"Ordinal=1", 
		"SaveLen=-1",
		"SEARCH_FILTERS", 
		"IgnoreRedirections=off",
		"Scope=body", 
		"LAST");

	web_submit_data("aplana_posttest", 
		"Action=http://{srp_host}:{srp_port}/sbbol_bicrypt_login/calculate_srp_data", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Mode=http", 
		"ITEMDATA", 
		"Name=user_login", "Value={login}", "ENDITEM", 
		"Name=user_password", "Value={password}", "ENDITEM", 
		"Name=srp_salt", "Value={srpB}", "ENDITEM", 
		"Name=srp_valueB", "Value={srpS}", "ENDITEM", 
		"LAST");

    lr_end_transaction(lr_eval_string("[Service]_{UC}_SRP_auth"), 2);

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
		"LAST");

	check_error();

	lr_end_transaction("{UC}_03_Логин",2);

	lr_start_transaction("{UC}_04_Ввод_одноразового_пароля");

	web_reg_save_param_ex("ParamName=csrftoken",
		"LB=csrftoken: ",
		"RB=\r\n",
		"SEARCH_FILTERS",
			"Scope=headers",
		"LAST");

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
		"LAST");
	check_error();

	(web_remove_auto_header("csrftoken", "ImplicitGen=Yes", "LAST"));        
	web_add_auto_header("csrftoken", lr_eval_string("{csrftoken}"));

	lr_end_transaction("{UC}_04_Ввод_одноразового_пароля",2);

	lr_start_transaction("{UC}_05_Загрузка_личного_кабинета");

	web_custom_request("update",
		"URL=http://{balancedHost}/ic/dcb/rest/accounts/update",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=http://{balancedHost}/ic/dcb/",
		"Mode=HTML",
		"EncType=",
		"LAST");

	lr_continue_on_error(1);

	web_reg_save_param_ex(
		"ParamName=p_signProfileId", 
		"LB=signProfiles\":[{\"id\":\"", 
		"RB=\",",
		"Notfound=error",
		"LAST");

    web_reg_save_param_regexp("ParamName=userName",
		"RegExp=name\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userAccountNumber",
		"RegExp=accountNumber\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userTaxNum",
		"RegExp=taxNumber\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userKpp",
		"RegExp=kpps\":\\[\"(.+?)\"", 
		"Notfound=warning",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userBankName",
		"RegExp=bank\":{.+?name\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userBankBic",
		"RegExp=bic\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userBankCorrAcct",
		"RegExp=corrAcct\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userSType",
		"RegExp=settlementType\":\"(.+?)\"", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=userBankCity",
		"RegExp=city\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");
		
    web_reg_save_param_regexp("ParamName=accountIds",
		"RegExp={\"id\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
		"LAST");

	web_reg_save_param_ex("ParamName=response",
        "Notfound=warning",
 		"SEARCH_FILTERS",
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
		"LAST");

    web_reg_save_param_regexp(
		"ParamName=p_orgName",
		"RegExp=financialName\":\"(.+?)\",", 
		"Notfound=error",
		"SEARCH_FILTERS", 
			"RequestUrl=http://{balancedHost}/ic/dcb/rest/accounts",
			"IgnoreRedirections=Yes",
			"Scope=Body",
			"Ordinal=1",
		"LAST");

	asupCheck();

	web_url("index.html", 
		"URL=http://{balancedHost}/ic/dcb/index.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{balancedHost}/ic/dcb/", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=rest/override-content/grib.js", "ENDITEM", 
		"Url=resources/features.json", "ENDITEM", 
		"Url=resources/features.json", "ENDITEM", 
		"Url=rest/configuration/settings/", "ENDITEM", 
		"Url=rest/auth/settings", "ENDITEM", 
		"Url=rest/configuration/settings", "ENDITEM", 
		"Url=rest/user-info/permissions", "ENDITEM", 
		"Url=rest/user-info/services", "ENDITEM", 
		"Url=rest/user-info/sign-profiles/", "ENDITEM", 
		"Url=rest/user-info/", "ENDITEM", 
		"Url=rest/letters/statistics", "ENDITEM", 
		"Url=rest/tokens/certificates/requests/profiles", "ENDITEM", 
		"Url=rest/payments/orders/statistics/for-sign", "ENDITEM", 
		"Url=rest/payments/orders/statistics/for-send", "ENDITEM", 
		"Url=rest/configuration/settings", "ENDITEM", 
		"Url=rest/payments/currency/personal-rate/available", "ENDITEM", 
		"Url=rest/accounts", "ENDITEM", 
		"Url=rest/e-invoicing/documents/statistics", "ENDITEM", 
		"Url=rest/configuration/settings", "ENDITEM", 
		"Url=rest/user-info/profile/settings", "ENDITEM", 
		"Url=rest/user-profile/?", "ENDITEM",
		"Url=rest/asup-data", "ENDITEM", 
		"Url=rest/configuration/asup-settings", "ENDITEM", 
		"Url=rest/asup-data/wn_plashka", "ENDITEM", 
		"Url=rest/asup-data/WN_FIRST_VISIT/shown-limited", "ENDITEM", 
		"Url=rest/asup-data/WN_NEXT_VISIT", "ENDITEM", 
		"LAST");

	if (lr_get_transaction_status("{UC}_05_Загрузка_личного_кабинета") == 1) {
		lr_convert_string_encoding(lr_eval_string("{response}"),"utf-8",0,"msg");
		lr_error_message("%s", lr_eval_string("{msg}"));
		lr_exit(2,1);
	}

	lr_continue_on_error(0);

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
		"EXTRARES", 
        "Url=/ic/dcb/images/sprite-i-main-page-menu.svg",
		"Referer=http://{balancedHost}/ic/dcb/dist/app.css", "ENDITEM", 
		"LAST");

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
		"LAST");

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
		"LAST");

	 
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
		"LAST");

    web_custom_request("userresponses", 
		"URL=http://{balancedHost}/ic/dcb/rest/asup-data/userresponses", 
		"Method=POST", 
		"Resource=0", 
		"Referer=http://{balancedHost}/ic/dcb/index.html",  
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"type\":\"LGN\"}", 
		"LAST");
	lr_end_transaction("{UC}_05_Загрузка_личного_кабинета",2);

	asupClick();

	return 0;
}
# 9 "globals.h" 2

# 1 "logout.c" 1
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
		"LAST");

	web_url("login.html", 
		"URL=http://{balancedHost}/ic/dcb/login.html?justSignedOut", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"Mode=HTML", 
		"LAST");

 	lr_end_transaction(lr_eval_string("{UC}_13_Выход"),2);

	return 0;
}
# 10 "globals.h" 2

 
 


 
 



# 3 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
 
 
 
 
	return 0;
}
# 4 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "Action.c" 1
Action()
{

	 

	lr_save_string("DCB_UC02","UC");

	 

 


	lr_think_time(atoi("{thinktime}"));


		lr_start_transaction("_{UC}_Создание_ПП");

        create();

		lr_end_transaction("_{UC}_Создание_ПП",2);

		lr_think_time(atoi("{thinktime}"));


	 


    return 0;
}
# 5 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "create.c" 1
create()
{
	 
	int amount = atoi("{amount}");
	double nds = ((double)amount/118)*18;
	char strNds[100];
	lr_save_int(nds,"nds");
	 
    lr_start_transaction("{UC}_06_Вкладка_платежи_и_переводы");

	web_url("statistics_3", 
		"URL=http://{balancedHost}/ic/dcb/rest/letters/statistics", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://{balancedHost}/ic/dcb/index.html", 
		"LAST");

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
		"LAST");
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
		"LAST");

	lr_end_transaction(lr_eval_string("{UC}_06_Вкладка_платежи_и_переводы"),2);

	lr_start_transaction(lr_eval_string("{UC}_07_Меню_Новый_платеж_контрагенту"));

	web_reg_save_param_ex("ParamName=number",
		"LB=number\":\"",
		"RB=\",\"",
        "Notfound=error",
 		"SEARCH_FILTERS",
 			"RequestUrl=http://{balancedHost}/ic/dcb/rest/payments/orders/prefilled-forms?type=RUB_COMM",
		"LAST");

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
		"EXTRARES", 
		"Url=../payments/orders/prefilled-forms?type=RUB_COMM", "ENDITEM", 
 		"Url=../dictionaries/common/small", "Referer=http://{balancedHost}/ic/dcb/index.html", "ENDITEM",
 		"Url=../dictionaries/common/vat", "Referer=http://{balancedHost}/ic/dcb/index.html", "ENDITEM",
		"LAST");

	lr_end_transaction(lr_eval_string("{UC}_07_Меню_Новый_платеж_контрагенту"),2);

	lr_think_time(atoi(lr_eval_string("{thinktime}")));

	lr_start_transaction(lr_eval_string("{UC}_08_Кнопка_Создать"));

	web_reg_save_param_ex("ParamName=docID", 
		"LB={\"id\":\"", 
		"RB=\",\"version",
		"Notfound=error",
		"LAST");
	
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
		"LAST");

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
		"EXTRARES", 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", "ENDITEM", 
		"LAST");

	lr_end_transaction(lr_eval_string("{UC}_08_Кнопка_Создать"),2);

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
		"LAST");

	check_error();

	lr_end_transaction(lr_eval_string("{UC}_09_Кнопка_Получить_SMS_код"),2);

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
		"LAST");

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
		"EXTRARES", 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", "ENDITEM", 
		"LAST");

	lr_end_transaction(lr_eval_string("{UC}_10_Ввод_и_отправка_SMS_пароля"),2);

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
		"LAST");

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
		"EXTRARES", 
		"Url={docID}", "Referer=http://{balancedHost}/ic/dcb/index.html", "ENDITEM", 
		"LAST");

	lr_end_transaction(lr_eval_string("{UC}_11_Кнопка_Отправить_в_банк"),2);

	return 0;
}
# 6 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 7 "e:\\aiteco\\lessons\\lesson_01\\task_03\\dcb_uc02_create_payment_order\\\\combined_DCB_UC02_Create_payment_order.c" 2

