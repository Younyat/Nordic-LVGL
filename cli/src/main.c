/*
 * Copyright (c) 2015 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr.h>
#include <sys/printk.h>
#include <shell/shell.h>
#include <version.h>
#include <logging/log.h>
#include <stdlib.h>
#include <kernel.h>
#include <stdio.h>
#include <secure_services.h>
#include <pm_config.h>
#include <fw_info.h>
#include <drivers/uart.h>
#include <cJSON.h>
#include <string.h>
#ifdef CONFIG_USB
#include <usb/usb_device.h>
#endif

#include <blst.h>
#include <common.h>
#include <bls_hsm_ns.h>


//------------------------
#include <device.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <logging/log.h>
uint32_t count = 0U;
#include <stdio.h>
char buf[2048] = "";
lv_obj_t * label1;

void lv_ex_label_1()
{
    label1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_BREAK);     /*Break the long lines*/
    lv_label_set_recolor(label1, true);                      /*Enable re-coloring by commands in the text*/
    lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
    lv_label_set_text(label1, "#0000ff Decentralized# #ff00ff Security# #ff0000 Decentralized # "
                              "Security");
    lv_obj_set_width(label1, 150);
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, -30);

    
}







#if LV_USE_BTN

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("Confirmado\n");
          /*Center aligned lines*/

    lv_label_set_text(label1, "#0000ffYounes Confirmado");
   
    }
    else if(event == LV_EVENT_VALUE_CHANGED) {
        printf("Habilitado\n");
    }
}

void lv_ex_btn_1(void)
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(btn1, event_handler);
    lv_obj_align(btn1, NULL, LV_ALIGN_IN_BOTTOM_MID, -80, 0);

    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Confirmation!!");

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(btn2, event_handler);
    lv_obj_align(btn2, NULL, LV_ALIGN_IN_BOTTOM_MID, 80, 0);
    lv_btn_set_checkable(btn2, true);
    lv_btn_toggle(btn2);
    lv_btn_set_fit2(btn2, LV_FIT_NONE, LV_FIT_TIGHT);

    label = lv_label_create(btn2, NULL);
    lv_label_set_text(label, "Enable");
}
#endif

#define LV_USE_BTN



//-----------------------------
char buffer[2048] = "";


#define CONFIG_SPM_SERVICE_RNG

LOG_MODULE_REGISTER(app);

static int cmd_keygen(const struct shell *shell, size_t argc, char **argv)
{
    if(argc == 1){
        keygen("", buffer);
    }else{
        keygen(argv[1], buffer);
    }
    printf(buffer);
    strcpy(buf,buffer);
    memset(buffer, 0, 2048);
    //v_label_set_text(label1, buf);
    return 0;
}

static int cmd_signature_message(const struct shell *shell, size_t argc, char **argv, char* buff)
{
    if(signature(argv[1], argv[2], buffer) == 0){
        printf("Signature: \n");
        printf("%s%s\n", "0x", buffer);
    }else{
        printf(buffer);
        strcpy(buf,buffer);
    lv_label_set_text(label1, buf);
    memset(buf, 0, 2048);
    }
    memset(buffer, 0, 2048);
	return 0;
}

static int cmd_signature_verification(const struct shell *shell, size_t argc, char **argv, char* buff)
{
    verify(argv[1], argv[2], argv[3], buffer);
    printf(buffer);
    strcpy(buf,buffer);
    lv_label_set_text(label1, buf);
    memset(buf, 0, 2048);
    memset(buffer, 0, 2048);
	return 0;
}

static int cmd_get_keys(const struct shell *shell, size_t argc, char **argv, char* buff)
{
    print_keys_Json(buffer);
    printf(buffer);
    strcpy(buf,buffer);
    lv_label_set_text(label1, buf);
    memset(buf, 0, 2048);
    memset(buffer, 0, 2048);
    
	return 0;
}

static int cmd_reset(const struct shell *shell, size_t argc, char **argv, char* buff){
    resetc(buffer);
    printf(buffer);
    memset(buffer, 0, 2048);
    return 0;
}

static int cmd_prompt(const struct shell *shell, size_t argc, char **argv){
    ARG_UNUSED(argc);

    if(strcmp(argv[1], "on") == 0){
        shell_prompt_change(shell, "uart:~$ ");
        
    }else if(strcmp(argv[1], "off") == 0){
        shell_prompt_change(shell, "");
    }else{
        printf("Usage: prompt on/off\n");
    }
    strcpy(buf,"uart:~$" );
    lv_label_set_text(label1, buf);
    memset(buf, 0, 2048);
    return 0;
}

static int cmd_import(const struct shell *shell, size_t argc, char **argv){
    lv_ex_label_1();
    import(argv[1], buffer);
    printf(buffer);
    strcpy(buf,buffer);
    lv_label_set_text(label1, buf);
    memset(buf, 0, 2048);
    memset(buffer, 0, 2048);
    return 0;
}

SHELL_CMD_ARG_REGISTER(keygen, NULL, "Generates secret key and public key", cmd_keygen, 1, 1);

SHELL_CMD_ARG_REGISTER(signature, NULL, "Signs a message with a specific public key", cmd_signature_message, 3, 0);

SHELL_CMD_ARG_REGISTER(verify, NULL, "Verifies the signature", cmd_signature_verification, 4, 0);

SHELL_CMD_ARG_REGISTER(getkeys, NULL, "Returns the identifiers of the keys available to the signer", cmd_get_keys, 1, 0);

SHELL_CMD_ARG_REGISTER(reset, NULL, "Deletes all generated keys", cmd_reset, 1, 0);

SHELL_CMD_ARG_REGISTER(prompt, NULL, "Toggle prompt", cmd_prompt, 2, 0);

SHELL_CMD_ARG_REGISTER(import, NULL, "Import secret key", cmd_import, 2, 0);

void main(void)
{
#if defined(CONFIG_USB_UART_CONSOLE)
	const struct device *dev;
	uint32_t dtr = 0;

	dev = device_get_binding(CONFIG_UART_SHELL_ON_DEV_NAME);
	if (dev == NULL || usb_enable(NULL)) {
		return;
	}

	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
#endif


    char count_str[11] = {0};
	const struct device *display_dev;
	lv_obj_t *hello_world_label;
	lv_obj_t *count_label;
    lv_event_t event;
	lv_obj_t * label;
	display_dev = device_get_binding(CONFIG_LVGL_DISPLAY_DEV_NAME);

	if (display_dev == NULL) {
		LOG_ERR("device not found.  Aborting test.");
		return;
	}

	if (IS_ENABLED(CONFIG_LVGL_POINTER_KSCAN)) {
		lv_obj_t *hello_world_button;

		//hello_world_button = lv_btn_create(lv_scr_act(), NULL);
		//lv_obj_align(hello_world_button, NULL, LV_ALIGN_CENTER, 0, 0);
		//lv_btn_set_fit(hello_world_button, LV_FIT_TIGHT);
		//hello_world_label = lv_label_create(hello_world_button, NULL);
	} else {
		hello_world_label = lv_label_create(lv_scr_act(), NULL);
	}

	//lv_label_set_text(hello_world_label, "Hello younes!");
	//lv_obj_align(hello_world_label, NULL, LV_ALIGN_CENTER, 0, 0);
 
    //strstr(buf,"Decentralized Security");
   // lv_ex_label_1();
	count_label = lv_label_create(lv_scr_act(), NULL);
	lv_obj_align(count_label, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

	lv_task_handler();
	display_blanking_off(display_dev);

	lv_ex_btn_1();
    lv_ex_label_1();
	while (1) {

	if ((count % 100) == 0U) {
			sprintf(count_str, "%d", count/100U);
			lv_label_set_text(count_label, count_str);
			
		}
	
		lv_task_handler();
		event_handler(label,event);
		k_sleep(K_MSEC(10));
		++count;
	}
}