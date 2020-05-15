//Automatically generated file for implementing asynchronous callback functions.
//You can modify the automatically generated callback implementations or add new ones.
//Asynchronous callback functions can be registered using web_reg_async_attributes steps.
int Poll_0_RequestCB()
{
	//Enter your implementation for RequestCB() here.

	//Call web_util_set_request_url() here to modify polling URL.
	//URL is expected to be of the form:
	//https://awaps.yandex.net/88/c1/tTu-PwEetoVWpffWBbe7CbdMmSsDlz2yQvFN6WrtxmcNfvNHCSLwXrG42pVuP_tEZTQ0qVi6aUlh1R+r5tpjkZG+ZBg2UzLFOb4Y2jFiyyc+JGiQepeQIX68yHn_tJa8F88R3nV3HyLgW+EL-5VWrz5SYaoBwtyiKTNW+rP3YvRff4cLXyDqhM2+p_tEPuPqB6XNAQZEbVscUkhmMU9emNOfdx1tY-w4PrzdC2+0wsB+OSgN-QW72us_tCABHWQrUlxzbLijh590EzTd05r3BkZjlkGmXJIO0w6fEbwN3lStMxmAJeZo+_t90vOdGRNGnqIBKglZzZM3knUng31XPdEMJLpgIuDv2nibJ1RriourTn7XelT_tQdFQe60v8X4R5-PCWWJVSwx-nfidQv17+E1pIa5QASb+8jjHV0FNwmV94SBY_tuVNtY8E+y+lMbv7koK5UVLCmYfK1Oaoeyf2nPf1ZRrmjWwkDunEGqydruAyw_Q5ITgjDNCbHJVH9zd2ICIdgAA_A_.gif?duration={Unknown_Poll_0_0}&adsdk-bundle-version=3312&adsdk-bundle-name=InteractiveViewer&adsdk-container-visibility=66&adsdk-container-width=700&adsdk-container-height=394&interactive-viewer-test-tag=14576&ad-session-id=2541601589560235177&sid=417f1069557735a9a16c44c9370642063085e6a6dc528cb1db8ee3686dc45bc5&top-ancestor=http%3a%2f%2fslovardalja.net&top-ancestor-undetermined=0&client-ts={TimeStamp_Poll_0_1}&viewability-undetermined=0

	//The following parameters must be assigned:

	//TODO - Implement parameter of unknown type: Unknown_Poll_0_0.
	//Known examples for Unknown_Poll_0_0: duration=3, duration=5, duration=5, duration=5, 
	lr_save_string("3","Unknown_Poll_0_0");

	web_save_timestamp_param("TimeStamp_Poll_0_1",LAST);

	//Once all parameters have been assigned, copy them to the updated URL.
	//Then call web_util_set_request_url() with the updated URL:
	web_util_set_request_url("https://awaps.yandex.net/88/c1/tTu-PwEetoVWpffWBbe7CbdMmSsDlz2yQvFN6WrtxmcNfvNHCSLwXrG42pVuP_tEZTQ0qVi6aUlh1R+r5tpjkZG+ZBg2UzLFOb4Y2jFiyyc+JGiQepeQIX68yHn_tJa8F88R3nV3HyLgW+EL-5VWrz5SYaoBwtyiKTNW+rP3YvRff4cLXyDqhM2+p_tEPuPqB6XNAQZEbVscUkhmMU9emNOfdx1tY-w4PrzdC2+0wsB+OSgN-QW72us_tCABHWQrUlxzbLijh590EzTd05r3BkZjlkGmXJIO0w6fEbwN3lStMxmAJeZo+_t90vOdGRNGnqIBKglZzZM3knUng31XPdEMJLpgIuDv2nibJ1RriourTn7XelT_tQdFQe60v8X4R5-PCWWJVSwx-nfidQv17+E1pIa5QASb+8jjHV0FNwmV94SBY_tuVNtY8E+y+lMbv7koK5UVLCmYfK1Oaoeyf2nPf1ZRrmjWwkDunEGqydruAyw_Q5ITgjDNCbHJVH9zd2ICIdgAA_A_.gif?duration={Unknown_Poll_0_0}&adsdk-bundle-version=3312&adsdk-bundle-name=InteractiveViewer&adsdk-container-visibility=66&adsdk-container-width=700&adsdk-container-height=394&interactive-viewer-test-tag=14576&ad-session-id=2541601589560235177&sid=417f1069557735a9a16c44c9370642063085e6a6dc528cb1db8ee3686dc45bc5&top-ancestor=http%3a%2f%2fslovardalja.net&top-ancestor-undetermined=0&client-ts={TimeStamp_Poll_0_1}&viewability-undetermined=0");

	//Call web_util_set_request_body() here to modify request body:
	//web_util_set_request_body("<request body>");

	return WEB_ASYNC_CB_RC_OK;
}

int Poll_0_ResponseCB(
	const char *	aResponseHeadersStr,
	int				aResponseHeadersLen,
	const char *	aResponseBodyStr,
	int				aResponseBodyLen,
	int				aHttpStatusCode)
{
	//Enter your implementation for ResponseCB() here.

	//TODO - To make the script wait for a specific response, use web_sync in the relevant Action file.
	//See the Modifying Callbacks section in the VuGen user guide for more details.

	return WEB_ASYNC_CB_RC_OK;
}

