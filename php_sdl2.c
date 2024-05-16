/* php_sdl2 extension for PHP (c) 2024 alxmrz */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_php_sdl2.h"
#include "php_sdl2_arginfo.h"

#include "SDL2/SDL.h"


/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

zend_class_entry *sdl_rect_ce;
zend_class_entry *sdl_window_ce;
zend_class_entry *sdl_renderer_ce;

static SDL_Window *_ext_window = NULL;
static SDL_Renderer *_ext_renderer = NULL;

/* {{{ int SDL_Init() */
PHP_FUNCTION(SDL_Init)
{
    long flags;

    ZEND_PARSE_PARAMETERS_START(0, 1)
            Z_PARAM_OPTIONAL
            Z_PARAM_LONG(flags)
    ZEND_PARSE_PARAMETERS_END();

    long result = SDL_Init(flags);

    RETURN_LONG(result);
}
/* }}} */

/* {{{ int SDL_GetError() */
PHP_FUNCTION(SDL_GetError)
{
    ZEND_PARSE_PARAMETERS_NONE();

    const char * result = SDL_GetError();

    RETURN_STRING(result);
}
/* }}} */

/* {{{ int SDL_CreateWindow() */
PHP_FUNCTION(SDL_CreateWindow)
{
    char *title = "Window title";
    size_t title_len = sizeof("Window title") - 1;

    long x;
    long y;
    long width;
    long height;
    long flags;

    ZEND_PARSE_PARAMETERS_START(6, 6)
            Z_PARAM_STRING(title, title_len)
            Z_PARAM_LONG(x)
            Z_PARAM_LONG(y)
            Z_PARAM_LONG(width)
            Z_PARAM_LONG(height)
            Z_PARAM_LONG(flags)
    ZEND_PARSE_PARAMETERS_END();

    SDL_Window *window = SDL_CreateWindow(
            title,
            (int)x,
            (int)y,
            (int)width,
            (int)height,
            flags
    );
    if (window == NULL) {
        RETURN_NULL();
    }

    _ext_window = window;

    zval result;

    object_init_ex(&result, sdl_window_ce);

    RETURN_OBJ(Z_OBJ(result));
}
/* }}} */

/* {{{ int SDL_CreateRenderer() */
PHP_FUNCTION(SDL_CreateRenderer)
{
    long index;
    long flags;

    ZEND_PARSE_PARAMETERS_START(2, 2)
            Z_PARAM_LONG(index)
            Z_PARAM_LONG(flags)
    ZEND_PARSE_PARAMETERS_END();

    SDL_Renderer *renderer = SDL_CreateRenderer(
            _ext_window,
            (int)index,
            (int)flags
    );
    if (renderer == NULL) {
        RETURN_NULL();
    }

    _ext_renderer = renderer;

    zval result;

    object_init_ex(&result, sdl_renderer_ce);

    RETURN_OBJ(Z_OBJ(result));
}
/* }}} */

/* {{{ int SDL_UpdateWindowSurface() */
PHP_FUNCTION(SDL_UpdateWindowSurface)
{
    ZEND_PARSE_PARAMETERS_NONE();

    if (SDL_UpdateWindowSurface(_ext_window) < 0) {
        RETURN_FALSE;
    }

    RETURN_TRUE;
}
/* }}} */

/* {{{ int SDL_SetRenderDrawColor() */
PHP_FUNCTION(SDL_SetRenderDrawColor)
{
    long r;
    long g;
    long b;
    long a;

    ZEND_PARSE_PARAMETERS_START(4, 4)
            Z_PARAM_LONG(r)
            Z_PARAM_LONG(g)
            Z_PARAM_LONG(b)
            Z_PARAM_LONG(a)
    ZEND_PARSE_PARAMETERS_END();

    if (SDL_SetRenderDrawColor(_ext_renderer, r, g, b, a) < 0) {
        RETURN_FALSE;
    }

    RETURN_TRUE;
}
/* }}} */

/* {{{ int SDL_RenderFillRect() */
PHP_FUNCTION(SDL_RenderFillRect)
{
    zval *obj;
    zval rv;

    zval* px, *py, *pw, *ph;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_OBJECT_OF_CLASS(obj, sdl_rect_ce)
    ZEND_PARSE_PARAMETERS_END();

    px = zend_read_property(sdl_rect_ce, Z_OBJ_P(obj), "x", sizeof("x")-1, 1, &rv);
    py = zend_read_property(sdl_rect_ce, Z_OBJ_P(obj), "y", sizeof("y")-1, 1, &rv);
    pw = zend_read_property(sdl_rect_ce, Z_OBJ_P(obj), "width", sizeof("width")-1, 1, &rv);
    ph = zend_read_property(sdl_rect_ce, Z_OBJ_P(obj), "height", sizeof("height")-1, 1, &rv);

    SDL_Rect rect = {
            (int) zval_get_long(px),
            (int) zval_get_long(py),
            (int) zval_get_long(pw),
            (int) zval_get_long(ph)
    };

    RETURN_LONG(SDL_RenderFillRect(_ext_renderer, &rect));
}
/* }}} */

/* {{{ int SDL_RenderPresent() */
PHP_FUNCTION(SDL_RenderPresent)
{
    ZEND_PARSE_PARAMETERS_NONE();

    SDL_RenderPresent(_ext_renderer);
}
/* }}} */

/* {{{ int SDL_Delay() */
PHP_FUNCTION(SDL_Delay)
{
    long ms;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_LONG(ms)
    ZEND_PARSE_PARAMETERS_END();

    SDL_Delay(ms);
}
/* }}} */

/* {{{ int SDL_DestroyRenderer() */
PHP_FUNCTION(SDL_DestroyRenderer)
{
    ZEND_PARSE_PARAMETERS_NONE();

    SDL_DestroyRenderer(_ext_renderer);
}
/* }}} */

/* {{{ int SDL_DestroyWindow() */
PHP_FUNCTION(SDL_DestroyWindow)
{
    ZEND_PARSE_PARAMETERS_NONE();

    SDL_DestroyWindow(_ext_window);
}
/* }}} */

/* {{{ int SDL_Quit() */
PHP_FUNCTION(SDL_Quit)
{
    ZEND_PARSE_PARAMETERS_NONE();

    SDL_Quit();
}
/* }}} */

PHP_METHOD(SDL_Rect, __construct) /* {{{ */
{
    zval *obj;

    long x;
    long y;
    long w;
    long h;

    ZEND_PARSE_PARAMETERS_START(4, 4)
            Z_PARAM_LONG(x)
            Z_PARAM_LONG(y)
            Z_PARAM_LONG(w)
            Z_PARAM_LONG(h)
    ZEND_PARSE_PARAMETERS_END();

    obj = getThis();

    zend_update_property_long(sdl_rect_ce, Z_OBJ_P(obj), "x", sizeof("x") - 1, x);
    zend_update_property_long(sdl_rect_ce, Z_OBJ_P(obj), "y", sizeof("x") - 1, x);
    zend_update_property_long(sdl_rect_ce, Z_OBJ_P(obj), "width", sizeof("width") - 1, w);
    zend_update_property_long(sdl_rect_ce, Z_OBJ_P(obj), "height", sizeof("height") - 1, h);
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(php_sdl2)
{
#if defined(ZTS) && defined(COMPILE_DL_PHP_SDL2)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(php_sdl2)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "php_sdl2 support", "enabled");
	php_info_print_table_end();
}
/* }}} */

PHP_MINIT_FUNCTION(php_sdl2)
{
    REGISTER_STRING_CONSTANT("SDL2_CONSTANT_FROM_EXTENSION", "VALUE_IS", CONST_CS|CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_TIMER", SDL_INIT_TIMER, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_AUDIO", SDL_INIT_AUDIO, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_VIDEO", SDL_INIT_VIDEO, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_JOYSTICK", SDL_INIT_JOYSTICK, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_HAPTIC", SDL_INIT_HAPTIC, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_GAMECONTROLLER", SDL_INIT_GAMECONTROLLER, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_EVENTS", SDL_INIT_EVENTS, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_SENSOR", SDL_INIT_SENSOR, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_INIT_EVERYTHING", SDL_INIT_EVERYTHING, CONST_PERSISTENT);

    REGISTER_LONG_CONSTANT("SDL_WINDOW_SHOWN", SDL_WINDOW_SHOWN, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_RENDERER_ACCELERATED", SDL_RENDERER_ACCELERATED, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SDL_WINDOWPOS_UNDEFINED", SDL_WINDOWPOS_UNDEFINED, CONST_PERSISTENT);

    sdl_rect_ce = register_class_SDL_Rect();
    sdl_renderer_ce = register_class_SDL_Renderer();
    sdl_window_ce = register_class_SDL_Window();

    return SUCCESS;
}


/* {{{ php_sdl2_module_entry */
zend_module_entry php_sdl2_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_sdl2",					/* Extension name */
	ext_functions,					/* zend_function_entry */
    PHP_MINIT(php_sdl2),	/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(php_sdl2),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(php_sdl2),			/* PHP_MINFO - Module info */
	PHP_PHP_SDL2_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_SDL2
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(php_sdl2)
#endif
