# If you want to change the display of OLED, you need to change here
SRC += ./lib/rgb_state_reader.c \
       ./lib/layer_state_reader.c \
       ./lib/logo_reader.c \
       ./lib/keylogger.c \
       # ./lib/mode_icon_reader.c \
       # ./lib/host_led_state_reader.c \
       # ./lib/timelogger.c \

BOOTMAGIC_ENABLE = lite  # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no     # Mouse keys
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
VIA_ENABLE = yes         # Enable VIA
