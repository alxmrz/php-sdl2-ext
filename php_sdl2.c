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

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        php_printf("Cant intitialize SDL: %s\n", SDL_GetError());
        return;
    }

    SDL_Window *window = SDL_CreateWindow(
            "Tetris with SDL2!",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            600,
            SDL_WINDOW_SHOWN);

    if (window == NULL) {
        php_printf("Can't create window: %s\n", SDL_GetError());
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        php_printf("Can't create renderer: %s\n", SDL_GetError());

        return;
    }

    SDL_UpdateWindowSurface(window);
    SDL_SetRenderDrawColor(renderer, 160, 160, 160, 0);
    SDL_Rect mainRect = {0, 0, 800, 600};

    if (SDL_RenderFillRect(renderer, &mainRect) < 0) {
        php_printf("Can't resresh canvas: (%s)", SDL_GetError());
        SDL_Quit();
        return ;
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    SDL_DestroyWindow(window);

	php_printf("The extension %s is loaded and working!\r\n", "php_sdl2");
	php_printf("The extension %s is loaded and working!\r\n", "php_sdl2");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

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

/* {{{ php_sdl2_module_entry */
zend_module_entry php_sdl2_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_sdl2",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
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
