//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe, 0xfe, 0x0e, 0x06, 0x06, 
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8e, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0x3e, 
        0x3c, 0x3e, 0x1e, 0x06, 0x06, 0x06, 0x06, 0xe6, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe, 0xfe, 
        0x06, 0x06, 0x06, 0x06, 0x0e, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe, 0x86, 0x06, 0x06, 
        0x06, 0x06, 0x3e, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x06, 
        0x06, 0x06, 0x06, 0x06, 0x06, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x06, 0x06, 0x06, 
        0x06, 0x06, 0xfe, 0xfe, 0xf8, 0x1c, 0x0e, 0x06, 0x06, 0x07, 0x03, 0x03, 0x06, 0x06, 0x06, 0x0c, 
        0x38, 0xe0, 0xf0, 0x38, 0x0c, 0x06, 0x06, 0x06, 0x07, 0x06, 0x06, 0x06, 0x0c, 0xfc, 0xf8, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x06, 0x06, 
        0x06, 0xee, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xf8, 0x20, 
        0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1e, 0x1e, 0x1e, 0x0c, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x38, 0x0c, 0x0c, 0x04, 0x07, 0x07, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1e, 0x3e, 0xfc, 0xfc, 0x3f, 0x3f, 0x00, 
        0x00, 0xf8, 0xf8, 0x08, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x08, 0xf8, 
        0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0x3f, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xe0, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc3, 0x00, 0x00, 
        0x00, 0x00, 0x08, 0x3e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x3c, 0x1c, 0x1c, 0x18, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3e, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xff, 0xff, 0x3b, 0x37, 0x2c, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x78, 0x00, 
        0x00, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1f, 
        0x1f, 0x0f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x00, 0x0f, 0x1c, 0x18, 0x18, 
        0x18, 0x18, 0x18, 0x18, 0x1f, 0x0f, 0x00, 0x00, 0x0f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
        0x18, 0x1f, 0x1f, 0x1f, 0x18, 0x10, 0x10, 0x10, 0x18, 0x18, 0x18, 0x1f, 0x07, 0x07, 0x0e, 0x0c, 
        0x18, 0x18, 0x18, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x1f, 0x1f, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x18, 0x1f, 0x1f, 0x0e, 0x0c, 0x18, 0x18, 0x18, 0x10, 0x10, 0x10, 0x30, 
        0x30, 0x30, 0x3f, 0x3f, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1f, 0x1f, 0x38, 0x30, 0x30, 0x30, 
        0x30, 0x3f, 0x1f, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x1c, 0x0f, 0x03, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("Mac"), false);
    } else {
        oled_write_ln_P(PSTR("Win"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    oled_write_ln_P(PSTR("LAYER"), false); 
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Cmds\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Symbl"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("SCRLK"), led_usb_state.scroll_lock);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
